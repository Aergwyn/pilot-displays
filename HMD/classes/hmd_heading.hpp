class Heading_Group
{
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
