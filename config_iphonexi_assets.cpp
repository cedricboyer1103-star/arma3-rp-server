/*
    ═══════════════════════════════════════════════════════════════
    📱 config.cpp - iphonexi_assets Addon
    ═══════════════════════════════════════════════════════════════
    À placer dans le dossier iphonexi_assets/ avant de packager en .pbo
    ═══════════════════════════════════════════════════════════════
*/

class CfgPatches {
    class iphonexi_assets {
        name = "iPhone XI Assets";
        author = "Maxence / Legion RP";
        url = "";
        
        units[] = {};
        weapons[] = {};
        
        requiredVersion = 1.70;
        requiredAddons[] = {
            "A3_Data_F"
        };
        
        version = "1.0";
        
        // Liste tous les fichiers .paa pour qu'ils soient chargés
        skipWhenMissingDependencies = 1;
    };
};

class CfgMods {
    class iphonexi_assets {
        name = "iPhone XI Assets";
        author = "Maxence / Legion RP";
        timepacked = "1716556597";
        
        actionName = "Website";
        actionUrl = "";
        
        description = "Textures et assets graphiques pour iPhone XI 3D";
        logo = "\iphonexi_assets\icons\adminMenu.paa";
        logoOver = "\iphonexi_assets\icons\adminMenu.paa";
        logoSmall = "\iphonexi_assets\icons\adminMenu.paa";
        tooltip = "iPhone XI Assets";
        tooltipOwned = "iPhone XI Assets";
        overview = "284 textures HD pour le système iPhone 3D";
        hideName = 0;
        hidePicture = 0;
    };
};
