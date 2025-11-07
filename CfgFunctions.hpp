/*
    ═══════════════════════════════════════════════════════════════
    📱 CfgFunctions.hpp - VERSION CORRIGÉE
    ═══════════════════════════════════════════════════════════════
    ✅ AJOUT : Section Garage + Économie + Vehicle
    À inclure dans votre description.ext
    ═══════════════════════════════════════════════════════════════
*/

class CfgFunctions {
    class LEG {
        tag = "LEG";
        
        // ═══ Fonctions iPhone 3D ═══
        class Phone3D {
            file = "core\phone3d";
            
            class initPhone3D {
                preInit = 0;
                postInit = 1;
            };
            
            class usePhone3D {};
            class storePhone3D {};
            class changeScreen3D {};
            class openPhone3DInterface {};
        };
        
        // ═══ Fonctions Orange ═══
        class Orange {
            file = "core\orange";
            
            class addOrangeVendorAction {};
            class addOrangeZoneAction {};
            class buyPlan {};
            class buySIM {};
            class checkPlanExpiry {};
            class openOrangeShop {};
            class orangeActions {};
            class orangeApp {};
            class removeOrangeZoneAction {};
            class setupOrangeShop {};
        };
        
        // ═══ Fonctions Téléphone ═══
        class Phone {
            file = "core\phone";
            
            class bankApp {};
            class closePhone {};
            class contactsApp {};
            class garageApp {};
            class homeScreen {};
            class messagesApp {};
            class openApp {};
            class openPhone {};
            class openPhone_withSIM {};
            class settingsApp {};
        };
        
        // ✅ NOUVEAU : Fonctions Garage
        class Garage {
            file = "core\garage";
            
            class openGarage {};
            class closeGarage {};
            class populateList {};
            class selectVehicle {};
            class spawnSelected {};
            class storeVehicle {};
        };
        
        // ✅ NOUVEAU : Fonctions Économie
        class Economy {
            file = "core\economy";
            
            class initMoney {};
            class getMoney {};
            class addMoney {};
            class removeMoney {};
            class saveMoney {};
            class loadMoney {};
        };
        
        // ✅ NOUVEAU : Fonctions Véhicule
        class Vehicle {
            file = "core\vehicle";
            
            class keyLockSystem {};
            class setOwner {};
        };
    };
};
