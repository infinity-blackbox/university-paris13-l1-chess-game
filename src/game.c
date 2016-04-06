/**
 * @since 2.3
 *
 * @package Chess Game
 * @category Game Main
 * @author William Phetsinorath
 *         Rakib Sheikh
 *		   Sabri Rezak Salem
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"loader.h"
#define MAX_CHAR 20

/**
 * empty cell detector
 *
 * @return int
 */
int case_vide(piece_t piece_v){
    if(piece_v.type == EMPTY){
        return 1;
    }
return 0;
}

/* ---- REVERTED CHANGE BY RAKIB ---- */
/* Data input level 1 */
    char game_command[MAX_CHAR] = "";

/**
 * cell editing
 */
void modifier_case(game_t * game_v, piece_t * piece_v, coordinate_t coordinate_v){
    piece_t res;

	res = piece_creer(piece_v->color,piece_v->type);
    game_v->board[coordinate_v.x][coordinate_v.y] = res;
}

/**
 * player switcher
 */
void changer_joueur(game_t * game_v){
    if(game_v->player == 1){
        game_v->player = 0;
    }else{
        game_v->player = 1;
    }
}

/**
 * player piece move
 */
void depalcement(game_t * game_v, coordinate_t coordinate_input_v, coordinate_t coordinate_output_v){
    movement_t game_movement_tmp;

    game_movement_tmp.input = coordinate_input_v;
    game_movement_tmp.ouput = coordinate_output_v;
    if(!case_vide(game_v->board[coordinate_input_v.x][coordinate_input_v.y])){
        if(!case_vide(game_v->board[coordinate_output_v.x][coordinate_output_v.y])){
            pile_stacking(game_v->catched, game_v->board[coordinate_output_v.x][coordinate_output_v.y]);
            game_movement_tmp.value = 1;
        }
        game_v->board[coordinate_output_v.x][coordinate_output_v.y] = game_v->board[coordinate_input_v.x][coordinate_input_v.y];
        game_v->board[coordinate_input_v.x][coordinate_input_v.y] = piece_creer(EMPTY_PIECE, EMPTY);
        file_thread(game_v->played, game_movement_tmp);
        changer_joueur(game_v);
    }
}

/**
 * player piece back
 */
void annuler_deplacement(game_t * game_v){
    file_unthread(game_v->played);
}

/**
 * player coordinate input
 *
 * @return struct coordinate_s
 */
coordinate_t saisie_case(){
    coordinate_t res;
    char * p, s[100];

    printf("x: ");
    while (fgets(s, sizeof(s), stdin)) {
        res.x = strtol(s, &p, 10);
        if (p == s || *p != '\n') {
            printf("x: ");
        } else break;
    }
    printf("y: ");
    while (fgets(s, sizeof(s), stdin)) {
        res.y = strtol(s, &p, 10);
        if (p == s || *p != '\n') {
            printf("y: ");
        } else break;
    }
    if(res.x >0 && res.x < 8){
        if(res.y >0 && res.y < 8){
            return res;
        }
    }
    return res;
}

/**
 * chess displayer
 */
void afficher_echiquier(game_t * game_v, coordinate_t game_input_tmp){
    int x, y;
    coordinate_t game_output_tmp;

    /* Interface */
    printf("\n");
    printf("                      0  1  2  3  4  5  6  7\n");
    for(x=0; x<8; x++){
        if(x<6 && x>1){
            printf("                   %d  ", x);
        }else if(x<6){
            if(game_v->player == 0){
                printf("  NOIR->           %d  ", x);
            }else{
                printf("                   %d  ", x);
            }
        }else if(x>1){
            if(game_v->player == 1){
                printf("  BLANC->          %d  ", x);
            }else{
                printf("                   %d  ", x);
            }
        }

        /* Selection detector */
        if(game_input_tmp.x != '\0' || game_input_tmp.y != '\0'){ /* Fixed warning */
            /* Chess board */
            for(y=0; y<8; y++){
                game_output_tmp.x = x;
                game_output_tmp.y = y;
                if(movement_valid_helper(game_v, game_input_tmp, game_output_tmp)){
                    if(game_v->board[x][y].type == EMPTY){
                        game_v->board[x][y].type = SELECT;
                    }
                }
                piece_afficher(game_v->board[x][y]);
                if(movement_valid_helper(game_v, game_input_tmp, game_output_tmp)){
                    if(game_v->board[x][y].type == SELECT){
                        game_v->board[x][y].type = EMPTY;
                    }
                }
                printf("  ");
            }
        }else{
            /* Chess board */
            for(y=0; y<8; y++){
                piece_afficher(game_v->board[x][y]);
                printf("  ");
            }
        }
        printf("\n");
    }
    printf("\n\n\n\n");
}

/**
 * game creator
 *
 * @return struct game_s
 */
game_t * partie_creer(){
    game_t * res;
    return res = (game_t*)malloc(sizeof(game_t));
}

/**
 * game destructor
 */
void partie_detruire(game_t * game_v){
    free(game_v);
}

/**
 * game save
 */
void partie_sauvegarder(game_t * game_v, char game_name_v[], char game_path_v[]){

}

/**
 * game load
 */
void partie_charger(char game_path_v[]){

}

/**
 * game new
 */
game_t * partie_nouvelle(){
    int x, y;
    game_t * res;

    /* Initialize */
	res = partie_creer();
    res->catched = pile_create();
    res->played = file_create();
    res->player = 0;

    /* Empty */
    for(x=0; x<8; x++){
        for(y=0; y<8; y++){
            res->board[y][x] = piece_creer(EMPTY_PIECE, EMPTY);
            res->board[y][x] = piece_creer(EMPTY_PIECE, EMPTY);
        }
    }

    /* Pawn */
    for(x=0;x<8;x++){
        res->board[6][x] = piece_creer(BLACK_PIECE, PAWN);
        res->board[1][x] = piece_creer(WHITE_PIECE, PAWN);
    }

    /* Rock */
    res->board[7][7] = piece_creer(BLACK_PIECE, ROCK);
    res->board[7][0] = piece_creer(BLACK_PIECE, ROCK);
    res->board[0][7] = piece_creer(WHITE_PIECE, ROCK);
    res->board[0][0] = piece_creer(WHITE_PIECE, ROCK);

    /* Knight */
    res->board[7][1] = piece_creer(BLACK_PIECE, KNIGHT);
    res->board[7][6] = piece_creer(BLACK_PIECE, KNIGHT);
    res->board[0][1] = piece_creer(WHITE_PIECE, KNIGHT);
    res->board[0][6] = piece_creer(WHITE_PIECE, KNIGHT);

    /* Bishop */
    res->board[0][2] = piece_creer(WHITE_PIECE, BISHOP);
    res->board[0][5] = piece_creer(WHITE_PIECE, BISHOP);
    res->board[7][2] = piece_creer(BLACK_PIECE, BISHOP);
    res->board[7][5] = piece_creer(BLACK_PIECE, BISHOP);

    /* Queen */
    res->board[7][3] = piece_creer(BLACK_PIECE, QUEEN);
    res->board[0][3] = piece_creer(WHITE_PIECE, QUEEN);

    /* King */
    res->board[7][4] = piece_creer(BLACK_PIECE, KING);
    res->board[4][5] = piece_creer(BLACK_PIECE, KING);
    res->board[0][4] = piece_creer(WHITE_PIECE, KING);
    return res;
}

/**
 * game separator
 */
void game_seperator(){
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}

/**
 * game select
 */
int game_selector(char game_command[MAX_CHAR], char select_v[MAX_CHAR]){ /* --- SPELL FIX AND TYPE FIX --- */
    if(strcmp(game_command, select_v) == 0){
		return 1;
	}else{
		return 0;
	}
}

/**
 * game play
 */
void partie_jouer(game_t * game_v){

    /* Variables */
    coordinate_t SELECT_NULL;

    /* Data input level 1 */
    char game_command[MAX_CHAR];

    /* Data input level 2 */
    coordinate_t game_input_tmp, game_output_tmp;
    char game_save_name[MAX_CHAR], game_save_path_v[MAX_CHAR];
    char game_exit_confirmation[MAX_CHAR];

    /* Game setting */
    int game_command_dev;
    int game_play;

    SELECT_NULL.x = '\0'; /* Fixed Warning */
    SELECT_NULL.y = '\0'; /* Fixed Warning */
	game_command_dev = 0;
	game_play = 1;

    /* Main */

    /* First chess board display*/
    printf("Je suis une poire.");
    game_seperator();
    printf("Nouvelle partie.\n");

    /* Enter loop */
    afficher_echiquier(game_v, SELECT_NULL);
    printf("\n\n\n");

    /* Main loop */
    while(game_play){
        /* Command input */
        printf("Entrer une commande: ");
        scanf("%19s", game_command);
        fflush(stdin);

        /* Help command */
        if(game_selector(game_command, "help")){
            /* Separator */
            game_seperator();

            /* Advanced command */
            if(game_command_dev){
                printf("PASS                  Passe le tour du joueur.\n");
                printf("FILE                  Affiche lse donnes contenu dans la file.\n");
                printf("PILE                  Affiche les donnes contenu dans la pile.\n");
                printf("CLEAR                 Detruit toute les donnes contenu les bases de donnees.\n");
            }else{
                printf("DEV                   Pour activer les command developpeur.\n");
            }
            printf("\n");

            /* Classic command */
            printf("SURREND               Declarer forfait.\n");
            printf("MOVE                  Selectionner le deplacement d'une piece.\n");
            printf("BACK                  Restaurer le deplacement precedent.\n");
            printf("SAVE                  Sauvegarder la partie.\n");
            printf("EXIT                  Quitter le jeu.\n");

            /* Enter loop */
            afficher_echiquier(game_v, SELECT_NULL);
            printf("\n\n\n");

        /* Developper command */
        }else if(game_selector(game_command, "dev")){
            /* Separator */
            game_seperator();

            printf("Les commandes developpeur sont active,\nsaisissez 'help' pour en savoir plus sur les commandes.\n");
            game_command_dev=1;

            /* Enter loop */
            afficher_echiquier(game_v, SELECT_NULL);
            printf("\n\n\n");

        /* Developper command */
        }else if(game_selector(game_command, "pass") && game_command_dev){
            /* Separator */
            game_seperator();

            changer_joueur(game_v);

            /* Enter loop */
            afficher_echiquier(game_v, SELECT_NULL);
            printf("\n\n\n");

        /* Developper command file */
        }else if(game_selector(game_command, "file") && game_command_dev){
            /* Separator */
            game_seperator();

            debug_file(game_v);

            /* Enter loop */
            afficher_echiquier(game_v, SELECT_NULL);
            printf("\n\n\n");

        /* Developper command pile */
        }else if(game_selector(game_command, "pile") && game_command_dev){
            /* Separator */
            game_seperator();

            debug_pile(game_v);

            /* Enter loop */
            afficher_echiquier(game_v, SELECT_NULL);
            printf("\n\n\n");

        /* Developper command clear */
        }else if(game_selector(game_command, "clear") && game_command_dev){
            /* Separator */
            game_seperator();

            /* pile destruct */
            pile_destruct(game_v->catched);
            game_v->catched = pile_create();

            /* file destruct */
            file_destruct(game_v->played);
            game_v->played = file_create();

            /* Enter loop */
            afficher_echiquier(game_v, SELECT_NULL);
            printf("\n\n\n");

        /* Surrend command */
        }else if(game_selector(game_command, "surrend")){
            /* Separator */
            game_seperator();

            changer_joueur(game_v);
            printf("Le joueur ");
            if(game_v->player == 0){
                printf("1");
            }else if(game_v->player == 1){
                printf("2");
            }
            printf(" a gagner la partie.\n");

            /* Exit loop */
            afficher_echiquier(game_v, SELECT_NULL);
            game_play=0;

        /* Move command */
        }else if(game_selector(game_command, "move")){

            do{
                /* Separator */
                game_seperator();
                printf("Saisir les coordonnees d'une piece:\n");

                /* Enter loop */
                afficher_echiquier(game_v, SELECT_NULL);
                printf("\n\n\n");
                game_input_tmp = saisie_case();
            }while(!movement_valid_input(game_v, game_input_tmp));

            printf("\n");

            do{
                /* Separator */
                game_seperator();
                printf("Vous avez selectionner la piece '");
                piece_afficher(game_v->board[game_input_tmp.x][game_input_tmp.y]);
                printf("' de coordonnees (%d;%d).", game_input_tmp.x, game_input_tmp.y);
                printf("\nSaisir les coordonnees du movement:\n");

                /* Enter loop */
                afficher_echiquier(game_v,game_input_tmp);
                printf("\n\n\n");
                game_output_tmp = saisie_case();
            }while(!movement_valid_output(game_v, game_output_tmp));

            /* Separator */
            game_seperator();
            depalcement_valide(game_v, game_input_tmp, game_output_tmp);

            /* Enter loop */
            afficher_echiquier(game_v, SELECT_NULL);
            printf("\n\n\n");

        /* Back command */
        }else if(game_selector(game_command, "back")){
            /* Separator */
            game_seperator();

            annuler_deplacement(game_v);

            /* Enter loop */
            afficher_echiquier(game_v, SELECT_NULL);
            printf("\n\n\n");

        /* Save command */
        }else if(game_selector(game_command, "save")){
            /* Separator */
            game_seperator();

            printf("Entrer le nom de la partie:");
            scanf("%19s", game_save_name);
            printf("Entrer l'emplacement de la sauvegarder:");
            scanf("%19s", game_save_path_v);
            partie_sauvegarder(game_v, game_save_name, game_save_path_v);

            /* Exit loop */
            afficher_echiquier(game_v, SELECT_NULL);
            game_play = 0;

        /* Exit command */
        }else if(game_selector(game_command, "exit")){
            /* Separator */
            game_seperator();

            /* Enter loop */
            afficher_echiquier(game_v, SELECT_NULL);
            printf("\n\n");
            printf("Etes vous sur de quitter sans sauvegarder? (oui/non)\n");
            scanf("%19s", game_exit_confirmation);

            if(strcmp(game_exit_confirmation,"oui") == 0){
                /* Separator */
                game_seperator();
                printf("Merci d'avoir jouer a ce jeu. - William Phetsinorath\n");
                /* Enter loop */
                afficher_echiquier(game_v, SELECT_NULL);
                printf("\n\n\n");
                game_play = 0;
            }else{
                /* Separator */
                game_seperator();
                /* Enter loop */
                afficher_echiquier(game_v, SELECT_NULL);
                printf("\n\n\n");
            }

        /* Unknown command */
        }else{
            /* Separator */
            game_seperator();

            printf("'%s' n'est pas reconnu comme une commande,\nsaisissez 'help' pour en savoir plus sur les commandes.\n", game_command);

            /* Enter loop */
            afficher_echiquier(game_v, SELECT_NULL);
            printf("\n\n\n");
        }
    }
}

/**
 * replay load
 */
void replay_charger(){

}

/**
 * replay play
 */
void replay_jouer(){

}
