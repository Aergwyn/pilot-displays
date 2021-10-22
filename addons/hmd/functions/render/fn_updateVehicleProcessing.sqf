/*
* This function evaluates if processing data for vehicle HUD elements is required.
*/
if (!hasInterface) exitWith {};

private _vehicle = vehicle player;
private _loopRequired = APD_HMD_VehicleAGLEnabled || APD_HMD_VehicleASLEnabled || APD_HMD_VehicleSPDEnabled;
private _processingRequired = [_vehicle] call APD_fnc_isValidForHMD;

if (_processingRequired && _loopRequired) then
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

call APD_fnc_updateVehicleLayout;
