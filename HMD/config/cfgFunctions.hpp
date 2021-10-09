class APD_HMD_Functions
{
	tag = "APD";

	class Functions
	{
		file = "HMD\functions";

		class updateMFDValues {};
	};

	class Layout
	{
		file = "HMD\functions\layout";

		class setupHUD {};
		class updateWaypointLayout {};
	};

	class Processing
	{
		file = "HMD\functions\processing";

		class updateWaypointProcessing {};
	};

	class UI
	{
		file = "HMD\functions\ui";

		class getDisplay {};
		class setCtrlPosition {};
		class setCtrlPositionAsGroup {};
		class setCtrlVisibility {};
	};

	class Util
	{
		file = "HMD\functions\util";

		class directionRelativeToWaypoint {};
		class isValidHMDVehicle {};
		class leftPadString {};
		class vectorToHeading {};
	};

	class Vehicle
	{
		file = "HMD\functions\vehicle";

		class evaluateVehicleProcessing {};
		class startVehicleLoop {};
	};

	class Waypoint
	{
		file = "HMD\functions\waypoint";

		class startWaypointLoop {};
		class toggleWaypointRendering {};
	};
};
