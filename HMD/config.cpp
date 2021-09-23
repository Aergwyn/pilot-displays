class CfgPatches
{
	class APD_HMD_Mod
	{
		name = "Aergwyn's Pilot HMD";
		units[] = {};
		weapons[] = {};
		requiredVersion = 2.0;
		requiredAddons[] = { "cba_settings" };
		author = "Aergwyn"
		authors[] = { "Aergwyn" };
		authorUrl = "https://github.com/Aergwyn/pilot-displays";
	};
};

#include "hmd/hmd_base.hpp"
#include "config/cfgFunctions.hpp"

class CfgVehicles
{
	#include "config/cfgVehicles.hpp"
};

class Extended_PreInit_EventHandlers
{
	class APD_HMD_PreInit
	{
		init = "call compileScript ['HMD\functions\XEH_preInit.sqf', true]";
	};
};

class Extended_PostInit_EventHandlers
{
	class APD_HMD_PostInit
	{
		init = "call compileScript ['HMD\functions\XEH_postInit.sqf', true]";
	};
};
