if (!hasInterface) exitWith {};

params["_vehicle"];

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

	_vehicle setUserMFDText [27, format ["AGL: %1 %2", _aglValue, _altUnit]];
	_vehicle setUserMFDText [28, format ["ASL: %1 %2", _aslValue, _altUnit]];
	_vehicle setUserMFDText [29, format ["SPD: %1 %2", _speedValue, _speedUnit]];

	sleep 0.1;
};
