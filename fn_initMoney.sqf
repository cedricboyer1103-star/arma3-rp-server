if (!hasInterface) exitWith {};
params [["_resetMoney", false, [false]]];

private _uid = getPlayerUID player;
if (_uid == "") exitWith { hint "❌ UID vide"; };

private _savedData = profileNamespace getVariable [format["LEG_Money_%1", _uid], []];
private _cash = 0;
private _bank = 0;

if (_resetMoney || {count _savedData == 0}) then {
    _cash = 5000;
    _bank = 25000;
    hint format["🎉 Bienvenue !\n💵 %1€ de départ", _cash + _bank];
} else {
    _cash = _savedData param [0, 5000];
    _bank = _savedData param [1, 25000];
    hint format["💰 Argent chargé\n💵 Liquide: %1€\n🏦 Banque: %2€", _cash, _bank];
};

player setVariable ["cash", _cash, true];
player setVariable ["bank", _bank, true];

[] spawn {
    while {alive player} do {
        sleep 300;
        [] call LEG_fnc_saveMoney;
    };
};

diag_log format["[ECONOMY] %1 : %2€ liquide, %3€ banque", name player, _cash, _bank];
true