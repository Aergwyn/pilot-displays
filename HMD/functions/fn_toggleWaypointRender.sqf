/*
* This function toggles the rendering of the waypoint marker, granted the circumstances allow it.
* Actions like deleting the current waypoint or changing specific settings will cause the rendering to stop.
*/
if (!hasInterface) exitWith {};

params [["_enable", false, [true]]];

private _handle = player getVariable ["APD_WaypointRenderHandle", nil];

if (_enable && isNil "_handle") then
{
	_handle = addMissionEventHandler ["Draw3D",
	{
		private _waypoint = customWaypointPosition;

		if (count _waypoint > 0) then
		{
			drawIcon3D [APD_HMD_WaypointMarkerTexture, APD_HMD_Colour, customWaypointPosition, 1, 1, 0];
		}
		else
		{
			[false] call APD_fnc_toggleWaypointRender;
		};
	}];
};

if (!_enable && !isNil "_handle") then
{
	removeMissionEventHandler ["Draw3D", _handle];
	_handle = nil;
};

player setVariable ["APD_WaypointRenderHandle", _handle];
