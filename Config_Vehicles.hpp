/*
    ═══════════════════════════════════════════════════════════════
    📁 config/Config_Vehicles.hpp
    ═══════════════════════════════════════════════════════════════
    🚗 Configuration des véhicules disponibles au garage
    ═══════════════════════════════════════════════════════════════
    
    Structure :
    class NomClasse {
        displayName = "Nom affiché";
        price = 50000;              // Prix d'achat
        sellPrice = 25000;          // Prix de revente (50%)
        maxSpeed = 310;             // km/h
        seats = 4;                  // Places
        trunk = 800;                // Capacité coffre (litres)
        fuel = "Essence Sans Plomb 98";
        power = 450;                // Chevaux
        icon = "\A3\ui_f\data\GUI\Cfg\Ranks\sergeant_gs.paa";
        side = "civ";               // "civ", "cop", "medic"
    };
*/

class LEG_Vehicles
{
    // ═══════════════════════════════════════════════════════════
    // 🚗 VÉHICULES CIVILS - CATÉGORIE ÉCONOMIQUE
    // ═══════════════════════════════════════════════════════════
    
    class C_Hatchback_01_F {
        displayName = "Hatchback (Citadine)";
        price = 15000;
        sellPrice = 7500;
        maxSpeed = 180;
        seats = 4;
        trunk = 350;
        fuel = "Essence Sans Plomb 95";
        power = 90;
        side = "civ";
    };
    
    class C_Offroad_01_F {
        displayName = "Offroad (4x4)";
        price = 25000;
        sellPrice = 12500;
        maxSpeed = 160;
        seats = 6;
        trunk = 500;
        fuel = "Diesel";
        power = 140;
        side = "civ";
    };
    
    class C_SUV_01_F {
        displayName = "SUV";
        price = 45000;
        sellPrice = 22500;
        maxSpeed = 210;
        seats = 6;
        trunk = 650;
        fuel = "Essence Sans Plomb 98";
        power = 220;
        side = "civ";
    };
    
    // ═══════════════════════════════════════════════════════════
    // 🏎️ VÉHICULES CIVILS - CATÉGORIE SPORTIVE
    // ═══════════════════════════════════════════════════════════
    
    class C_Hatchback_01_sport_F {
        displayName = "Hatchback Sport";
        price = 75000;
        sellPrice = 37500;
        maxSpeed = 240;
        seats = 2;
        trunk = 200;
        fuel = "Essence Sans Plomb 98";
        power = 280;
        side = "civ";
    };
    
    class C_Van_01_transport_F {
        displayName = "Camionnette Transport";
        price = 35000;
        sellPrice = 17500;
        maxSpeed = 150;
        seats = 3;
        trunk = 1200;
        fuel = "Diesel";
        power = 120;
        side = "civ";
    };
    
    class C_Van_01_box_F {
        displayName = "Camionnette Utilitaire";
        price = 40000;
        sellPrice = 20000;
        maxSpeed = 140;
        seats = 3;
        trunk = 1500;
        fuel = "Diesel";
        power = 120;
        side = "civ";
    };
    
    class C_Van_02_transport_F {
        displayName = "Van Transport";
        price = 55000;
        sellPrice = 27500;
        maxSpeed = 160;
        seats = 12;
        trunk = 800;
        fuel = "Diesel";
        power = 180;
        side = "civ";
    };
    
    // ═══════════════════════════════════════════════════════════
    // 🚓 VÉHICULES POLICE
    // ═══════════════════════════════════════════════════════════
    
    class B_GEN_Offroad_01_gen_F {
        displayName = "Offroad Police";
        price = 0;
        sellPrice = 0;
        maxSpeed = 180;
        seats = 6;
        trunk = 400;
        fuel = "Diesel";
        power = 160;
        side = "cop";
    };
    
    class C_SUV_01_F_police {
        displayName = "SUV Police";
        price = 0;
        sellPrice = 0;
        maxSpeed = 220;
        seats = 6;
        trunk = 500;
        fuel = "Essence Sans Plomb 98";
        power = 240;
        side = "cop";
    };
    
    class C_Van_02_vehicle_F_police {
        displayName = "Fourgon Police";
        price = 0;
        sellPrice = 0;
        maxSpeed = 170;
        seats = 12;
        trunk = 1000;
        fuel = "Diesel";
        power = 200;
        side = "cop";
    };
    
    // ═══════════════════════════════════════════════════════════
    // 🚑 VÉHICULES MÉDICAUX
    // ═══════════════════════════════════════════════════════════
    
    class C_Offroad_01_F_medic {
        displayName = "Offroad Médical";
        price = 0;
        sellPrice = 0;
        maxSpeed = 170;
        seats = 6;
        trunk = 600;
        fuel = "Diesel";
        power = 150;
        side = "medic";
    };
    
    class C_Van_02_medevac_F {
        displayName = "Ambulance";
        price = 0;
        sellPrice = 0;
        maxSpeed = 160;
        seats = 8;
        trunk = 800;
        fuel = "Diesel";
        power = 180;
        side = "medic";
    };
    
    // ═══════════════════════════════════════════════════════════
    // 🏍️ MOTOS
    // ═══════════════════════════════════════════════════════════
    
    class C_Quadbike_01_F {
        displayName = "Quad";
        price = 8000;
        sellPrice = 4000;
        maxSpeed = 120;
        seats = 2;
        trunk = 100;
        fuel = "Essence Sans Plomb 95";
        power = 45;
        side = "civ";
    };
    
    // ═══════════════════════════════════════════════════════════
    // 🚛 VÉHICULES LOURDS
    // ═══════════════════════════════════════════════════════════
    
    class C_Truck_02_transport_F {
        displayName = "Camion Zamak Transport";
        price = 120000;
        sellPrice = 60000;
        maxSpeed = 110;
        seats = 3;
        trunk = 3000;
        fuel = "Diesel";
        power = 350;
        side = "civ";
    };
    
    class C_Truck_02_covered_F {
        displayName = "Camion Zamak Bâché";
        price = 135000;
        sellPrice = 67500;
        maxSpeed = 110;
        seats = 3;
        trunk = 3500;
        fuel = "Diesel";
        power = 350;
        side = "civ";
    };
};