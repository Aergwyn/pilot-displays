/*
* This function updates the HUD elements to the currently configured properties (e. g. colour, size, position, etc.).
*/
if (!hasInterface) exitWith {};

{
	_x ctrlSetFont "EtelkaMonospacePro";
	_x ctrlSetTextColor APD_HMD_Colour;
	_x ctrlCommit 0;
} forEach APD_HMD_HUDCtrlList;
