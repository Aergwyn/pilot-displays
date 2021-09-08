class APD_HMD_Base
{
	color[] = { 0, 0, 0, 0 };
	enableParallax = 0;
	font = "EtelkaMonospacePro";
	helmetMountedDisplay = 1;
	turret[] = {};

	borderTop = 0;
	borderLeft = 0;
	borderRight = 0;
	borderBottom = 0;
	topLeft = "";
	topRight = "";
	bottomLeft = "";

	#define HMD_WIDTH 0.06
	#define HMD_HEIGHT 0.04

	helmetPosition[] = { -(HMD_WIDTH / 2), HMD_HEIGHT / 2, 0.04 };
	helmetRight[] = { HMD_WIDTH, 0, 0 };
	helmetDown[] = { 0, -HMD_HEIGHT, 0 };

	class material
	{
		ambient[] = {1, 1, 1, 1};
		diffuse[] = {0.5, 0.5, 0.5, 1};
		emissive[] = {100, 100, 100, 1};
	};
	class Bones
	{
		#define VIEW_X_OFFSET 0.1214
		#define VIEW_Y_OFFSET 0.1725

		class Waypoint_To_View_Bone
		{
			type = "vector";
			source = "wppointtoview";
			pos0[] = { 0.5, 0.5 };
			pos10[] = { 0.5 + VIEW_X_OFFSET, 0.5 + VIEW_Y_OFFSET };
		};
		class Horizon_0_Bone
		{
			angle = 0;
			type = "horizon";
			pos0[] = { 0.5, 0.5 };
			pos10[] = { 0.5 + VIEW_X_OFFSET, 0.5 + VIEW_Y_OFFSET };
		};
		class Horizon_P10_Bone : Horizon_0_Bone
		{
			angle = 10;
		};
		class Horizon_N10_Bone : Horizon_0_Bone
		{
			angle = -10;
		};
	};
	class Draw
	{
		condition = "user0";

		class Heading_Group
		{
			alpha = "user1";
			color[] = { "user2", "user3", "user4" };
			clipTL[] = { 0.03, 0 };
			clipBR[] = { 0.97, 0.1 };
			condition = "user10";
			type="group";

			class Heading_Scale
			{
				align = "center";
				horizontal = 1;
				majorLineEach = 3;
				NeverEatSeaWeed = 1;
				numberEach = 6;
				scale = 1;
				source = "heading";
				sourceScale = 1;
				step = 15;
				stepSize = 0.04;
				type = "scale";

				top = 0;
				bottom = 1;
				center = 0.5;

				width = 2;
				lineXleft = 0.01;
				lineYright = 0.03;
				lineXleftMajor = 0.01;
				lineYrightMajor =0.02;

				#define SIZE 0.03
				#define X_OFFSET -0.0027
				#define Y_OFFSET 0.018

				pos[] = { 0 + X_OFFSET, 0 + Y_OFFSET };
				right[] = { 0 + X_OFFSET + SIZE, 0 + Y_OFFSET };
				down[] = { 0 + X_OFFSET, 0 + Y_OFFSET + SIZE };
			};
			class Heading_Index
			{
				lineType = 0;
				type = "line";
				width = 2;

				points[] =
				{
					{ { 0.5, 0.045 }, 1 },
					{ { 0.5, 0.055 }, 1 },
					{ },
					{ { 0.475, 0.065 }, 1 },
					{ { 0.475, 0.055 }, 1 },
					{ { 0.525, 0.055 }, 1 },
					{ { 0.525, 0.065 }, 1 }
				};
			};
			class Heading_Number
			{
				align = "center";
				refreshRate = 0;
				scale = 1;
				source = "heading";
				sourceLength = 3;
				sourceScale = 1;
				type = "text";

				#define SIZE 0.03
				#define X_OFFSET -0.003
				#define Y_OFFSET 0.054

				pos[] = { { 0.5 + X_OFFSET, 0 + Y_OFFSET }, 1 };
				right[] = { { 0.5 + X_OFFSET + SIZE, 0 + Y_OFFSET }, 1 };
				down[] = { { 0.5 + X_OFFSET, 0 + Y_OFFSET + SIZE }, 1 };
			};
		};
		class Horizon_Group
		{
			#define HORIZON_WIDTH 0.5

			alpha = "user1";
			color[] = { "user2", "user3", "user4" };
			type = "group";

			class Orientation
			{
				lineType = 0;
				type = "line";
				width = 3;

				#define WIDTH 0.15
				#define HEIGHT 0.01
				#define GAP_WIDTH 0.02

				points[] =
				{
					{ { 0.5 + -(WIDTH / 2), 0.5 }, 1 },
					{ { 0.5 - GAP_WIDTH, 0.5 }, 1 },
					{ { 0.5 - GAP_WIDTH, 0.5 + HEIGHT }, 1 },
					{ },
					{ { 0.5 - GAP_WIDTH / 10, 0.5 }, 1 },
					{ { 0.5 + GAP_WIDTH / 10, 0.5 }, 1 },
					{ },
					{ { 0.5, 0.5 - GAP_WIDTH / 10 }, 1 },
					{ { 0.5, 0.5 + GAP_WIDTH / 10 }, 1 },
					{ },
					{ { 0.5 + GAP_WIDTH, 0.5 + HEIGHT }, 1 },
					{ { 0.5 + GAP_WIDTH, 0.5 }, 1 },
					{ { 0.5 + WIDTH / 2, 0.5 }, 1 },
				};
			};
			class Horizon_P10
			{
				lineType = 2;
				type = "line";
				width = 1.5;

				points[] =
				{
					{ "Horizon_P10_Bone", { -(HORIZON_WIDTH / 4), 0 }, 1 },
					{ "Horizon_P10_Bone", { HORIZON_WIDTH / 4, 0 }, 1 }
				};
			};
			class Horizon_0
			{
				lineType = 2;
				type = "line";
				width = 1.5;

				points[] =
				{
					{ "Horizon_0_Bone", { -(HORIZON_WIDTH / 2), 0 }, 1 },
					{ "Horizon_0_Bone", { HORIZON_WIDTH / 2, 0 }, 1 }
				};
			};
			class Horizon_N10
			{
				lineType = 2;
				type = "line";
				width = 1.5;

				points[] =
				{
					{ "Horizon_N10_Bone", { -(HORIZON_WIDTH / 4), 0 }, 1 },
					{ "Horizon_N10_Bone", { HORIZON_WIDTH / 4, 0 }, 1 }
				};
			};
		};
		class Waypoint_Group
		{
			alpha = "user1";
			color[] = { "user2", "user3", "user4" };
			condition = "WPvalid * (user11 > 0)";
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
				condition = "user11 > 1";
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
					sourceIndex = 12;
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
					sourceIndex = 13;
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
	};
};
