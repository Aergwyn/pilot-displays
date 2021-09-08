if (!hasInterface) exitWith {};

player onMapSingleClick { [_shift] call APD_fnc_onMapClick; };

// TODO remove debug output once events were tested if being loaded in by 3rd party triggers these as well
player addEventHandler ["GetInMan", { systemChat "GetInMan"; call APD_fnc_updateMFDValues; }];
player addEventHandler ["GetOutMan", { systemChat "GetOutMan"; call APD_fnc_evaluateWaypointLoop; }];
player addEventHandler ["Killed", { call APD_fnc_evaluateWaypointLoop; }];
