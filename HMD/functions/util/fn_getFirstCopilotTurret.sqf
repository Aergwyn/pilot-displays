/*
* This function will return the first turret that is configured to be a copilot and has a memory point for optics.
* The return value will be an array ["turretPath", "memoryPoint"] or nil if no turret matches the criteria.
*/
if (!hasInterface) exitWith {};

params ["_vehicle"];

private _copilotTurret = nil;

{
	private _turretConfig = [_vehicle, _x] call BIS_fnc_turretConfig;
	private _isCopilot = getNumber (_turretConfig >> "isCopilot") > 0;

	if (_isCopilot) then
	{
		private _memPoint = getText (_turretConfig >> "memoryPointGunnerOptics");

		if (_memPoint isNotEqualTo "") then
		{
			_copilotTurret = [_x, _memPoint];
			break; // first come, first serve
		};
	};
} forEach (allTurrets _vehicle);

_copilotTurret;
