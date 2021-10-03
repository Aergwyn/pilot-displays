if (!hasInterface) exitWith {};

private _vehicle = vehicle player;

if (_vehicle != player && APD_HMD_Enabled &&
	(APD_HMD_VehicleAltitudeEnabled || APD_HMD_VehicleAirspeedEnabled)) then
{
	if (!APD_HMD_VehicleLoopRunning) then
	{
		APD_HMD_VehicleLoopRunning = true;
		[_vehicle] spawn APD_fnc_vehicleLoop;
	};
}
else
{
	APD_HMD_VehicleLoopRunning = false;
};

if (_vehicle != player && APD_HMD_Enabled && APD_HMD_WaypointDetailsEnabled) then
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
