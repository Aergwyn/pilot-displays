class APD_HMD_Functions
{
	tag = "APD";

	class Event
	{
		file = "HMD\functions\event";

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
		file = "HMD\functions\process";

		class startVehicleLoop {};
		class startWaypointLoop {};
	};

	class Render
	{
		file = "HMD\functions\render";

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
		file = "HMD\functions\ui";

		class getDisplay {};
		class setCtrlPosition {};
		class setCtrlPositionAsGroup {};
		class setCtrlVisibility {};
		class setupHUD {};
	};

	class Util
	{
		file = "HMD\functions\util";

		class directionRelativeToWaypoint {};
		class getFirstCopilotTurret {};
		class isValidHMDVehicle {};
		class leftPadString {};
		class vectorToHeading {};
	};
};
