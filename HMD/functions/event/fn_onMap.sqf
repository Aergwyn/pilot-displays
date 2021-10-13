/*
* This function is only ever (supposed to be) called by the "Map" mission event handler.
*/
if (!hasInterface) exitWith {};

//params ["_mapIsOpened", "_mapIsForced"];
private _mapIsOpened = param [0];

if (!_mapIsOpened) then
{
	call APD_fnc_updateWaypointProcessing;
};
