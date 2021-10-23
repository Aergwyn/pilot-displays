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

[
	"APD_HMD_CopilotMarkerScale", "SLIDER",
	"Size",
	[_modCategory, _catCopilotMarker],
	_supportedSizes,
	nil,
	{ call APD_fnc_updateCopilotLayout; }
] call CBA_fnc_addSetting;

[
	"APD_HMD_CopilotMarkerTexture", "LIST",
	"Style",
	[_modCategory, _catCopilotMarker],
	[_supportedTexturePaths, _supportedTextureNames, 3],
	nil,
	{  }
] call CBA_fnc_addSetting;
