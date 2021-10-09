/*
* This function sets the position of the given controls as a group.
* The given controls are always paired with a boolean value that determines if the control will advance the vertical position.
*/
if (!hasInterface) exitWith {};

params [["_xOffset", 0, [0]], ["_yOffset", 0, [0]], ["_spacing", 0, [0]], ["_ctrlList", [], [[]]]];

{
	[_x, _xOffset, _yOffset] call APD_fnc_setCtrlPosition;

	private _enabled = _x getVariable ["APD_Control_Enabled", true];

	if (_enabled) then
	{
		_yOffset = _yOffset + _spacing;
	};
} forEach _ctrlList;
