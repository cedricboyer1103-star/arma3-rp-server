/*
    Classes de base pour les dialogs Orange
    Version compatible avec theprogrammer_dialog_master.cpp
    Ne redéfinit PAS les classes si elles existent déjà
*/

// Les classes RscText et RscButton sont déjà définies par theprogrammer_dialog_master.cpp
// Ce fichier est maintenant vide mais doit exister pour éviter les erreurs d'include

// Si vous n'utilisez PAS theprogrammer_dialog_master.cpp, décommentez ces lignes:
/*
class RscText {
    access = 0;
    idc = -1;
    type = CT_STATIC;
    style = ST_LEFT;
    colorBackground[] = {0,0,0,0};
    colorText[] = {1,1,1,1};
    font = "PuristaLight";
    sizeEx = 0.03;
    lineSpacing = 1;
    fixedWidth = 0;
    shadow = 1;
    x = 0;
    y = 0;
    w = 0.2;
    h = 0.05;
    text = "";
};

class RscButton {
    access = 0;
    type = CT_BUTTON;
    style = ST_CENTER;
    default = 0;
    font = "PuristaMedium";
    sizeEx = 0.03;
    colorText[] = {1,1,1,1};
    colorDisabled[] = {0.4,0.4,0.4,1};
    colorBackground[] = {0,0,0,0.8};
    colorBackgroundDisabled[] = {0.3,0.3,0.3,0.5};
    colorBackgroundActive[] = {1,1,1,0.3};
    colorFocused[] = {0,0,0,0.8};
    colorShadow[] = {0,0,0,0};
    colorBorder[] = {0,0,0,1};
    soundEnter[] = {"\A3\ui_f\data\sound\RscButton\soundEnter",0.09,1};
    soundPush[] = {"\A3\ui_f\data\sound\RscButton\soundPush",0.09,1};
    soundClick[] = {"\A3\ui_f\data\sound\RscButton\soundClick",0.09,1};
    soundEscape[] = {"\A3\ui_f\data\sound\RscButton\soundEscape",0.09,1};
    x = 0;
    y = 0;
    w = 0.095589;
    h = 0.039216;
    shadow = 2;
    offsetX = 0.003;
    offsetY = 0.003;
    offsetPressedX = 0.002;
    offsetPressedY = 0.002;
    borderSize = 0;
};
*/
