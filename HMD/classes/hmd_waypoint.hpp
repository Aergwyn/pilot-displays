class Waypoint_Group
{
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

		#define X_OFFSET -0.2
		#define Y_OFFSET -0.13
		#define X_ALIGNMENT 1
		#define Y_ALIGNMENT 1
		#define TEXT_SIZE 0.025

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
			sourceIndex = 15;
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
			sourceIndex = 16;
			sourceScale = 1;
			type = "text";

			pos[] = { { X_ALIGNMENT + X_OFFSET, Y_ALIGNMENT + Y_OFFSET + (TEXT_SIZE * 2) }, 1 };
			right[] = { { X_ALIGNMENT + X_OFFSET + TEXT_SIZE, Y_ALIGNMENT + Y_OFFSET + (TEXT_SIZE * 2) }, 1 };
			down[] = { { X_ALIGNMENT + X_OFFSET, Y_ALIGNMENT + Y_OFFSET + (TEXT_SIZE * 3) }, 1 };
		};
	};
};
