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
		class Horizon_P90_Bone : Horizon_0_Bone
		{
			angle = 90;
		};
		class Horizon_P75_Bone : Horizon_0_Bone
		{
			angle = 75;
		};
		class Horizon_P60_Bone : Horizon_0_Bone
		{
			angle = 60;
		};
		class Horizon_P45_Bone : Horizon_0_Bone
		{
			angle = 45;
		};
		class Horizon_P30_Bone : Horizon_0_Bone
		{
			angle = 30;
		};
		class Horizon_P15_Bone : Horizon_0_Bone
		{
			angle = 15;
		};
		class Horizon_N15_Bone : Horizon_0_Bone
		{
			angle = -15;
		};
		class Horizon_N30_Bone : Horizon_0_Bone
		{
			angle = -30;
		};
		class Horizon_N45_Bone : Horizon_0_Bone
		{
			angle = -45;
		};
		class Horizon_N60_Bone : Horizon_0_Bone
		{
			angle = -60;
		};
		class Horizon_N75_Bone : Horizon_0_Bone
		{
			angle = -75;
		};
		class Horizon_N90_Bone : Horizon_0_Bone
		{
			angle = -90;
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
			clipBR[] = { 0.97, 0.09 };
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

		#include "hmd_horizon.hpp"

		class Speed_Group
		{
			alpha = "user1";
			color[] = { "user2", "user3", "user4" };
			condition = "user12";
			type = "group";

			#define SIZE 0.025

			class Airspeed
			{
				align = "right";
				scale = 1;
				source = "userText";
				sourceIndex = 13;
				sourceScale = 1;
				type = "text";

				#define X_OFFSET 0.2
				#define Y_OFFSET 0.15

				pos[] = { { 0 + X_OFFSET, 0 + Y_OFFSET }, 1 };
				right[] = { { 0 + X_OFFSET + SIZE, 0 + Y_OFFSET }, 1 };
				down[] = { { 0 + X_OFFSET, 0 + Y_OFFSET + SIZE }, 1 };
			};
			class Vertical_Speed
			{
				align = "right";
				scale = 1;
				source = "vspeed";
				sourceScale = 1;
				type = "text";

				#define X_OFFSET 0.23
				#define Y_OFFSET 0.18

				pos[] = { { 0 + X_OFFSET, 0 + Y_OFFSET }, 1 };
				right[] = { { 0 + X_OFFSET + SIZE, 0 + Y_OFFSET }, 1 };
				down[] = { { 0 + X_OFFSET, 0 + Y_OFFSET + SIZE }, 1 };
			};
			class Vertical_Speed_Text
			{
				align = "right";
				scale = 1;
				source = "static";
				text = "VS";
				type = "text";

				#define X_OFFSET 0.2
				#define Y_OFFSET 0.18

				pos[] = { { 0 + X_OFFSET, 0 + Y_OFFSET }, 1 };
				right[] = { { 0 + X_OFFSET + SIZE, 0 + Y_OFFSET }, 1 };
				down[] = { { 0 + X_OFFSET, 0 + Y_OFFSET + SIZE }, 1 };
			};
		};
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
	};
};
