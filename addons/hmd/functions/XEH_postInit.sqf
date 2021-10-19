if (!hasInterface) exitWith {};

call APD_fnc_setupHUD;

private _player = player;
_player addEventHandler ["GetInMan", { _this call APD_fnc_onGetInMan; }];
_player addEventHandler ["GetOutMan", { _this call APD_fnc_onGetOutMan; }];
_player addEventHandler ["Killed", { _this call APD_fnc_onKilled; }];
_player addEventHandler ["Respawn", { _this call APD_fnc_onRespawn; }];

addMissionEventHandler ["Map", { _this call APD_fnc_onMap; }];
