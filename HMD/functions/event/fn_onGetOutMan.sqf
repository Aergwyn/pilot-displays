/*
* This function is only ever (supposed to be) called by the "GetOutMan" event handler.
*/
if (!hasInterface) exitWith {};

//params ["_unit", "_role", "_vehicle", "_turret"];
private _vehicle = param [2];

systemChat "GetOutMan";

private _getInHandle = player getVariable ["APD_GetInHandle", -1];
private _getOutHandle = player getVariable ["APD_GetOutHandle", -1];
private _seatSwitchedHandle = player getVariable ["APD_SeatSwitchedHandle", -1];

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

player setVariable ["APD_CopilotTurret", nil];

call APD_fnc_updateVehicleProcessing;
call APD_fnc_updateWaypointProcessing;
call APD_fnc_updateGunViewProcessing;
