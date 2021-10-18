/*
* This function toggles the rendering of the vehicles gun view marker to the given state.
*/
if (!hasInterface) exitWith {};

params [["_enable", false, [true]]];

private _handleName = "APD_GunViewRenderHandle";
private _handle = player getVariable [_handleName, nil];
private _exists = !isNil "_handle";

private _turretData = player getVariable ["APD_CopilotTurretData", []];

if (_enable && !_exists && count _turretData > 0) then
{
	private _vehicle = vehicle player;
	private _memPoint = _turretData # 1;
	private _memPointPos = _vehicle selectionPosition [_memPoint, "Memory"];

	_handle = addMissionEventHandler ["Draw3D",
	{
		_thisArgs params ["_vehicle", "_memPoint", "_memPointPos"];

		private _memPointVectors = _vehicle selectionVectorDirAndUp [_memPoint, "Memory"];
		private _memPointDir = _vehicle vectorModelToWorld (_memPointVectors select 0);

		private _start = _vehicle modelToWorld _memPointPos;
		private _end = _start vectorAdd (_memPointDir vectorMultiply 5000);
		private _worldPos = terrainIntersectAtASL [AGLtoASL _start, AGLtoASL _end];

		if (_worldPos isNotEqualTo [0, 0, 0]) then
		{
			drawLine3D [_start, _end, [1, 0, 0, 1]];
			drawIcon3D [APD_HMD_WaypointMarkerTexture, [1, 0, 0, 1], ASLToAGL _worldPos, 1, 1, 0];
		};
	}, [_vehicle, _memPoint, _memPointPos]];
};

if (!_enable && _exists) then
{
	removeMissionEventHandler ["Draw3D", _handle];
	_handle = nil;
};

player setVariable [_handleName, _handle];
