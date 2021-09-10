if (!hasInterface) exitWith {};

private _vehicle = vehicle player;

if (_vehicle != player) then
{
	_vehicle setUserMFDValue [0, parseNumber APD_HMD_Enabled];

	_vehicle setUserMFDValue [1, APD_HMD_Colour select 3];	// Alpha
	_vehicle setUserMFDValue [2, APD_HMD_Colour select 2];	// Blue
	_vehicle setUserMFDValue [3, APD_HMD_Colour select 1];	// Green
	_vehicle setUserMFDValue [4, APD_HMD_Colour select 0];	// Red

	_vehicle setUserMFDValue [10, parseNumber APD_HMD_HeadingEnabled];
	_vehicle setUserMFDValue [11, parseNumber APD_HMD_HorizonEnabled];
	_vehicle setUserMFDValue [12, parseNumber APD_HMD_SpeedEnabled];
	// 13 Airspeed
	_vehicle setUserMFDValue [14, APD_HMD_WaypointStyle];
	// 15 Waypoint Distance
	// 16 Waypoint ETA
};

call APD_fnc_evaluateLoops;
