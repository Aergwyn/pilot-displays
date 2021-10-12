if (!hasInterface) exitWith {};

call APD_fnc_setupHUD;

// TODO remove debug output once events were tested if being loaded in by 3rd party triggers these as well

player addEventHandler ["GetInMan",
	{
		params ["_unit", "_role", "_vehicle"];

		systemChat "GetInMan";

		private _seatSwitchedHandle = _vehicle addEventHandler ["SeatSwitched",
			{
				systemChat "SeatSwitched";

				call APD_fnc_updateGunViewProcessing;
			}
		];

		private _getInHandle = _vehicle addEventHandler ["GetIn",
			{
				params ["_vehicle", "_role", "_unit", "_turret"];

				systemChat format ["GetIn %1", _role];

				call APD_fnc_updateGunViewProcessing;
			}
		];

		private _getOutHandle = _vehicle addEventHandler ["GetOut",
			{
				systemChat "GetOut";

				call APD_fnc_updateGunViewProcessing;
			}
		];

		player setVariable ["APD_SeatSwitchedHandle", _seatSwitchedHandle];
		player setVariable ["APD_GetInHandle", _getInHandle];
		player setVariable ["APD_GetOutHandle", _getOutHandle];

		call APD_fnc_updateMFDValues;
		call APD_fnc_updateGunViewProcessing;
	}
];

player addEventHandler ["GetOutMan",
	{
		params ["_unit", "_role", "_vehicle"];

		systemChat "GetOutMan";

		private _seatSwitchedHandle = player getVariable ["APD_SeatSwitchedHandle", -1];
		private _getInHandle = player getVariable ["APD_GetInHandle", -1];
		private _getOutHandle = player getVariable ["APD_GetOutHandle", -1];

		if (_seatSwitchedHandle >= 0) then
		{
			_vehicle removeEventHandler ["SeatSwitched", _seatSwitchedHandle];
			player setVariable ["APD_SeatSwitchedHandle", -1];
		};

		if (_getInHandle >= 0) then
		{
			_vehicle removeEventHandler ["GetIn", _getInHandle];
			player setVariable ["APD_GetInHandle", -1];
		};

		if (_getOutHandle >= 0) then
		{
			_vehicle removeEventHandler ["GetOut", _getOutHandle];
			player setVariable ["APD_GetOutHandle", -1];
		};

		call APD_fnc_updateVehicleProcessing;
		call APD_fnc_updateWaypointProcessing;
		call APD_fnc_updateGunViewProcessing;
	}
];

player addEventHandler ["Killed",
	{
		systemChat "Killed";
		call APD_fnc_updateVehicleProcessing;
		call APD_fnc_updateWaypointProcessing;
		call APD_fnc_updateGunViewProcessing;
	}
];

addMissionEventHandler ["Map",
	{
		params ["_mapIsOpened"];

		if (!_mapIsOpened) then
		{
			call APD_fnc_updateWaypointProcessing;
		};
	}
];
