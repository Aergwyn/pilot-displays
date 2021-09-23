class APD_HMD_Base
{
	alpha = 0;
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

	class Material
	{
		ambient[] = { 1, 1, 1, 1 };
		diffuse[] = { 0, 0, 0, 0 };
		emissive[] = { 0, 0, 0, 0 };
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
		class Horizon_P80_Bone : Horizon_0_Bone
		{
			angle = 80;
		};
		class Horizon_P75_Bone : Horizon_0_Bone
		{
			angle = 75;
		};
		class Horizon_P70_Bone : Horizon_0_Bone
		{
			angle = 70;
		};
		class Horizon_P60_Bone : Horizon_0_Bone
		{
			angle = 60;
		};
		class Horizon_P50_Bone : Horizon_0_Bone
		{
			angle = 50;
		};
		class Horizon_P45_Bone : Horizon_0_Bone
		{
			angle = 45;
		};
		class Horizon_P40_Bone : Horizon_0_Bone
		{
			angle = 40;
		};
		class Horizon_P30_Bone : Horizon_0_Bone
		{
			angle = 30;
		};
		class Horizon_P20_Bone : Horizon_0_Bone
		{
			angle = 20;
		};
		class Horizon_P15_Bone : Horizon_0_Bone
		{
			angle = 15;
		};
		class Horizon_P10_Bone : Horizon_0_Bone
		{
			angle = 10;
		};
		class Horizon_N10_Bone : Horizon_0_Bone
		{
			angle = -10;
		};
		class Horizon_N15_Bone : Horizon_0_Bone
		{
			angle = -15;
		};
		class Horizon_N20_Bone : Horizon_0_Bone
		{
			angle = -20;
		};
		class Horizon_N30_Bone : Horizon_0_Bone
		{
			angle = -30;
		};
		class Horizon_N40_Bone : Horizon_0_Bone
		{
			angle = -40;
		};
		class Horizon_N45_Bone : Horizon_0_Bone
		{
			angle = -45;
		};
		class Horizon_N50_Bone : Horizon_0_Bone
		{
			angle = -50;
		};
		class Horizon_N60_Bone : Horizon_0_Bone
		{
			angle = -60;
		};
		class Horizon_N70_Bone : Horizon_0_Bone
		{
			angle = -70;
		};
		class Horizon_N75_Bone : Horizon_0_Bone
		{
			angle = -75;
		};
		class Horizon_N80_Bone : Horizon_0_Bone
		{
			angle = -80;
		};
		class Horizon_N90_Bone : Horizon_0_Bone
		{
			angle = -90;
		};
	};
	class Draw
	{
		condition = "user0";

		class HMD_Content
		{
			alpha = "user4";
			color[] = { "user1", "user2", "user3" };

			#include "hmd/hmd_compass.hpp"
			#include "hmd/hmd_horizon.hpp"
			#include "hmd/hmd_waypoint.hpp"

			class Speed_Group
			{
				condition = "user25";
				type = "group";

				#define SIZE 0.025

				class Airspeed
				{
					align = "right";
					scale = 1;
					source = "userText";
					sourceIndex = 26;
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
		};
	};
};
