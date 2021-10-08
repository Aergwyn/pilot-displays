/*
* This function evaluates if processing regarding waypoint functionality is necessary.
*/
if (!hasInterface) exitWith {};

private _vehicle = vehicle player;
private _processingRequired = [_vehicle] call APD_fnc_isValidHMDVehicle && count customWaypointPosition > 0;

[_processingRequired && !(APD_HMD_WaypointMarkerTexture isEqualTo "")] call APD_fnc_toggleWaypointRendering;

if (_processingRequired && APD_HMD_WaypointDetailsEnabled) then
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