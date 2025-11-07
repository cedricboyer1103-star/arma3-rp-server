/*
    ═══════════════════════════════════════════════════════════════
    📁 config/phone_3d_dialog.hpp - VERSION FINALE CORRIGÉE
    ═══════════════════════════════════════════════════════════════
    
    🎯 Interface graphique pour le téléphone 3D
    
    ✅ CORRECTIONS :
    - Classe renommée : LEG_iPhone3D_Dialog (évite conflit)
    - IDD changé : 36100 (au lieu de 36000)
    - Toutes les classes Life_Rsc* → Rsc*
    
    📝 À INCLURE DANS : description.ext
    #include "config\phone_3d_dialog.hpp"
*/

class LEG_iPhone3D_Dialog {
    idd = 36100;
    movingEnable = 0;
    enableSimulation = 1;
    
    class ControlsBackground {
        // Fond du téléphone (image du modèle 3D)
        class PhoneBackground: RscPicture {
            idc = -1;
            text = "\iphonexi_assets\menus\main_menu.paa";
            x = 0.3;
            y = 0.1;
            w = 0.4;
            h = 0.8;
        };
    };
    
    class Controls {
        // Barre de statut en haut
        class StatusBar: RscText {
            idc = 36010;
            text = "12:00";
            x = 0.35;
            y = 0.12;
            w = 0.1;
            h = 0.03;
            colorBackground[] = {0,0,0,0.7};
            sizeEx = 0.025;
        };
        
        class CarrierText: RscText {
            idc = 36011;
            text = "Orange 📶";
            x = 0.55;
            y = 0.12;
            w = 0.15;
            h = 0.03;
            colorBackground[] = {0,0,0,0.7};
            sizeEx = 0.02;
        };
        
        // Icône App Orange
        class BtnOrange: RscButton {
            idc = 36101;
            text = "🔶";
            x = 0.35;
            y = 0.25;
            w = 0.08;
            h = 0.08;
            tooltip = "📱 Orange - Mon forfait";
            action = "[] call LEG_fnc_orangeApp;";
            colorBackground[] = {1,0.5,0,0.8};
        };
        
        // Icône App Banque
        class BtnBank: RscButton {
            idc = 36102;
            text = "💰";
            x = 0.45;
            y = 0.25;
            w = 0.08;
            h = 0.08;
            tooltip = "💰 Banque";
            action = "[] call LEG_fnc_bankApp;";
            colorBackground[] = {0,0.6,0,0.8};
        };
        
        // Icône App Contacts
        class BtnContacts: RscButton {
            idc = 36103;
            text = "👥";
            x = 0.55;
            y = 0.25;
            w = 0.08;
            h = 0.08;
            tooltip = "👥 Contacts";
            action = "[] call LEG_fnc_contactsApp;";
            colorBackground[] = {0.2,0.5,1,0.8};
        };
        
        // Icône App Messages
        class BtnMessages: RscButton {
            idc = 36104;
            text = "💬";
            x = 0.35;
            y = 0.35;
            w = 0.08;
            h = 0.08;
            tooltip = "💬 Messages";
            action = "[] call LEG_fnc_messagesApp;";
            colorBackground[] = {0,0.8,0.3,0.8};
        };
        
        // Icône App Paramètres
        class BtnSettings: RscButton {
            idc = 36105;
            text = "⚙️";
            x = 0.45;
            y = 0.35;
            w = 0.08;
            h = 0.08;
            tooltip = "⚙️ Paramètres";
            action = "[] call LEG_fnc_settingsApp;";
            colorBackground[] = {0.5,0.5,0.5,0.8};
        };
        
        // Icône App Garage
        class BtnGarage: RscButton {
            idc = 36106;
            text = "🚗";
            x = 0.55;
            y = 0.35;
            w = 0.08;
            h = 0.08;
            tooltip = "🚗 Garage";
            action = "[] call LEG_fnc_garageApp;";
            colorBackground[] = {0.8,0,0,0.8};
        };
        
        // Zone de contenu pour les apps
        class ContentArea: RscStructuredText {
            idc = 36200;
            text = "";
            x = 0.32;
            y = 0.2;
            w = 0.36;
            h = 0.6;
            colorBackground[] = {0,0,0,0};
            show = 0;
        };
        
        // Bouton Retour
        class BtnBack: RscButton {
            idc = 36300;
            text = "← RETOUR";
            x = 0.32;
            y = 0.82;
            w = 0.15;
            h = 0.04;
            colorBackground[] = {1,0.5,0,0.7};
            action = "[] call LEG_fnc_homeScreen;";
            show = 0;
        };
        
        // Bouton Fermer
        class BtnClose: RscButton {
            idc = 36301;
            text = "✕ FERMER";
            x = 0.53;
            y = 0.82;
            w = 0.15;
            h = 0.04;
            colorBackground[] = {0.8,0,0,0.7};
            action = "closeDialog 0; player setVariable ['LEG_phone3D_active', false, false];";
        };
    };
};
