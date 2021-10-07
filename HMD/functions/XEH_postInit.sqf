if (!hasInterface) exitWith {};

// TODO remove debug output once events were tested if being loaded in by 3rd party triggers these as well
player addEventHandler ["GetInMan", { systemChat "GetInMan"; call APD_fnc_updateMFDValues; }];
player addEventHandler ["GetOutMan", { systemChat "GetOutMan"; call APD_fnc_evaluateLoops; }];
player addEventHandler ["Killed", { call APD_fnc_evaluateLoops; }];

addMissionEventHandler ["Map", {
	params ["_mapIsOpened", "_mapIsForced"];

	if (!_mapIsOpened && count customWaypointPosition < 1) then
	{
		[false] call APD_fnc_toggleWaypointRender;
	};
}];

addMissionEventHandler ["MapSingleClick", {
	params ["_units", "_pos", "_alt", "_shift"];

	if (_shift) then
	{
		call APD_fnc_evaluateLoops;
	};
}];
