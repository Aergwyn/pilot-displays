class Waypoint_Group
{
	condition = "WPvalid";
	type = "group";

	#define MARKER_SIZE 0.02
	
	#define LINE_CLASS(CLASS, TYPE, WIDTH)\
		class CLASS\
		{\
			lineType = TYPE;\
			type = "line";\
			width = WIDTH;\

	#define POINT_SETUP\
		points[] =\
		{\
			{ "Waypoint_To_View_Bone", { -0.002, 0 }, 1 },\
			{ "Waypoint_To_View_Bone", { 0.002, 0 }, 1 },\
			{ },\
			{ "Waypoint_To_View_Bone", { 0, -0.002 }, 1 },\
			{ "Waypoint_To_View_Bone", { 0, 0.002 }, 1 },\
			{ },\

	class Waypoint_Cross_Group
	{
		condition = EQUAL_CONDITION(user20, 1);
		type = "group";

		LINE_CLASS(Waypoint_Cross, 0, 2)
			POINT_SETUP
				{ "Waypoint_To_View_Bone", { -(MARKER_SIZE / 2), -(MARKER_SIZE / 2) }, 1 },
				{ "Waypoint_To_View_Bone", { MARKER_SIZE / 2, MARKER_SIZE / 2 }, 1 },
				{ },
				{ "Waypoint_To_View_Bone", { -(MARKER_SIZE / 2), MARKER_SIZE / 2 }, 1 },
				{ "Waypoint_To_View_Bone", { MARKER_SIZE / 2, -(MARKER_SIZE / 2) }, 1 }
			};
		};
	};
	class Waypoint_Triangle_Group
	{
		condition = EQUAL_CONDITION(user20, 2);
		type = "group";

		LINE_CLASS(Waypoint_Triangle, 0, 2)
			POINT_SETUP
				// Offset according to centroid
				{ "Waypoint_To_View_Bone", { 0, MARKER_SIZE * 0.6666 }, 1 },
				{ "Waypoint_To_View_Bone", { -(MARKER_SIZE / 2), -(MARKER_SIZE / 3) }, 1 },
				{ "Waypoint_To_View_Bone", { MARKER_SIZE / 2, -(MARKER_SIZE / 3) }, 1 },
				{ "Waypoint_To_View_Bone", { 0, MARKER_SIZE * 0.6666 }, 1 }
			};
		};
	};
	class Waypoint_Detail_Group
	{
		condition = "user21";
		type = "group";

		#define X_OFFSET -0.25
		#define Y_OFFSET 0.2
		#define X_ALIGNMENT 1
		#define Y_ALIGNMENT 0.5
		#define TEXT_SIZE 0.02

		class Waypoint_Header
		{
			align = "right";
			scale = 1;
			source = "static";
			text  = "WYPT";
			type = "text";

			pos[] = { { X_ALIGNMENT + X_OFFSET, Y_ALIGNMENT + Y_OFFSET }, 1 };
			right[] = { { X_ALIGNMENT + X_OFFSET + TEXT_SIZE, Y_ALIGNMENT + Y_OFFSET }, 1 };
			down[] = { { X_ALIGNMENT + X_OFFSET, Y_ALIGNMENT + Y_OFFSET + TEXT_SIZE }, 1 };
		};
		class Waypoint_Distance
		{
			align = "right";
			scale = 1;
			source = "userText";
			sourceIndex = 22;
			sourceScale = 1;
			type = "text";

			pos[] = { { X_ALIGNMENT + X_OFFSET, Y_ALIGNMENT + Y_OFFSET + TEXT_SIZE }, 1 };
			right[] = { { X_ALIGNMENT + X_OFFSET + TEXT_SIZE, Y_ALIGNMENT + Y_OFFSET + TEXT_SIZE }, 1 };
			down[] = { { X_ALIGNMENT + X_OFFSET, Y_ALIGNMENT + Y_OFFSET + (TEXT_SIZE * 2) }, 1 };
		};
		class Waypoint_ETA
		{
			align = "right";
			scale = 1;
			source = "userText";
			sourceIndex = 23;
			sourceScale = 1;
			type = "text";

			pos[] = { { X_ALIGNMENT + X_OFFSET, Y_ALIGNMENT + Y_OFFSET + (TEXT_SIZE * 2) }, 1 };
			right[] = { { X_ALIGNMENT + X_OFFSET + TEXT_SIZE, Y_ALIGNMENT + Y_OFFSET + (TEXT_SIZE * 2) }, 1 };
			down[] = { { X_ALIGNMENT + X_OFFSET, Y_ALIGNMENT + Y_OFFSET + (TEXT_SIZE * 3) }, 1 };
		};
	};
};
