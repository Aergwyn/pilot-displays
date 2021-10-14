/*
* This function evaluates if processing data for gun view HUD elements is required.
*/
if (!hasInterface) exitWith {};

private _vehicle = vehicle player;
private _processingRequired = [_vehicle] call APD_fnc_isValidHMDVehicle;

private _turretData = player getVariable ["APD_CopilotTurretData", []];

if (_processingRequired && count _turretData > 0) then
{
	private _turretUnit = _vehicle turretUnit (_turretData # 0);
	_processingRequired = !isNull _turretUnit && _turretUnit != player;
};

[_processingRequired] call APD_fnc_toggleGunViewRendering;
