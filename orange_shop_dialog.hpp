/*
    Dialog Interface Boutique Orange
    Interface graphique complete avec boutons colores
    Version: 2.0 GUI - CORRECTED
*/

#define GUI_GRID_X  (0)
#define GUI_GRID_Y  (0)
#define GUI_GRID_W  (0.025)
#define GUI_GRID_H  (0.04)
#define GUI_GRID_WAbs   (1)
#define GUI_GRID_HAbs   (1)

// Couleurs Orange
#define ORANGE_COLOR    {1, 0.4, 0, 1}
#define ORANGE_BTN      {1, 0.4, 0, 0.8}
#define YELLOW_BTN      {1, 0.85, 0, 0.8}
#define PURPLE_BTN      {0.5, 0.2, 0.8, 0.8}
#define RED_BTN         {0.8, 0.2, 0.2, 0.8}
#define GREEN_TEXT      {0.2, 1, 0.2, 1}
#define DARK_BG         {0.15, 0.15, 0.15, 0.95}

class orange_shop_dialog {
    idd = 8500;
    movingEnable = 0;
    enableSimulation = 1;
    
    class controlsBackground {
        // Fond principal
        class MainBackground: RscText {
            idc = -1;
            x = 0.3 * safezoneW + safezoneX;
            y = 0.2 * safezoneH + safezoneY;
            w = 0.4 * safezoneW;
            h = 0.6 * safezoneH;
            colorBackground[] = DARK_BG;
        };
        
        // Header Orange
        class HeaderOrange: RscText {
            idc = -1;
            x = 0.3 * safezoneW + safezoneX;
            y = 0.2 * safezoneH + safezoneY;
            w = 0.4 * safezoneW;
            h = 0.05 * safezoneH;
            colorBackground[] = ORANGE_COLOR;
            text = "";
        };
        
        // Separateur Carte SIM
        class SeparatorSIM: RscText {
            idc = -1;
            x = 0.31 * safezoneW + safezoneX;
            y = 0.32 * safezoneH + safezoneY;
            w = 0.38 * safezoneW;
            h = 0.002 * safezoneH;
            colorBackground[] = {1, 0.4, 0, 0.3};
        };
        
        // Separateur Forfaits
        class SeparatorForfaits: RscText {
            idc = -1;
            x = 0.31 * safezoneW + safezoneX;
            y = 0.42 * safezoneH + safezoneY;
            w = 0.38 * safezoneW;
            h = 0.002 * safezoneH;
            colorBackground[] = {1, 0.4, 0, 0.3};
        };
    };
    
    class controls {
        // Titre "BOUTIQUE ORANGE"
        class Title: RscText {
            idc = -1;
            x = 0.3 * safezoneW + safezoneX;
            y = 0.2 * safezoneH + safezoneY;
            w = 0.4 * safezoneW;
            h = 0.05 * safezoneH;
            text = "BOUTIQUE ORANGE";
            colorText[] = {1, 1, 1, 1};
            font = "PuristaLight";
            sizeEx = 0.05;
            style = 2; // CENTER
        };
        
        // =====================================================
        // SECTION CARTE SIM
        // =====================================================
        
        class LabelCarteSIM: RscText {
            idc = -1;
            x = 0.31 * safezoneW + safezoneX;
            y = 0.26 * safezoneH + safezoneY;
            w = 0.38 * safezoneW;
            h = 0.03 * safezoneH;
            text = "CARTE SIM";
            colorText[] = ORANGE_COLOR;
            font = "PuristaMedium";
            sizeEx = 0.04;
        };
        
        class TextCarteSIMName: RscText {
            idc = -1;
            x = 0.32 * safezoneW + safezoneX;
            y = 0.29 * safezoneH + safezoneY;
            w = 0.25 * safezoneW;
            h = 0.025 * safezoneH;
            text = "Carte SIM Orange";
            colorText[] = {1, 1, 1, 1};
            font = "PuristaLight";
            sizeEx = 0.035;
        };
        
        class TextCarteSIMDesc: RscText {
            idc = -1;
            x = 0.32 * safezoneW + safezoneX;
            y = 0.31 * safezoneH + safezoneY;
            w = 0.25 * safezoneW;
            h = 0.02 * safezoneH;
            text = "Necessaire pour utiliser votre iPhone";
            colorText[] = {0.7, 0.7, 0.7, 1};
            font = "PuristaLight";
            sizeEx = 0.028;
        };
        
        class TextCarteSIMPrice: RscText {
            idc = 8501;
            x = 0.58 * safezoneW + safezoneX;
            y = 0.29 * safezoneH + safezoneY;
            w = 0.06 * safezoneW;
            h = 0.025 * safezoneH;
            text = "50 EUR";
            colorText[] = GREEN_TEXT;
            font = "PuristaMedium";
            sizeEx = 0.035;
            style = 1;
        };
        
        class TextCarteSIMStatus: RscText {
            idc = 8502;
            x = 0.64 * safezoneW + safezoneX;
            y = 0.29 * safezoneH + safezoneY;
            w = 0.05 * safezoneW;
            h = 0.025 * safezoneH;
            text = "";
            colorText[] = {0.5, 0.5, 0.5, 1};
            font = "PuristaLight";
            sizeEx = 0.028;
        };
        
        // =====================================================
        // SECTION FORFAITS
        // =====================================================
        
        class LabelForfaits: RscText {
            idc = -1;
            x = 0.31 * safezoneW + safezoneX;
            y = 0.36 * safezoneH + safezoneY;
            w = 0.38 * safezoneW;
            h = 0.03 * safezoneH;
            text = "FORFAITS DISPONIBLES";
            colorText[] = ORANGE_COLOR;
            font = "PuristaMedium";
            sizeEx = 0.04;
        };
        
        class TextForfaitsDesc: RscText {
            idc = -1;
            x = 0.32 * safezoneW + safezoneX;
            y = 0.39 * safezoneH + safezoneY;
            w = 0.36 * safezoneW;
            h = 0.02 * safezoneH;
            text = "Choisissez votre forfait (duree: 30 jours de jeu)";
            colorText[] = {0.7, 0.7, 0.7, 1};
            font = "PuristaLight";
            sizeEx = 0.028;
        };
        
        // ----- FORFAIT BASIQUE -----
        class LabelBasique: RscText {
            idc = -1;
            x = 0.32 * safezoneW + safezoneX;
            y = 0.44 * safezoneH + safezoneY;
            w = 0.25 * safezoneW;
            h = 0.025 * safezoneH;
            text = "FORFAIT BASIQUE";
            colorText[] = ORANGE_COLOR;
            font = "PuristaMedium";
            sizeEx = 0.032;
        };
        
        class TextBasiqueDesc: RscText {
            idc = -1;
            x = 0.32 * safezoneW + safezoneX;
            y = 0.465 * safezoneH + safezoneY;
            w = 0.25 * safezoneW;
            h = 0.02 * safezoneH;
            text = "Appels illimites - SMS illimites";
            colorText[] = {0.8, 0.8, 0.8, 1};
            font = "PuristaLight";
            sizeEx = 0.028;
        };
        
        class TextBasiquePrice: RscText {
            idc = -1;
            x = 0.58 * safezoneW + safezoneX;
            y = 0.44 * safezoneH + safezoneY;
            w = 0.08 * safezoneW;
            h = 0.025 * safezoneH;
            text = "200 EUR / mois";
            colorText[] = GREEN_TEXT;
            font = "PuristaMedium";
            sizeEx = 0.032;
            style = 1;
        };
        
        class ButtonBasique: RscButton {
            idc = 8510;
            x = 0.605 * safezoneW + safezoneX;
            y = 0.465 * safezoneH + safezoneY;
            w = 0.08 * safezoneW;
            h = 0.03 * safezoneH;
            text = "SOUSCRIRE";
            colorBackground[] = ORANGE_BTN;
            colorBackgroundActive[] = {1, 0.5, 0, 1};
            colorText[] = {1, 1, 1, 1};
            font = "PuristaMedium";
            sizeEx = 0.03;
            action = "[""basic"", 200] call fnc_orange_buyForfait_GUI; closeDialog 8500;";
        };
        
        // ----- FORFAIT PREMIUM -----
        class LabelPremium: RscText {
            idc = -1;
            x = 0.32 * safezoneW + safezoneX;
            y = 0.51 * safezoneH + safezoneY;
            w = 0.25 * safezoneW;
            h = 0.025 * safezoneH;
            text = "FORFAIT PREMIUM";
            colorText[] = {1, 0.85, 0, 1};
            font = "PuristaMedium";
            sizeEx = 0.032;
        };
        
        class TextPremiumDesc: RscText {
            idc = -1;
            x = 0.32 * safezoneW + safezoneX;
            y = 0.535 * safezoneH + safezoneY;
            w = 0.25 * safezoneW;
            h = 0.02 * safezoneH;
            text = "Tout illimite - GPS gratuit - Priorite reseau";
            colorText[] = {0.8, 0.8, 0.8, 1};
            font = "PuristaLight";
            sizeEx = 0.028;
        };
        
        class TextPremiumPrice: RscText {
            idc = -1;
            x = 0.58 * safezoneW + safezoneX;
            y = 0.51 * safezoneH + safezoneY;
            w = 0.08 * safezoneW;
            h = 0.025 * safezoneH;
            text = "500 EUR / mois";
            colorText[] = GREEN_TEXT;
            font = "PuristaMedium";
            sizeEx = 0.032;
            style = 1;
        };
        
        class ButtonPremium: RscButton {
            idc = 8511;
            x = 0.605 * safezoneW + safezoneX;
            y = 0.535 * safezoneH + safezoneY;
            w = 0.08 * safezoneW;
            h = 0.03 * safezoneH;
            text = "SOUSCRIRE";
            colorBackground[] = YELLOW_BTN;
            colorBackgroundActive[] = {1, 0.9, 0, 1};
            colorText[] = {0.2, 0.2, 0.2, 1};
            font = "PuristaMedium";
            sizeEx = 0.03;
            action = "[""premium"", 500] call fnc_orange_buyForfait_GUI; closeDialog 8500;";
        };
        
        // ----- FORFAIT VIP -----
        class LabelVIP: RscText {
            idc = -1;
            x = 0.32 * safezoneW + safezoneX;
            y = 0.58 * safezoneH + safezoneY;
            w = 0.25 * safezoneW;
            h = 0.025 * safezoneH;
            text = "FORFAIT VIP";
            colorText[] = {0.7, 0.4, 1, 1};
            font = "PuristaMedium";
            sizeEx = 0.032;
        };
        
        class TextVIPDesc: RscText {
            idc = -1;
            x = 0.32 * safezoneW + safezoneX;
            y = 0.605 * safezoneH + safezoneY;
            w = 0.25 * safezoneW;
            h = 0.02 * safezoneH;
            text = "Tout illimite - Services VIP - Support 24/7";
            colorText[] = {0.8, 0.8, 0.8, 1};
            font = "PuristaLight";
            sizeEx = 0.028;
        };
        
        class TextVIPPrice: RscText {
            idc = -1;
            x = 0.58 * safezoneW + safezoneX;
            y = 0.58 * safezoneH + safezoneY;
            w = 0.08 * safezoneW;
            h = 0.025 * safezoneH;
            text = "1000 EUR / mois";
            colorText[] = GREEN_TEXT;
            font = "PuristaMedium";
            sizeEx = 0.032;
            style = 1;
        };
        
        class ButtonVIP: RscButton {
            idc = 8512;
            x = 0.605 * safezoneW + safezoneX;
            y = 0.605 * safezoneH + safezoneY;
            w = 0.08 * safezoneW;
            h = 0.03 * safezoneH;
            text = "SOUSCRIRE";
            colorBackground[] = PURPLE_BTN;
            colorBackgroundActive[] = {0.6, 0.3, 0.9, 1};
            colorText[] = {1, 1, 1, 1};
            font = "PuristaMedium";
            sizeEx = 0.03;
            action = "[""vip"", 1000] call fnc_orange_buyForfait_GUI; closeDialog 8500;";
        };
        
        // =====================================================
        // FOOTER INFO
        // =====================================================
        
        class TextMoney: RscText {
            idc = 8520;
            x = 0.32 * safezoneW + safezoneX;
            y = 0.68 * safezoneH + safezoneY;
            w = 0.18 * safezoneW;
            h = 0.025 * safezoneH;
            text = "Votre argent: 0 EUR";
            colorText[] = GREEN_TEXT;
            font = "PuristaMedium";
            sizeEx = 0.032;
        };
        
        class TextStatus: RscText {
            idc = 8521;
            x = 0.32 * safezoneW + safezoneX;
            y = 0.71 * safezoneH + safezoneY;
            w = 0.36 * safezoneW;
            h = 0.02 * safezoneH;
            text = "Carte SIM activee - Aucun forfait";
            colorText[] = {1, 0.6, 0.2, 1};
            font = "PuristaLight";
            sizeEx = 0.028;
        };
        
        // =====================================================
        // BOUTON FERMER
        // =====================================================
        
        class ButtonClose: RscButton {
            idc = -1;
            x = 0.605 * safezoneW + safezoneX;
            y = 0.74 * safezoneH + safezoneY;
            w = 0.08 * safezoneW;
            h = 0.04 * safezoneH;
            text = "FERMER";
            colorBackground[] = RED_BTN;
            colorBackgroundActive[] = {1, 0.3, 0.3, 1};
            colorText[] = {1, 1, 1, 1};
            font = "PuristaMedium";
            sizeEx = 0.035;
            action = "closeDialog 8500;";
        };
    };
};
