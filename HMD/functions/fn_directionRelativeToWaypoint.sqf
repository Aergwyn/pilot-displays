/*
* This function will calculate an Azimuth (0-360 number) from the player towards given waypoint.
* The passed vector is a direction/movement from which we can determine our own relevant heading.
*/
params [["_waypoint", nil, [[0, 0], [0, 0, 0]]], ["_vector", nil, [[0, 0], [0, 0, 0]]]];

// Calculate the "vector" relative from the player to the waypoint
private _playerPos = getPos player;
private _relPosX = (_waypoint select 0) - (_playerPos select 0);
private _relPosY = (_waypoint select 1) - (_playerPos select 1);
private _relativeToWaypoint = [_relPosX, _relPosY, 0];

private _vectorHeading = [_vector] call APD_fnc_vectorToHeading;
private _waypointHeading = [_relativeToWaypoint] call APD_fnc_vectorToHeading;

private _relativeHeading = _waypointHeading - _vectorHeading;

/*
* WYPT: 270		Vector: 355		=> Relative: - 85
* WYPT:   0		Vector:  90		=> Relative: - 90 [WYPT is ahead but we are moving perpendicular]
* WYPT: 345		Vector: 145		=> Relative:  200
* WYPT: 180		Vector: 180		=> Relative:    0 [WYPT is behind but we are moving backwards]
* WYPT:   5		Vector: 355		=> Relative: -350 [WYPT is slightly right but we are moving slightly left]
*/

if (_relativeHeading < 0) then
{
	_relativeHeading = _relativeHeading + 360;
};

_relativeHeading;
