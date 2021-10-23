/*
* This function toggles the rendering of the waypoint marker to the given state.
*/
if (!hasInterface) exitWith {};

params [["_enable", false, [true]]];

private _handleName = "APD_WaypointRenderHandle";
private _handle = player getVariable [_handleName, nil];
private _exists = !isNil "_handle";

private _display = call APD_fnc_getDisplay;
private _ctrlPictureWaypointMarker = _display displayCtrl 5000;

if (_enable && !_exists) then
{
	_handle = addMissionEventHandler ["Draw3D",
	{
		_thisArgs params ["_ctrl"];

		private _uiPos = worldToScreen customWaypointPosition;
		private _uiOffset = APD_HMD_WaypointMarkerTextureOffset;

		if (count _uiPos >= 2) then
		{
			_ctrl ctrlSetText APD_HMD_WaypointMarkerTexture;
			_ctrl ctrlSetPosition [_uiPos # 0 - _uiOffset, _uiPos # 1 - _uiOffset];
			_ctrl ctrlCommit 0;
		}
		else
		{
			_ctrl ctrlSetText "";
		};
	}, [_ctrlPictureWaypointMarker]];
};

if (!_enable && _exists) then
{
	removeMissionEventHandler ["Draw3D", _handle];
	_ctrlPictureWaypointMarker ctrlSetText "";
	_handle = nil;
};

player setVariable [_handleName, _handle];
