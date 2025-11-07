class LEG_SpawnMenu {
    idd = 9900;
    movingEnable = 0;
    enableSimulation = 1;
    onLoad = "params ['_disp']; uiNamespace setVariable ['LEG_Spawn_Display', _disp]; private _data = uiNamespace getVariable ['LEG_Spawn_List', []]; private _lb = _disp displayCtrl 9901; { private _idx = _lb lbAdd (_x select 0); _lb lbSetData [_idx, (_x select 1)]; } forEach _data; if ((lbSize _lb) > 0) then { _lb lbSetCurSel 0; };";

    class controlsBackground {
        class Title: RscText {
            idc = -1;
            text = "Choix du point de spawn";
            x = 0.30;
            y = 0.18;
            w = 0.40;
            h = 0.04;
            colorBackground[] = {0,0,0,0.8};
        };
    };

    class controls {
        class SpawnList: RscListbox {
            idc = 9901;
            x = 0.30;
            y = 0.24;
            w = 0.40;
            h = 0.40;
            colorDisabled[] = {1,1,1,0.25};
            soundSelect[] = {"",0.1,1};
        };

        class BtnSpawn: RscButton {
            idc = 9902;
            text = "SPAWN";
            x = 0.30;
            y = 0.66;
            w = 0.19;
            h = 0.05;
            action = "private _disp = uiNamespace getVariable ['LEG_Spawn_Display', displayNull]; if (isNull _disp) exitWith {}; private _lb = _disp displayCtrl 9901; private _idx = lbCurSel _lb; if (_idx < 0) exitWith { hint 'Sélectionne un point de spawn.'; }; private _marker = _lb lbData _idx; player setPosATL (getMarkerPos _marker); closeDialog 0;";
        };

        class BtnClose: RscButton {
            idc = 9903;
            text = "FERMER";
            x = 0.51;
            y = 0.66;
            w = 0.19;
            h = 0.05;
            action = "closeDialog 0;";
        };
    };
};


