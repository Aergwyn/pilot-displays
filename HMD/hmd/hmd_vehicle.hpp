class Vehicle_Stat_Group
{
	condition = "user25";
	type = "group";

	#define X_OFFSET -0.25
	#define Y_OFFSET -0.2
	#define X_ALIGNMENT 1
	#define Y_ALIGNMENT 0.5
	#define TEXT_SIZE 0.02

	class Above_Ground_Level
	{
		align = "right";
		scale = 1;
		source = "userText";
		sourceIndex = 26;
		sourceScale = 1;
		type = "text";

		pos[] = { { X_ALIGNMENT + X_OFFSET, Y_ALIGNMENT + Y_OFFSET }, 1 };
		right[] = { { X_ALIGNMENT + X_OFFSET + TEXT_SIZE, Y_ALIGNMENT + Y_OFFSET }, 1 };
		down[] = { { X_ALIGNMENT + X_OFFSET, Y_ALIGNMENT + Y_OFFSET + TEXT_SIZE }, 1 };
	};
	class Mean_Sea_Level
	{
		align = "right";
		scale = 1;
		source = "userText";
		sourceIndex = 27;
		sourceScale = 1;
		type = "text";

		pos[] = { { X_ALIGNMENT + X_OFFSET, Y_ALIGNMENT + Y_OFFSET + TEXT_SIZE }, 1 };
		right[] = { { X_ALIGNMENT + X_OFFSET + TEXT_SIZE, Y_ALIGNMENT + Y_OFFSET + TEXT_SIZE }, 1 };
		down[] = { { X_ALIGNMENT + X_OFFSET, Y_ALIGNMENT + Y_OFFSET + (TEXT_SIZE * 2) }, 1 };
	};
	class Speed
	{
		align = "right";
		scale = 1;
		source = "userText";
		sourceIndex = 28;
		sourceScale = 1;
		type = "text";

		pos[] = { { X_ALIGNMENT + X_OFFSET, Y_ALIGNMENT + Y_OFFSET + (TEXT_SIZE * 2) }, 1 };
		right[] = { { X_ALIGNMENT + X_OFFSET + TEXT_SIZE, Y_ALIGNMENT + Y_OFFSET + (TEXT_SIZE * 2) }, 1 };
		down[] = { { X_ALIGNMENT + X_OFFSET, Y_ALIGNMENT + Y_OFFSET + (TEXT_SIZE * 3) }, 1 };
	};
};
