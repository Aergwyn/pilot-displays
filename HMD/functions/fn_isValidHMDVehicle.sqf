/*
* This function checks if the given vehicle allows displaying the HMD.
*/
params["_vehicle"];

if (isNil "_vehicle") exitWith { false; };

if (APD_HMD_Enabled && _vehicle != player && _vehicle isKindOf "Air") exitWith { true; };

false;
