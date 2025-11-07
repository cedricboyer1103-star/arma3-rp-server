/*
    spawnVehicle.sqf — Création du véhicule depuis le garage
*/

params ["_class"];

// Position de spawn (marqueur ou à côté du joueur)
private _pos = getMarkerPos "civ_garage_1";
if (_pos isEqualTo [0,0,0]) then { _pos = player modelToWorld [3,3,0]; };

// Création du véhicule
private _veh = createVehicle [_class, _pos, [], 0, "NONE"];
_veh setDir (getDir player);
_veh setPosATL _pos;

// ✅ Définir le propriétaire et verrouiller par défaut
_veh setVariable ["ownerUID", getPlayerUID player, true];  // Définit le propriétaire
_veh setVehicleLock "LOCKED";                              // Véhicule verrouillé à la sortie


// Feedback visuel
hint format ["🚗 %1 sorti du garage (véhicule verrouillé).", getText(configFile >> "CfgVehicles" >> _class >> "displayName")];

