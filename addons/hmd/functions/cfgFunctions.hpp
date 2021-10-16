class APD_HMD_Functions
{
	tag = "APD";

	class Event
	{
		file = "z\pilot-displays\addons\hmd\functions\event";

		class onGetIn {};
		class onGetInMan {};
		class onGetOut {};
		class onGetOutMan {};
		class onKilled {};
		class onMap {};
		class onSeatSwitched {};
	};

	class Process
	{
		file = "z\pilot-displays\addons\hmd\functions\process";

		class startVehicleLoop {};
		class startWaypointLoop {};
	};

	class Render
	{
		file = "z\pilot-displays\addons\hmd\functions\render";

		class toggleGunViewRendering {};
		class toggleWaypointRendering {};
		class updateGunViewProcessing {};
		class updateVehicleLayout  {};
		class updateVehicleProcessing {};
		class updateWaypointLayout {};
		class updateWaypointProcessing {};
	};

	class Ui
	{
		file = "z\pilot-displays\addons\hmd\functions\ui";

		class getDisplay {};
		class setCtrlPosition {};
		class setCtrlPositionAsGroup {};
		class setCtrlVisibility {};
		class setupHUD {};
	};

	class Util
	{
		file = "z\pilot-displays\addons\hmd\functions\util";

		class directionRelativeToWaypoint {};
		class getFirstCopilotTurret {};
		class isValidHMDVehicle {};
		class leftPadString {};
		class vectorToHeading {};
	};
};
