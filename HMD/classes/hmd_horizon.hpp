class Horizon_Group
{
	clipTL[] = { 0, 0.09 };
	clipBR[] = { 1, 0.91 };
	condition = "user11 * (on + (abs(speed) >= 0.5) + (abs(vspeed) >= 0.5))";
	type = "group";

	#define LINE_GAP 0.025
	#define LINE_WIDTH 0.3

	#define TEXT_SIZE 0.025
	#define TEXT_X_OFFSET -0.003
	#define TEXT_Y_OFFSET -0.001

	class Orientation
	{
		lineType = 0;
		type = "line";
		width = 3;

		#define GAP 0.02
		#define WIDTH 0.12
		#define HEIGHT 0.01

		points[] =
		{
			{ { 0.5 - GAP - (WIDTH / 2), 0.5 }, 1 },
			{ { 0.5 - GAP, 0.5 }, 1 },
			{ { 0.5 - GAP, 0.5 + HEIGHT }, 1 },
			{ },
			{ { 0.5 - 0.002, 0.5 }, 1 },
			{ { 0.5 + 0.002, 0.5 }, 1 },
			{ },
			{ { 0.5, 0.5 - 0.002 }, 1 },
			{ { 0.5, 0.5 + 0.002 }, 1 },
			{ },
			{ { 0.5 + GAP, 0.5 + HEIGHT }, 1 },
			{ { 0.5 + GAP, 0.5 }, 1 },
			{ { 0.5 + GAP + (WIDTH / 2), 0.5 }, 1 },
		};
	};
	class Horizon_0
	{
		lineType = 2;
		type = "line";
		width = 1.5;

		points[] =
		{
			{ "Horizon_0_Bone", { -LINE_WIDTH - LINE_GAP, 0 }, 1 },
			{ "Horizon_0_Bone", { -LINE_GAP, 0 }, 1 },
			{ },
			{ "Horizon_0_Bone", { LINE_GAP, 0 }, 1 },
			{ "Horizon_0_Bone", { LINE_WIDTH + LINE_GAP, 0 }, 1 }
		};
	};
	class Horizon_0_Text
	{
		align = "center";
		scale = 1;
		source = "static";
		text  = "";
		type = "text";

		pos[] = { { 0, 0 }, 1 };
		right[] = { { 0, 0 }, 1 };
		down[] = { { 0, 0 }, 1 };
	};
	class Horizon_P90 : Horizon_0
	{
		points[] =
		{
			{ "Horizon_P90_Bone", { -(LINE_WIDTH / 2) - LINE_GAP, 0 }, 1 },
			{ "Horizon_P90_Bone", { -LINE_GAP, 0 }, 1 },
			{ },
			{ "Horizon_P90_Bone", { LINE_GAP, 0 }, 1 },
			{ "Horizon_P90_Bone", { (LINE_WIDTH / 2) + LINE_GAP, 0 }, 1 }
		};
	};
	class Horizon_P90_Text : Horizon_0_Text
	{
		text  = "90";

		pos[] = { "Horizon_P90_Bone", { TEXT_X_OFFSET, TEXT_Y_OFFSET - (TEXT_SIZE / 2) }, 1 };
		right[] = { "Horizon_P90_Bone", { TEXT_X_OFFSET + TEXT_SIZE, TEXT_Y_OFFSET - (TEXT_SIZE / 2) }, 1 };
		down[] = { "Horizon_P90_Bone", { TEXT_X_OFFSET, TEXT_Y_OFFSET + (TEXT_SIZE / 2) }, 1 };
	};
	class Horizon_P75 : Horizon_0
	{
		points[] =
		{
			{ "Horizon_P75_Bone", { -(LINE_WIDTH / 4), 0 }, 1 },
			{ "Horizon_P75_Bone", { (LINE_WIDTH / 4), 0 }, 1 }
		};
	};
	class Horizon_P60 : Horizon_0
	{
		points[] =
		{
			{ "Horizon_P60_Bone", { -(LINE_WIDTH / 2) - LINE_GAP, 0 }, 1 },
			{ "Horizon_P60_Bone", { -LINE_GAP, 0 }, 1 },
			{ },
			{ "Horizon_P60_Bone", { LINE_GAP, 0 }, 1 },
			{ "Horizon_P60_Bone", { (LINE_WIDTH / 2) + LINE_GAP, 0 }, 1 }
		};
	};
	class Horizon_P60_Text : Horizon_0_Text
	{
		text  = "60";

		pos[] = { "Horizon_P60_Bone", { TEXT_X_OFFSET, TEXT_Y_OFFSET - (TEXT_SIZE / 2) }, 1 };
		right[] = { "Horizon_P60_Bone", { TEXT_X_OFFSET + TEXT_SIZE, TEXT_Y_OFFSET - (TEXT_SIZE / 2) }, 1 };
		down[] = { "Horizon_P60_Bone", { TEXT_X_OFFSET, TEXT_Y_OFFSET + (TEXT_SIZE / 2) }, 1 };
	};
	class Horizon_P45 : Horizon_0
	{
		points[] =
		{
			{ "Horizon_P45_Bone", { -(LINE_WIDTH / 4), 0 }, 1 },
			{ "Horizon_P45_Bone", { (LINE_WIDTH / 4), 0 }, 1 }
		};
	};
	class Horizon_P30 : Horizon_0
	{
		points[] =
		{
			{ "Horizon_P30_Bone", { -(LINE_WIDTH / 2) - LINE_GAP, 0 }, 1 },
			{ "Horizon_P30_Bone", { -LINE_GAP, 0 }, 1 },
			{ },
			{ "Horizon_P30_Bone", { LINE_GAP, 0 }, 1 },
			{ "Horizon_P30_Bone", { (LINE_WIDTH / 2) + LINE_GAP, 0 }, 1 }
		};
	};
	class Horizon_P30_Text : Horizon_0_Text
	{
		text  = "30";

		pos[] = { "Horizon_P30_Bone", { TEXT_X_OFFSET, TEXT_Y_OFFSET - (TEXT_SIZE / 2) }, 1 };
		right[] = { "Horizon_P30_Bone", { TEXT_X_OFFSET + TEXT_SIZE, TEXT_Y_OFFSET - (TEXT_SIZE / 2) }, 1 };
		down[] = { "Horizon_P30_Bone", { TEXT_X_OFFSET, TEXT_Y_OFFSET + (TEXT_SIZE / 2) }, 1 };
	};
	class Horizon_P15 : Horizon_0
	{
		points[] =
		{
			{ "Horizon_P15_Bone", { -(LINE_WIDTH / 4), 0 }, 1 },
			{ "Horizon_P15_Bone", { (LINE_WIDTH / 4), 0 }, 1 }
		};
	};
	class Horizon_N15 : Horizon_0
	{
		points[] =
		{
			{ "Horizon_N15_Bone", { -(LINE_WIDTH / 4), 0 }, 1 },
			{ "Horizon_N15_Bone", { (LINE_WIDTH / 4), 0 }, 1 }
		};
	};
	class Horizon_N30 : Horizon_0
	{
		points[] =
		{
			{ "Horizon_N30_Bone", { -(LINE_WIDTH / 2) - LINE_GAP, 0 }, 1 },
			{ "Horizon_N30_Bone", { -LINE_GAP, 0 }, 1 },
			{ },
			{ "Horizon_N30_Bone", { LINE_GAP, 0 }, 1 },
			{ "Horizon_N30_Bone", { (LINE_WIDTH / 2) + LINE_GAP, 0 }, 1 }
		};
	};
	class Horizon_N30_Text : Horizon_0_Text
	{
		text  = "-30";

		pos[] = { "Horizon_N30_Bone", { TEXT_X_OFFSET, TEXT_Y_OFFSET - (TEXT_SIZE / 2) }, 1 };
		right[] = { "Horizon_N30_Bone", { TEXT_X_OFFSET + TEXT_SIZE, TEXT_Y_OFFSET - (TEXT_SIZE / 2) }, 1 };
		down[] = { "Horizon_N30_Bone", { TEXT_X_OFFSET, TEXT_Y_OFFSET + (TEXT_SIZE / 2) }, 1 };
	};
	class Horizon_N45 : Horizon_0
	{
		points[] =
		{
			{ "Horizon_N45_Bone", { -(LINE_WIDTH / 4), 0 }, 1 },
			{ "Horizon_N45_Bone", { (LINE_WIDTH / 4), 0 }, 1 }
		};
	};
	class Horizon_N60 : Horizon_0
	{
		points[] =
		{
			{ "Horizon_N60_Bone", { -(LINE_WIDTH / 2) - LINE_GAP, 0 }, 1 },
			{ "Horizon_N60_Bone", { -LINE_GAP, 0 }, 1 },
			{ },
			{ "Horizon_N60_Bone", { LINE_GAP, 0 }, 1 },
			{ "Horizon_N60_Bone", { (LINE_WIDTH / 2) + LINE_GAP, 0 }, 1 }
		};
	};
	class Horizon_N60_Text : Horizon_0_Text
	{
		text  = "-60";

		pos[] = { "Horizon_N60_Bone", { TEXT_X_OFFSET, TEXT_Y_OFFSET - (TEXT_SIZE / 2) }, 1 };
		right[] = { "Horizon_N60_Bone", { TEXT_X_OFFSET + TEXT_SIZE, TEXT_Y_OFFSET - (TEXT_SIZE / 2) }, 1 };
		down[] = { "Horizon_N60_Bone", { TEXT_X_OFFSET, TEXT_Y_OFFSET + (TEXT_SIZE / 2) }, 1 };
	};
	class Horizon_N75 : Horizon_0
	{
		points[] =
		{
			{ "Horizon_N75_Bone", { -(LINE_WIDTH / 4), 0 }, 1 },
			{ "Horizon_N75_Bone", { (LINE_WIDTH / 4), 0 }, 1 }
		};
	};
	class Horizon_N90 : Horizon_0
	{
		points[] =
		{
			{ "Horizon_N90_Bone", { -(LINE_WIDTH / 2) - LINE_GAP, 0 }, 1 },
			{ "Horizon_N90_Bone", { -LINE_GAP, 0 }, 1 },
			{ },
			{ "Horizon_N90_Bone", { LINE_GAP, 0 }, 1 },
			{ "Horizon_N90_Bone", { (LINE_WIDTH / 2) + LINE_GAP, 0 }, 1 }
		};
	};
	class Horizon_N90_Text : Horizon_0_Text
	{
		text  = "-90";

		pos[] = { "Horizon_N90_Bone", { TEXT_X_OFFSET, TEXT_Y_OFFSET - (TEXT_SIZE / 2) }, 1 };
		right[] = { "Horizon_N90_Bone", { TEXT_X_OFFSET + TEXT_SIZE, TEXT_Y_OFFSET - (TEXT_SIZE / 2) }, 1 };
		down[] = { "Horizon_N90_Bone", { TEXT_X_OFFSET, TEXT_Y_OFFSET + (TEXT_SIZE / 2) }, 1 };
	};
};
