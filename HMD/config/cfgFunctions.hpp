class APD_HMD_Functions
{
	tag = "APD";

	class Functions
	{
		file = "HMD\functions";

		class updateMFDValues {};
	};

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

	class GunView
	{
		file = "HMD\functions\gunview";

		class toggleGunViewRendering {};
	};

	class Layout
	{
		file = "HMD\functions\layout";

		class setupHUD {};
		class updateVehicleLayout  {};
		class updateWaypointLayout {};
	};

	class Processing
	{
		file = "HMD\functions\processing";

		class updateGunViewProcessing {};
		class updateVehicleProcessing {};
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

		class startVehicleLoop {};
	};

	class Waypoint
	{
		file = "HMD\functions\waypoint";

		class startWaypointLoop {};
		class toggleWaypointRendering {};
	};
};
