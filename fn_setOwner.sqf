params [["_vehicle", objNull, [objNull]], ["_uid", "", [""]]];
if (isNull _vehicle) exitWith { false };
if (_uid == "") then { _uid = getPlayerUID player; };

_vehicle setVariable ["ownerUID", _uid, true];

if (isNil {_vehicle getVariable "plate"}) then {
    private _plate = format["LEG-%1", floor (random 10000)];
    _vehicle setVariable ["plate", _plate, true];
};

true