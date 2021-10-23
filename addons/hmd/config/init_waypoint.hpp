private _catWyptMarker = "Waypoint Marker";
private _catWyptInfo = "Waypoint Information";

// Waypoint Marker

[
	"APD_HMD_WaypointMarkerEnabled", "CHECKBOX",
	"Enabled",
	[_modCategory, _catWyptMarker],
	TRUE,
	nil,
	{ call APD_fnc_updateWaypointProcessing; }
] call CBA_fnc_addSetting;

[
	"APD_HMD_WaypointMarkerScale", "SLIDER",
	"Size",
	[_modCategory, _catWyptMarker],
	_supportedSizes,
	nil,
	{ call APD_fnc_updateWaypointLayout; }
] call CBA_fnc_addSetting;

[
	"APD_HMD_WaypointMarkerTexture", "LIST",
	"Style",
	[_modCategory, _catWyptMarker],
	[_supportedTexturePaths, _supportedTextureNames, 1],
	nil,
	{  }
] call CBA_fnc_addSetting;

// Waypoint Information

[
	"APD_HMD_WaypointHeaderEnabled", "CHECKBOX",
	"Show Title",
	[_modCategory, _catWyptInfo],
	TRUE,
	nil,
	{ call APD_fnc_updateWaypointLayout; }
] call CBA_fnc_addSetting;

[
	"APD_HMD_WaypointDistanceEnabled", "CHECKBOX",
	"Show Distance",
	[_modCategory, _catWyptInfo],
	TRUE,
	nil,
	{ call APD_fnc_updateWaypointProcessing; }
] call CBA_fnc_addSetting;

[
	"APD_HMD_WaypointTimeEnabled", "CHECKBOX",
	"Show Estimated Time",
	[_modCategory, _catWyptInfo],
	TRUE,
	nil,
	{ call APD_fnc_updateWaypointProcessing; }
] call CBA_fnc_addSetting;

[
	"APD_HMD_WaypointTextFont", "LIST",
	"Font",
	[_modCategory, _catWyptInfo],
	[_supportedFonts, _supportedFonts, _defaultFont],
	nil,
	{ call APD_fnc_updateWaypointLayout; }
] call CBA_fnc_addSetting;

[
	"APD_HMD_WaypointTextScale", "SLIDER",
	"Text Size",
	[_modCategory, _catWyptInfo],
	_supportedSizes,
	nil,
	{ call APD_fnc_updateWaypointLayout; }
] call CBA_fnc_addSetting;

[
	"APD_HMD_WaypointXOffset", "SLIDER",
	"Horizontal Position",
	[_modCategory, _catWyptInfo],
	[0, 1, 0.66, 2],
	nil,
	{ call APD_fnc_updateWaypointLayout; }
] call CBA_fnc_addSetting;

[
	"APD_HMD_WaypointYOffset", "SLIDER",
	"Vertical Position",
	[_modCategory, _catWyptInfo],
	[0, 1, 0.74, 2],
	nil,
	{ call APD_fnc_updateWaypointLayout; }
] call CBA_fnc_addSetting;
