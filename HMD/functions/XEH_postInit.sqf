if (!hasInterface) exitWith {};

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
		call APD_fnc_evaluateWaypointProcessing;
	}
];

player addEventHandler ["Killed",
	{
		call APD_fnc_evaluateVehicleProcessing;
		call APD_fnc_evaluateWaypointProcessing;
	}
];

addMissionEventHandler ["Map",
	{
		params ["_mapIsOpened", "_mapIsForced"];

		if (!_mapIsOpened) then
		{
			call APD_fnc_evaluateWaypointProcessing;
		};
	}
];


// TESTING
private _layer = "APD_HUD_Layer" call BIS_fnc_rscLayer;
_layer cutRsc ["APD_HUD", "PLAIN", -1, false];

private _display = ["APD_HUD_Display"] call APD_fnc_getDisplay;

private _text = _display ctrlCreate ["RscText", 5001];
_text ctrlSetPosition [0.25 * safezoneW + safezoneX, 0.22 * safezoneH + safezoneY];
_text ctrlSetTextColor APD_HMD_Colour;
