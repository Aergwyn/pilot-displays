class Heading_Group
{
	clipTL[] = { 0.025, 0.1 };
	clipBR[] = { 0.975, 0.3 };
	condition = "user10";
	type="group";

	class Heading_Scale
	{
		align = "center";
		horizontal = 1;
		majorLineEach = 2;
		NeverEatSeaWeed = 1;
		numberEach = 6;
		scale = 1;
		source = "heading";
		sourceLength = 3;
		sourceScale = 1;
		step = 15;
		stepSize = 0.04;
		type = "scale";

		top = 0;
		bottom = 1;
		center = 0.5;

		width = 1.5;
		lineXleft = 0.172;
		lineYright = 0.19;
		lineXleftMajor = 0.18;
		lineYrightMajor = 0.19;

		#define SIZE 0.025
		#define X_OFFSET -0.002
		#define Y_OFFSET 0.158

		pos[] = { 0 + X_OFFSET, 0 + Y_OFFSET };
		right[] = { 0 + X_OFFSET + SIZE, 0 + Y_OFFSET };
		down[] = { 0 + X_OFFSET, 0 + Y_OFFSET + SIZE };
	};
	class Heading_Index
	{
		lineType = 0;
		type = "line";
		width = 1.5;

		#define WIDTH 0.042
		#define HEIGHT 0.014
		#define X_OFFSET 0.5
		#define Y_OFFSET 0.2

		points[] =
		{
			{ { X_OFFSET, Y_OFFSET - (HEIGHT / 2) }, 1 },
			{ { X_OFFSET, Y_OFFSET }, 1 },
			{ },
			{ { X_OFFSET - (WIDTH / 2), Y_OFFSET + (HEIGHT / 2) }, 1 },
			{ { X_OFFSET - (WIDTH / 2), Y_OFFSET }, 1 },
			{ { X_OFFSET + (WIDTH / 2), Y_OFFSET }, 1 },
			{ { X_OFFSET + (WIDTH / 2), Y_OFFSET + (HEIGHT / 2) }, 1 }
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

		#define SIZE 0.025
		#define X_OFFSET -0.0022
		#define Y_OFFSET 0.198

		pos[] = { { 0.5 + X_OFFSET, 0 + Y_OFFSET }, 1 };
		right[] = { { 0.5 + X_OFFSET + SIZE, 0 + Y_OFFSET }, 1 };
		down[] = { { 0.5 + X_OFFSET, 0 + Y_OFFSET + SIZE }, 1 };
	};
};
