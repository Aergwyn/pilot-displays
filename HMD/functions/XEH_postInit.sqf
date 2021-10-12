if (!hasInterface) exitWith {};

call APD_fnc_setupHUD;

// TODO remove debug output once events were tested if being loaded in by 3rd party triggers these as well
player addEventHandler ["GetInMan",
	{
		systemChat "GetInMan";
		call APD_fnc_updateMFDValues;
		call APD_fnc_updateGunViewProcessing;
	}
];

player addEventHandler ["GetOutMan",
	{
		systemChat "GetOutMan";
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
