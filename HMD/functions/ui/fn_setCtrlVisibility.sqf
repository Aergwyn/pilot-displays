/*
* This function toggles a specific control to the desired state.
*/
if (!hasInterface) exitWith {};

params ["_ctrl", ["_show", false, [true]]];

private _enabled = _ctrl getVariable ["APD_Control_Enabled", true];

if (_show && _enabled) then
{
	_ctrl ctrlSetFade 0;
}
else
{
	_ctrl ctrlSetFade 1;
};
