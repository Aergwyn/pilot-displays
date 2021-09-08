class APD_HMD_Base
{
	#define HMD_WIDTH 0.06
	#define HMD_HEIGHT 0.04

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
		class Waypoint_To_View_Bone
		{
			#define X_OFFSET 0.1214
			#define Y_OFFSET 0.1725

			type = "vector";
			source = "wppointtoview";
			pos0[] = { 0.5, 0.5 };
			pos10[] = { 0.5 + X_OFFSET, 0.5 + Y_OFFSET };
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

				pos[] = { -0.0027, 0.018 };
				right[] = { 0.0273, 0.018 };
				down[] = { -0.0027, 0.048 };
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
				#define SIZE 0.03
				#define X_OFFSET -0.003
				#define Y_OFFSET 0.054

				align = "center";
				refreshRate = 0;
				scale = 1;
				source = "heading";
				sourceLength = 3;
				sourceScale = 1;
				type = "text";

				pos[] = { { 0.5 + X_OFFSET, 0 + Y_OFFSET }, 1 };
				right[] = { { 0.5 + X_OFFSET + SIZE, 0 + Y_OFFSET }, 1 };
				down[] = { { 0.5 + X_OFFSET, 0 + Y_OFFSET + SIZE }, 1 };
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
				#define SIZE 0.025

				type = "line";
				width = 2;

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
					#define SIZE 0.025
					#define X_OFFSET -0.2
					#define Y_OFFSET -0.13

					align = "right";
					scale = 1;
					source = "static";
					text  = "WYPT";
					type = "text";

					pos[] = { { 1 + X_OFFSET, 1 + Y_OFFSET }, 1 };
					right[] = { { 1 + X_OFFSET + SIZE, 1 + Y_OFFSET }, 1 };
					down[] = { { 1 + X_OFFSET, 1 + Y_OFFSET + SIZE }, 1 };
				};
				class Waypoint_Distance
				{
					#define SIZE 0.025
					#define X_OFFSET -0.2
					#define Y_OFFSET -0.1

					align = "right";
					scale = 1;
					source = "userText";
					sourceIndex = 12;
					sourceScale = 1;
					type = "text";

					pos[] = { { 1 + X_OFFSET, 1 + Y_OFFSET }, 1 };
					right[] = { { 1 + X_OFFSET + SIZE, 1 + Y_OFFSET }, 1 };
					down[] = { { 1 + X_OFFSET, 1 + Y_OFFSET + SIZE }, 1 };
				};
				class Waypoint_ETA
				{
					#define SIZE 0.025
					#define X_OFFSET -0.2
					#define Y_OFFSET -0.07

					align = "right";
					scale = 1;
					source = "userText";
					sourceIndex = 13;
					sourceScale = 1;
					type = "text";

					pos[] = { { 1 + X_OFFSET, 1 + Y_OFFSET }, 1 };
					right[] = { { 1 + X_OFFSET + SIZE, 1 + Y_OFFSET }, 1 };
					down[] = { { 1 + X_OFFSET, 1 + Y_OFFSET + SIZE }, 1 };
				};
			};
		};
	};
};
