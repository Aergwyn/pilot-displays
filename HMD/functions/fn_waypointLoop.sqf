if (!hasInterface) exitWith {};

params["_vehicle"];

while { APD_HMD_WaypointLoopRunning } do
{
	private _waypoint = customWaypointPosition;

	if (count _waypoint > 0) then
	{
		private _distanceUnit = APD_HMD_SystemOfUnits select 0;
		private _distanceMultiplier = APD_HMD_SystemOfUnits select 1;
		private _distancePrecision = APD_HMD_SystemOfUnits select 2;

		private _distanceRaw = _vehicle distance2D _waypoint; // m
		private _distanceValue = (_distanceRaw * _distanceMultiplier) toFixed _distancePrecision;

		private _etaSecond = "??";
		private _etaMinute = "??";
		private _speed = vectorMagnitude (velocity _vehicle); // m/s

		if (_speed > 1) then // 1 m/s => 3.6 km/h
		{
			private _direction = cos ([_waypoint, velocity _vehicle] call APD_fnc_directionRelativeToWaypoint);

			// ensure moving towards the waypoint
			if (_direction > 0) then
			{
				private _etaRaw = ceil (_distanceRaw / _speed / _direction);

				if (_etaRaw < 3600) then
				{
					_etaMinute = [floor (_etaRaw / 60), 2, "0"] call APD_fnc_leftPadString;
					_etaSecond = [_etaRaw % 60, 2, "0"] call APD_fnc_leftPadString;
				};
			};
		};

		_vehicle setUserMFDText [12, format ["%1 %2", _distanceValue, _distanceUnit]];
		_vehicle setUserMFDText [13, format ["T-%1:%2", _etaMinute, _etaSecond]];

		sleep 1;
	}
	else
	{
		_vehicle setUserMFDText [12, ""]; // Waypoint Distance
		_vehicle setUserMFDText [13, ""]; // Waypoint ETA
		APD_HMD_WaypointLoopRunning = false;
	};
};
