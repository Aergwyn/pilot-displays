if (!hasInterface) exitWith {};

call APD_fnc_setupHUD;

// TODO remove debug output once events were tested if being loaded in by 3rd party triggers these as well
player addEventHandler ["GetInMan",
	{
		systemChat "GetInMan";
		call APD_fnc_updateMFDValues;
	}
];

player addEventHandler ["GetOutMan",
	{
		systemChat "GetOutMan";
		call APD_fnc_evaluateVehicleProcessing;
		call APD_fnc_updateWaypointProcessing;
	}
];

player addEventHandler ["Killed",
	{
		call APD_fnc_evaluateVehicleProcessing;
		call APD_fnc_updateWaypointProcessing;
	}
];

addMissionEventHandler ["Map",
	{
		params ["_mapIsOpened", "_mapIsForced"];

		if (!_mapIsOpened) then
		{
			call APD_fnc_updateWaypointProcessing;
		};
	}
];
