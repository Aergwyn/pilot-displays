if (!hasInterface) exitWith {};

// Misc

APD_HMD_VehicleLoopRunning = false;
APD_HMD_WaypointLoopRunning = false;

APD_HMD_CopilotMarkerTextureOffset = 0;
APD_HMD_WaypointMarkerTextureOffset = 0;

// Common Setting Values

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

// CBA Init

private _modCategory = "Aergwyn's Pilot Displays - HMD";

#include "..\config\init_general.hpp"
#include "..\config\init_waypoint.hpp"
#include "..\config\init_vehicle.hpp"
