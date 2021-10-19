private _catGeneral = "General";

[
	"APD_HMD_Enabled", "CHECKBOX",
	"Enabled",
	[_modCategory, _catGeneral],
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
	[_modCategory, _catGeneral],
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
	[_modCategory, _catGeneral],
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
	[_modCategory, _catGeneral],
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
	[_modCategory, _catGeneral],
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
