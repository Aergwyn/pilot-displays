class Horizon_Group
{
	clipTL[] = { 0, 0.085 };
	clipBR[] = { 1, 0.915 };
	condition = "(user15 > 0) * (on + (abs(speed) >= 0.5) + (abs(vspeed) >= 0.5))";
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

	#define CREATE_SHORT_LINE_CLASS(CLASS)\
		class CLASS : Horizon_0\
		{\
			points[] =\
			{\
				{ CLASS##_Bone, { -(LINE_WIDTH / 4), 0 }, 1 },\
				{ CLASS##_Bone, { (LINE_WIDTH / 4), 0 }, 1 }\
			};\
		}

	#define CREATE_LONG_LINE_CLASS_WITH_TEXT(CLASS, TEXT)\
		class CLASS : Horizon_0\
		{\
			points[] =\
			{\
				{ CLASS##_Bone, { -(LINE_WIDTH / 2) - LINE_GAP, 0 }, 1 },\
				{ CLASS##_Bone, { -LINE_GAP, 0 }, 1 },\
				{ },\
				{ CLASS##_Bone, { LINE_GAP, 0 }, 1 },\
				{ CLASS##_Bone, { (LINE_WIDTH / 2) + LINE_GAP, 0 }, 1 }\
			};\
		};\
		class CLASS##_Text : Horizon_0_Text\
		{\
			text = TEXT;\
			\
			pos[] = { CLASS##_Bone, { TEXT_X_OFFSET, TEXT_Y_OFFSET - (TEXT_SIZE / 2) }, 1 };\
			right[] = { CLASS##_Bone, { TEXT_X_OFFSET + TEXT_SIZE, TEXT_Y_OFFSET - (TEXT_SIZE / 2) }, 1 };\
			down[] = { CLASS##_Bone, { TEXT_X_OFFSET, TEXT_Y_OFFSET + (TEXT_SIZE / 2) }, 1 };\
		}

	class Horizon_10_Degree_Group
	{
		condition = "(user15 > 1) * (user15 < 3)";
		type = "group";

		CREATE_SHORT_LINE_CLASS(Horizon_P80);
		CREATE_SHORT_LINE_CLASS(Horizon_P70);
		CREATE_SHORT_LINE_CLASS(Horizon_P50);
		CREATE_SHORT_LINE_CLASS(Horizon_P40);
		CREATE_SHORT_LINE_CLASS(Horizon_P20);
		CREATE_SHORT_LINE_CLASS(Horizon_P10);
		CREATE_SHORT_LINE_CLASS(Horizon_N10);
		CREATE_SHORT_LINE_CLASS(Horizon_N20);
		CREATE_SHORT_LINE_CLASS(Horizon_N40);
		CREATE_SHORT_LINE_CLASS(Horizon_N50);
		CREATE_SHORT_LINE_CLASS(Horizon_N70);
		CREATE_SHORT_LINE_CLASS(Horizon_N80);
	};
	class Horizon_15_Degree_Group
	{
		condition = "(user15 > 2) * (user15 < 4)";
		type = "group";

		CREATE_SHORT_LINE_CLASS(Horizon_P75);
		CREATE_SHORT_LINE_CLASS(Horizon_P45);
		CREATE_SHORT_LINE_CLASS(Horizon_P15);
		CREATE_SHORT_LINE_CLASS(Horizon_N15);
		CREATE_SHORT_LINE_CLASS(Horizon_N45);
		CREATE_SHORT_LINE_CLASS(Horizon_N75);
	};
	class Horizon_30_Degree_Group
	{
		condition = "user15 > 1";
		type = "group";

		CREATE_LONG_LINE_CLASS_WITH_TEXT(Horizon_P90, 90);
		CREATE_LONG_LINE_CLASS_WITH_TEXT(Horizon_P60, 60);
		CREATE_LONG_LINE_CLASS_WITH_TEXT(Horizon_P30, 30);
		CREATE_LONG_LINE_CLASS_WITH_TEXT(Horizon_N30, -30);
		CREATE_LONG_LINE_CLASS_WITH_TEXT(Horizon_N60, -60);
		CREATE_LONG_LINE_CLASS_WITH_TEXT(Horizon_N90, -90);
	};
};
