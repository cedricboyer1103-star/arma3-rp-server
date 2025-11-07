if (!hasInterface) exitWith {};

private _nearGarage = false;
{
    if (player distance (getMarkerPos _x) < 10) exitWith { _nearGarage = true; };
} forEach ["civ_garage_1", "cop_garage_1", "medic_garage_1"];

if (!_nearGarage) exitWith {
    hint "❌ Tu dois être près d'un garage !";
};

createDialog "LEG_Garage_Dialog";