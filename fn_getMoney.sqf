params [["_type", "cash", [""]]];
private _cash = player getVariable ["cash", 0];
private _bank = player getVariable ["bank", 0];

switch (_type) do {
    case "cash": { _cash };
    case "bank": { _bank };
    case "total": { _cash + _bank };
    default { 0 };
};