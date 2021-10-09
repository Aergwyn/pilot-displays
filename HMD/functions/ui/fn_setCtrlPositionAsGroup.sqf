/*
* This function sets the position of the given controls as a group.
* The given controls are always paired with a boolean value that determines visibility.
*/
if (!hasInterface) exitWith {};

params [["_xOffset", 0, [0]], ["_yOffset", 0, [0]], ["_spacing", 0, [0]], ["_ctrlList", [], [[]]]];

{
	_x params ["_ctrl", "_enabled"];

	if (_enabled) then
	{
		[_ctrl, _xOffset, _yOffset] call APD_fnc_setCtrlPosition;
		_yOffset = _yOffset + _spacing;
	};
	_ctrl ctrlCommit 0;
} forEach _ctrlList;
