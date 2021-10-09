if (!hasInterface) exitWith {};

// -----------------
// --- Misc Init ---
// -----------------

APD_HMD_VehicleLoopRunning = false;
APD_HMD_WaypointLoopRunning = false;

// --------------------
// --- CBA-Settings ---
// --------------------

private _wynCategory = "Aergwyn's Pilot HMD";
private _wynCategory01 = "01 - General";
private _wynCategory02 = "02 - Compass";
private _wynCategory03 = "03 - Horizon";
private _wynCategory04 = "04 - Vehicle";
private _wynCategory05 = "05 - Waypoint";

private _defaultFont = 1;
private _supportedFonts =
[
	"Caveat",
	"EtelkaMonospacePro",
	"LCD14",
	"LucidaConsoleB",
	"PixelSplitterBold",
	"PuristaBold",
	"PuristaLight",
	"PuristaMedium",
	"PuristaSemibold",
	"RobotoCondensed",
	"TahomaB"
];

// TODO I'm not sure about the order as custom fonts appearing/disappearing could change the index and thus the used font randomly...
//private _supportedFonts = ("true" configClasses (configFile >> "CfgFontFamilies")) apply { configName _x; };

private _supportedSizes = [0.25, 4, 1, 2, true]; // Min, Max, Default, Decimals, Percentage

// - General

[
	"APD_HMD_Enabled", "CHECKBOX",
	"Enabled",
	[_wynCategory, _wynCategory01],
	TRUE,
	nil,
	{ call APD_fnc_updateMFDValues; }
] call CBA_fnc_addSetting;

[
	"APD_HMD_Colour", "COLOR",
	"Colour",
	[_wynCategory, _wynCategory01],
	[ 0, 1, 0, 1 ],
	nil,
	{ call APD_fnc_updateMFDValues; }
] call CBA_fnc_addSetting;

[
	"APD_HMD_SoU_Speed", "LIST",
	"Unit for Speed",
	[_wynCategory, _wynCategory01],
	[
		// Unit, Multiplier (to convert from metric meter)
		[
			["KM/H", 3.6],
			["MPH", 2.23694],
			["KN", 1.94384]
		],
		[
			"Metric (KM/H)",
			"Imperial (MPH)",
			"Aviation (KN)"
		], 0
	],
	nil,
	{ call APD_fnc_updateMFDValues; }
] call CBA_fnc_addSetting;

[
	"APD_HMD_SoU_Distance", "LIST",
	"Unit for Distance",
	[_wynCategory, _wynCategory01],
	[
		// Unit, Multiplier (to convert from metric meter), Precision
		[
			["M", 1, 0],
			["KM", (1 / 1000), 2],
			["FT", 3.28084, 0],
			["MI", (1 / 1609.34), 2],
			["NM", (1 / 1852), 2]
		],
		[
			"Metric (M)",
			"Metric (KM)",
			"Imperial (FT)",
			"Imperial (MI)",
			"Aviation (NM)"
		], 1
	],
	nil,
	{ call APD_fnc_updateMFDValues; }
] call CBA_fnc_addSetting;

[
	"APD_HMD_SoU_Altitude", "LIST",
	"Unit for Altitude",
	[_wynCategory, _wynCategory01],
	[
		// Unit, Multiplier (to convert from metric meter)
		[
			["M", 1],
			["FT", 3.28084]
		],
		[
			"Metric (M)",
			"Imperial (FT)"
		], 0
	],
	nil,
	{ call APD_fnc_updateMFDValues; }
] call CBA_fnc_addSetting;

// - Compass

[
	"APD_HMD_CompassEnabled", "CHECKBOX",
	"Show Compass",
	[_wynCategory, _wynCategory02],
	TRUE,
	nil,
	{ call APD_fnc_updateMFDValues; }
] call CBA_fnc_addSetting;

// - Horizon

[
	"APD_HMD_HorizonStyle", "LIST",
	"Horizon Style",
	[_wynCategory, _wynCategory03],
	[[0, 1, 2, 3, 4], ["Disabled", "0° Only", "10° Lines", "15° Lines", "30° Lines"], 2],
	nil,
	{ call APD_fnc_updateMFDValues; }
] call CBA_fnc_addSetting;

// - Vehicle

[
	"APD_HMD_VehicleAGLEnabled", "CHECKBOX",
	"Show Altitude Above Ground Level (AGL)",
	[_wynCategory, _wynCategory04],
	TRUE,
	nil,
	{ call APD_fnc_updateVehicleProcessing; }
] call CBA_fnc_addSetting;

[
	"APD_HMD_VehicleASLEnabled", "CHECKBOX",
	"Show Altitude Above Sea Level (ASL)",
	[_wynCategory, _wynCategory04],
	TRUE,
	nil,
	{ call APD_fnc_updateVehicleProcessing; }
] call CBA_fnc_addSetting;

[
	"APD_HMD_VehicleSPDEnabled", "CHECKBOX",
	"Show Speed (SPD)",
	[_wynCategory, _wynCategory04],
	TRUE,
	nil,
	{ call APD_fnc_updateVehicleProcessing; }
] call CBA_fnc_addSetting;

[
	"APD_HMD_VehicleTextFont", "LIST",
	"Font",
	[_wynCategory, _wynCategory04],
	[_supportedFonts, _supportedFonts, _defaultFont],
	nil,
	{ call APD_fnc_updateVehicleLayout; }
] call CBA_fnc_addSetting;

[
	"APD_HMD_VehicleTextScale", "SLIDER",
	"Text Size",
	[_wynCategory, _wynCategory04],
	_supportedSizes,
	nil,
	{ call APD_fnc_updateVehicleLayout; }
] call CBA_fnc_addSetting;

[
	"APD_HMD_VehicleXOffset", "SLIDER",
	"Horizontal Position",
	[_wynCategory, _wynCategory04],
	[0, 1, 0.66, 2],
	nil,
	{ call APD_fnc_updateVehicleLayout; }
] call CBA_fnc_addSetting;

[
	"APD_HMD_VehicleYOffset", "SLIDER",
	"Vertical Position",
	[_wynCategory, _wynCategory04],
	[0, 1, 0.28, 2],
	nil,
	{ call APD_fnc_updateVehicleLayout; }
] call CBA_fnc_addSetting;

// - Waypoint

[
	"APD_HMD_WaypointMarkerTexture", "LIST",
	"Marker Style",
	[_wynCategory, _wynCategory05],
	[
		[
			"",
			"HMD\textures\wypt_plus.paa",
			"HMD\textures\wypt_cross.paa",
			"HMD\textures\wypt_square.paa",
			"HMD\textures\wypt_circle.paa"
		],
		[
			"Disabled",
			"Plus",
			"Cross",
			"Square",
			"Circle"
		], 2
	],
	nil,
	{ call APD_fnc_updateWaypointProcessing; }
] call CBA_fnc_addSetting;

[
	"APD_HMD_WaypointHeaderEnabled", "CHECKBOX",
	"Show Title",
	[_wynCategory, _wynCategory05],
	TRUE,
	nil,
	{ call APD_fnc_updateWaypointLayout; }
] call CBA_fnc_addSetting;

[
	"APD_HMD_WaypointDistanceEnabled", "CHECKBOX",
	"Show Distance",
	[_wynCategory, _wynCategory05],
	TRUE,
	nil,
	{ call APD_fnc_updateWaypointProcessing; }
] call CBA_fnc_addSetting;

[
	"APD_HMD_WaypointTimeEnabled", "CHECKBOX",
	"Show Estimated Time",
	[_wynCategory, _wynCategory05],
	TRUE,
	nil,
	{ call APD_fnc_updateWaypointProcessing; }
] call CBA_fnc_addSetting;


[
	"APD_HMD_WaypointTextFont", "LIST",
	"Font",
	[_wynCategory, _wynCategory05],
	[_supportedFonts, _supportedFonts, _defaultFont],
	nil,
	{ call APD_fnc_updateWaypointLayout; }
] call CBA_fnc_addSetting;

[
	"APD_HMD_WaypointTextScale", "SLIDER",
	"Text Size",
	[_wynCategory, _wynCategory05],
	_supportedSizes,
	nil,
	{ call APD_fnc_updateWaypointLayout; }
] call CBA_fnc_addSetting;

[
	"APD_HMD_WaypointXOffset", "SLIDER",
	"Horizontal Position",
	[_wynCategory, _wynCategory05],
	[0, 1, 0.66, 2],
	nil,
	{ call APD_fnc_updateWaypointLayout; }
] call CBA_fnc_addSetting;

[
	"APD_HMD_WaypointYOffset", "SLIDER",
	"Vertical Position",
	[_wynCategory, _wynCategory05],
	[0, 1, 0.74, 2],
	nil,
	{ call APD_fnc_updateWaypointLayout; }
] call CBA_fnc_addSetting;

// - Other
