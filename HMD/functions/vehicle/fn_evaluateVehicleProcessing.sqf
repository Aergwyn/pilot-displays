/*
* This function evaluates if processing of the current vehicle is necessary.
*/
if (!hasInterface) exitWith {};

private _vehicle = vehicle player;
private _isValidVehicle = [_vehicle] call APD_fnc_isValidHMDVehicle;

if (_isValidVehicle && (APD_HMD_VehicleAltitudeEnabled || APD_HMD_VehicleAirspeedEnabled)) then
{
	if (!APD_HMD_VehicleLoopRunning) then
	{
		APD_HMD_VehicleLoopRunning = true;
		[_vehicle] spawn APD_fnc_startVehicleLoop;
	};
}
else
{
	APD_HMD_VehicleLoopRunning = false;
};
