/*
* This function evaluates if processing data for waypoint HUD elements is required.
*/
if (!hasInterface) exitWith {};

private _vehicle = vehicle player;
private _loopRequired = APD_HMD_WaypointDistanceEnabled || APD_HMD_WaypointTimeEnabled;
private _processingRequired = [_vehicle] call APD_fnc_isValidForHMD && count customWaypointPosition > 0;

[_processingRequired && APD_HMD_WaypointMarkerEnabled] call APD_fnc_toggleWaypointRendering;

if (_processingRequired && _loopRequired) then
{
	if (!APD_HMD_WaypointLoopRunning) then
	{
		APD_HMD_WaypointLoopRunning = true;
		[_vehicle] spawn APD_fnc_startWaypointLoop;
	};
}
else
{
	APD_HMD_WaypointLoopRunning = false;
};

call APD_fnc_updateWaypointLayout;
