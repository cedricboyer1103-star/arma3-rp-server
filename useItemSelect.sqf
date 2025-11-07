/*
    Author: Vincent
    Web site: www.the-programmer.com
    Discord: https://discord.the-programmer.com

    Terms of use:
        - This file is forbidden unless you have permission from the author. If you have this file without permission to use it please do not use it and do not share it.
        - If you have permission to use this file, you can use it on your server however it is strictly forbidden to share it.
        - Out of respect for the author please do not delete this information.
*/
_config = missionConfigFile >> "Max_Settings_EffetsEcran";

if (_item in (getArray (_config >> "item_cannabis"))) exitWith {
    if ((getNumber (_config >> "remove_item_on_use")) isEqualTo 1) then {
        if ([false,_item,1] call life_fnc_handleInv) then {
            [] spawn theprogrammer_effects_fnc_cannabis;
        };
    } else {
        [] spawn theprogrammer_effects_fnc_cannabis;
    };
};

if (_item in (getArray (_config >> "item_heroine"))) exitWith {
    if ((getNumber (_config >> "remove_item_on_use")) isEqualTo 1) then {
        if ([false,_item,1] call life_fnc_handleInv) then {
            [] spawn theprogrammer_effects_fnc_heroine;
        };
    } else {
        [] spawn theprogrammer_effects_fnc_heroine;
    };
};

if (_item in (getArray (_config >> "item_cocaine"))) exitWith {
    if ((getNumber (_config >> "remove_item_on_use")) isEqualTo 1) then {
        if ([false,_item,1] call life_fnc_handleInv) then {
            [] spawn theprogrammer_effects_fnc_cocaine;
        };
    } else {
        [] spawn theprogrammer_effects_fnc_cocaine;
    };
};

if (_item in (getArray (_config >> "item_alcool"))) exitWith {
    if ((getNumber (_config >> "remove_item_on_use")) isEqualTo 1) then {
        if ([false,_item,1] call life_fnc_handleInv) then {
            [] spawn theprogrammer_effects_fnc_alcool;
        };
    } else {
        [] spawn theprogrammer_effects_fnc_alcool;
    };
};

if (_item in (getArray (_config >> "item_control_alcool"))) exitWith {
    [] spawn theprogrammer_effects_fnc_alcoolTest;
};

if (_item in (getArray (_config >> "item_control_drugs"))) exitWith {
    [] spawn theprogrammer_effects_fnc_drogueTest;
};
