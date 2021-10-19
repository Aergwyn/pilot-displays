/*
* This function is only ever (supposed to be) called by the "GetInMan" event handler.
*/
if (!hasInterface) exitWith {};

//params ["_unit", "_role", "_vehicle", "_turret"];
private _vehicle = param [2];

systemChat "GetInMan";

private _getInHandle = _vehicle addEventHandler ["GetIn", { _this call APD_fnc_handleGetIn; }];
private _getOutHandle = _vehicle addEventHandler ["GetOut", { _this call APD_fnc_handleGetOut; }];
private _seatSwitchedHandle = _vehicle addEventHandler ["SeatSwitched", { _this call APD_fnc_handleSeatSwitched; }];
private _killedHandle = _vehicle addEventHandler ["Killed", { _this call APD_fnc_handleKilled; }];

player setVariable ["APD_GetInHandle", _getInHandle];
player setVariable ["APD_GetOutHandle", _getOutHandle];
player setVariable ["APD_SeatSwitchedHandle", _seatSwitchedHandle];
player setVariable ["APD_KilledHandle", _killedHandle];

player setVariable ["APD_CopilotTurretData", [_vehicle] call APD_fnc_getFirstCopilotTurret];

call APD_fnc_updateVehicleProcessing;
call APD_fnc_updateWaypointProcessing;
call APD_fnc_updateCopilotProcessing;
