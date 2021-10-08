/*
* This function sets up the various HUD elements.
*/
if (!hasInterface) exitWith {};

private _layer = "APD_HUD_Layer" call BIS_fnc_rscLayer;
_layer cutRsc ["APD_HUD", "PLAIN", -1, false];

private _display = ["APD_HUD_Display"] call APD_fnc_getDisplay;

private _ctrlTextDistance = _display ctrlCreate ["RscText", 5001];
_ctrlTextDistance ctrlSetPosition [safezoneX + 0.6 * safeZoneW, safezoneY + 0.745 * safeZoneH];
_ctrlTextDistance ctrlCommit 0;
APD_HMD_HUDCtrlList pushBack _ctrlTextDistance;

private _ctrlTextETA = _display ctrlCreate ["RscText", 5002];
_ctrlTextETA ctrlSetPosition [safezoneX + 0.6 * safeZoneW, safezoneY + 0.765 * safeZoneH];
_ctrlTextETA ctrlCommit 0;
APD_HMD_HUDCtrlList pushBack _ctrlTextETA;

[false] call APD_fnc_toggleHUD;
call APD_fnc_updateHUD;
