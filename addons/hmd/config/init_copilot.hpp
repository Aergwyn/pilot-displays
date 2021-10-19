private _catCopilotMarker = "Copilot Marker (WIP)";

// Copilot Marker

[
	"APD_HMD_CopilotMarkerEnabled", "CHECKBOX",
	"Enabled",
	[_modCategory, _catCopilotMarker],
	TRUE,
	nil,
	{ call APD_fnc_updateCopilotProcessing; }
] call CBA_fnc_addSetting;
