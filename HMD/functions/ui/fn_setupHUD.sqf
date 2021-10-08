/*
* This function sets up the various HUD elements.
*/
if (!hasInterface) exitWith {};

private _layer = "APD_HUD_Layer" call BIS_fnc_rscLayer;
_layer cutRsc ["APD_HUD", "PLAIN", -1, false];

private _display = ["APD_HUD_Display"] call APD_fnc_getDisplay;

private _ctrlTextWaypointTitle = _display ctrlCreate ["RscText", 5000];
_ctrlTextWaypointTitle ctrlSetText "WYPT";
_ctrlTextWaypointTitle ctrlSetPosition [safezoneX + 0.66 * safeZoneW, safezoneY + 0.74 * safeZoneH];
_ctrlTextWaypointTitle ctrlCommit 0;
APD_HMD_HUDCtrlList pushBack _ctrlTextWaypointTitle;

private _ctrlTextWaypointDistance = _display ctrlCreate ["RscText", 5001];
_ctrlTextWaypointDistance ctrlSetPosition [safezoneX + 0.66 * safeZoneW, safezoneY + 0.76 * safeZoneH];
_ctrlTextWaypointDistance ctrlCommit 0;
APD_HMD_HUDCtrlList pushBack _ctrlTextWaypointDistance;

private _ctrlTextWaypointETA = _display ctrlCreate ["RscText", 5002];
_ctrlTextWaypointETA ctrlSetPosition [safezoneX + 0.66 * safeZoneW, safezoneY + 0.78 * safeZoneH];
_ctrlTextWaypointETA ctrlCommit 0;
APD_HMD_HUDCtrlList pushBack _ctrlTextWaypointETA;

[false] call APD_fnc_toggleHUD;
call APD_fnc_updateHUD;
