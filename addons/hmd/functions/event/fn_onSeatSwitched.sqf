/*
* This function is only ever (supposed to be) called by the "SeatSwitched" event handler.
*/
if (!hasInterface) exitWith {};

//params ["_vehicle", "_unit1", "_unit2"];

systemChat "SeatSwitched";

call APD_fnc_updateCopilotProcessing;
