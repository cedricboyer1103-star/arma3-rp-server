if (!hasInterface) exitWith {};
private _uid = getPlayerUID player;
if (_uid == "") exitWith { [0, 0] };

private _data = profileNamespace getVariable [format["LEG_Money_%1", _uid], []];
if (count _data == 0) exitWith { [5000, 25000] };
_data