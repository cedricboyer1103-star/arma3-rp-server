if (!hasInterface) exitWith {};
private _uid = getPlayerUID player;
if (_uid == "") exitWith { false };

private _cash = player getVariable ["cash", 0];
private _bank = player getVariable ["bank", 0];

profileNamespace setVariable [format["LEG_Money_%1", _uid], [_cash, _bank]];
saveProfileNamespace;

diag_log format["[ECONOMY] Sauvegarde : %1€ liquide, %2€ banque", _cash, _bank];
true