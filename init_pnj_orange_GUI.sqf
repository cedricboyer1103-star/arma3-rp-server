/*
    Script d'Initialisation PNJ Orange - Version GUI
    Configure le PNJ avec l'interface graphique
*/

if (!isServer) exitWith {};

params [["_pnj", objNull]];

if (isNull _pnj) exitWith {
    diag_log "[ORANGE] Erreur: PNJ null !";
};

// ============================================================================
// CONFIGURATION DU PNJ
// ============================================================================

_pnj allowDamage false;
_pnj setCaptive true;
_pnj disableAI "MOVE";
_pnj disableAI "AUTOTARGET";
_pnj disableAI "TARGET";
_pnj switchMove "";
_pnj playMoveNow "AmovPercMstpSnonWnonDnon";

if (isNil {_pnj getVariable "pnj_name"}) then {
    _pnj setVariable ["pnj_name", "Vendeur Orange", true];
};

// ============================================================================
// AJOUTER L'ACTION BOUTIQUE (GUI)
// ============================================================================

removeAllActions _pnj;

_pnj addAction [
    "<t color='#FF6600' size='1.2'>📱 Boutique Orange</t>",
    "core\orange\fn_openOrangeShop_GUI.sqf",
    nil,
    1.5,
    true,
    true,
    "",
    "true",
    5,
    false,
    "",
    ""
];

_pnj addAction [
    "<t color='#FFFFFF'>ℹ️ Informations</t>",
    {
        hint parseText format [
            "<t size='1.5' color='#FF6600'>ORANGE</t><br/>" +
            "<t size='1'>Opérateur télécom #1</t><br/><br/>" +
            
            "<t size='1.2' color='#FFFFFF'>📱 NOS OFFRES</t><br/><br/>" +
            
            "<t color='#FFD700'>🔶 CARTE SIM</t><br/>" +
            "<t size='0.9'>50€ - Obligatoire</t><br/><br/>" +
            
            "<t color='#FF6600'>📦 FORFAIT BASIQUE</t><br/>" +
            "<t size='0.9'>200€/mois - Appels & SMS illimités</t><br/><br/>" +
            
            "<t color='#FFD700'>📦 FORFAIT PREMIUM</t><br/>" +
            "<t size='0.9'>500€/mois - Tout illimité + GPS + Priorité</t><br/><br/>" +
            
            "<t color='#9966FF'>📦 FORFAIT VIP</t><br/>" +
            "<t size='0.9'>1000€/mois - Services VIP + Support 24/7</t><br/><br/>" +
            
            "<t size='0.8' color='#AAAAAA'>Durée: 30 jours de jeu</t>"
        ];
    },
    nil,
    1.4,
    true,
    true,
    "",
    "true",
    5,
    false,
    "",
    ""
];

// ============================================================================
// MARQUEUR SUR LA CARTE
// ============================================================================

private _markerName = format ["orange_shop_%1", _pnj];
deleteMarker _markerName;

private _marker = createMarker [_markerName, getPos _pnj];
_marker setMarkerType "hd_dot";
_marker setMarkerColor "ColorOrange";
_marker setMarkerText "Boutique Orange";
_marker setMarkerSize [1, 1];

// ============================================================================
// PANNEAU 3D
// ============================================================================

[_pnj] spawn {
    params ["_pnj"];
    
    while {alive _pnj} do {
        {
            if (player distance _pnj < 50) then {
                drawIcon3D [
                    "",
                    [1, 0.4, 0, 1],
                    [
                        (getPos _pnj select 0),
                        (getPos _pnj select 1),
                        ((getPos _pnj select 2) + 2.5)
                    ],
                    1,
                    1,
                    0,
                    "BOUTIQUE ORANGE",
                    2,
                    0.04,
                    "PuristaMedium"
                ];
                
                drawIcon3D [
                    "\A3\ui_f\data\map\markers\nato\o_installation.paa",
                    [1, 0.4, 0, 1],
                    [
                        (getPos _pnj select 0),
                        (getPos _pnj select 1),
                        ((getPos _pnj select 2) + 3)
                    ],
                    1.5,
                    1.5,
                    0,
                    "",
                    2,
                    0.04,
                    "PuristaMedium"
                ];
            };
        } forEach allPlayers;
        
        sleep 0.5;
    };
};

// ============================================================================
// RESPAWN
// ============================================================================

_pnj addEventHandler ["Killed", {
    params ["_unit"];
    
    diag_log "[ORANGE] PNJ tué ! Respawn dans 60 secondes...";
    
    [{
        params ["_unit"];
        
        if (!alive _unit) then {
            private _pos = getPos _unit;
            deleteVehicle _unit;
            
            private _newPNJ = createAgent [typeOf _unit, _pos, [], 0, "NONE"];
            [_newPNJ] execVM "core\orange\init_pnj_orange_GUI.sqf";
            
            diag_log "[ORANGE] PNJ respawné !";
        };
    }, [_unit], 60] call CBA_fnc_waitAndExecute;
}];

// ============================================================================
// LOG
// ============================================================================

diag_log format ["[ORANGE GUI] PNJ initialisé: %1 | Position: %2", _pnj, getPos _pnj];

true
