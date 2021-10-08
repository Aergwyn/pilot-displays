/*
* This function toggles the rendering of the HUD elements to the given state.
*/
if (!hasInterface) exitWith {};

params [["_enable", false, [true]]];

private _t = 1; // we set "transparency" and not alpha, so the value appears "reversed"

if (_enable) then
{
	_t = 0;
};

{
	_x ctrlSetFade _t;
	_x ctrlCommit 0.5;
} forEach APD_HMD_HUDCtrlList;
