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

	_vehicle setUserMFDValue [21, parseNumber APD_HMD_WaypointDetailsEnabled];
	// 22 Waypoint Distance
	// 23 Waypoint ETA

	_vehicle setUserMFDValue [25, parseNumber APD_HMD_VehicleAltitudeEnabled];
	_vehicle setUserMFDValue [26, parseNumber APD_HMD_VehicleAirspeedEnabled];
	// 27 AGL
	// 28 ASL
	// 29 Speed
};

call APD_fnc_updateHUD;
call APD_fnc_evaluateVehicleProcessing;
call APD_fnc_evaluateWaypointProcessing;
