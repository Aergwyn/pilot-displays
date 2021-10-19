/*
* This function toggles the rendering of the vehicles gun view marker to the given state.
*/
if (!hasInterface) exitWith {};

params [["_enable", false, [true]]];

private _handleName = "APD_GunViewRenderHandle";
private _handle = player getVariable [_handleName, nil];
private _exists = !isNil "_handle";

private _turretData = player getVariable ["APD_CopilotTurretData", []];

private _display = call APD_fnc_getDisplay;
private _ctrlPictureCopilotMarker = _display displayCtrl 5100;

if (_enable && !_exists && count _turretData > 0) then
{
	private _vehicle = vehicle player;
	private _memPoint = _turretData # 1;
	private _memPointPos = _vehicle selectionPosition [_memPoint, "Memory"];

	_handle = addMissionEventHandler ["Draw3D",
	{
		_thisArgs params ["_ctrl", "_vehicle", "_memPoint", "_memPointPos"];

		private _memPointVectors = _vehicle selectionVectorDirAndUp [_memPoint, "Memory"];
		private _memPointDir = _vehicle vectorModelToWorld (_memPointVectors select 0);

		private _start = _vehicle modelToWorld _memPointPos;
		private _end = _start vectorAdd (_memPointDir vectorMultiply 5000);
		private _worldPos = terrainIntersectAtASL [AGLtoASL _start, AGLtoASL _end];

		if (_worldPos isNotEqualTo [0, 0, 0]) then
		{
			private _uiPos = worldToScreen (ASLtoAGL _worldPos);
			private _uiOffset = APD_HMD_CopilotMarkerTextureOffset;

			if (count _uiPos >= 2) then
			{
				_ctrl ctrlSetText APD_HMD_WaypointMarkerTexture;
				_ctrl ctrlSetPosition [_uiPos # 0 - _uiOffset, _uiPos # 1 - _uiOffset];
				_ctrl ctrlCommit 0;
			};
		}
		else
		{
			_ctrl ctrlSetText "";
		};
	}, [_ctrlPictureCopilotMarker, _vehicle, _memPoint, _memPointPos]];
};

if (!_enable && _exists) then
{
	removeMissionEventHandler ["Draw3D", _handle];
	_ctrlPictureCopilotMarker ctrlSetText "";
	_handle = nil;
};

player setVariable [_handleName, _handle];
