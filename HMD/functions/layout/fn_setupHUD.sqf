/*
* This function sets up the various HUD elements.
*/
if (!hasInterface) exitWith {};

private _layer = "APD_HUD_Layer" call BIS_fnc_rscLayer;
_layer cutRsc ["APD_HUD", "PLAIN", -1, false];

private _display = ["APD_HUD_Display"] call APD_fnc_getDisplay;

private _ctrlTextWaypointTitle = _display ctrlCreate ["RscText", 5000];
_ctrlTextWaypointTitle ctrlSetText "WYPT";
APD_HMD_HUDCtrlList pushBack _ctrlTextWaypointTitle;

private _ctrlTextWaypointDistance = _display ctrlCreate ["RscText", 5001];
APD_HMD_HUDCtrlList pushBack _ctrlTextWaypointDistance;

private _ctrlTextWaypointTime = _display ctrlCreate ["RscText", 5002];
APD_HMD_HUDCtrlList pushBack _ctrlTextWaypointTime;

call APD_fnc_updateWaypointProcessing;
