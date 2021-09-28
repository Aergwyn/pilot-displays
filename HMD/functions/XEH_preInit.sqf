if (!hasInterface) exitWith {};

// -----------------
// --- Misc Init ---
// -----------------

APD_HMD_SpeedLoopRunning = false;
APD_HMD_WaypointLoopRunning = false;

// --------------------
// --- CBA-Settings ---
// --------------------

private _wynCategory = "Aergwyn's Pilot HMD";
private _wynCategory01 = "01 - General";
private _wynCategory02 = "02 - Compass";
private _wynCategory03 = "03 - Horizon";
private _wynCategory04 = "04 - Waypoint";
private _wynCategory05 = "05 - Other";

// - 01

[
	"APD_HMD_Enabled", "CHECKBOX",
	"Enabled",
	[_wynCategory, _wynCategory01],
	TRUE,
	nil,
	{ call APD_fnc_updateMFDValues; }
] call CBA_Settings_fnc_init;

[
	"APD_HMD_Colour", "COLOR",
	"Colour",
	[_wynCategory, _wynCategory01],
	[ 0, 1, 0, 1 ],
	nil,
	{ call APD_fnc_updateMFDValues; }
] call CBA_Settings_fnc_init;

[
	"APD_HMD_SoU_Speed", "LIST",
	"Unit for Speed",
	[_wynCategory, _wynCategory01],
	[
		// Unit, Multiplier (to convert from metric meter)
		[
			["KPH", 3.6],
			["MPH", 2.23694],
			["KN", 1.94384]
		],
		[
			"Metric (KMH)",
			"Imperial (MPH)",
			"Aviation (KN)"
		], 0
	],
	nil,
	{ call APD_fnc_updateMFDValues; }
] call CBA_Settings_fnc_init;

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
] call CBA_Settings_fnc_init;

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
] call CBA_Settings_fnc_init;

// - 02

[
	"APD_HMD_CompassEnabled", "CHECKBOX",
	"Show Compass",
	[_wynCategory, _wynCategory02],
	TRUE,
	nil,
	{ call APD_fnc_updateMFDValues; }
] call CBA_Settings_fnc_init;

// - Horizon

[
	"APD_HMD_HorizonStyle", "LIST",
	"Horizon Style",
	[_wynCategory, _wynCategory03],
	[[0, 1, 2, 3, 4], ["Disabled", "0° Only", "10° Lines", "15° Lines", "30° Lines"], 2],
	nil,
	{ call APD_fnc_updateMFDValues; }
] call CBA_Settings_fnc_init;

// - Waypoint

[
	"APD_HMD_WaypointMarkerStyle", "LIST",
	"Marker Style",
	[_wynCategory, _wynCategory04],
	[[0, 1, 2], ["Disabled", "Cross", "Triangle"], 1],
	nil,
	{ call APD_fnc_updateMFDValues; }
] call CBA_Settings_fnc_init;

[
	"APD_HMD_WaypointDetailsEnabled", "CHECKBOX",
	"Show Details",
	[_wynCategory, _wynCategory04],
	TRUE,
	nil,
	{ call APD_fnc_updateMFDValues; }
] call CBA_Settings_fnc_init;

// - Other

[
	"APD_HMD_SpeedEnabled", "CHECKBOX",
	"Show air- and vertical speed",
	[_wynCategory, _wynCategory05],
	TRUE,
	nil,
	{ call APD_fnc_updateMFDValues; }
] call CBA_Settings_fnc_init;
