/*
    ═══════════════════════════════════════════════════════════════
    📱 initPlayerLocal.sqf - Legion RP Malden - VERSION GUI
    ═══════════════════════════════════════════════════════════════
    Dernière mise à jour : 2025-11-07 09:05:38
    Auteur : cedricboyer1103-star
    ═══════════════════════════════════════════════════════════════
*/

if (!hasInterface) exitWith {};

// Attendre que le joueur soit prêt
waitUntil {!isNull player};
waitUntil {player == player};

// Initialisation The-Programmer en premier
[] spawn {
    if (isNil "theprogrammer_core_fnc_clientInit") then {
        systemChat "⚠️ ERREUR: Core The-Programmer non trouvé!";
        diag_log "ERROR: theprogrammer_core_fnc_clientInit not found!";
    } else {
        [] spawn theprogrammer_core_fnc_clientInit;
    };
};

systemChat "═══════════════════════════════════════════════";
systemChat "📱 Legion RP - Initialisation...";
systemChat "═══════════════════════════════════════════════";

// ═══════════════════════════════════════════════════════════════
// 💰 INITIALISATION SYSTÈME ÉCONOMIE
// ═══════════════════════════════════════════════════════════════

[] spawn {
    // Initialiser l'argent du joueur avec le paramètre de mission
    private _startMoney = ["StartingMoney", 5000] call BIS_fnc_getParamValue;
    
    if (isNil {player getVariable "cash"}) then {
        player setVariable ["cash", _startMoney, true];
        systemChat format["💰 Argent initialisé : %1€", _startMoney];
    };
    
    if (isNil {player getVariable "bank"}) then {
        player setVariable ["bank", 0, true];
        systemChat "🏦 Compte bancaire initialisé";
    };
    
    // Synchronisation avec le système The-Programmer
    if (isNil "life_cash") then {
        life_cash = player getVariable ["cash", _startMoney];
        publicVariable "life_cash";
    };

    // Vérification des variables économiques
    if (isNil "life_cash" || isNil "life_atm") then {
        systemChat "⚠️ ERREUR: Variables économiques non initialisées!";
        diag_log "ERROR: Economy variables not initialized!";
    } else {
        systemChat format["💰 Système économique initialisé - Argent: %1€", life_cash];
    };
};

// ═══════════════════════════════════════════════════════════════
// 🔶 INITIALISATION SYSTÈME ORANGE
// ═══════════════════════════════════════════════════════════════

[] spawn {
    sleep 1;
    
    // Variables locales
    private _vars = [
        ["orange_hasSIM", false],
        ["orange_plan", ""],
        ["orange_planExpiry", 0]
    ];
    
    {
        _x params ["_var", "_default"];
        if (isNil {player getVariable _var}) then {
            player setVariable [_var, _default, true];
        };
    } forEach _vars;
    
    // Variables globales
    if (isNil "orange_player_hasSIM") then {
        orange_player_hasSIM = player getVariable ["orange_hasSIM", false];
    };
    
    if (isNil "orange_player_forfait") then {
        orange_player_forfait = player getVariable ["orange_plan", ""];
    };
    
    if (isNil "orange_forfait_expiration") then {
        orange_forfait_expiration = player getVariable ["orange_planExpiry", 0];
    };
    
    // Vérification de l'expiration
    [] spawn {
        while {true} do {
            sleep 1800; // Vérifier toutes les 30 minutes
            
            private _plan = player getVariable ["orange_plan", ""];
            private _expiry = player getVariable ["orange_planExpiry", 0];
            
            if (_plan != "" && _expiry > 0) then {
                if (serverTime >= _expiry) then {
                    player setVariable ["orange_plan", "", true];
                    player setVariable ["orange_planExpiry", 0, true];
                    orange_player_forfait = "";
                    orange_forfait_expiration = 0;
                    
                    hint parseText 
                        "<t size='1.2' color='#FF3B30'>📵 FORFAIT EXPIRÉ</t><br/><br/>" +
                        "<t size='0.9'>Votre forfait Orange a expiré</t><br/><br/>" +
                        "<t size='0.85' color='#FF8800'>Rendez-vous chez Orange pour le renouveler</t>";
                    
                    systemChat "📱 Orange : Forfait expiré";
                };
            };
        };
    };
    
    systemChat "🔶 Système Orange chargé";
};

// ═══════════════════════════════════════════════════════════════
// 📱 INITIALISATION SYSTÈME iPHONE 3D
// ═══════════════════════════════════════════════════════════════

[] spawn {
    sleep 2;
    
    // Vérification des fonctions iPhone
    if (isNil "LEG_fnc_usePhone3D" || isNil "LEG_fnc_storePhone3D") then {
        systemChat "⚠️ ERREUR: Fonctions iPhone non trouvées!";
        diag_log "ERROR: iPhone functions not found!";
    } else {
        // Ajout de l'iPhone
        for "_i" from 1 to 3 do {
            if (!("LEG_iPhone_3D" in (items player))) then {
                player addItem "LEG_iPhone_3D";
            };
        };
        
        systemChat "📱 iPhone XI ajouté à votre inventaire";
        
        sleep 1;
        hint parseText 
            "<t size='1.2' color='#00D9FF'>📱 iPhone XI</t><br/><br/>" +
            "<t size='0.9'>Votre iPhone est dans votre inventaire</t><br/><br/>" +
            "<t size='0.8' color='#999'>━━━━━━━━━━━━━━━━</t><br/>" +
            "<t size='0.85' color='#FF8800'>🔶 Rendez-vous chez Orange</t><br/>" +
            "<t size='0.75' color='#666'>Achetez une carte SIM (50€) et<br/>souscrivez à un forfait pour activer<br/>votre téléphone</t><br/><br/>" +
            "<t size='0.7' color='#4A90E2'>💡 Appuyez sur Y pour sortir le téléphone</t>";
    };
};

// [Le reste de votre code reste identique, incluant les keybinds, actions, notifications, etc.]

// ═══════════════════════════════════════════════════════════════
// 🎮 EVENT HANDLERS
// ═══════════════════════════════════════════════════════════════

player addEventHandler ["Respawn", {
    params ["_unit", "_corpse"];
    
    // Réinitialiser le téléphone 3D
    if (_unit getVariable ["LEG_phone3D_active", false]) then {
        if (!isNil "LEG_fnc_storePhone3D") then {
            [_unit] call LEG_fnc_storePhone3D;
        };
    };
    
    // Réajouter l'iPhone
    for "_i" from 1 to 3 do {
        if (!("LEG_iPhone_3D" in (items _unit))) then {
            _unit addItem "LEG_iPhone_3D";
        };
    };
}];

player addEventHandler ["Killed", {
    params ["_unit", "_killer"];
    
    if (_unit getVariable ["LEG_phone3D_active", false]) then {
        if (!isNil "LEG_fnc_storePhone3D") then {
            [_unit] call LEG_fnc_storePhone3D;
        };
    };
}];

// ═══════════════════════════════════════════════════════════════
// ✅ INITIALISATION TERMINÉE
// ═══════════════════════════════════════════════════════════════

[] spawn {
    sleep 5;
    systemChat "═══════════════════════════════════════════════";
    systemChat "✅ Initialisation terminée !";
    systemChat "═══════════════════════════════════════════════";
};

// ═══════════════════════════════════════════════════════════════
// 🐛 DEBUG
// ═══════════════════════════════════════════════════════════════

if (true) then {
    [] spawn {
        sleep 10;
        diag_log format["[Legion RP] %1 - Initialisation terminée", name player];
        diag_log format["[Legion RP] Variables: cash=%1€ | orange_sim=%2 | orange_plan=%3", 
            life_cash, 
            orange_player_hasSIM, 
            orange_player_forfait
        ];
    };
};