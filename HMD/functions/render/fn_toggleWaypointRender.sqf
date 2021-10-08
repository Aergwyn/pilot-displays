/*
* This function toggles the rendering of the waypoint marker, granted the circumstances allow it.
* For example deleting the current waypoint or changing specific settings will cause the rendering to stop.
*/
if (!hasInterface) exitWith {};

params [["_enable", false, [true]]];

private _handle = player getVariable ["APD_WaypointRenderHandle", nil];
private _allowRender = !(APD_HMD_WaypointMarkerTexture isEqualTo "") && count customWaypointPosition > 0;

if (_enable && _allowRender && isNil "_handle") then
{
	_handle = addMissionEventHandler ["Draw3D",
	{
		drawIcon3D [APD_HMD_WaypointMarkerTexture, APD_HMD_Colour, customWaypointPosition, 1, 1, 0];
	}];
};

if (!_enable && !isNil "_handle") then
{
	removeMissionEventHandler ["Draw3D", _handle];
	_handle = nil;
};

player setVariable ["APD_WaypointRenderHandle", _handle];
