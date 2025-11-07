disableSerialization;

private _display = findDisplay 35000;
if (isNull _display) exitWith {};

private _list = _display displayCtrl 35001;
private _index = lbCurSel _list;

if (_index < 0) exitWith { hint "❌ Sélectionne un véhicule !"; };

private _class = _list lbData _index;
private _garageIndex = _list lbValue _index;

private _uid = getPlayerUID player;
private _garage = profileNamespace getVariable [format["LEG_Garage_%1", _uid], []];
private _vehData = _garage param [_garageIndex, []];

if (count _vehData == 0) exitWith { hint "❌ Erreur: véhicule introuvable"; };

_vehData params ["_vClass", "_damage", "_fuel", "_inventory", "_plate"];

private _spawnPos = getMarkerPos "civ_garage_1";
private _spawnDir = 90;

if (_spawnPos isEqualTo [0,0,0]) then {
    _spawnPos = player modelToWorld [5, 0, 0];
};

private _veh = createVehicle [_class, _spawnPos, [], 0, "NONE"];
_veh setDir _spawnDir;
_veh setPosATL _spawnPos;
_veh setDamage _damage;
_veh setFuel _fuel;
_veh setVariable ["ownerUID", _uid, true];
_veh setVariable ["plate", _plate, true];
_veh setVehicleLock "LOCKED";

clearWeaponCargoGlobal _veh;
clearMagazineCargoGlobal _veh;
clearItemCargoGlobal _veh;
clearBackpackCargoGlobal _veh;

_garage deleteAt _garageIndex;
profileNamespace setVariable [format["LEG_Garage_%1", _uid], _garage];
saveProfileNamespace;

closeDialog 0;

hint format["🚗 %1 sorti du garage !\n🔒 Véhicule verrouillé (touche U)", 
    getText (configFile >> "CfgVehicles" >> _class >> "displayName")];