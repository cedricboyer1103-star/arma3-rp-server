params [["_amount", 0, [0]], ["_type", "cash", [""]]];
if (_amount <= 0) exitWith { false };

private _current = player getVariable [_type, 0];
private _new = _current + _amount;
player setVariable [_type, _new, true];

private _icon = if (_type == "cash") then {"💵"} else {"🏦"};
hint format["%1 +%2€", _icon, _amount];

[] call LEG_fnc_saveMoney;
true