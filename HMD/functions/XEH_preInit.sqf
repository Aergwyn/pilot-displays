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
private _wynCategory02 = "02 - Specific";

[
	"APD_HMD_Enabled", "CHECKBOX",
	"Enabled",
	[_wynCategory, _wynCategory01],
	TRUE,
	nil,
	{ call APD_fnc_updateMFDValues; }
] call CBA_Settings_fnc_init;

[
	"APD_HMD_SoU_Speed", "LIST",
	"System of Units for Speed",
	[_wynCategory, _wynCategory01],
	[
		// Unit, Multiplier (to convert from metric meter)
		[
			["KMH", 3.6],
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
	"System of Units for Distance",
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
	"APD_HMD_Colour", "COLOR",
	"Colour",
	[_wynCategory, _wynCategory01],
	[ 0, 1, 0, 1 ],
	nil,
	{ call APD_fnc_updateMFDValues; }
] call CBA_Settings_fnc_init;

[
	"APD_HMD_HeadingEnabled", "CHECKBOX",
	"Show Heading",
	[_wynCategory, _wynCategory02],
	TRUE,
	nil,
	{ call APD_fnc_updateMFDValues; }
] call CBA_Settings_fnc_init;

[
	"APD_HMD_HorizonEnabled", "CHECKBOX",
	"Show Horizon",
	[_wynCategory, _wynCategory02],
	TRUE,
	nil,
	{ call APD_fnc_updateMFDValues; }
] call CBA_Settings_fnc_init;

[
	"APD_HMD_SpeedEnabled", "CHECKBOX",
	"Show air- and vertical speed",
	[_wynCategory, _wynCategory02],
	TRUE,
	nil,
	{ call APD_fnc_updateMFDValues; }
] call CBA_Settings_fnc_init;

[
	"APD_HMD_WaypointStyle", "LIST",
	"Waypoint Style",
	[_wynCategory, _wynCategory02],
	[[0, 1, 2], ["Disabled", "Marker", "Marker + Detail"], 2],
	nil,
	{ call APD_fnc_updateMFDValues; }
] call CBA_Settings_fnc_init;
