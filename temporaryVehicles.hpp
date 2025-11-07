/*
    Author: Maxence
    Web site: www.the-programmer.com
    Discord : https://discord.the-programmer.com

    Terms of use:
        - This file is forbidden unless you have permission from the author. If you have this file without permission to use it please do not use it and do not share it.
        - If you have permission to use this file, you can use it on your server however it is strictly forbidden to share it.
        - Out of respect for the author please do not delete this information.
*/
class Maxence_Temporary_Keys {
    idd = 3700;
    name = "Maxence_Temporary_Keys";
    movingEnabled = 0;
    enableSimulation = 1;
    onLoad = "";
    
    class controlsBackground {
        class Life_RscTitleBackground : Life_RscText {
            colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", "(profilenamespace getvariable ['GUI_BCG_RGB_A',0.7])"};
            idc = -1;
            x = 0.1;
            y = 0.2;
            w = 0.8;
            h = (1 / 25);
        };
        
        class MainBackground : Life_RscText {
            colorBackground[] = {0,0,0,0.7};
            idc = -1;
            x = 0.1;
            y = 0.2 + (11 / 250);
            w = 0.8;
            h = 0.75 - (22 / 250);
        };
        
        class Title : Life_RscTitle {
            idc = 3711;
            text = "";
            x = 0.1;
            y = 0.2;
            w = 0.8;
            h = (1 / 25);
        };
        
        class VehicleTitleBox : Life_RscText {
            idc = 3718;
            text = "";
            colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", "(profilenamespace getvariable ['GUI_BCG_RGB_A',0.7])"};
            x = 0.11;
            y = 0.26;
            w = 0.3;
            h = (1 / 25);
        };
        
        class VehicleInfoHeader : Life_RscText {
            idc = 3702;
            text = "$STR_GUI_VehInfo";
            colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", "(profilenamespace getvariable ['GUI_BCG_RGB_A',0.7])"};
            x = 0.42;
            y = 0.26;
            w = 0.46;
            h = (1 / 25);
        };
        
        class CloseBtn : Life_RscButtonMenu {
            idc = -1;
            text = "$STR_Global_Close";
            onButtonClick = "closeDialog 0;";
            x = -0.06 + (6.25 / 40) + (1 / 250 / (safezoneW / safezoneH));
            y = 0.95 - (1 / 25);
            w = (6.25 / 40);
            h = (1 / 25);
            class Attributes {align = "center";};
        };
        
        class UnimpoundVeh : Life_RscButtonMenu {
            idc = 3717;
            text = "$STR_Global_Retrieve";
            onButtonClick = "[] spawn max_keytransfer_fnc_unimpoundVehicle;";
            x = 0.1 + (6.25 / 40) + (1 / 250 / (safezoneW / safezoneH));
            y = 0.95 - (1 / 25);
            w = (6.25 / 40);
            h = (1 / 25);
            class Attributes {align = "center";};
        };
    };
    
    class controls {
        class VehicleList : Life_RscListBox {
            idc = 3713;
            text = "";
            sizeEx = 0.04;
            colorBackground[] = {0.1,0.1,0.1,0.9};
            onLBSelChanged = "_this call max_keytransfer_fnc_temporaryKeysLBChange;";
            x = 0.11;
            y = 0.302;
            w = 0.303;
            h = 0.59;
        };
        
        class vehicleInfomationList : Life_RscStructuredText {
            idc = 3714;
            text = "";
            sizeEx = 0.035;
            x = 0.41;
            y = 0.3;
            w = 0.5;
            h = 0.6;
        };
        
        class MainBackgroundHider : Life_RscText {
            colorBackground[] = {0,0,0,1};
            idc = 3715;
            x = 0.1;
            y = 0.2 + (11 / 250);
            w = 0.8;
            h = 0.75 - (22 / 250);
        };
        
        class MainHideText : Life_RscText {
            idc = 3716;
            text = "$STR_ANOTF_QueryGarage";
            sizeEx = 0.06;
            x = 0.24;
            y = 0.5;
            w = 0.6;
            h = (1 / 15);
        };
    };
};