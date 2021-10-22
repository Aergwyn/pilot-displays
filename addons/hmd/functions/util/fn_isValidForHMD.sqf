/*
* This function checks if the given player and/or vehicle circumstances allow displaying the HMD.
*/
if (!hasInterface) exitWith {};

params ["_vehicle"];

if (!APD_HMD_Enabled || _vehicle isEqualTo player || !alive _vehicle) exitWith { false; };

// "currentPilot" would be amazing to use but is horribly bugged and returns "NULL-Object" most of the time

private _isPilot = (driver _vehicle) isEqualTo player;

private _isCopilot = false;
private _copilotData = player getVariable ["APD_CopilotTurretData", []];

if (!_isPilot && count _copilotData > 0) then
{
	private _copilotTurret = _copilotData # 0;
	_isCopilot = (_vehicle turretUnit _copilotTurret) isEqualTo player;
};

if ((_isPilot || _isCopilot) && (_vehicle isKindOf "Helicopter" || _vehicle isKindOf "Plane")) exitWith { true; };

false;
