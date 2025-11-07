/*
    Author: Vincent
    Web site: www.the-programmer.com
    Discord: https://discord.the-programmer.com

    Terms of use:
        - This file is forbidden unless you have permission from the author. If you have this file without permission to use it please do not use it and do not share it.
        - If you have permission to use this file, you can use it on your server however it is strictly forbidden to share it.
        - Out of respect for the author please do not delete this information.
*/
#define true 1
#define false 0

class Max_Settings_EffetsEcran {
    default_lang = "fr"; // fr / en / de

    remove_item_on_use = true; // true / false

    item_cannabis[] = {"marijuana"};
    item_cocaine[] = {"cocaine_processed"};
    item_heroine[] = {"heroin_processed"};
    item_alcool[] = {"waterBottle"};
    item_control_alcool[] = {"alcohol_test"};
    item_control_drugs[] = {"drug_test"};

    active_cannabis_sound = true;
    active_cocaine_sound = true;
    active_heroine_sound = true;

    time_when_player_cant_take_damages_with_heroin = 30;

    number_drugs_before_death = 5; // (there is a random before this check)
    number_alcool_before_death = 10; // (there is a random before this check)

    // PERSONNALISATION DES EFFETS (CONFIGURATION DE BASE FONCTIONNELLE !)
    class tazer {
        //Temps de commencement de l'effet
        temps_Commencement_min = 1;//temps d'attente avant les effets minimum
        temps_Commencement_max = 1;//temps d'attente avant les effets maximum
        
        //Temps de durée de l'effet
        duree_min = 1;//temps d'effet minimum
        duree_max = 2;//temps d'effet maximum
        
        //Amplitude du déséquilibre
        equilbre_min = 150;//perte d'equilibre minimale
        equilbre_max = 150;//perte d'equilibre maximale
        equilibre_monte = 0;//vitesse evolution d'equilibre
        
        //Amplitude du flou
        flou_min = 0.1;//flou minimal
        flou_max = 0.1;//flou maximal
        flou_monte = 0;//vitesse evolution flou
        
        //Amplitude de la séparation des couleurs
        couleurs_min = 0;//couleurs minimale
        couleurs_max = 0;//couleurs maximales
        couleurs_monte = 0;//vitesse evolution couleurs
        
        //Fréquence du déséquilibre
        frequence = 5;//frequence perte d'equilibre initiale en Hz
        frequence_min = 5;//frequence minimale
        frequence_max = 5;//frequence maximale
        frequence_monte = 0;//vitesse evolution frequence
    };

    class assomer {
        //Temps de commencement de l'effet
        temps_Commencement_min = 0.1;//temps d'attente avant les effets minimum
        temps_Commencement_max = 0.1;//temps d'attente avant les effets maximum
        
        //Temps de durée de l'effet
        duree_min = 5;//temps d'effet minimum
        duree_max = 5;//temps d'effet maximum
        
        //Amplitude du déséquilibre
        equilbre_min = 20;//perte d'equilibre minimale
        equilbre_max = 20;//perte d'equilibre maximale
        equilibre_monte = 0;//vitesse evolution d'equilibre
        
        //Amplitude du flou
        flou_min = 0;//flou minimal
        flou_max = 10;//flou maximal
        flou_monte = 0.1;//vitesse evolution flou
        
        //Amplitude de la séparation des couleurs
        couleurs_min = 0;//couleurs minimale
        couleurs_max = 0;//couleurs maximales
        couleurs_monte = 0;//vitesse evolution couleurs
        
        //Fréquence du déséquilibre
        frequence = 0.5;//frequence perte d'equilibre initiale en Hz
        frequence_min = 0.5;//frequence minimale
        frequence_max = 0.5;//frequence maximale
        frequence_monte = 0;//vitesse evolution frequence
    };

    class cocaine {
        //Temps de commencement de l'effet
        temps_Commencement_min = 1;//temps d'attente avant les effets minimum
        temps_Commencement_max = 10;//temps d'attente avant les effets maximum
        
        //Temps de durée de l'effet
        duree_min = 60;//temps d'effet minimum
        duree_max = 600;//temps d'effet maximum
        
        //Amplitude du déséquilibre
        equilbre_min = 0;//perte d'equilibre minimale
        equilbre_max = 200;//perte d'equilibre maximale
        equilibre_monte = 2;//vitesse evolution d'equilibre
        
        //Amplitude du flou
        flou_min = 0.1;//flou minimal
        flou_max = 0.025;//flou maximal
        flou_monte = 0.0008;//vitesse evolution flou
        
        //Amplitude de la séparation des couleurs
        couleurs_min = 0;//couleurs minimale
        couleurs_max = 0.25;//couleurs maximales
        couleurs_monte = 0.002;//vitesse evolution couleurs
        
        //Fréquence du déséquilibre
        frequence = 1;//frequence perte d'equilibre initiale en Hz
        frequence_min = 0.5;//frequence minimale
        frequence_max = 5;//frequence maximale
        frequence_monte = 0.01;//vitesse evolution frequence
    };

    class cannabis {
        //Temps de commencement de l'effet
        temps_Commencement_min = 5;//temps d'attente avant les effets minimum
        temps_Commencement_max = 30;//temps d'attente avant les effets maximum
        
        //Temps de durée de l'effet
        duree_min = 60;//temps d'effet minimum
        duree_max = 600;//temps d'effet maximum
        
        //Amplitude du déséquilibre
        equilbre_min = 0;//perte d'equilibre minimale
        equilbre_max = 50;//perte d'equilibre maximale
        equilibre_monte = 5;//vitesse evolution d'equilibre
        
        //Amplitude du flou
        flou_min = 0;//flou minimal
        flou_max = 0.005;//flou maximal
        flou_monte = 0.0005;//vitesse evolution flou
        
        //Amplitude de la séparation des couleurs
        couleurs_min = 0;//couleurs minimale
        couleurs_max = 1;//couleurs maximales
        couleurs_monte = 0.05;//vitesse evolution couleurs
        
        //Fréquence du déséquilibre
        frequence = 0.1;//frequence perte d'equilibre initiale en Hz
        frequence_min = 0.01;//frequence minimale
        frequence_max = 0.4;//frequence maximale
        frequence_monte = 0.005;//vitesse evolution frequence
    };

    class heroine {
        //Temps de commencement de l'effet
        temps_Commencement_min = 5;//temps d'attente avant les effets minimum
        temps_Commencement_max = 30;//temps d'attente avant les effets maximum
        
        //Temps de durée de l'effet
        duree_min = 60;//temps d'effet minimum
        duree_max = 600;//temps d'effet maximum
        
        //Amplitude du déséquilibre
        equilbre_min = 0;//perte d'equilibre minimale
        equilbre_max = 150;//perte d'equilibre maximale
        equilibre_monte = 3;//vitesse evolution d'equilibre
        
        //Amplitude du flou
        flou_min = 0;//flou minimal
        flou_max = 0.05;//flou maximal
        flou_monte = 0.002;//vitesse evolution flou
        
        //Amplitude de la séparation des couleurs
        couleurs_min = 0;//couleurs minimale
        couleurs_max = 2;//couleurs maximales
        couleurs_monte = 0.02;//vitesse evolution couleurs
        
        //Fréquence du déséquilibre
        frequence = 0.5;//frequence perte d'equilibre initiale en Hz
        frequence_min = 0.1;//frequence minimale
        frequence_max = 1;//frequence maximale
        frequence_monte = 0.05;//vitesse evolution frequence
    };

    class alcool {
        //Temps de commencement de l'effet
        temps_Commencement_min = 5;//temps d'attente avant les effets minimum
        temps_Commencement_max = 30;//temps d'attente avant les effets maximum
        
        //Temps de durée de l'effet
        duree_min = 30;//temps d'effet minimum
        duree_max = 150;//temps d'effet maximum
        
        //Amplitude du déséquilibre
        equilbre_min = 0;//perte d'equilibre minimale
        equilbre_max = 100;//perte d'equilibre maximale
        equilibre_monte = 1;//vitesse evolution d'equilibre
        
        //Amplitude du flou
        flou_min = 0;//flou minimal
        flou_max = 0.012;//flou maximal
        flou_monte = 0.0001;//vitesse evolution flou
        
        //Amplitude de la séparation des couleurs
        couleurs_min = 0;//couleurs minimale
        couleurs_max = 0.8;//couleurs maximales
        couleurs_monte = 0.0006;//vitesse evolution couleurs
        
        //Fréquence du déséquilibre
        frequence = 0.1;//frequence perte d'equilibre initiale en Hz
        frequence_min = 0.1;//frequence minimale
        frequence_max = 0.1;//frequence maximale
        frequence_monte = 0;//vitesse evolution frequence
    };

    class tremblement {
        //Temps de commencement de l'effet
        temps_Commencement_min = 300;//temps d'attente avant les effets minimum
        temps_Commencement_max = 600;//temps d'attente avant les effets maximum
        
        //Temps de durée de l'effet
        duree_min = 60;//temps d'effet minimum
        duree_max = 300;//temps d'effet maximum
        
        //Amplitude du déséquilibre
        equilbre_min = 0;//perte d'equilibre minimale
        equilbre_max = 10;//perte d'equilibre maximale
        equilibre_monte = 0.1;//vitesse evolution d'equilibre
        
        //Amplitude du flou
        flou_min = 0;//flou minimal
        flou_max = 0.0001;//flou maximal
        flou_monte = 0.00001;//vitesse evolution flou
        
        //Amplitude de la séparation des couleurs
        couleurs_min = 0;//couleurs minimale
        couleurs_max = 0.01;//couleurs maximales
        couleurs_monte = 0.001;//vitesse evolution couleurs
        
        //Fréquence du déséquilibre
        frequence = 0.1;//frequence perte d'equilibre initiale en Hz
        frequence_min = 1;//frequence minimale
        frequence_max = 3;//frequence maximale
        frequence_monte = 0.1;//vitesse evolution frequence
    };
};
