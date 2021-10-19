/*
* This function updates the layout of copilot HUD elements.
*/
if (!hasInterface) exitWith {};

APD_HMD_CopilotMarkerTextureOffset = 0.03 * APD_HMD_CopilotMarkerScale;

private _display = call APD_fnc_getDisplay;

private _ctrlPictureCopilotMarker = _display displayCtrl 5100;
_ctrlPictureCopilotMarker ctrlSetTextColor [1, 0, 0, 1]; // TODO use proper setting
_ctrlPictureCopilotMarker ctrlSetScale APD_HMD_CopilotMarkerScale;
_ctrlPictureCopilotMarker ctrlCommit 0;
