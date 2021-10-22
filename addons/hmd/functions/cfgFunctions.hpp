class APD_HMD
{
	tag = "APD";

	class Event
	{
		file = "hmd\functions\event";

		class handleGetIn {};
		class handleGetInMan {};
		class handleGetOut {};
		class handleGetOutMan {};
		class handleKilled {};
		class handleMissionMap {};
		class handleRespawn {};
		class handleSeatSwitched {};
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
		class updateCopilotLayout {};
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
		class isValidForHMD {};
		class leftPadString {};
		class vectorToHeading {};
	};
};
