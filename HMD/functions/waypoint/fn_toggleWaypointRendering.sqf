/*
* This function toggles the rendering of the waypoint marker to the given state.
*/
if (!hasInterface) exitWith {};

params [["_enable", false, [true]]];

private _handle = player getVariable ["APD_WaypointRenderHandle", nil];

if (_enable && isNil "_handle") then
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
