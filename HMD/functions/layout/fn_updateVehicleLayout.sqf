/*
* This function updates the layout of vehicle HUD elements.
*/
if (!hasInterface) exitWith {};

private _display = call APD_fnc_getDisplay;

private _ctrlTextVehicleAGL = _display displayCtrl 5100;
_ctrlTextVehicleAGL setVariable ["APD_Control_Enabled", APD_HMD_VehicleAGLEnabled];
private _ctrlTextVehicleASL = _display displayCtrl 5101;
_ctrlTextVehicleASL setVariable ["APD_Control_Enabled", APD_HMD_VehicleASLEnabled];
private _ctrlTextVehicleSPD = _display displayCtrl 5102;
_ctrlTextVehicleSPD setVariable ["APD_Control_Enabled", APD_HMD_VehicleSPDEnabled];

private _vehicleControls = [_ctrlTextVehicleAGL, _ctrlTextVehicleASL, _ctrlTextVehicleSPD];

[APD_HMD_VehicleXOffset, APD_HMD_VehicleYOffset, 0.02 * APD_HMD_VehicleTextScale, _vehicleControls] call APD_fnc_setCtrlPositionAsGroup;
{
	_x ctrlSetFont APD_HMD_VehicleTextFont;
	_x ctrlSetScale APD_HMD_VehicleTextScale;
	_x ctrlSetTextColor APD_HMD_Colour;
	[_x, APD_HMD_VehicleLoopRunning] call APD_fnc_setCtrlVisibility;
	_x ctrlCommit 0.4;
} forEach _vehicleControls;
