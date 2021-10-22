/*
* This function is only ever (supposed to be) called by the "GetOutMan" event handler.
*/
if (!hasInterface) exitWith {};

//params ["_unit", "_role", "_vehicle", "_turret"];
private _vehicle = param [2];

private _getInHandle = player getVariable ["APD_GetInHandle", -1];
private _getOutHandle = player getVariable ["APD_GetOutHandle", -1];
private _seatSwitchedHandle = player getVariable ["APD_SeatSwitchedHandle", -1];
private _killedHandle = player getVariable ["APD_KilledHandle", -1];

if (_getInHandle >= 0) then
{
	_vehicle removeEventHandler ["GetIn", _getInHandle];
	player setVariable ["APD_GetInHandle", -1];
};

if (_getOutHandle >= 0) then
{
	_vehicle removeEventHandler ["GetOut", _getOutHandle];
	player setVariable ["APD_GetOutHandle", -1];
};

if (_seatSwitchedHandle >= 0) then
{
	_vehicle removeEventHandler ["SeatSwitched", _seatSwitchedHandle];
	player setVariable ["APD_SeatSwitchedHandle", -1];
};

if (_killedHandle >= 0) then
{
	_vehicle removeEventHandler ["Killed", _killedHandle];
	player setVariable ["APD_KilledHandle", -1];
};

player setVariable ["APD_CopilotTurretData", []];

call APD_fnc_updateVehicleProcessing;
call APD_fnc_updateWaypointProcessing;
call APD_fnc_updateCopilotProcessing;
