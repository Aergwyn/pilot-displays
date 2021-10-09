/*
* This function sets up the various HUD elements.
*/
if (!hasInterface) exitWith {};

private _layer = "APD_HUD_Layer" call BIS_fnc_rscLayer;
_layer cutRsc ["APD_HUD", "PLAIN", -1, false];

private _display = call APD_fnc_getDisplay;

// Vehicle Stuff

private _ctrlTextVehicleAGL = _display ctrlCreate ["RscText", 5100];
APD_HMD_HUDCtrlList pushBack _ctrlTextVehicleAGL;

private _ctrlTextVehicleASL = _display ctrlCreate ["RscText", 5101];
APD_HMD_HUDCtrlList pushBack _ctrlTextVehicleASL;

private _ctrlTextVehicleSPD = _display ctrlCreate ["RscText", 5102];
APD_HMD_HUDCtrlList pushBack _ctrlTextVehicleSPD;

// Waypoint Stuff

private _ctrlTextWaypointTitle = _display ctrlCreate ["RscText", 5000];
_ctrlTextWaypointTitle ctrlSetText "WYPT";
APD_HMD_HUDCtrlList pushBack _ctrlTextWaypointTitle;

private _ctrlTextWaypointDistance = _display ctrlCreate ["RscText", 5001];
APD_HMD_HUDCtrlList pushBack _ctrlTextWaypointDistance;

private _ctrlTextWaypointTime = _display ctrlCreate ["RscText", 5002];
APD_HMD_HUDCtrlList pushBack _ctrlTextWaypointTime;

// Initial Processing

call APD_fnc_updateVehicleProcessing;
call APD_fnc_updateWaypointProcessing;
