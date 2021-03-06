/*
* This function processes the necessary vehicle information to display.
*/
if (!hasInterface) exitWith {};

params ["_vehicle"];

private _display = call APD_fnc_getDisplay;
private _ctrlTextVehicleAGL = _display displayCtrl 5101;
private _ctrlTextVehicleASL = _display displayCtrl 5102;
private _ctrlTextVehicleVSI = _display displayCtrl 5103;
private _ctrlTextVehicleIAS = _display displayCtrl 5104;

while { APD_HMD_VehicleLoopRunning } do
{
	private _altUnit = APD_HMD_SoU_Altitude # 0;
	private _altMultiplier = APD_HMD_SoU_Altitude # 1;
	private _speedUnit = APD_HMD_SoU_Speed # 0;
	private _speedMultiplier = APD_HMD_SoU_Speed # 1;

	private _aglRaw = (getPosATL _vehicle) # 2;
	private _aslRaw = (getPosASL _vehicle) # 2;

	// getPos is inconsistent (and sometimes negative?)
	// best effort we can make here without destroying performance
	if (_aglRaw > _aslRaw) then
	{
		_aglRaw = _aslRaw; // ensure that AGL matches ASL over water
	};

	private _aglValue = (_aglRaw * _altMultiplier) toFixed 0;
	private _aslValue = (_aslRaw * _altMultiplier) toFixed 0;

	private _velocity = velocity _vehicle;
	private _speedRaw = vectorMagnitude _velocity;
	private _speedValue = (_speedRaw * _speedMultiplier) toFixed 0;
	private _verticalRaw = _velocity # 2;

	if (_verticalRaw > -1 && _verticalRaw < 1) then
	{
		_verticalRaw = 0; // because of rounding -0 is common and just awkward
	};

	private _verticalValue = _verticalRaw toFixed 0;

	_ctrlTextVehicleAGL ctrlSetText (format ["AGL: %1 %2", _aglValue, _altUnit]);
	_ctrlTextVehicleASL ctrlSetText (format ["ASL: %1 %2", _aslValue, _altUnit]);
	_ctrlTextVehicleVSI ctrlSetText (format ["VSI: %1 M/S", _verticalValue]);
	_ctrlTextVehicleIAS ctrlSetText (format ["IAS: %1 %2", _speedValue, _speedUnit]);

	sleep 0.1;
};
