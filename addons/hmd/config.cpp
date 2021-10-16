class CfgPatches
{
	class APD_HMD
	{
		name = "Aergwyn's Pilot HMD";
		units[] = {};
		weapons[] = {};
		requiredVersion = 2.0;
		requiredAddons[] = { "cba_settings" };
		author = "Aergwyn";
		authors[] = { "Aergwyn" };
		authorUrl = "https://github.com/Aergwyn/pilot-displays";
	};
};

#include "ui\display.hpp"

class CfgFunctions
{
	#include "functions\cfgFunctions.hpp"
};

class Extended_PreInit_EventHandlers
{
	class APD_HMD_PreInit
	{
		init = "call compileScript ['z\pilot-displays\addons\hmd\functions\XEH_preInit.sqf', true]";
	};
};

class Extended_PostInit_EventHandlers
{
	class APD_HMD_PostInit
	{
		init = "call compileScript ['z\pilot-displays\addons\hmd\functions\XEH_postInit.sqf', true]";
	};
};
