/*
	_null=this execVM "The-Programmer\Fourriere\init.sqf";
*/
_this allowDamage false; 
_this enableSimulation false;
_this addAction [(["STR_IMPOUND_ACTION","Max_Settings_Fourriere","Fourriere_Localization"] call theprogrammer_core_fnc_localize),{[] call max_fourriere_fnc_impoundVehicle},"",0,false,false,"",'',5];
