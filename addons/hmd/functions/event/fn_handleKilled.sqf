/*
* This function is only ever (supposed to be) called by the "Killed" event handler.
*/
if (!hasInterface) exitWith {};

//params ["_unit", "_killer", "_instigator", "_useEffects"];

call APD_fnc_updateVehicleProcessing;
call APD_fnc_updateWaypointProcessing;
call APD_fnc_updateCopilotProcessing;
