/*
    ═══════════════════════════════════════════════════════════════
    📱 defines.hpp - Legion RP
    ═══════════════════════════════════════════════════════════════
    Dernière mise à jour : 2025-11-07 09:31:43
    Auteur : cedricboyer1103-star
    Testé et vérifié : ✅
    ═══════════════════════════════════════════════════════════════
*/

// ═══════════════════════════════════════════════════════════════
// TYPES DE CONTRÔLES GUI
// ═══════════════════════════════════════════════════════════════

#define CT_STATIC           0
#define CT_BUTTON           1
#define CT_EDIT             2
#define CT_SLIDER           3
#define CT_COMBO            4
#define CT_LISTBOX          5
#define CT_TOOLBOX          6
#define CT_CHECKBOXES       7
#define CT_PROGRESS         8
#define CT_HTML             9
#define CT_STATIC_SKEW      10
#define CT_ACTIVETEXT       11
#define CT_TREE             12
#define CT_STRUCTURED_TEXT  13
#define CT_CONTEXT_MENU     14
#define CT_CONTROLS_GROUP   15
#define CT_SHORTCUTBUTTON   16
#define CT_XKEYDESC         40
#define CT_XBUTTON          41
#define CT_XLISTBOX         42
#define CT_XSLIDER          43
#define CT_XCOMBO           44
#define CT_ANIMATED_TEXTURE 45
#define CT_OBJECT           80
#define CT_OBJECT_ZOOM      81
#define CT_OBJECT_CONTAINER 82
#define CT_OBJECT_CONT_ANIM 83
#define CT_LINEBREAK        98
#define CT_USER             99
#define CT_MAP              100
#define CT_MAP_MAIN         101
#define CT_LISTNBOX         102
#define CT_ITEMSLOT         103
#define CT_CHECKBOX         77

// ═══════════════════════════════════════════════════════════════
// STYLES DE CONTRÔLES
// ═══════════════════════════════════════════════════════════════

#define ST_POS            0x0F
#define ST_HPOS           0x03
#define ST_VPOS           0x0C
#define ST_LEFT           0x00
#define ST_RIGHT          0x01
#define ST_CENTER         0x02
#define ST_DOWN           0x04
#define ST_UP             0x08
#define ST_VCENTER        0x0C
#define ST_TYPE           0xF0
#define ST_SINGLE         0x00
#define ST_MULTI          0x10
#define ST_TITLE_BAR      0x20
#define ST_PICTURE        0x30
#define ST_FRAME          0x40
#define ST_BACKGROUND     0x50
#define ST_GROUP_BOX      0x60
#define ST_GROUP_BOX2     0x70
#define ST_HUD_BACKGROUND 0x80
#define ST_TILE_PICTURE   0x90
#define ST_WITH_RECT      0xA0
#define ST_LINE           0xB0
#define ST_SHADOW         0x100
#define ST_NO_RECT        0x200
#define ST_KEEP_ASPECT_RATIO  0x800

// ═══════════════════════════════════════════════════════════════
// STYLES ADDITIONNELS
// ═══════════════════════════════════════════════════════════════

#define LB_TEXTURES       0x10
#define LB_MULTI          0x20

// ═══════════════════════════════════════════════════════════════
// CLASSES DE BASE
// ═══════════════════════════════════════════════════════════════

class RscText {
    access = 0;
    idc = -1;
    type = CT_STATIC;
    style = ST_LEFT;
    colorBackground[] = {0,0,0,0};
    colorText[] = {1,1,1,1};
    font = "PuristaMedium";
    sizeEx = 0.03;
    shadow = 1;
    x = 0;
    y = 0;
    w = 0.3;
    h = 0.05;
    text = "";
};

class RscStructuredText {
    access = 0;
    type = CT_STRUCTURED_TEXT;
    idc = -1;
    style = ST_LEFT;
    colorText[] = {1,1,1,1};
    class Attributes {
        font = "PuristaMedium";
        color = "#ffffff";
        colorLink = "#D09B43";
        align = "left";
        shadow = 1;
    };
    x = 0;
    y = 0;
    h = 0.035;
    w = 0.1;
    text = "";
    size = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
    shadow = 1;
};

class RscPicture {
    access = 0;
    type = CT_STATIC;
    style = ST_PICTURE;
    colorBackground[] = {0,0,0,0};
    colorText[] = {1,1,1,1};
    font = "PuristaMedium";
    sizeEx = 0;
    lineSpacing = 0;
    text = "";
    fixedWidth = 0;
    shadow = 0;
    x = 0;
    y = 0;
    w = 0.2;
    h = 0.15;
};

class RscButton {
    access = 0;
    type = CT_BUTTON;
    style = ST_CENTER;
    text = "";
    colorText[] = {1,1,1,1};
    colorDisabled[] = {0.4,0.4,0.4,1};
    colorBackground[] = {0,0,0,0.8};
    colorBackgroundDisabled[] = {0,0,0,0.5};
    colorBackgroundActive[] = {0,0,0,1};
    colorFocused[] = {0,0,0,1};
    colorShadow[] = {0,0,0,0};
    colorBorder[] = {0,0,0,1};
    soundEnter[] = {"\A3\ui_f\data\sound\RscButton\soundEnter",0.09,1};
    soundPush[] = {"\A3\ui_f\data\sound\RscButton\soundPush",0.09,1};
    soundClick[] = {"\A3\ui_f\data\sound\RscButton\soundClick",0.09,1};
    soundEscape[] = {"\A3\ui_f\data\sound\RscButton\soundEscape",0.09,1};
    font = "PuristaMedium";
    sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
    offsetX = 0.003;
    offsetY = 0.003;
    offsetPressedX = 0.002;
    offsetPressedY = 0.002;
    borderSize = 0;
    w = 0.095589;
    h = 0.039216;
};

class RscListBox {
    access = 0;
    type = CT_LISTBOX;
    style = ST_MULTI;
    colorBackground[] = {0,0,0,0.3};
    colorText[] = {1,1,1,1};
    colorScrollbar[] = {1,0,0,0};
    colorSelect[] = {0,0,0,1};
    colorSelect2[] = {0,0,0,1};
    colorSelectBackground[] = {0.95,0.95,0.95,1};
    colorSelectBackground2[] = {1,1,1,0.5};
    font = "PuristaMedium";
    sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
    rowHeight = 0.03;
    soundSelect[] = {"\A3\ui_f\data\sound\RscListbox\soundSelect",0.09,1};
};

class RscCombo {
    access = 0;
    type = CT_COMBO;
    style = ST_LEFT + LB_TEXTURES;
    x = 0;
    y = 0;
    w = 0.12;
    h = 0.035;
    colorSelect[] = {0,0,0,1};
    colorText[] = {1,1,1,1};
    colorBackground[] = {0,0,0,1};
    colorScrollbar[] = {1,0,0,1};
    colorDisabled[] = {1,1,1,0.25};
    colorPicture[] = {1,1,1,1};
    colorPictureSelected[] = {1,1,1,1};
    colorPictureDisabled[] = {1,1,1,0.25};
    colorPictureRight[] = {1,1,1,1};
    colorPictureRightSelected[] = {1,1,1,1};
    colorPictureRightDisabled[] = {1,1,1,0.25};
    colorTextRight[] = {1,1,1,1};
    colorSelectRight[] = {0,0,0,1};
    colorSelect2Right[] = {0,0,0,1};
    tooltipColorText[] = {1,1,1,1};
    tooltipColorBox[] = {1,1,1,1};
    tooltipColorShade[] = {0,0,0,0.65};
    soundSelect[] = {"\A3\ui_f\data\sound\RscCombo\soundSelect",0.1,1};
    soundExpand[] = {"\A3\ui_f\data\sound\RscCombo\soundExpand",0.1,1};
    soundCollapse[] = {"\A3\ui_f\data\sound\RscCombo\soundCollapse",0.1,1};
    maxHistoryDelay = 1;
    font = "PuristaMedium";
    sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
    shadow = 0;
    
    class ComboScrollBar {
        color[] = {1,1,1,0.6};
        colorActive[] = {1,1,1,1};
        colorDisabled[] = {1,1,1,0.3};
        thumb = "\A3\ui_f\data\gui\cfg\scrollbar\thumb_ca.paa";
        arrowEmpty = "\A3\ui_f\data\gui\cfg\scrollbar\arrowEmpty_ca.paa";
        arrowFull = "\A3\ui_f\data\gui\cfg\scrollbar\arrowFull_ca.paa";
        border = "\A3\ui_f\data\gui\cfg\scrollbar\border_ca.paa";
    };
};

class RscEdit {
    access = 0;
    type = CT_EDIT;
    style = ST_LEFT+ST_FRAME;
    x = 0;
    y = 0;
    h = 0.04;
    w = 0.2;
    colorBackground[] = {0,0,0,1};
    colorText[] = {0.95,0.95,0.95,1};
    colorSelection[] = {0.8784,0.8471,0.651,1};
    font = "PuristaMedium";
    sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
    autocomplete = "";
    text = "";
};

// ═══════════════════════════════════════════════════════════════
// CLASSES LIFE
// ═══════════════════════════════════════════════════════════════

class Life_RscText : RscText {};
class Life_RscStructuredText : RscStructuredText {};
class Life_RscPicture : RscPicture {};
class Life_RscTextSmall : RscText {
    sizeEx = 0.02;
};
class Life_RscTitle : Life_RscText {
    style = ST_CENTER;
    x = 0.15;
    y = 0.2;
    w = 0.7;
    colorText[] = {0.95,0.95,0.95,1};
    sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
    font = "PuristaMedium";
};

class Life_RscButton : RscButton {
    style = "0x02 + 0x0C";
};

class Life_RscButtonMenu : Life_RscButton {
    idc = -1;
    type = CT_BUTTON;
    style = ST_CENTER + ST_FRAME + ST_HUD_BACKGROUND;
    default = 0;
    shadow = 1;
    x = 0;
    y = 0;
    w = 0.095589;
    h = 0.039216;
    colorBackground[] = {0,0,0,0.8};
    colorBackgroundActive[] = {0.95,0.95,0.95,0.8};
    colorFocused[] = {1,0.5,0,1};
    
    class TextPos {
        left = "0.25 * (((safezoneW / safezoneH) min 1.2) / 40)";
        top = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) - (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)) / 2";
        right = 0.005;
        bottom = 0.0;
    };
};

class Life_RscListBox : RscListBox {};
class Life_RscEdit : RscEdit {};
class Life_RscCombo : RscCombo {};

// ═══════════════════════════════════════════════════════════════
// FIN DU FICHIER
// ═══════════════════════════════════════════════════════════════