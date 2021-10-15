/*
* This function sets up the various HUD elements.
*/
if (!hasInterface) exitWith {};

private _layer = "APD_HUD_Layer" call BIS_fnc_rscLayer;
_layer cutRsc ["APD_HUD", "PLAIN", -1, false];

private _display = call APD_fnc_getDisplay;

// Waypoint Stuff

private _ctrlTextWaypointTitle = _display ctrlCreate ["RscText", 5000];
_ctrlTextWaypointTitle ctrlSetText "WYPT";

private _ctrlTextWaypointDistance = _display ctrlCreate ["RscText", 5001];
private _ctrlTextWaypointTime = _display ctrlCreate ["RscText", 5002];

// Vehicle Stuff

private _ctrlTextVehicleAGL = _display ctrlCreate ["RscText", 5100];
private _ctrlTextVehicleASL = _display ctrlCreate ["RscText", 5101];
private _ctrlTextVehicleSPD = _display ctrlCreate ["RscText", 5102];

// Initial Processing

call APD_fnc_updateVehicleProcessing;
call APD_fnc_updateWaypointProcessing;
