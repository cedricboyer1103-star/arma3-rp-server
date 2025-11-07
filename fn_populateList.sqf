/*
    ═══════════════════════════════════════════════════════════════
    📁 core/garage/fn_populateList.sqf
    ═══════════════════════════════════════════════════════════════
    
    🎯 Remplir la liste des véhicules dans le garage
    
    📝 Appelé par : fn_openGarage.sqf
*/

// Vider la liste actuelle
lbClear 2800;

// Récupérer les véhicules du joueur
private _vehicles = player getVariable ["owned_vehicles", []];

// Si aucun véhicule
if (count _vehicles == 0) exitWith {
    lbAdd [2800, "Aucun véhicule dans le garage"];
    lbSetData [2800, 0, ""];
    lbSetColor [2800, 0, [0.7, 0.7, 0.7, 1]];
};

// Ajouter chaque véhicule à la liste
{
    private _vehicleClass = _x select 0;
    private _vehicleName = getText (configFile >> "CfgVehicles" >> _vehicleClass >> "displayName");
    private _plate = _x select 1;
    private _index = lbAdd [2800, format["%1 [%2]", _vehicleName, _plate]];
    
    // Stocker les données du véhicule
    lbSetData [2800, _index, str _forEachIndex];
    
    // Couleur selon le statut
    private _color = [0, 1, 0, 1]; // Vert = disponible
    lbSetColor [2800, _index, _color];
    
} forEach _vehicles;

// Sélectionner le premier véhicule
lbSetCurSel [2800, 0];
