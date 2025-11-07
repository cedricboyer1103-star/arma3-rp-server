/*
    ═══════════════════════════════════════════════════════════════
    📱 CONFIG.CPP - IPHONE XI 3D + ORANGE SYSTEM
    ═══════════════════════════════════════════════════════════════
*/

class CfgPatches {
    class Legion_iPhone_3D {
        units[] = {};
        weapons[] = {"Legion_iPhone_XI"};
        requiredVersion = 0.1;
        requiredAddons[] = {"TheProgrammer_IphoneXI"};
    };
};

class CfgWeapons {
    class ItemCore;
    class ItemRadio: ItemCore {};
    
    class Legion_iPhone_XI: ItemRadio {
        scope = 2;
        displayName = "iPhone XI 📱";
        descriptionShort = "iPhone XI avec Orange<br/>Appuyez sur Y pour utiliser";
        picture = "\TheProgrammer_IphoneXI\phone\IphoneXI_Icon.paa";
        model = "\TheProgrammer_IphoneXI\phone\p3d\iphone_xi.p3d";
        
        hiddenSelections[] = {"screen"};
        hiddenSelectionsTextures[] = {"\iphonexi_assets\menus\main_menu.paa"};
    };
};

class CfgFunctions {
    class LIFE {
        tag = "LIFE";
        class Phone3D {
            file = "core\phone3d";
            class usePhone3D {};
            class changeScreen {};
            class updateTexture {};
        };
    };
};
