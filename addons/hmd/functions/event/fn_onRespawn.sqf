/*
* This function is only ever (supposed to be) called by the "Respawn" event handler.
*/
if (!hasInterface) exitWith {};

//params ["_unit", "_corpse"];

call APD_fnc_updateVehicleProcessing;
call APD_fnc_updateWaypointProcessing;
call APD_fnc_updateCopilotProcessing;
