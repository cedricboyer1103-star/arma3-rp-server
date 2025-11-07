/*
    Script Boutique Orange - Interface Graphique
    Ouvre le dialog et gère les achats
    Version: 2.0 GUI
*/

// ============================================================================
// VARIABLES GLOBALES
// ============================================================================
if (isNil "orange_sim_price") then { orange_sim_price = 50; };
if (isNil "orange_forfait_basic_price") then { orange_forfait_basic_price = 200; };
if (isNil "orange_forfait_premium_price") then { orange_forfait_premium_price = 500; };
if (isNil "orange_forfait_vip_price") then { orange_forfait_vip_price = 1000; };

// ============================================================================
// FONCTION: Notification
// ============================================================================
fnc_orange_notification = {
    params ["_message", "_type"];
    
    private _color = switch (_type) do {
        case "success": { [0.2, 1, 0.2, 1] };
        case "error": { [1, 0.2, 0.2, 1] };
        case "info": { [0.2, 0.6, 1, 1] };
        default { [1, 1, 1, 1] };
    };
    
    [
        _message,
        0,
        0,
        5,
        _color
    ] spawn BIS_fnc_dynamicText;
    
    playSound "FD_Finish_F";
};

// ============================================================================
// FONCTION: Vérifier argent
// ============================================================================
fnc_orange_checkMoney = {
    params ["_amount"];
    
    private _cash = 0;
    
    if (!isNil "life_cash") then {
        _cash = life_cash;
    };
    
    if (_cash == 0 && !isNil "player_money") then {
        _cash = player_money;
    };
    
    (_cash >= _amount)
};

// ============================================================================
// FONCTION: Retirer argent
// ============================================================================
fnc_orange_removeMoney = {
    params ["_amount"];
    
    if (!isNil "life_cash") then {
        life_cash = life_cash - _amount;
        publicVariable "life_cash";
    };
    
    if (!isNil "player_money") then {
        player_money = player_money - _amount;
        publicVariable "player_money";
    };
    
    true
};

// ============================================================================
// FONCTION: Obtenir l'argent du joueur
// ============================================================================
fnc_orange_getMoney = {
    private _cash = 0;
    
    if (!isNil "life_cash") then {
        _cash = life_cash;
    } else {
        if (!isNil "player_money") then {
            _cash = player_money;
        };
    };
    
    _cash
};

// ============================================================================
// FONCTION: Vérifier carte SIM
// ============================================================================
fnc_orange_hasSIM = {
    private _hasSIM = false;
    
    if ("orange_sim" in (items player)) then {
        _hasSIM = true;
    };
    
    if (!isNil "orange_player_hasSIM") then {
        if (orange_player_hasSIM) then {
            _hasSIM = true;
        };
    };
    
    _hasSIM
};

// ============================================================================
// FONCTION: Vérifier forfait actif
// ============================================================================
fnc_orange_hasForfait = {
    private _hasForfait = false;
    
    if (!isNil "orange_player_forfait" && !isNil "orange_forfait_expiration") then {
        if (time < orange_forfait_expiration) then {
            _hasForfait = true;
        };
    };
    
    _hasForfait
};

// ============================================================================
// FONCTION: Activer forfait (GUI)
// ============================================================================
fnc_orange_activateForfait_GUI = {
    params ["_forfaitType"];
    
    private _duration = 30 * 24 * 60 * 60;
    private _expirationDate = time + _duration;
    
    orange_player_forfait = _forfaitType;
    orange_forfait_expiration = _expirationDate;
    publicVariable "orange_player_forfait";
    publicVariable "orange_forfait_expiration";
    
    private _forfaitName = switch (_forfaitType) do {
        case "basic": { "Basique" };
        case "premium": { "Premium" };
        case "vip": { "VIP" };
        default { "Inconnu" };
    };
    
    ["✓ Forfait Orange " + _forfaitName + " activé pour 30 jours !", "success"] call fnc_orange_notification;
};

// ============================================================================
// FONCTION: Acheter forfait (GUI)
// ============================================================================
fnc_orange_buyForfait_GUI = {
    params ["_forfaitType", "_price"];
    
    // Vérifier la carte SIM
    if (!(call fnc_orange_hasSIM)) then {
        ["✗ Vous devez d'abord acheter une carte SIM !", "error"] call fnc_orange_notification;
        [] call fnc_orange_openShop;
    } else {
        // Vérifier si déjà un forfait
        if (call fnc_orange_hasForfait) then {
            ["✗ Vous avez déjà un forfait actif !", "error"] call fnc_orange_notification;
        } else {
            // Vérifier l'argent
            if ([_price] call fnc_orange_checkMoney) then {
                [_price] call fnc_orange_removeMoney;
                [_forfaitType] call fnc_orange_activateForfait_GUI;
            } else {
                ["✗ Argent insuffisant !", "error"] call fnc_orange_notification;
                [] call fnc_orange_openShop;
            };
        };
    };
};

// ============================================================================
// FONCTION: Acheter carte SIM (GUI)
// ============================================================================
fnc_orange_buySIM_GUI = {
    if (call fnc_orange_hasSIM) then {
        ["✗ Vous avez déjà une carte SIM Orange !", "error"] call fnc_orange_notification;
    } else {
        if ([orange_sim_price] call fnc_orange_checkMoney) then {
            [orange_sim_price] call fnc_orange_removeMoney;
            
            // Activer la SIM
            orange_player_hasSIM = true;
            publicVariable "orange_player_hasSIM";
            
            // Ajouter l'item si possible
            if (player canAdd "orange_sim") then {
                player addItem "orange_sim";
            };
            
            ["✓ Carte SIM Orange activée !", "success"] call fnc_orange_notification;
            sleep 0.5;
            
            // Rouvrir le dialog pour refresh
            [] call fnc_orange_openShop;
        } else {
            ["✗ Argent insuffisant ! Carte SIM: 50€", "error"] call fnc_orange_notification;
        };
    };
};

// ============================================================================
// FONCTION: Mettre à jour l'interface
// ============================================================================
fnc_orange_updateGUI = {
    disableSerialization;
    
    private _display = findDisplay 8500;
    if (isNull _display) exitWith {};
    
    // Mettre à jour l'argent
    private _money = call fnc_orange_getMoney;
    private _ctrlMoney = _display displayCtrl 8520;
    _ctrlMoney ctrlSetText format ["Votre argent : %1 €", _money];
    
    // Mettre à jour le status carte SIM
    private _hasSIM = call fnc_orange_hasSIM;
    private _ctrlSIMStatus = _display displayCtrl 8502;
    
    if (_hasSIM) then {
        _ctrlSIMStatus ctrlSetText "POSSÉDÉE";
        _ctrlSIMStatus ctrlSetTextColor [0.2, 1, 0.2, 1];
    } else {
        _ctrlSIMStatus ctrlSetText "";
    };
    
    // Mettre à jour le prix de la carte SIM
    private _ctrlSIMPrice = _display displayCtrl 8501;
    if (_hasSIM) then {
        _ctrlSIMPrice ctrlSetText "";
    } else {
        _ctrlSIMPrice ctrlSetText format ["%1 €", orange_sim_price];
    };
    
    // Mettre à jour le status forfait
    private _hasForfait = call fnc_orange_hasForfait;
    private _ctrlStatus = _display displayCtrl 8521;
    
    if (!_hasSIM) then {
        _ctrlStatus ctrlSetText "Aucune carte SIM";
        _ctrlStatus ctrlSetTextColor [1, 0.2, 0.2, 1];
    } else {
        if (_hasForfait) then {
            private _forfaitName = switch (orange_player_forfait) do {
                case "basic": { "Basique" };
                case "premium": { "Premium" };
                case "vip": { "VIP" };
                default { "Inconnu" };
            };
            
            private _daysLeft = floor ((orange_forfait_expiration - time) / 86400);
            _ctrlStatus ctrlSetText format ["Forfait %1 actif - %2 jours restants", _forfaitName, _daysLeft];
            _ctrlStatus ctrlSetTextColor [0.2, 1, 0.2, 1];
        } else {
            _ctrlStatus ctrlSetText "Carte SIM activée - Aucun forfait";
            _ctrlStatus ctrlSetTextColor [1, 0.6, 0.2, 1];
        };
    };
    
    // Désactiver les boutons si déjà un forfait ou pas de SIM
    private _btnBasic = _display displayCtrl 8510;
    private _btnPremium = _display displayCtrl 8511;
    private _btnVIP = _display displayCtrl 8512;
    
    if (!_hasSIM || _hasForfait) then {
        _btnBasic ctrlEnable false;
        _btnPremium ctrlEnable false;
        _btnVIP ctrlEnable false;
        
        _btnBasic ctrlSetBackgroundColor [0.3, 0.3, 0.3, 0.5];
        _btnPremium ctrlSetBackgroundColor [0.3, 0.3, 0.3, 0.5];
        _btnVIP ctrlSetBackgroundColor [0.3, 0.3, 0.3, 0.5];
    };
};

// ============================================================================
// FONCTION: Ouvrir la boutique
// ============================================================================
fnc_orange_openShop = {
    // Créer le dialog
    createDialog "orange_shop_dialog";
    
    // Attendre que le dialog soit créé
    waitUntil {!isNull findDisplay 8500};
    
    // Mettre à jour l'interface
    [] call fnc_orange_updateGUI;
    
    // Ajouter le bouton carte SIM si pas possédée
    private _hasSIM = call fnc_orange_hasSIM;
    if (!_hasSIM) then {
        private _display = findDisplay 8500;
        
        // Créer le bouton "Acheter carte SIM"
        private _btnSIM = _display ctrlCreate ["RscButton", 8503];
        _btnSIM ctrlSetPosition [
            0.605 * safezoneW + safezoneX,
            0.29 * safezoneH + safezoneY,
            0.08 * safezoneW,
            0.03 * safezoneH
        ];
        _btnSIM ctrlSetText "ACHETER";
        _btnSIM ctrlSetBackgroundColor [1, 0.4, 0, 0.8];
        _btnSIM ctrlSetTextColor [1, 1, 1, 1];
        _btnSIM ctrlSetFont "PuristaMedium";
        _btnSIM ctrlSetFontHeight 0.03;
        _btnSIM ctrlCommit 0;
        
        _btnSIM ctrlAddEventHandler ["ButtonClick", {
            [] call fnc_orange_buySIM_GUI;
        }];
    };
};

// ============================================================================
// OUVRIR LA BOUTIQUE
// ============================================================================
[] call fnc_orange_openShop;
