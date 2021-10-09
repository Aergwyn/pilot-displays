/*
* This function sets the position of the given control. The position is always relative to the top left corner.
*/
if (!hasInterface) exitWith {};

params ["_ctrl", ["_xOffset", 0, [0]], ["_yOffset", 0, [0]]];

_ctrl ctrlSetPosition [safezoneX + _xOffset * safeZoneW, safezoneY + _yOffset * safeZoneH];
