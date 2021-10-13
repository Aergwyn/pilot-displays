/*
* This function is only ever (supposed to be) called by the "GetIn" event handler.
*/
if (!hasInterface) exitWith {};

//params ["_vehicle", "_role", "_unit", "_turret"];

systemChat "GetIn";

call APD_fnc_updateGunViewProcessing;
