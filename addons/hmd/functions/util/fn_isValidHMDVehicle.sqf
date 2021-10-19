/*
* This function checks if the given vehicle allows displaying the HMD.
*/
if (!hasInterface) exitWith {};

params ["_vehicle"];

if (APD_HMD_Enabled && alive _vehicle && _vehicle != player && _vehicle isKindOf "Air") exitWith { true; };

false;
