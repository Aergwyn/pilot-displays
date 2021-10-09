/*
* This function updates the currently used vehicle with the necessary MFD user values that control the HMD.
*/
if (!hasInterface) exitWith {};

private _vehicle = vehicle player;

if (_vehicle != player) then
{
	_vehicle setUserMFDValue [0, parseNumber APD_HMD_Enabled];
	_vehicle setUserMFDValue [1, APD_HMD_Colour select 0];	// Red
	_vehicle setUserMFDValue [2, APD_HMD_Colour select 1];	// Green
	_vehicle setUserMFDValue [3, APD_HMD_Colour select 2];	// Blue
	_vehicle setUserMFDValue [4, APD_HMD_Colour select 3];	// Alpha

	_vehicle setUserMFDValue [10, parseNumber APD_HMD_CompassEnabled];

	_vehicle setUserMFDValue [15, APD_HMD_HorizonStyle];
};

call APD_fnc_updateVehicleProcessing;
call APD_fnc_updateWaypointProcessing;
