/*
* This function sets up the various HUD elements.
*/
if (!hasInterface) exitWith {};

private _layer = "APD_HUD_Layer" call BIS_fnc_rscLayer;
_layer cutRsc ["APD_HUD", "PLAIN", -1, false];

private _display = call APD_fnc_getDisplay;

// Waypoint Stuff

_display ctrlCreate ["APDPicture", 5000];

private _ctrlTextWaypointTitle = _display ctrlCreate ["APDText", 5001];
_ctrlTextWaypointTitle ctrlSetText "WYPT";

_display ctrlCreate ["APDText", 5002];
_display ctrlCreate ["APDText", 5003];

// Vehicle Stuff

_display ctrlCreate ["APDPicture", 5100];
_display ctrlCreate ["APDText", 5101];
_display ctrlCreate ["APDText", 5102];
_display ctrlCreate ["APDText", 5103];
_display ctrlCreate ["APDText", 5104];

// Initial Processing

call APD_fnc_updateVehicleProcessing;
call APD_fnc_updateWaypointProcessing;
call APD_fnc_updateCopilotProcessing;
