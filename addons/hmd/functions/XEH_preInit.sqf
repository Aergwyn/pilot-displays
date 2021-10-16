if (!hasInterface) exitWith {};

// -----------------
// --- Misc Init ---
// -----------------

APD_HMD_VehicleLoopRunning = false;
APD_HMD_WaypointLoopRunning = false;

APD_HMD_WaypointMarkerTextureOffset = 0;

// --------------------
// --- CBA-Settings ---
// --------------------

private _modCategory = "Aergwyn's Pilot HMD";
private _subCategory01 = "01 - General";
private _subCategory02 = "02 - Compass";
private _subCategory03 = "03 - Horizon";
private _subCategory04 = "04 - Waypoint Marker";
private _subCategory05 = "05 - Waypoint Information";
private _subCategory06 = "06 - Vehicle Information";

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
	[_modCategory, _subCategory01],
	TRUE,
	nil,
	{
		call APD_fnc_updateVehicleProcessing;
		call APD_fnc_updateWaypointProcessing;
	}
] call CBA_fnc_addSetting;

[
	"APD_HMD_Colour", "COLOR",
	"Colour",
	[_modCategory, _subCategory01],
	[ 0, 1, 0, 1 ],
	nil,
	{
		call APD_fnc_updateVehicleLayout;
		call APD_fnc_updateWaypointLayout;
	}
] call CBA_fnc_addSetting;

[
	"APD_HMD_SoU_Speed", "LIST",
	"Unit for Speed",
	[_modCategory, _subCategory01],
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
	{ call APD_fnc_updateVehicleLayout; }
] call CBA_fnc_addSetting;

[
	"APD_HMD_SoU_Distance", "LIST",
	"Unit for Distance",
	[_modCategory, _subCategory01],
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
	{ call APD_fnc_updateWaypointLayout; }
] call CBA_fnc_addSetting;

[
	"APD_HMD_SoU_Altitude", "LIST",
	"Unit for Altitude",
	[_modCategory, _subCategory01],
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
	{ call APD_fnc_updateVehicleLayout; }
] call CBA_fnc_addSetting;

// - Waypoint Marker

[
	"APD_HMD_WaypointMarkerEnabled", "CHECKBOX",
	"Enabled",
	[_modCategory, _subCategory04],
	TRUE,
	nil,
	{ call APD_fnc_updateWaypointProcessing; }
] call CBA_fnc_addSetting;

[
	"APD_HMD_WaypointMarkerScale", "SLIDER",
	"Size",
	[_modCategory, _subCategory04],
	_supportedSizes,
	nil,
	{ call APD_fnc_updateWaypointLayout; }
] call CBA_fnc_addSetting;

[
	"APD_HMD_WaypointMarkerTexture", "LIST",
	"Style",
	[_modCategory, _subCategory04],
	[
		[
			"z\pilot-displays\addons\hmd\textures\wypt_plus.paa",
			"z\pilot-displays\addons\hmd\textures\wypt_cross.paa",
			"z\pilot-displays\addons\hmd\textures\wypt_square.paa",
			"z\pilot-displays\addons\hmd\textures\wypt_circle.paa"
		],
		[
			"Plus",
			"Cross",
			"Square",
			"Circle"
		], 1
	],
	nil,
	{  }
] call CBA_fnc_addSetting;

// Waypoint Information

[
	"APD_HMD_WaypointHeaderEnabled", "CHECKBOX",
	"Show Title",
	[_modCategory, _subCategory05],
	TRUE,
	nil,
	{ call APD_fnc_updateWaypointLayout; }
] call CBA_fnc_addSetting;

[
	"APD_HMD_WaypointDistanceEnabled", "CHECKBOX",
	"Show Distance",
	[_modCategory, _subCategory05],
	TRUE,
	nil,
	{ call APD_fnc_updateWaypointProcessing; }
] call CBA_fnc_addSetting;

[
	"APD_HMD_WaypointTimeEnabled", "CHECKBOX",
	"Show Estimated Time",
	[_modCategory, _subCategory05],
	TRUE,
	nil,
	{ call APD_fnc_updateWaypointProcessing; }
] call CBA_fnc_addSetting;

[
	"APD_HMD_WaypointTextFont", "LIST",
	"Font",
	[_modCategory, _subCategory05],
	[_supportedFonts, _supportedFonts, _defaultFont],
	nil,
	{ call APD_fnc_updateWaypointLayout; }
] call CBA_fnc_addSetting;

[
	"APD_HMD_WaypointTextScale", "SLIDER",
	"Text Size",
	[_modCategory, _subCategory05],
	_supportedSizes,
	nil,
	{ call APD_fnc_updateWaypointLayout; }
] call CBA_fnc_addSetting;

[
	"APD_HMD_WaypointXOffset", "SLIDER",
	"Horizontal Position",
	[_modCategory, _subCategory05],
	[0, 1, 0.66, 2],
	nil,
	{ call APD_fnc_updateWaypointLayout; }
] call CBA_fnc_addSetting;

[
	"APD_HMD_WaypointYOffset", "SLIDER",
	"Vertical Position",
	[_modCategory, _subCategory05],
	[0, 1, 0.74, 2],
	nil,
	{ call APD_fnc_updateWaypointLayout; }
] call CBA_fnc_addSetting;

// - Vehicle Information

[
	"APD_HMD_VehicleAGLEnabled", "CHECKBOX",
	"Show Altitude Above Ground Level (AGL)",
	[_modCategory, _subCategory06],
	TRUE,
	nil,
	{ call APD_fnc_updateVehicleProcessing; }
] call CBA_fnc_addSetting;

[
	"APD_HMD_VehicleASLEnabled", "CHECKBOX",
	"Show Altitude Above Sea Level (ASL)",
	[_modCategory, _subCategory06],
	TRUE,
	nil,
	{ call APD_fnc_updateVehicleProcessing; }
] call CBA_fnc_addSetting;

[
	"APD_HMD_VehicleSPDEnabled", "CHECKBOX",
	"Show Indicated Airspeed (IAS)",
	[_modCategory, _subCategory06],
	TRUE,
	nil,
	{ call APD_fnc_updateVehicleProcessing; }
] call CBA_fnc_addSetting;

[
	"APD_HMD_VehicleTextFont", "LIST",
	"Font",
	[_modCategory, _subCategory06],
	[_supportedFonts, _supportedFonts, _defaultFont],
	nil,
	{ call APD_fnc_updateVehicleLayout; }
] call CBA_fnc_addSetting;

[
	"APD_HMD_VehicleTextScale", "SLIDER",
	"Text Size",
	[_modCategory, _subCategory06],
	_supportedSizes,
	nil,
	{ call APD_fnc_updateVehicleLayout; }
] call CBA_fnc_addSetting;

[
	"APD_HMD_VehicleXOffset", "SLIDER",
	"Horizontal Position",
	[_modCategory, _subCategory06],
	[0, 1, 0.66, 2],
	nil,
	{ call APD_fnc_updateVehicleLayout; }
] call CBA_fnc_addSetting;

[
	"APD_HMD_VehicleYOffset", "SLIDER",
	"Vertical Position",
	[_modCategory, _subCategory06],
	[0, 1, 0.28, 2],
	nil,
	{ call APD_fnc_updateVehicleLayout; }
] call CBA_fnc_addSetting;
