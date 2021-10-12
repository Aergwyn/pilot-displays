/*
* This function evaluates if processing data for gun view HUD elements is required.
*/
if (!hasInterface) exitWith {};

private _vehicle = vehicle player;
private _processingRequired = [_vehicle] call APD_fnc_isValidHMDVehicle;

[_processingRequired && !(APD_HMD_WaypointMarkerTexture isEqualTo "")] call APD_fnc_toggleGunViewRendering;
