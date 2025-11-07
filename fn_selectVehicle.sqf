disableSerialization;
params ["_control", "_selectedIndex"];

private _display = ctrlParent _control;
private _infoCtrl = _display displayCtrl 35020;
private _invCtrl = _display displayCtrl 35021;

if (_selectedIndex < 0) exitWith {};

private _class = _control lbData _selectedIndex;
private _garageIndex = _control lbValue _selectedIndex;

private _uid = getPlayerUID player;
private _garage = profileNamespace getVariable [format["LEG_Garage_%1", _uid], []];
private _vehData = _garage param [_garageIndex, []];

if (count _vehData == 0) exitWith {};

_vehData params ["_vClass", "_damage", "_fuel", "_inventory", "_plate"];

private _cfg = configFile >> "LEG_Vehicles" >> _class;
private _name = getText (_cfg >> "displayName");
private _price = getNumber (_cfg >> "price");
private _sellPrice = getNumber (_cfg >> "sellPrice");
private _maxSpeed = getNumber (_cfg >> "maxSpeed");
private _seats = getNumber (_cfg >> "seats");
private _trunk = getNumber (_cfg >> "trunk");
private _fuelType = getText (_cfg >> "fuel");
private _power = getNumber (_cfg >> "power");

private _damagePercent = round ((1 - _damage) * 100);
private _fuelPercent = round (_fuel * 100);

private _assuranceState = if (_damagePercent > 80) then { "Assuré" } else { "⚠️ Assurance expirée" };
private _assuranceLevel = if (_damagePercent > 90) then { "⭐⭐⭐" } else { "⭐⭐" };

private _infoText = format [
    "<t size='1.1' color='#ff9933'>%1</t><br/><t size='0.05'> </t><br/>" +
    "<t size='0.85' color='#ffcc66'>Prix d'achat :</t> <t color='#99ff99'>%2€</t><br/>" +
    "<t size='0.85' color='#ffcc66'>Prix de vente :</t> <t color='#ff9999'>%3€</t><br/>" +
    "<t size='0.02'> </t><br/>" +
    "<t size='0.85' color='#ffcc66'>Contrôle technique :</t> <t color='#99ff99'>Valide</t><br/>" +
    "<t size='0.85' color='#ffcc66'>État de l'assurance :</t> <t color='#99ff99'>%4</t><br/>" +
    "<t size='0.85' color='#ffcc66'>Niveau d'assurance :</t> <t color='#ffcc66'>%5</t><br/>" +
    "<t size='0.02'> </t><br/>" +
    "<t size='0.85' color='#ffcc66'>Plaque :</t> <t color='#cccccc'>%6</t><br/>" +
    "<t size='0.85' color='#ffcc66'>Vitesse Max :</t> <t color='#cccccc'>%7 km/h</t><br/>" +
    "<t size='0.85' color='#ffcc66'>Puissance :</t> <t color='#cccccc'>%8 CV</t><br/>" +
    "<t size='0.85' color='#ffcc66'>Sièges :</t> <t color='#cccccc'>%9</t><br/>" +
    "<t size='0.85' color='#ffcc66'>Type d'essence :</t> <t color='#cccccc'>%10</t><br/>" +
    "<t size='0.85' color='#ffcc66'>Réservoir :</t> <t color='#cccccc'>%11 / 100</t>",
    _name, _price, _sellPrice, _assuranceState, _assuranceLevel, _plate,
    _maxSpeed, _power, _seats - 1, _fuelType, _fuelPercent
];

_infoCtrl ctrlSetStructuredText parseText _infoText;

private _invText = "<t size='0.9' color='#ffcc66'>▼ Inventaire du véhicule</t><br/>";
if (count _inventory > 0) then {
    {
        _x params ["_item", "_qty"];
        _invText = _invText + format["<t size='0.85' color='#cccccc'>  • %1 (%2)</t><br/>", _item, _qty];
    } forEach _inventory;
} else {
    _invText = _invText + "<t size='0.85' color='#999999'>  Coffre vide</t>";
};

_invCtrl ctrlSetStructuredText parseText _invText;
