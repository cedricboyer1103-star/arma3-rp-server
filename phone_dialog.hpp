/*
    ═══════════════════════════════════════════════════════════════
    📱 iPHONE 11 MODÉ - ULTRA MODERNE - LEGION RP
    ═══════════════════════════════════════════════════════════════
    ✨ Effets visuels avancés | Design premium | Animations fluides
    ═══════════════════════════════════════════════════════════════
*/

class LEG_iPhone_Dialog
{
    idd = 36000;
    movingEnable = 0;
    enableSimulation = 1;
    onLoad = "_this call LEG_fnc_homeScreen;";

    class controlsBackground
    {
        // ═════════════════════════════════════════════════════════
        // 🌌 FOND D'ÉCRAN ANIMÉ (Multiple layers pour profondeur)
        // ═════════════════════════════════════════════════════════
        
        class Background: RscText
        {
            idc = -1;
            x = 0;
            y = 0;
            w = 1;
            h = 1;
            colorBackground[] = {0.02, 0.02, 0.05, 0.95};
        };
        
        // ═════════════════════════════════════════════════════════
        // 📱 CHASSIS DU TÉLÉPHONE (Bordure ultra fine)
        // ═════════════════════════════════════════════════════════
        
        class PhoneBorder: RscText
        {
            idc = -1;
            x = 0.655 * safezoneW + safezoneX;
            y = 0.04 * safezoneH + safezoneY;
            w = 0.29 * safezoneW;
            h = 0.89 * safezoneH;
            colorBackground[] = {0.08, 0.08, 0.1, 0.98};
        };
        
        // ═════════════════════════════════════════════════════════
        // 🎨 ÉCRAN PRINCIPAL
        // ═════════════════════════════════════════════════════════
        
        class Screen: RscText
        {
            idc = -1;
            x = 0.66 * safezoneW + safezoneX;
            y = 0.055 * safezoneH + safezoneY;
            w = 0.28 * safezoneW;
            h = 0.86 * safezoneH;
            colorBackground[] = {0, 0, 0, 1};
        };
        
        // ═════════════════════════════════════════════════════════
        // 🌈 WALLPAPER DÉGRADÉ DYNAMIQUE (5 couches)
        // ═════════════════════════════════════════════════════════
        
        class WallLayer1: RscText
        {
            idc = -1;
            x = 0.66 * safezoneW + safezoneX;
            y = 0.055 * safezoneH + safezoneY;
            w = 0.28 * safezoneW;
            h = 0.17 * safezoneH;
            colorBackground[] = {0.1, 0.05, 0.25, 1};
        };
        
        class WallLayer2: RscText
        {
            idc = -1;
            x = 0.66 * safezoneW + safezoneX;
            y = 0.225 * safezoneH + safezoneY;
            w = 0.28 * safezoneW;
            h = 0.17 * safezoneH;
            colorBackground[] = {0.15, 0.1, 0.35, 1};
        };
        
        class WallLayer3: RscText
        {
            idc = -1;
            x = 0.66 * safezoneW + safezoneX;
            y = 0.395 * safezoneH + safezoneY;
            w = 0.28 * safezoneW;
            h = 0.17 * safezoneH;
            colorBackground[] = {0.2, 0.15, 0.5, 1};
        };
        
        class WallLayer4: RscText
        {
            idc = -1;
            x = 0.66 * safezoneW + safezoneX;
            y = 0.565 * safezoneH + safezoneY;
            w = 0.28 * safezoneW;
            h = 0.17 * safezoneH;
            colorBackground[] = {0.25, 0.2, 0.65, 1};
        };
        
        class WallLayer5: RscText
        {
            idc = -1;
            x = 0.66 * safezoneW + safezoneX;
            y = 0.735 * safezoneH + safezoneY;
            w = 0.28 * safezoneW;
            h = 0.18 * safezoneH;
            colorBackground[] = {0.15, 0.1, 0.4, 1};
        };
        
        // ═════════════════════════════════════════════════════════
        // 🔊 NOTCH ULTRA RÉALISTE (encoche iPhone 11)
        // ═════════════════════════════════════════════════════════
        
        class NotchLeft: RscText
        {
            idc = -1;
            x = 0.745 * safezoneW + safezoneX;
            y = 0.0595 * safezoneH + safezoneY;
            w = 0.015 * safezoneW;
            h = 0.025 * safezoneH;
            colorBackground[] = {0, 0, 0, 1};
        };
        
        class NotchMain: RscText
        {
            idc = -1;
            x = 0.76 * safezoneW + safezoneX;
            y = 0.0595 * safezoneH + safezoneY;
            w = 0.08 * safezoneW;
            h = 0.025 * safezoneH;
            colorBackground[] = {0, 0, 0, 1};
        };
        
        class NotchRight: RscText
        {
            idc = -1;
            x = 0.84 * safezoneW + safezoneX;
            y = 0.0595 * safezoneH + safezoneY;
            w = 0.015 * safezoneW;
            h = 0.025 * safezoneH;
            colorBackground[] = {0, 0, 0, 1};
        };
        
        class SpeakerGrill: RscText
        {
            idc = -1;
            x = 0.7725 * safezoneW + safezoneX;
            y = 0.0625 * safezoneH + safezoneY;
            w = 0.055 * safezoneW;
            h = 0.003 * safezoneH;
            colorBackground[] = {0.1, 0.1, 0.12, 1};
        };
        
        class FrontCamera: RscText
        {
            idc = -1;
            x = 0.7925 * safezoneW + safezoneX;
            y = 0.0695 * safezoneH + safezoneY;
            w = 0.015 * safezoneW;
            h = 0.012 * safezoneH;
            colorBackground[] = {0.05, 0.05, 0.08, 0.9};
        };
        
        // ═════════════════════════════════════════════════════════
        // 📊 BARRE D'ÉTAT (Status Bar moderne)
        // ═════════════════════════════════════════════════════════
        
        class StatusBarBG: RscText
        {
            idc = -1;
            x = 0.664 * safezoneW + safezoneX;
            y = 0.088 * safezoneH + safezoneY;
            w = 0.272 * safezoneW;
            h = 0.028 * safezoneH;
            colorBackground[] = {0, 0, 0, 0};
        };
        
        // ═════════════════════════════════════════════════════════
        // 🎯 DOCK AVEC EFFET VERRE DÉPOLI
        // ═════════════════════════════════════════════════════════
        
        class DockShadow: RscText
        {
            idc = -1;
            x = 0.675 * safezoneW + safezoneX;
            y = 0.823 * safezoneH + safezoneY;
            w = 0.25 * safezoneW;
            h = 0.07 * safezoneH;
            colorBackground[] = {0, 0, 0, 0.3};
        };
        
        class DockGlass: RscText
        {
            idc = -1;
            x = 0.677 * safezoneW + safezoneX;
            y = 0.825 * safezoneH + safezoneY;
            w = 0.246 * safezoneW;
            h = 0.065 * safezoneH;
            colorBackground[] = {0.15, 0.15, 0.18, 0.85};
        };
        
        // ═════════════════════════════════════════════════════════
        // 🏠 HOME INDICATOR (Trait blanc animé)
        // ═════════════════════════════════════════════════════════
        
        class HomeIndicator: RscText
        {
            idc = -1;
            x = 0.765 * safezoneW + safezoneX;
            y = 0.9 * safezoneH + safezoneY;
            w = 0.07 * safezoneW;
            h = 0.005 * safezoneH;
            colorBackground[] = {0.9, 0.9, 0.9, 0.8};
        };
    };

    class controls
    {
        // ═════════════════════════════════════════════════════════
        // 🕐 HEURE MODERNE (Gros et bold)
        // ═════════════════════════════════════════════════════════
        
        class TimeDisplay: RscText
        {
            idc = 36010;
            text = "17:42";
            x = 0.668 * safezoneW + safezoneX;
            y = 0.091 * safezoneH + safezoneY;
            w = 0.08 * safezoneW;
            h = 0.023 * safezoneH;
            colorText[] = {1, 1, 1, 1};
            font = "PuristaBold";
            sizeEx = 0.03;
            shadow = 2;
        };
        
        // ═════════════════════════════════════════════════════════
        // 📶 ICÔNES STATUS (Signal, WiFi, Batterie)
        // ═════════════════════════════════════════════════════════
        
        class SignalIcon: RscText
        {
            idc = -1;
            text = "📶";
            x = 0.857 * safezoneW + safezoneX;
            y = 0.091 * safezoneH + safezoneY;
            w = 0.025 * safezoneW;
            h = 0.022 * safezoneH;
            colorText[] = {1, 1, 1, 1};
            sizeEx = 0.028;
            shadow = 2;
        };
        
        class BatteryPercent: RscText
        {
            idc = 36011;
            text = "88%";
            x = 0.882 * safezoneW + safezoneX;
            y = 0.091 * safezoneH + safezoneY;
            w = 0.04 * safezoneW;
            h = 0.022 * safezoneH;
            colorText[] = {1, 1, 1, 1};
            font = "PuristaSemiBold";
            sizeEx = 0.026;
            style = 1;
            shadow = 2;
        };
        
        // ═════════════════════════════════════════════════════════
        // 📱 GRILLE D'APPS PREMIUM (3x4 avec ombres)
        // ═════════════════════════════════════════════════════════
        
        // ═══ LIGNE 1 ═══
        
        class App1Shadow: RscText
        {
            idc = -1;
            x = 0.6815 * safezoneW + safezoneX;
            y = 0.142 * safezoneH + safezoneY;
            w = 0.055 * safezoneW;
            h = 0.08 * safezoneH;
            colorBackground[] = {0, 0, 0, 0.5};
        };
        
        class App1: RscButton
        {
            idc = 36101;
            text = "🔑\nKeys";
            x = 0.68 * safezoneW + safezoneX;
            y = 0.14 * safezoneH + safezoneY;
            w = 0.055 * safezoneW;
            h = 0.08 * safezoneH;
            colorBackground[] = {0.2, 0.2, 0.25, 0.95};
            colorBackgroundActive[] = {0.25, 0.25, 0.3, 1};
            colorFocused[] = {0.3, 0.3, 0.35, 1};
            font = "PuristaLight";
            sizeEx = 0.024;
            borderSize = 0;
            shadow = 0;
            action = "hint '🔑 Système de clés';";
        };
        
        class App2Shadow: RscText
        {
            idc = -1;
            x = 0.7455 * safezoneW + safezoneX;
            y = 0.142 * safezoneH + safezoneY;
            w = 0.055 * safezoneW;
            h = 0.08 * safezoneH;
            colorBackground[] = {0, 0, 0, 0.5};
        };
        
        class App2: RscButton
        {
            idc = 36102;
            text = "⚙️\nSettings";
            x = 0.744 * safezoneW + safezoneX;
            y = 0.14 * safezoneH + safezoneY;
            w = 0.055 * safezoneW;
            h = 0.08 * safezoneH;
            colorBackground[] = {0.2, 0.2, 0.25, 0.95};
            colorBackgroundActive[] = {0.25, 0.25, 0.3, 1};
            font = "PuristaLight";
            sizeEx = 0.024;
            borderSize = 0;
            action = "['settings'] call LEG_fnc_openApp;";
        };
        
        class App3Shadow: RscText
        {
            idc = -1;
            x = 0.8095 * safezoneW + safezoneX;
            y = 0.142 * safezoneH + safezoneY;
            w = 0.055 * safezoneW;
            h = 0.08 * safezoneH;
            colorBackground[] = {0, 0, 0, 0.5};
        };
        
        class App3: RscButton
        {
            idc = 36103;
            text = "💰\nBank";
            x = 0.808 * safezoneW + safezoneX;
            y = 0.14 * safezoneH + safezoneY;
            w = 0.055 * safezoneW;
            h = 0.08 * safezoneH;
            colorBackground[] = {0.2, 0.2, 0.25, 0.95};
            colorBackgroundActive[] = {0.25, 0.25, 0.3, 1};
            font = "PuristaLight";
            sizeEx = 0.024;
            borderSize = 0;
            action = "['bank'] call LEG_fnc_openApp;";
        };
        
        class App4Shadow: RscText
        {
            idc = -1;
            x = 0.8735 * safezoneW + safezoneX;
            y = 0.142 * safezoneH + safezoneY;
            w = 0.055 * safezoneW;
            h = 0.08 * safezoneH;
            colorBackground[] = {0, 0, 0, 0.5};
        };
        
        class App4: RscButton
        {
            idc = 36104;
            text = "🚗\nGarage";
            x = 0.872 * safezoneW + safezoneX;
            y = 0.14 * safezoneH + safezoneY;
            w = 0.055 * safezoneW;
            h = 0.08 * safezoneH;
            colorBackground[] = {0.2, 0.2, 0.25, 0.95};
            colorBackgroundActive[] = {0.25, 0.25, 0.3, 1};
            font = "PuristaLight";
            sizeEx = 0.024;
            borderSize = 0;
            action = "['garage'] call LEG_fnc_openApp;";
        };
        
        // ═══ LIGNE 2 ═══
        
        class App5Shadow: RscText
        {
            idc = -1;
            x = 0.6815 * safezoneW + safezoneX;
            y = 0.232 * safezoneH + safezoneY;
            w = 0.055 * safezoneW;
            h = 0.08 * safezoneH;
            colorBackground[] = {0, 0, 0, 0.5};
        };
        
        class App5: RscButton
        {
            idc = 36105;
            text = "📞\nPhone";
            x = 0.68 * safezoneW + safezoneX;
            y = 0.23 * safezoneH + safezoneY;
            w = 0.055 * safezoneW;
            h = 0.08 * safezoneH;
            colorBackground[] = {0.2, 0.2, 0.25, 0.95};
            colorBackgroundActive[] = {0.25, 0.25, 0.3, 1};
            font = "PuristaLight";
            sizeEx = 0.024;
            borderSize = 0;
            action = "['contacts'] call LEG_fnc_openApp;";
        };
        
        class App6Shadow: RscText
        {
            idc = -1;
            x = 0.7455 * safezoneW + safezoneX;
            y = 0.232 * safezoneH + safezoneY;
            w = 0.055 * safezoneW;
            h = 0.08 * safezoneH;
            colorBackground[] = {0, 0, 0, 0.5};
        };
        
        class App6: RscButton
        {
            idc = 36106;
            text = "💬\nMessages";
            x = 0.744 * safezoneW + safezoneX;
            y = 0.23 * safezoneH + safezoneY;
            w = 0.055 * safezoneW;
            h = 0.08 * safezoneH;
            colorBackground[] = {0.2, 0.2, 0.25, 0.95};
            colorBackgroundActive[] = {0.25, 0.25, 0.3, 1};
            font = "PuristaLight";
            sizeEx = 0.024;
            borderSize = 0;
            action = "['messages'] call LEG_fnc_openApp;";
        };
        
        class App7Shadow: RscText
        {
            idc = -1;
            x = 0.8095 * safezoneW + safezoneX;
            y = 0.232 * safezoneH + safezoneY;
            w = 0.055 * safezoneW;
            h = 0.08 * safezoneH;
            colorBackground[] = {0, 0, 0, 0.5};
        };
        
        class App7: RscButton
        {
            idc = 36107;
            text = "📷\nCamera";
            x = 0.808 * safezoneW + safezoneX;
            y = 0.23 * safezoneH + safezoneY;
            w = 0.055 * safezoneW;
            h = 0.08 * safezoneH;
            colorBackground[] = {0.2, 0.2, 0.25, 0.95};
            colorBackgroundActive[] = {0.25, 0.25, 0.3, 1};
            font = "PuristaLight";
            sizeEx = 0.024;
            borderSize = 0;
            action = "hint '📷 Appareil photo';";
        };
        
        class App8Shadow: RscText
        {
            idc = -1;
            x = 0.8735 * safezoneW + safezoneX;
            y = 0.232 * safezoneH + safezoneY;
            w = 0.055 * safezoneW;
            h = 0.08 * safezoneH;
            colorBackground[] = {0, 0, 0, 0.5};
        };
        
        class App8: RscButton
        {
            idc = 36108;
            text = "📍\nGPS";
            x = 0.872 * safezoneW + safezoneX;
            y = 0.23 * safezoneH + safezoneY;
            w = 0.055 * safezoneW;
            h = 0.08 * safezoneH;
            colorBackground[] = {0.2, 0.2, 0.25, 0.95};
            colorBackgroundActive[] = {0.25, 0.25, 0.3, 1};
            font = "PuristaLight";
            sizeEx = 0.024;
            borderSize = 0;
            action = "hint '📍 Navigation GPS';";
        };
        
        // ═══ LIGNE 3 ═══
        
        class App9Shadow: RscText
        {
            idc = -1;
            x = 0.6815 * safezoneW + safezoneX;
            y = 0.322 * safezoneH + safezoneY;
            w = 0.055 * safezoneW;
            h = 0.08 * safezoneH;
            colorBackground[] = {0, 0, 0, 0.5};
        };
        
        class App9: RscButton
        {
            idc = 36109;
            text = "☁️\nWeather";
            x = 0.68 * safezoneW + safezoneX;
            y = 0.32 * safezoneH + safezoneY;
            w = 0.055 * safezoneW;
            h = 0.08 * safezoneH;
            colorBackground[] = {0.2, 0.2, 0.25, 0.95};
            colorBackgroundActive[] = {0.25, 0.25, 0.3, 1};
            font = "PuristaLight";
            sizeEx = 0.024;
            borderSize = 0;
            action = "hint '☁️ Météo';";
        };
        
        class App10Shadow: RscText
        {
            idc = -1;
            x = 0.7455 * safezoneW + safezoneX;
            y = 0.322 * safezoneH + safezoneY;
            w = 0.055 * safezoneW;
            h = 0.08 * safezoneH;
            colorBackground[] = {0, 0, 0, 0.5};
        };
        
        class App10: RscButton
        {
            idc = 36110;
            text = "🎮\nGames";
            x = 0.744 * safezoneW + safezoneX;
            y = 0.32 * safezoneH + safezoneY;
            w = 0.055 * safezoneW;
            h = 0.08 * safezoneH;
            colorBackground[] = {0.2, 0.2, 0.25, 0.95};
            colorBackgroundActive[] = {0.25, 0.25, 0.3, 1};
            font = "PuristaLight";
            sizeEx = 0.024;
            borderSize = 0;
            action = "hint '🎮 Mini-jeux';";
        };
        
        class App11Shadow: RscText
        {
            idc = -1;
            x = 0.8095 * safezoneW + safezoneX;
            y = 0.322 * safezoneH + safezoneY;
            w = 0.055 * safezoneW;
            h = 0.08 * safezoneH;
            colorBackground[] = {0, 0, 0, 0.5};
        };
        
        class App11: RscButton
        {
            idc = 36111;
            text = "📱\nSocial";
            x = 0.808 * safezoneW + safezoneX;
            y = 0.32 * safezoneH + safezoneY;
            w = 0.055 * safezoneW;
            h = 0.08 * safezoneH;
            colorBackground[] = {0.2, 0.2, 0.25, 0.95};
            colorBackgroundActive[] = {0.25, 0.25, 0.3, 1};
            font = "PuristaLight";
            sizeEx = 0.024;
            borderSize = 0;
            action = "hint '📱 Réseaux sociaux';";
        };
        
        class App12Shadow: RscText
        {
            idc = -1;
            x = 0.8735 * safezoneW + safezoneX;
            y = 0.322 * safezoneH + safezoneY;
            w = 0.055 * safezoneW;
            h = 0.08 * safezoneH;
            colorBackground[] = {0, 0, 0, 0.5};
        };
        
        class App12: RscButton
        {
            idc = 36112;
            text = "🎵\nMusic";
            x = 0.872 * safezoneW + safezoneX;
            y = 0.32 * safezoneH + safezoneY;
            w = 0.055 * safezoneW;
            h = 0.08 * safezoneH;
            colorBackground[] = {0.2, 0.2, 0.25, 0.95};
            colorBackgroundActive[] = {0.25, 0.25, 0.3, 1};
            font = "PuristaLight";
            sizeEx = 0.024;
            borderSize = 0;
            action = "hint '🎵 Lecteur musique';";
        };
        
        // ═════════════════════════════════════════════════════════
        // 🎯 DOCK PREMIUM (4 apps essentielles avec ombres)
        // ═════════════════════════════════════════════════════════
        
        class Dock1Shadow: RscText
        {
            idc = -1;
            x = 0.6875 * safezoneW + safezoneX;
            y = 0.838 * safezoneH + safezoneY;
            w = 0.05 * safezoneW;
            h = 0.048 * safezoneH;
            colorBackground[] = {0, 0, 0, 0.6};
        };
        
        class Dock1: RscButton
        {
            idc = 36201;
            text = "📞";
            x = 0.686 * safezoneW + safezoneX;
            y = 0.836 * safezoneH + safezoneY;
            w = 0.05 * safezoneW;
            h = 0.048 * safezoneH;
            colorBackground[] = {0.15, 0.7, 0.25, 0.95};
            colorBackgroundActive[] = {0.2, 0.8, 0.3, 1};
            font = "PuristaLight";
            sizeEx = 0.04;
            borderSize = 0;
            action = "['contacts'] call LEG_fnc_openApp;";
        };
        
        class Dock2Shadow: RscText
        {
            idc = -1;
            x = 0.7475 * safezoneW + safezoneX;
            y = 0.838 * safezoneH + safezoneY;
            w = 0.05 * safezoneW;
            h = 0.048 * safezoneH;
            colorBackground[] = {0, 0, 0, 0.6};
        };
        
        class Dock2: RscButton
        {
            idc = 36202;
            text = "💬";
            x = 0.746 * safezoneW + safezoneX;
            y = 0.836 * safezoneH + safezoneY;
            w = 0.05 * safezoneW;
            h = 0.048 * safezoneH;
            colorBackground[] = {1, 0.8, 0.1, 0.95};
            colorBackgroundActive[] = {1, 0.85, 0.2, 1};
            font = "PuristaLight";
            sizeEx = 0.04;
            borderSize = 0;
            action = "['messages'] call LEG_fnc_openApp;";
        };
        
        class Dock3Shadow: RscText
        {
            idc = -1;
            x = 0.8075 * safezoneW + safezoneX;
            y = 0.838 * safezoneH + safezoneY;
            w = 0.05 * safezoneW;
            h = 0.048 * safezoneH;
            colorBackground[] = {0, 0, 0, 0.6};
        };
        
        class Dock3: RscButton
        {
            idc = 36203;
            text = "💰";
            x = 0.806 * safezoneW + safezoneX;
            y = 0.836 * safezoneH + safezoneY;
            w = 0.05 * safezoneW;
            h = 0.048 * safezoneH;
            colorBackground[] = {1, 0.5, 0.1, 0.95};
            colorBackgroundActive[] = {1, 0.6, 0.2, 1};
            font = "PuristaLight";
            sizeEx = 0.04;
            borderSize = 0;
            action = "['bank'] call LEG_fnc_openApp;";
        };
        
        class Dock4Shadow: RscText
        {
            idc = -1;
            x = 0.8675 * safezoneW + safezoneX;
            y = 0.838 * safezoneH + safezoneY;
            w = 0.05 * safezoneW;
            h = 0.048 * safezoneH;
            colorBackground[] = {0, 0, 0, 0.6};
        };
        
        class Dock4: RscButton
        {
            idc = 36204;
            text = "🚗";
            x = 0.866 * safezoneW + safezoneX;
            y = 0.836 * safezoneH + safezoneY;
            w = 0.05 * safezoneW;
            h = 0.048 * safezoneH;
            colorBackground[] = {0.2, 0.5, 1, 0.95};
            colorBackgroundActive[] = {0.3, 0.6, 1, 1};
            font = "PuristaLight";
            sizeEx = 0.04;
            borderSize = 0;
            action = "['garage'] call LEG_fnc_openApp;";
        };
    };
};

