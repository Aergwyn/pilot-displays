/*
* This function will convert a vector (direction/movement) into a heading.
*/
if (!hasInterface) exitWith {};

params [["_vector", nil, [[[0]]], [2, 3]]];
_vector params ["_x", "_y"];

_x atan2 _y;
