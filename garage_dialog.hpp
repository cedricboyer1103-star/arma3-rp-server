/*
    ═══════════════════════════════════════════════════════════════
    📁 dialogs/garage_dialog.hpp - VERSION FINALE CORRIGÉE
    ═══════════════════════════════════════════════════════════════
    ✅ SANS ERREUR ListScrollBar
    ═══════════════════════════════════════════════════════════════
*/

class LEG_Garage_Dialog
{
    idd = 35000;
    movingEnable = 0;
    enableSimulation = 1;
    onLoad = "_this call LEG_fnc_populateList;";

    class controlsBackground
    {
        // ═════════════════════════════════════════════════════════
        // 🎨 PANNEAU GAUCHE - LISTE VÉHICULES
        // ═════════════════════════════════════════════════════════
        
        class LeftPanel: RscText
        {
            idc = -1;
            x = 0.05 * safezoneW + safezoneX;
            y = 0.10 * safezoneH + safezoneY;
            w = 0.25 * safezoneW;
            h = 0.75 * safezoneH;
            colorBackground[] = {0.1, 0.08, 0.05, 0.85};
        };
        
        class LeftTitle: RscText
        {
            idc = -1;
            text = "Garage";
            x = 0.05 * safezoneW + safezoneX;
            y = 0.10 * safezoneH + safezoneY;
            w = 0.25 * safezoneW;
            h = 0.04 * safezoneH;
            colorBackground[] = {0.15, 0.10, 0.05, 0.95};
            style = 2;
            font = "PuristaBold";
            sizeEx = 0.040;
        };
        
        // ═════════════════════════════════════════════════════════
        // 🎨 PANNEAU DROIT - CARTE GRISE
        // ═════════════════════════════════════════════════════════
        
        class RightPanel: RscText
        {
            idc = -1;
            x = 0.70 * safezoneW + safezoneX;
            y = 0.10 * safezoneH + safezoneY;
            w = 0.25 * safezoneW;
            h = 0.50 * safezoneH;
            colorBackground[] = {0.1, 0.08, 0.05, 0.85};
        };
        
        class RightTitle: RscText
        {
            idc = 35010;
            text = "Carte grise du véhicule";
            x = 0.70 * safezoneW + safezoneX;
            y = 0.10 * safezoneH + safezoneY;
            w = 0.25 * safezoneW;
            h = 0.04 * safezoneH;
            colorBackground[] = {0.8, 0.5, 0.1, 0.95};
            style = 2;
            font = "PuristaBold";
            sizeEx = 0.035;
        };
        
        // ═════════════════════════════════════════════════════════
        // 🎨 PANNEAU INVENTAIRE
        // ═════════════════════════════════════════════════════════
        
        class InventoryPanel: RscText
        {
            idc = -1;
            x = 0.70 * safezoneW + safezoneX;
            y = 0.62 * safezoneH + safezoneY;
            w = 0.25 * safezoneW;
            h = 0.23 * safezoneH;
            colorBackground[] = {0.1, 0.08, 0.05, 0.85};
        };
        
        class InventoryTitle: RscText
        {
            idc = -1;
            text = "Inventaire du véhicule";
            x = 0.70 * safezoneW + safezoneX;
            y = 0.62 * safezoneH + safezoneY;
            w = 0.25 * safezoneW;
            h = 0.04 * safezoneH;
            colorBackground[] = {0.8, 0.5, 0.1, 0.95};
            style = 2;
            font = "PuristaBold";
            sizeEx = 0.032;
        };
    };

    class controls
    {
        // ═════════════════════════════════════════════════════════
        // 📋 LISTE DES VÉHICULES - ✅ CORRIGÉE (hérite de RscListbox)
        // ═════════════════════════════════════════════════════════
        
        class VehicleList: RscListBox
        {
            idc = 35001;
            x = 0.052 * safezoneW + safezoneX;
            y = 0.15 * safezoneH + safezoneY;
            w = 0.246 * safezoneW;
            h = 0.55 * safezoneH;
            
            colorBackground[] = {0.05, 0.04, 0.03, 0.9};
            colorSelect[] = {1, 1, 1, 1};
            colorSelectBackground[] = {0.6, 0.4, 0.1, 0.8};
            colorDisabled[] = {0.5, 0.5, 0.5, 1};

            rowHeight = 0.05;
            font = "PuristaLight";
            sizeEx = 0.030;
            
            onLBSelChanged = "_this call LEG_fnc_selectVehicle;";
        };
        
        // ═════════════════════════════════════════════════════════
        // 🔍 BARRE DE RECHERCHE
        // ═════════════════════════════════════════════════════════
        
        class SearchLabel: RscText
        {
            idc = -1;
            text = "Effectuez une recherche";
            x = 0.052 * safezoneW + safezoneX;
            y = 0.72 * safezoneH + safezoneY;
            w = 0.246 * safezoneW;
            h = 0.03 * safezoneH;
            colorBackground[] = {0.05, 0.04, 0.03, 0.7};
            font = "PuristaLight";
            sizeEx = 0.028;
            colorText[] = {0.7, 0.7, 0.7, 1};
        };
        
        class SearchBox: RscEdit
        {
            idc = 35002;
            x = 0.052 * safezoneW + safezoneX;
            y = 0.76 * safezoneH + safezoneY;
            w = 0.246 * safezoneW;
            h = 0.04 * safezoneH;
            colorBackground[] = {0.02, 0.02, 0.02, 0.9};
            font = "PuristaLight";
            sizeEx = 0.030;
        };
        
        // ═════════════════════════════════════════════════════════
        // 🔘 BOUTONS BAS GAUCHE
        // ═════════════════════════════════════════════════════════
        
        class BtnClose: RscButton
        {
            idc = 35003;
            text = "FERMER";
            x = 0.052 * safezoneW + safezoneX;
            y = 0.82 * safezoneH + safezoneY;
            w = 0.118 * safezoneW;
            h = 0.04 * safezoneH;
            
            colorBackground[] = {0.15, 0.08, 0.05, 0.9};
            colorBackgroundActive[] = {0.20, 0.10, 0.05, 1};
            font = "PuristaBold";
            sizeEx = 0.032;
            
            action = "closeDialog 0;";
        };
        
        class BtnSpawn: RscButton
        {
            idc = 35004;
            text = "RÉCUPÉRER";
            x = 0.180 * safezoneW + safezoneX;
            y = 0.82 * safezoneH + safezoneY;
            w = 0.118 * safezoneW;
            h = 0.04 * safezoneH;
            
            colorBackground[] = {0.5, 0.35, 0.1, 0.9};
            colorBackgroundActive[] = {0.7, 0.5, 0.2, 1};
            font = "PuristaBold";
            sizeEx = 0.032;
            
            action = "[] call LEG_fnc_spawnSelected;";
        };
        
        // ═════════════════════════════════════════════════════════
        // 📄 CARTE GRISE - INFOS VÉHICULE
        // ═════════════════════════════════════════════════════════
        
        class VehicleInfo: RscStructuredText
        {
            idc = 35020;
            x = 0.705 * safezoneW + safezoneX;
            y = 0.15 * safezoneH + safezoneY;
            w = 0.24 * safezoneW;
            h = 0.44 * safezoneH;
            
            colorBackground[] = {0, 0, 0, 0};
            
            text = "<t size='0.9' color='#cccccc' align='left'>Sélectionne un véhicule<br/>pour voir ses informations</t>";
            
            class Attributes
            {
                font = "PuristaLight";
                color = "#ffffff";
                align = "left";
                valign = "top";
                shadow = 0;
            };
            size = 0.030;
        };
        
        // ═════════════════════════════════════════════════════════
        // 📦 INVENTAIRE VÉHICULE
        // ═════════════════════════════════════════════════════════
        
        class InventoryText: RscStructuredText
        {
            idc = 35021;
            x = 0.705 * safezoneW + safezoneX;
            y = 0.67 * safezoneH + safezoneY;
            w = 0.24 * safezoneW;
            h = 0.17 * safezoneH;
            
            colorBackground[] = {0, 0, 0, 0};
            
            text = "<t size='0.85' color='#999999'>Coffre vide</t>";
            
            class Attributes
            {
                font = "PuristaLight";
                color = "#cccccc";
                align = "left";
                valign = "top";
                shadow = 0;
            };
            size = 0.028;
        };
    };
};