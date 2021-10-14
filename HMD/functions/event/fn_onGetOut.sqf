/*
* This function is only ever (supposed to be) called by the "GetOut" event handler.
*/
if (!hasInterface) exitWith {};

//params ["_vehicle", "_role", "_unit", "_turret"];
private _unit = param [2];

if (_unit != player) then
{
	call APD_fnc_updateGunViewProcessing;
};
