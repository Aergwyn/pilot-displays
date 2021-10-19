if (!hasInterface) exitWith {};

call APD_fnc_setupHUD;

private _player = player;
_player addEventHandler ["GetInMan", { _this call APD_fnc_handleGetInMan; }];
_player addEventHandler ["GetOutMan", { _this call APD_fnc_handleGetOutMan; }];
_player addEventHandler ["Killed", { _this call APD_fnc_handleKilled; }];
_player addEventHandler ["Respawn", { _this call APD_fnc_handleRespawn; }];

addMissionEventHandler ["Map", { _this call APD_fnc_handleMap; }];
