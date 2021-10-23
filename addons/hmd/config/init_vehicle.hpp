private _catVhclInfo = "Vehicle Information";

[
	"APD_HMD_VehicleAGLEnabled", "CHECKBOX",
	"Show Altitude Above Ground Level (AGL)",
	[_modCategory, _catVhclInfo],
	TRUE,
	nil,
	{ call APD_fnc_updateVehicleProcessing; }
] call CBA_fnc_addSetting;

[
	"APD_HMD_VehicleASLEnabled", "CHECKBOX",
	"Show Altitude Above Sea Level (ASL)",
	[_modCategory, _catVhclInfo],
	TRUE,
	nil,
	{ call APD_fnc_updateVehicleProcessing; }
] call CBA_fnc_addSetting;

[
	"APD_HMD_VehicleVSIEnabled", "CHECKBOX",
	"Show Vertical Speed Indicator (VSI)",
	[_modCategory, _catVhclInfo],
	TRUE,
	nil,
	{ call APD_fnc_updateVehicleProcessing; }
] call CBA_fnc_addSetting;

[
	"APD_HMD_VehicleIASEnabled", "CHECKBOX",
	"Show Indicated Airspeed (IAS)",
	[_modCategory, _catVhclInfo],
	TRUE,
	nil,
	{ call APD_fnc_updateVehicleProcessing; }
] call CBA_fnc_addSetting;

[
	"APD_HMD_VehicleTextFont", "LIST",
	"Font",
	[_modCategory, _catVhclInfo],
	[_supportedFonts, _supportedFonts, _defaultFont],
	nil,
	{ call APD_fnc_updateVehicleLayout; }
] call CBA_fnc_addSetting;

[
	"APD_HMD_VehicleTextScale", "SLIDER",
	"Text Size",
	[_modCategory, _catVhclInfo],
	_supportedSizes,
	nil,
	{ call APD_fnc_updateVehicleLayout; }
] call CBA_fnc_addSetting;

[
	"APD_HMD_VehicleXOffset", "SLIDER",
	"Horizontal Position",
	[_modCategory, _catVhclInfo],
	[0, 1, 0.66, 2],
	nil,
	{ call APD_fnc_updateVehicleLayout; }
] call CBA_fnc_addSetting;

[
	"APD_HMD_VehicleYOffset", "SLIDER",
	"Vertical Position",
	[_modCategory, _catVhclInfo],
	[0, 1, 0.28, 2],
	nil,
	{ call APD_fnc_updateVehicleLayout; }
] call CBA_fnc_addSetting;
