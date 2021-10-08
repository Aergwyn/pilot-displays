/*
* This function will convert a vector (direction/movement) into a heading.
*/
if (!hasInterface) exitWith {};

params [["_vector", nil, [[0, 0], [0, 0, 0]]]];
_vector params ["_x", "_y"];

if (_y != 0) then
{
	if (_y > 0) then
	{
		if (_x >= 0) then
		{
			atan (_x / _y);
		}
		else
		{
			360 + atan (_x / _y);
		};
	}
	else
	{
		180 + atan (_x / _y);
	};
}
else
{
	if (_x > 0) then
	{
		90;
	}
	else
	{
		if (_x < 0) then
		{
			270;
		}
		else
		{
			0;
		};
	};
};
