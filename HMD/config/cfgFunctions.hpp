class APD_HMD_Functions
{
	tag = "APD";

	class Functions
	{
		file = "HMD\functions";

		class directionRelativeToWaypoint {};
		class isValidHMDVehicle {};
		class updateMFDValues {};
	};

	class UI
	{
		file = "HMD\functions\ui";

		class getDisplay {};
		class setCtrlPosition {};
		class setCtrlPositionAsGroup {};
		class setupHUD {};
		class toggleHUD {};
		class updateHUD {};
	};

	class Util
	{
		file = "HMD\functions\util";

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

		class evaluateWaypointProcessing {};
		class startWaypointLoop {};
		class toggleWaypointRendering {};
	};


};
