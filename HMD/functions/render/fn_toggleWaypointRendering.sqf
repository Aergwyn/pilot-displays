/*
* This function toggles the rendering of the waypoint marker to the given state.
*/
if (!hasInterface) exitWith {};

params [["_enable", false, [true]]];

private _handleName = "APD_WaypointRenderHandle";
private _handle = player getVariable [_handleName, nil];
private _exists = !isNil "_handle";

if (_enable && !_exists) then
{
	_handle = addMissionEventHandler ["Draw3D",
	{
		drawIcon3D [APD_HMD_WaypointMarkerTexture, APD_HMD_Colour, customWaypointPosition, 1, 1, 0];
	}];
};

if (!_enable && _exists) then
{
	removeMissionEventHandler ["Draw3D", _handle];
	_handle = nil;
};

player setVariable [_handleName, _handle];
