class Waypoint_Group
{
	alpha = "user1";
	color[] = { "user2", "user3", "user4" };
	condition = "WPvalid * (user14 > 0)";
	type = "group";

	class Waypoint_Triangle
	{
		lineType = 0;
		type = "line";
		width = 2;

		#define SIZE 0.025

		points[] =
		{
			{ "Waypoint_To_View_Bone", { 0, SIZE / 2 }, 1 },
			{ "Waypoint_To_View_Bone", { -(SIZE / 2), -(SIZE / 2) }, 1 },
			{ "Waypoint_To_View_Bone", { SIZE / 2, -(SIZE / 2) }, 1 },
			{ "Waypoint_To_View_Bone", { 0, SIZE / 2 }, 1 }
		};
	};
	class Waypoint_Detail_Group
	{
		condition = "user14 > 1";
		type = "group";

		class Waypoint_Header
		{
			align = "right";
			scale = 1;
			source = "static";
			text  = "WYPT";
			type = "text";

			#define SIZE 0.025
			#define X_OFFSET -0.2
			#define Y_OFFSET -0.13

			pos[] = { { 1 + X_OFFSET, 1 + Y_OFFSET }, 1 };
			right[] = { { 1 + X_OFFSET + SIZE, 1 + Y_OFFSET }, 1 };
			down[] = { { 1 + X_OFFSET, 1 + Y_OFFSET + SIZE }, 1 };
		};
		class Waypoint_Distance
		{
			align = "right";
			scale = 1;
			source = "userText";
			sourceIndex = 15;
			sourceScale = 1;
			type = "text";

			#define SIZE 0.025
			#define X_OFFSET -0.2
			#define Y_OFFSET -0.1

			pos[] = { { 1 + X_OFFSET, 1 + Y_OFFSET }, 1 };
			right[] = { { 1 + X_OFFSET + SIZE, 1 + Y_OFFSET }, 1 };
			down[] = { { 1 + X_OFFSET, 1 + Y_OFFSET + SIZE }, 1 };
		};
		class Waypoint_ETA
		{
			align = "right";
			scale = 1;
			source = "userText";
			sourceIndex = 16;
			sourceScale = 1;
			type = "text";

			#define SIZE 0.025
			#define X_OFFSET -0.2
			#define Y_OFFSET -0.07

			pos[] = { { 1 + X_OFFSET, 1 + Y_OFFSET }, 1 };
			right[] = { { 1 + X_OFFSET + SIZE, 1 + Y_OFFSET }, 1 };
			down[] = { { 1 + X_OFFSET, 1 + Y_OFFSET + SIZE }, 1 };
		};
	};
};
