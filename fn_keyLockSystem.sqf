if (!hasInterface) exitWith {};
waitUntil { !isNull findDisplay 46 };

if (!isNil "LEG_keyEH") then {
    (findDisplay 46) displayRemoveEventHandler ["KeyDown", LEG_keyEH];
};

LEG_keyEH = (findDisplay 46) displayAddEventHandler ["KeyDown", {
    params ["_display", "_key", "_shift", "_ctrl", "_alt"];
    if (_key != 0x16) exitWith { false };
    
    private _veh = cursorObject;
    if (isNull _veh || !(_veh isKindOf "AllVehicles")) then {
        _veh = vehicle player;
        if (_veh isEqualTo player) then {
            private _near = nearestObjects [player, ["Car","Tank","Air","Ship"], 10];
            if (count _near > 0) then { _veh = _near select 0; };
        };
    };
    
    if (isNull _veh || {_veh isEqualTo player}) exitWith {
        hint "❌ Aucun véhicule";
        false
    };
    
    private _owner = _veh getVariable ["ownerUID", ""];
    private _myUID = getPlayerUID player;
    
    if (_owner == "") then {
        _veh setVariable ["ownerUID", _myUID, true];
        _owner = _myUID;
        hint "✅ Véhicule revendiqué";
    };
    
    if (_owner != _myUID) exitWith {
        hint "🔒 Pas ton véhicule";
        true
    };
    
    private _locked = locked _veh > 1;
    if (_locked) then {
        _veh setVehicleLock "UNLOCKED";
        hint "🔓 Déverrouillé";
    } else {
        _veh setVehicleLock "LOCKED";
        hint "🔒 Verrouillé";
    };
    
    [_veh] spawn {
        params ["_v"];
        if (!isNull _v) then {
            _v setPilotLight true;
            sleep 0.3;
            _v setPilotLight false;
        };
    };
    true
}];

diag_log "[VEHICLE] ✅ Système clé activé";
