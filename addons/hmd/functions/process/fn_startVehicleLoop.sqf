/*
* This function processes the necessary vehicle statistics to display.
*/
if (!hasInterface) exitWith {};

params ["_vehicle"];

private _display = call APD_fnc_getDisplay;
private _ctrlTextVehicleAGL = _display displayCtrl 5100;
private _ctrlTextVehicleASL = _display displayCtrl 5101;
private _ctrlTextVehicleSPD = _display displayCtrl 5102;

while { APD_HMD_VehicleLoopRunning } do
{
	private _altUnit = APD_HMD_SoU_Altitude select 0;
	private _altMultiplier = APD_HMD_SoU_Altitude select 1;
	private _speedUnit = APD_HMD_SoU_Speed select 0;
	private _speedMultiplier = APD_HMD_SoU_Speed select 1;

	private _aglRaw = (getPosATL _vehicle) select 2;
	private _aslRaw = (getPosASL _vehicle) select 2;
	private _aglValue = (_aglRaw * _altMultiplier) toFixed 0;
	private _aslValue = (_aslRaw * _altMultiplier) toFixed 0;
	private _speedRaw = vectorMagnitude (velocity _vehicle);
	private _speedValue = (_speedRaw * _speedMultiplier) toFixed 0;

	_ctrlTextVehicleAGL ctrlSetText (format ["AGL: %1 %2", _aglValue, _altUnit]);
	_ctrlTextVehicleASL ctrlSetText (format ["ASL: %1 %2", _aslValue, _altUnit]);
	_ctrlTextVehicleSPD ctrlSetText (format ["IAS: %1 %2", _speedValue, _speedUnit]);

	sleep 0.1;
};
