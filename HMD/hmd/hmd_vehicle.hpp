class Vehicle_Stat_Group
{
	condition = "user25";
	type = "group";

	#define X_OFFSET -0.25
	#define Y_OFFSET -0.2
	#define X_ALIGNMENT 1
	#define Y_ALIGNMENT 0.5
	#define TEXT_SIZE 0.02

	class Airspeed
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
	class Altitude_Ground
	{
		align = "right";
		scale = 1;
		source = "altitudeAGL";
		sourceScale = 1;
		type = "text";

		pos[] = { { X_ALIGNMENT + X_OFFSET, Y_ALIGNMENT + Y_OFFSET + TEXT_SIZE }, 1 };
		right[] = { { X_ALIGNMENT + X_OFFSET + TEXT_SIZE, Y_ALIGNMENT + Y_OFFSET + TEXT_SIZE }, 1 };
		down[] = { { X_ALIGNMENT + X_OFFSET, Y_ALIGNMENT + Y_OFFSET + (TEXT_SIZE * 2) }, 1 };
	};
	class Altitude_Sea
	{
		align = "right";
		scale = 1;
		source = "altitudeASL";
		sourceScale = 1;
		type = "text";

		pos[] = { { X_ALIGNMENT + X_OFFSET, Y_ALIGNMENT + Y_OFFSET + (TEXT_SIZE * 2) }, 1 };
		right[] = { { X_ALIGNMENT + X_OFFSET + TEXT_SIZE, Y_ALIGNMENT + Y_OFFSET + (TEXT_SIZE * 2) }, 1 };
		down[] = { { X_ALIGNMENT + X_OFFSET, Y_ALIGNMENT + Y_OFFSET + (TEXT_SIZE * 3) }, 1 };
	};
};
