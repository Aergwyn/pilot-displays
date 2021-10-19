class APD_HMD
{
	tag = "APD";

	class Event
	{
		file = "hmd\functions\event";

		class onGetIn {};
		class onGetInMan {};
		class onGetOut {};
		class onGetOutMan {};
		class onKilled {};
		class onMap {};
		class onRespawn {};
		class onSeatSwitched {};
	};

	class Process
	{
		file = "hmd\functions\process";

		class startVehicleLoop {};
		class startWaypointLoop {};
	};

	class Render
	{
		file = "hmd\functions\render";

		class toggleCopilotRendering {};
		class toggleWaypointRendering {};
		class updateCopilotProcessing {};
		class updateVehicleLayout {};
		class updateVehicleProcessing {};
		class updateWaypointLayout {};
		class updateWaypointProcessing {};
	};

	class Ui
	{
		file = "hmd\functions\ui";

		class getDisplay {};
		class setCtrlPosition {};
		class setCtrlPositionAsGroup {};
		class setCtrlVisibility {};
		class setupHUD {};
	};

	class Util
	{
		file = "hmd\functions\util";

		class directionRelativeToWaypoint {};
		class getFirstCopilotTurret {};
		class isValidHMDVehicle {};
		class leftPadString {};
		class vectorToHeading {};
	};
};
