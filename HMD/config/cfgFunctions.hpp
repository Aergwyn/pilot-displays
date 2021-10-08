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

	class Processing
	{
		file = "HMD\functions\process";

		class evaluateLoops {};
		class vehicleLoop {};
		class waypointLoop {};
	};

	class Rendering
	{
		file = "HMD\functions\render";

		class toggleWaypointRender {};
	};

	class UI
	{
		file = "HMD\functions\ui";

		class getDisplay {};
	};

	class Utility
	{
		file = "HMD\functions\util";

		class leftPadString {};
		class vectorToHeading {};
	};
};
