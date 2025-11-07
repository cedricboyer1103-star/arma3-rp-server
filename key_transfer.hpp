/*
    Author: Maxence
    Web site: www.the-programmer.com
    Discord: https://discord.the-programmer.com

    Terms of use:
        - This file is forbidden unless you have permission from the author. If you have this file without permission to use it please do not use it and do not share it.
        - If you have permission to use this file, you can use it on your server however it is strictly forbidden to share it.
        - Out of respect for the author please do not delete this information.
*/

#include "defines.hpp"

class Max_KeyTransfer_Menu {
    idd = 1580;
    name = "Max_KeyTransfer_Menu";
    movingenable = 0;
    enablesimulation = 1;
    onload = "[] spawn max_keytransfer_fnc_keyTransferMenu;";
    
    class controlsBackground {
        class Life_RscTitleBackground: Life_RscText {
            colorbackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.463])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',1])", "(profilenamespace getvariable ['GUI_BCG_RGB_A',0.7])"};
            idc = -1;
            x = 0.293479166666667 * safezoneW + safezoneX;
            y = 0.317335299901671 * safezoneH + safezoneY;
            w = 0.409125 * safezoneW;
            h = 0.0238643067846609 * safezoneH;
        };
        
        class MainBackground: Life_RscText {
            colorbackground[] = {0, 0, 0, 0.7};
            idc = -1;
            x = 0.293229166666667 * safezoneW + safezoneX;
            y = 0.344294985250737 * safezoneH + safezoneY;
            w = 0.409125 * safezoneW;
            h = 0.364652900688299 * safezoneH;
        };
    };
    
    class controls {
        class Title: Life_RscTitle {
            colorbackground[] = {0, 0, 0, 0};
            idc = 1581;
            text = "";
            x = 0.293479166666667 * safezoneW + safezoneX;
            y = 0.317335299901671 * safezoneH + safezoneY;
            w = 0.409125 * safezoneW;
            h = 0.0238643067846609 * safezoneH;
        };
        
        class KeyChainList: Life_RscListBox {
            idc = 1582;
            text = "";
            sizeex = 0.035;
            x = 0.2996875 * safezoneW + safezoneX;
            y = 0.356361848574238 * safezoneH + safezoneY;
            w = 0.395625 * safezoneW;
            h = 0.208043264503441 * safezoneH;
        };
        
        class CloseButtonKey: Life_RscButtonMenu {
            idc = -1;
            text = "$STR_Global_Close";
            onbuttonclick = "closeDialog 0;";
            x = 0.293479166666667 * safezoneW + safezoneX;
            y = 0.710648967551623 * safezoneH + safezoneY;
            w = 0.0825625 * safezoneW;
            h = 0.0238643067846609 * safezoneH;
        };
        
        class NearPlayers: Life_RscCombo {
            idc = 1583;
            x = 0.392291666666667 * safezoneW + safezoneX;
            y = 0.57298918387414 * safezoneH + safezoneY;
            w = 0.209270833333333 * safezoneW;
            h = 0.0238643067846609 * safezoneH;
        };
        
        class GiveKey: Life_RscButtonMenu {
            idc = 1584;
            text = "";
            colorbackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", 0.5};
            onbuttonclick = "[] spawn max_keytransfer_fnc_keyTransferAction;";
            x = 0.423 * safezoneW + safezoneX;
            y = 0.671450344149459 * safezoneH + safezoneY;
            w = 0.15 * safezoneW;
            h = 0.0238643067846609 * safezoneH;
        };
        
        class textPrice: Life_RscEdit {
            idc = 1585;
            text = "";
            x = 0.4046875 * safezoneW + safezoneX;
            y = 0.607404129793511 * safezoneH + safezoneY;
            w = 0.0942708333333333 * safezoneW;
            h = 0.0238643067846609 * safezoneH;
        };
        
        class textDuration: Life_RscEdit {
            idc = 1586;
            text = "";
            x = 0.50078125 * safezoneW + safezoneX;
            y = 0.607404129793511 * safezoneH + safezoneY;
            w = 0.0942708333333333 * safezoneW;
            h = 0.0238643067846609 * safezoneH;
        };
        
        class GiveTemporary: Life_RscButtonMenu {
            idc = 1587;
            text = "";
            colorbackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", 0.5};
            onbuttonclick = "[] spawn max_keytransfer_fnc_keyTransferTemporaryAction;";
            x = 0.423 * safezoneW + safezoneX;
            y = 0.638869223205506 * safezoneH + safezoneY;
            w = 0.15 * safezoneW;
            h = 0.0238643067846609 * safezoneH;
        };
    };
};