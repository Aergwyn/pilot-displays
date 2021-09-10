if (!hasInterface) exitWith {};

private _vehicle = vehicle player;

if (_vehicle != player && APD_HMD_Enabled && APD_HMD_SpeedEnabled) then
{
	if (!APD_HMD_SpeedLoopRunning) then
	{
		APD_HMD_SpeedLoopRunning = true;
		[_vehicle] spawn APD_fnc_speedLoop;
	};
}
else
{
	APD_HMD_SpeedLoopRunning = false;
};

if (_vehicle != player && APD_HMD_Enabled && APD_HMD_WaypointStyle > 1) then
{
	if (!APD_HMD_WaypointLoopRunning) then
	{
		APD_HMD_WaypointLoopRunning = true;
		[_vehicle] spawn APD_fnc_waypointLoop;
	};
}
else
{
	APD_HMD_WaypointLoopRunning = false;
};
