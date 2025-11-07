/*
    ═══════════════════════════════════════════════════════════════
    📱 init.sqf - Legion RP Malden - VERSION GUI
    ═══════════════════════════════════════════════════════════════
    Dernière mise à jour : 2025-11-07 09:06:58
    Auteur : cedricboyer1103-star
    Initialisation serveur
    ✅ Compatible avec le nouveau système Orange GUI
    ═══════════════════════════════════════════════════════════════
*/

if (!isServer) exitWith {};

// Logs d'initialisation
diag_log "═══════════════════════════════════════════════";
diag_log "🖥️ Legion RP - Initialisation serveur...";
diag_log format["📅 Date: %1", date];
diag_log format["🌍 Mission: %1", missionName];
diag_log "═══════════════════════════════════════════════";

// ═══════════════════════════════════════════════════════════════
// ✅ CONFIGURATION ORANGE - NOUVEAU SYSTÈME GUI
// ═══════════════════════════════════════════════════════════════

[] spawn {
    sleep 5;
    
    // Vérification du PNJ Orange
    if (!isNil "orange_vendor") then {
        if (alive orange_vendor) then {
            diag_log format["✅ PNJ Orange trouvé et valide: %1", orange_vendor];
            diag_log format["📍 Position: %1", getPos orange_vendor];
            
            // Variables serveur Orange
            missionNamespace setVariable ["orange_vendor_ready", true, true];
            diag_log "✅ Variables Orange initialisées sur le serveur";
        } else {
            diag_log "⚠️ PNJ Orange trouvé mais non valide!";
        };
    } else {
        diag_log "⚠️ Aucun PNJ 'orange_vendor' trouvé";
        diag_log "💡 Vérifiez que le PNJ a bien l'init configuré dans l'éditeur";
    };
    
    // Vérification des scripts The-Programmer
    if (isNil "theprogrammer_core_fnc_clientInit") then {
        diag_log "⚠️ ERREUR: Core The-Programmer non trouvé!";
    } else {
        diag_log "✅ Core The-Programmer détecté";
    };
};

// ═══════════════════════════════════════════════════════════════
// 🌍 PARAMÈTRES SERVEUR
// ═══════════════════════════════════════════════════════════════

[] spawn {
    // Paramètres de mission
    private _dayLength = ["DayLength", 4] call BIS_fnc_getParamValue;
    private _startMoney = ["StartingMoney", 5000] call BIS_fnc_getParamValue;
    
    diag_log format["📊 Paramètres serveur:"];
    diag_log format["- Durée jour: %1h", _dayLength];
    diag_log format["- Argent initial: %1€", _startMoney];
    
    // Publication des variables
    missionNamespace setVariable ["server_dayLength", _dayLength, true];
    missionNamespace setVariable ["server_startMoney", _startMoney, true];
};

// ═══════════════════════════════════════════════════════════════
// ✅ FIN INITIALISATION
// ═══════════════════════════════════════════════════════════════

[] spawn {
    sleep 10;
    diag_log "═══════════════════════════════════════════════";
    diag_log "✅ Serveur Legion RP initialisé avec succès!";
    diag_log "═══════════════════════════════════════════════";
};

// Publication de la version serveur
missionNamespace setVariable ["server_version", "1.0.0", true];