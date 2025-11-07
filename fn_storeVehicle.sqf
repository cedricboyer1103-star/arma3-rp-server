private _veh = vehicle player;

if (_veh isEqualTo player) then {
    _veh = cursorObject;
    if (isNull _veh || !(_veh isKindOf "AllVehicles")) then {
        _veh = (nearestObjects [player, ["Car","Tank","Air","Ship"], 10]) param [0, objNull];
    };
};

if (isNull _veh || {_veh isEqualTo player}) exitWith {
    hint "❌ Aucun véhicule à proximité";
};

private _owner = _veh getVariable ["ownerUID", ""];
private _uid = getPlayerUID player;

if (_owner != _uid) exitWith {
    hint "❌ Ce véhicule ne t'appartient pas !";
};

private _class = typeOf _veh;
private _damage = damage _veh;
private _fuel = fuel _veh;
private _plate = _veh getVariable ["plate", format["LEG-%1", floor (random 9999)]];
private _inventory = [];

private _garage = profileNamespace getVariable [format["LEG_Garage_%1", _uid], []];
_garage pushBack [_class, _damage, _fuel, _inventory, _plate];

profileNamespace setVariable [format["LEG_Garage_%1", _uid], _garage];
saveProfileNamespace;

deleteVehicle _veh;

hint format["✅ Véhicule rangé\n💾 %1 véhicule(s) au garage", count _garage];
