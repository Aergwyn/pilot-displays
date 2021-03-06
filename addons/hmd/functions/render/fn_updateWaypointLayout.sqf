/*
* This function updates the layout of waypoint HUD elements.
*/
if (!hasInterface) exitWith {};

APD_HMD_WaypointMarkerTextureOffset = 0.03 * APD_HMD_WaypointMarkerScale;

private _display = call APD_fnc_getDisplay;

private _ctrlPictureWaypointMarker = _display displayCtrl 5000;
_ctrlPictureWaypointMarker ctrlSetTextColor APD_HMD_Colour;
_ctrlPictureWaypointMarker ctrlSetScale APD_HMD_WaypointMarkerScale;
_ctrlPictureWaypointMarker ctrlCommit 0;

private _ctrlTextWaypointTitle = _display displayCtrl 5001;
_ctrlTextWaypointTitle setVariable ["APD_Control_Enabled", APD_HMD_WaypointHeaderEnabled];
private _ctrlTextWaypointDistance = _display displayCtrl 5002;
_ctrlTextWaypointDistance setVariable ["APD_Control_Enabled", APD_HMD_WaypointDistanceEnabled];
private _ctrlTextWaypointTime = _display displayCtrl 5003;
_ctrlTextWaypointTime setVariable ["APD_Control_Enabled", APD_HMD_WaypointTimeEnabled];

private _waypointControls = [_ctrlTextWaypointTitle, _ctrlTextWaypointDistance, _ctrlTextWaypointTime];

[APD_HMD_WaypointXOffset, APD_HMD_WaypointYOffset, 0.02 * APD_HMD_WaypointTextScale, _waypointControls] call APD_fnc_setCtrlPositionAsGroup;
{
	_x ctrlSetFont APD_HMD_WaypointTextFont;
	_x ctrlSetScale APD_HMD_WaypointTextScale;
	_x ctrlSetTextColor APD_HMD_Colour;
	[_x, APD_HMD_WaypointLoopRunning] call APD_fnc_setCtrlVisibility;
	_x ctrlCommit 0.4;
} forEach _waypointControls;
