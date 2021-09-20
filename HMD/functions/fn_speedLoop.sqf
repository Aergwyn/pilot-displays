if (!hasInterface) exitWith {};

params["_vehicle"];

while { APD_HMD_SpeedLoopRunning } do
{
	private _speedUnit = APD_HMD_SoU_Speed select 0;
	private _speedMultiplier = APD_HMD_SoU_Speed select 1;

	private _speedRaw = vectorMagnitude (velocity _vehicle);
	private _speedValue = (_speedRaw * _speedMultiplier) toFixed 0;

	_vehicle setUserMFDText [13, format ["%1 %2", _speedValue, _speedUnit]];

	sleep 0.1;
};
