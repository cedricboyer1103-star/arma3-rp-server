/*
    Author: Maxence
    Web site: www.the-programmer.com
    Discord: https://discord.the-programmer.com

    Terms of use:
        - This file is forbidden unless you have permission from the author. If you have this file without permission to use it please do not use it and do not share it.
        - If you have permission to use this file, you can use it on your server however it is strictly forbidden to share it.
        - Out of respect for the author please do not delete this information.
*/
class Maxence_Impound_menu {
    idd = 5010;
    name = "Maxence_Impound_menu";
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
            h = 0.7 - (22 / 250);
        };
        
        class Title : Life_RscTitle {
            idc = 5011;
            text = "";
            x = 0.1;
            y = 0.2;
            w = 0.8;
            h = (1 / 25);
        };
        
        class VehicleTitleBox : Life_RscText {
            idc = 5018;
            text = "";
            colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", "(profilenamespace getvariable ['GUI_BCG_RGB_A',0.7])"};
            x = 0.11;
            y = 0.26;
            w = 0.3;
            h = (1 / 25);
        };
        
        class VehicleInfoHeader : Life_RscText {
            idc = 5012;
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
            y = 0.9 - (1 / 25);
            w = (6.25 / 40);
            h = (1 / 25);
            class Attributes {align = "center";};
        };
        
        class UnimpoundVeh : Life_RscButtonMenu {
            idc = 5017;
            text = "$STR_Global_Retrieve";
            onButtonClick = "[] spawn max_fourriere_fnc_unimpoundVehFourriere;";
            x = 0.1 + (6.25 / 40) + (1 / 250 / (safezoneW / safezoneH));
            y = 0.9 - (1 / 25);
            w = (6.25 / 40);
            h = (1 / 25);
            class Attributes {align = "center";};
        };
    };
    
    class controls {
        class VehicleList : Life_RscListBox {
            idc = 5013;
            text = "";
            sizeEx = 0.04;
            colorBackground[] = {0.1,0.1,0.1,0.9};
            onLBSelChanged = "_this call max_fourriere_fnc_garageLBChangevehFourriere;";
            x = 0.11;
            y = 0.302;
            w = 0.303;
            h = 0.49;
        };
        
        class vehicleInfomationList : Life_RscStructuredText {
            idc = 5014;
            text = "";
            sizeEx = 0.035;
            x = 0.41;
            y = 0.3;
            w = 0.5;
            h = 0.5;
        };
        
        class MainBackgroundHider : Life_RscText {
            colorBackground[] = {0,0,0,1};
            idc = 5015;
            x = 0.1;
            y = 0.2 + (11 / 250);
            w = 0.8;
            h = 0.7 - (22 / 250);
        };
        
        class MainHideText : Life_RscText {
            idc = 5016;
            text = "$STR_ANOTF_QueryGarage";
            sizeEx = 0.06;
            x = 0.24;
            y = 0.5;
            w = 0.6;
            h = (1 / 15);
        };

        class TitleSearch : Life_RscTitle {
            idc = 5021;
            text = "";
            x = 0.42;
            y = 0.81;
            w = 1.8;
            h = (1 / 25);
        };
        
        class SearchTxt : Life_RscEdit {
            idc = 5019;
            text = "";
            x = 0.42;
            y = 0.9 - (1 / 25);
            w = 0.2;
            h = (1 / 25);
        };
        
        class Search : Life_RscButtonMenu {
            idc = 5020;
            text = "";
            onButtonClick = "[] spawn max_fourriere_fnc_searchVehicle;";
            x = 0.625;
            y = 0.9 - (1 / 25);
            w = (6.25 / 40);
            h = (1 / 25);
            class Attributes {align = "center";};
        };
    };
};