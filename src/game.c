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
#define MAX_CHAR 256

/**
 * global
 */
coordinate_t COORDINATE_NULL = {42, 42};

/**
 * empty cell detector
 *
 * Parameters:
 *     piece_t - piece_v
 *
 * @return int
 */
int case_vide(piece_t piece_v)
{
	//======================================================================
	// Main
	//======================================================================
    if(piece_v.type == EMPTY)
    {
        return 1;
    }

    return 0;
}

/**
 * cell editing
 *
 * Parameters:
 *     game_t       - game_v
 *     piece_t      - piece_v
 *     coordinate_t - coordinate_v
 */
void modifier_case(game_t * game_v, piece_t * piece_v, coordinate_t coordinate_v)
{
	//======================================================================
	// Variables
	//======================================================================
    piece_t res;

    /* Initialize */
    res   = piece_creer(piece_v -> color, piece_v -> type);

	//======================================================================
	// Main
	//======================================================================
    game_v -> board[coordinate_v.x][coordinate_v.y] = res;
}

/**
 * player switcher
 *
 * Parameters:
 *     game_t - game_v
 */
void changer_joueur(game_t * game_v)
{
	//======================================================================
	// Main
	//======================================================================
    if(game_v   ->  player == 1)
    {
        game_v  ->  player = 0;
    }
    else
    {
        game_v  -> player  = 1;
    }

}

/**
 * player piece move
 *
 * Parameters:
 *     game_t       - game_v
 *     coordinate_t - coordinate_input_v
 *     coordinate_t - coordinate_output_v
 */
void deplacement(game_t * game_v, coordinate_t coordinate_input_v, coordinate_t coordinate_output_v)
{
	//======================================================================
	// Variables
	//======================================================================
	movement_t                game_movement_tmp;
    game_movement_tmp.input = coordinate_input_v;
    game_movement_tmp.output = coordinate_output_v;

	//======================================================================
	// Main
	//======================================================================
    if(!case_vide(game_v -> board[coordinate_input_v.x][coordinate_input_v.y])){

        /* Piece output presence check */

        if(!case_vide(game_v -> board[coordinate_output_v.x][coordinate_output_v.y]) && piece_couleur(game_v -> board[coordinate_output_v.x][coordinate_output_v.y]) != piece_couleur(game_v -> board[coordinate_input_v.x][coordinate_input_v.y]) )
        {
            pile_stacking(game_v->catched, game_v->board[coordinate_output_v.x][coordinate_output_v.y]);
            game_movement_tmp.value = 1;

            /* Apply movement */
            game_v -> board[coordinate_output_v.x][coordinate_output_v.y]   = game_v -> board[coordinate_input_v.x][coordinate_input_v.y];
            game_v -> board[coordinate_input_v.x][coordinate_input_v.y]     = piece_creer(EMPTY_PIECE, EMPTY);

            /* Piece switch */

            file_thread(game_v -> played, game_movement_tmp);
            changer_joueur(game_v);
        }
        else
        {
            game_v -> board[coordinate_output_v.x][coordinate_output_v.y]   = game_v -> board[coordinate_input_v.x][coordinate_input_v.y];
            game_v -> board[coordinate_input_v.x][coordinate_input_v.y]     = piece_creer(EMPTY_PIECE, EMPTY);

        /* Piece switch */

        file_thread(game_v -> played, game_movement_tmp);
        changer_joueur(game_v);
        }

    }
}

/**
 * player piece back
 *
 * Parameters:
 *     game_t - game_v
 */
void annuler_deplacement(game_t * game_v)
{
	//======================================================================
	// Variables
	//======================================================================
	coordinate_t movement_output_tmp = game_v -> played -> last -> movement.output;
	coordinate_t movement_input_tmp = game_v -> played -> last -> movement.input;

	//======================================================================
	// Main
	//======================================================================
	game_v->board[movement_input_tmp.x][movement_input_tmp.y] = game_v->board[movement_output_tmp.x][movement_output_tmp.y];
    if(game_v -> played -> last -> movement.value)
    {
        game_v -> board[game_v -> played -> last -> movement.output.x][game_v -> played -> last -> movement.output.y] = game_v -> catched -> last -> piece;
        pile_unstacking(game_v -> catched);
    }
    file_unthread(game_v -> played);
}

/**
 * player coordinate input
 *
 * Parameters:
 *     game_t - game_v
 *
 * @return struct coordinate_s
 */
coordinate_t saisie_case()
{
	//======================================================================
	// Variables
	//======================================================================
    coordinate_t res;
    char *       p, s[100];

	//======================================================================
	// Main
	//======================================================================
    printf("x: ");

    while(fgets(s, sizeof(s), stdin)){
        res.y = strtol(s, &p, 10);

        if(p == s || *p != '\n') {
            printf("x: ");
        }
		else
		{
            break;
        }
    }

    printf("y: ");

    while(fgets(s, sizeof(s), stdin))
    {
        res.x = strtol(s, &p, 10);
        if(p == s || *p != '\n')
        {
            printf("y: ");
        }
        else
        {
            break;
        }
    }

    if    (res.x > 0 && res.x < 8)
    {
        if(res.y > 0 && res.y < 8)
        {
            return res;
        }
    }
    return res;
}

/**
 * chess displayer
 *
 * Parameters:
 *     game_t       - game_v
 *     coordinate_t - game_input_tmp
 */
void afficher_echiquier(game_t * game_v, coordinate_t game_input_tmp)
{
	//======================================================================
	// Variables
	//======================================================================
	int x, y;

	//======================================================================
	// Main
	//======================================================================
    /* Interface */
    /* Refresh */
    movement_restriction_destruct(game_v);
    printf("\n");
    printf("                      0  1  2  3  4  5  6  7\n");

    for    (x = 0; x<8; x++)
    {
        if     (x < 6 && x > 1)
        {
            printf("                   %d  ", x);
        }
        else if(x < 6)
        {
			/* Player Indicator */
            if (game_v->player == 0)
            {
                printf("  NOIR->           %d  ", x);
            }
            else
            {
                printf("                   %d  ", x);
            }

        }
        else if(x > 1)
        {
			/* Player Indicator */
            if (game_v->player == 1)
            {
                printf("  BLANC->          %d  ", x);
            }
            else
            {
                printf("                   %d  ", x);
            }

        }

        /* Selection detector */

        if(game_input_tmp.x != 42 || game_input_tmp.y != 42)
        {
            //printf("DEBUG ************ %d : %d *******************\n",game_input_tmp.x,game_input_tmp.y);
            movement_restriction(game_v, game_input_tmp);
        }

        /* Chess board */
        for(y = 0; y < 8; y++)
        {
            piece_afficher(game_v -> board[x][y]);
            printf("  ");
        }

        printf("\n");
    }
}

/**
 * game creator
 *
 * @return struct game_s
 */
game_t * partie_creer()
{
	//======================================================================
	// Variables
	//======================================================================
    game_t * res;

	//======================================================================
	// Main
	//======================================================================
    return res = (game_t*)malloc(sizeof(game_t));
}

/**
 * game destructor
 *
 * Parameters:
 *     game_t - game_v
 */
void partie_detruire(game_t * game_v)
{
	//======================================================================
	// Main
	//======================================================================
    free(game_v);
}

/**
 * game save
 *
 * Parameters:
 *     game_t - game_v
 *     char   - game_name_v
 *     char   - game_path_v
 */
void partie_sauvegarder(game_t * game_v, char game_name_v[], char game_path_v[])
{
	//======================================================================
	// Variables
	//======================================================================
    int x, y;
    char game_plt_tmp[MAX_CHAR], game_part_tmp[MAX_CHAR];
    FILE * game_plt_file_tmp, * game_part_file_tmp;

    file_link_t * file_link_tmp;
    pile_link_t * pile_link_tmp;

	//======================================================================
	// Main
	//======================================================================
	strcpy(game_plt_tmp, "\\Plateaux\\");
	strcpy(game_plt_tmp, game_path_v);
	strcpy(game_plt_tmp, "\\");
	strcpy(game_plt_tmp, game_name_v);
	strcpy(game_plt_tmp, ".ptl");

    game_plt_file_tmp = fopen(game_plt_tmp, "w+");

    for    (x = 0; x < 8; x++)
    {

        for(y = 0; y < 8; y++)
        {
            fprintf(game_plt_file_tmp, "%c", piece_caractere(game_v -> board[x][y]));
        }

    }
    fclose(game_plt_file_tmp);

    strcpy(game_part_tmp, "\\Parties\\");
    strcpy(game_part_tmp, game_path_v);
	strcpy(game_plt_tmp, "\\");
	strcpy(game_plt_tmp, game_name_v);
	strcpy(game_plt_tmp, ".part");

    game_part_file_tmp = fopen(game_plt_tmp, "w+");

    while(!file_empty(game_v -> played))
    {
        file_link_tmp = file_list_extract(game_v->played);
        fprintf(game_part_file_tmp, " %d :", file_link_tmp -> movement.input.x);
        fprintf(game_part_file_tmp, " %d :", file_link_tmp -> movement.input.y);
        fprintf(game_part_file_tmp, " %d :", file_link_tmp -> movement.output.x);
        fprintf(game_part_file_tmp, " %d :", file_link_tmp -> movement.output.y);
    }

    fprintf(game_part_file_tmp, "\n");

    while(!file_empty(game_v -> played))
    {
        pile_link_tmp = pile_list_extract(game_v -> catched);
        fprintf(game_part_file_tmp, " %d :", pile_link_tmp -> piece.color);
        fprintf(game_part_file_tmp, " %d :", pile_link_tmp -> piece.type);
    }
}

/**
 * game load
 *
 * Parameters:
 *     char - game_path_v
 */
game_t * partie_charger(char game_path_v[])
{
	//======================================================================
	// Variables
	//======================================================================
    FILE *   game_file_tmp = NULL;
    game_t * res = partie_creer();
    char     game_data_tmp;
    int x, y;

	//======================================================================
	// Main
	//======================================================================
    game_file_tmp = fopen(game_path_v, "r");

    if(game_file_tmp != NULL)
    {

        for    (x = 0; x < 8; x++)
        {

            for(y = 0; y < 8; y++)
            {
                fscanf(game_file_tmp, "%c", &game_data_tmp);
                res -> board[x][y] = piece_identifier(game_data_tmp);
            }

        }

    }
    else
    {
        printf("Impossible d'ouvrir le fichier %s.part.\n", game_path_v);
    }

    return res;
}

/**
 * game new
 *
 * @return struct game_s
 */
game_t * partie_nouvelle()
{
	//======================================================================
	// Variables
	//======================================================================
	int x, y;
    game_t *         res;

    /* Initialize */
    res            = partie_creer();
    res -> catched = pile_create();
    res -> played  = file_create();
    res -> player  = 0;

	//======================================================================
	// Main
	//======================================================================
    /* Empty */
    for    (x = 0; x < 8; x++)
    {

        for(y = 0; y < 8; y++)
        {
            res -> board[y][x] = piece_creer(EMPTY_PIECE, EMPTY);
            res -> board[y][x] = piece_creer(EMPTY_PIECE, EMPTY);
        }

    }

    /* Pawn */
    for(x = 0; x < 8; x++)
    {
        res     -> board[6][x] = piece_creer(BLACK_PIECE, PAWN);
        res     -> board[1][x] = piece_creer(WHITE_PIECE, PAWN);
    }

    /* Rock */

    res          -> board[7][7] = piece_creer(BLACK_PIECE, ROCK);
    res          -> board[7][0] = piece_creer(BLACK_PIECE, ROCK);
    res          -> board[0][7] = piece_creer(WHITE_PIECE, ROCK);
    res          -> board[0][0] = piece_creer(WHITE_PIECE, ROCK);

    /* Knight */

    res          -> board[7][1] = piece_creer(BLACK_PIECE, KNIGHT);
    res          -> board[7][6] = piece_creer(BLACK_PIECE, KNIGHT);
    res          -> board[0][1] = piece_creer(WHITE_PIECE, KNIGHT);
    res          -> board[0][6] = piece_creer(WHITE_PIECE, KNIGHT);

    /* Bishop */

    res          -> board[0][2] = piece_creer(WHITE_PIECE, BISHOP);
    res          -> board[0][5] = piece_creer(WHITE_PIECE, BISHOP);
    res          -> board[7][2] = piece_creer(BLACK_PIECE, BISHOP);
    res          -> board[7][5] = piece_creer(BLACK_PIECE, BISHOP);

    /* Queen */

    res          -> board[7][3] = piece_creer(BLACK_PIECE, QUEEN);
    res          -> board[0][3] = piece_creer(WHITE_PIECE, QUEEN);

    /* King */

    res          -> board[7][4] = piece_creer(BLACK_PIECE, KING);
    res          -> board[0][4] = piece_creer(WHITE_PIECE, KING);

    return res;
}

/**
 * game separator
 */
void game_seperator()
{
	//======================================================================
	// Main
	//======================================================================
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}

/**
 * game exit
 */
int game_exit(game_t * game_v)
{
	//======================================================================
	// Main
	//======================================================================
	file_destruct(game_v -> played);
	pile_destruct(game_v -> catched);
	partie_detruire(game_v);

    return 0;
}

/**
 * game select
 *
 * Parameters:
 *     char - game_command
 *     char - select_v
 *
 * @return int
 */
int game_selector(char game_command[MAX_CHAR], char select_v[MAX_CHAR])
{
	//======================================================================
	// Main
	//======================================================================
    if(strcmp(game_command, select_v) == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/**
 * game buffer
 */
void game_buffer()
{
	//======================================================================
	// Variables
	//======================================================================
    char empty_buffer;
	//======================================================================
	// Variables
	//======================================================================
    do empty_buffer = getchar(); while (empty_buffer != '\n' && empty_buffer != EOF);
}

/**
 * game play
 *
 * Parameters:
 *     game_t - game_v
 */
void partie_jouer(game_t * game_v)
{
	//======================================================================
	// Variables
	//======================================================================
    char             game_command[MAX_CHAR] = "";
    char *           game_save_name = malloc (MAX_CHAR);
    char *           game_save_path = malloc (MAX_CHAR);
    char             game_exit_confirmation[MAX_CHAR];

    coordinate_t game_input_tmp, game_output_tmp;

    /* Game setting */
    int              game_command_dev = 0;
    int              game_play        = 1;

	//======================================================================
	// Main
	//======================================================================
    /* First chess board display*/

    printf("Je suis une poire.");
    game_seperator();
    printf("Nouvelle partie.\n");

    /* Enter loop */
    afficher_echiquier(game_v, COORDINATE_NULL);
    printf("\n\n\n");

    /* Main loop */
    while(game_play)
    {

        /* Command input */
        printf("Entrer une commande: ");

        if(scanf("%19s", game_command) != 1){
            /* Separator */
            game_seperator();

            printf("Entrer au moins un caractere.\n");

            /* Enter loop */
            afficher_echiquier(game_v, COORDINATE_NULL);
            printf("\n\n\n");
        }

        game_buffer();

        /* Help command */
        if(game_selector(game_command, "help"))
        {

            /* Separator */
            game_seperator();

            /* Advanced command */
            if(game_command_dev)
            {
                printf("PASS                  Passe le tour du joueur.\n");
                printf("FILE                  Affiche lse donnes contenu dans la file.\n");
                printf("PILE                  Affiche les donnes contenu dans la pile.\n");
                printf("CELL                  Inspecter une cellule.\n");
            }
            else
            {
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
            afficher_echiquier(game_v, COORDINATE_NULL);
            printf("\n\n\n");

        /* Developper command */
        }
        else if(game_selector(game_command, "dev"))
        {

            /* Separator */
            game_seperator();

            if(game_command_dev == 0)
            {
                printf("Les commandes developpeur sont active,\nsaisissez 'help' pour en savoir plus sur les commandes.\n");
                game_command_dev = 1;
            }
            else
            {
                printf("Les commandes developpeur ont ete desactive.\n");
                game_command_dev = 0;
            }

            /* Enter loop */
            afficher_echiquier(game_v, COORDINATE_NULL);
            printf("\n\n\n");

        /* Developper command */
        }
        else if(game_selector(game_command, "pass") && game_command_dev)
        {

            /* Separator */
            game_seperator();

            changer_joueur(game_v);

            /* Enter loop */
            afficher_echiquier(game_v, COORDINATE_NULL);
            printf("\n\n\n");

        /* Developper command file */
        }
        else if(game_selector(game_command, "file") && game_command_dev)
        {

            /* Separator */
            game_seperator();

            debug_file(game_v);

            /* Enter loop */
            afficher_echiquier(game_v, COORDINATE_NULL);
            printf("\n\n\n");

        /* Developper command pile */
        }
        else if(game_selector(game_command, "pile") && game_command_dev)
        {

            /* Separator */
            game_seperator();

            debug_pile(game_v);

            /* Enter loop */
            afficher_echiquier(game_v, COORDINATE_NULL);
            printf("\n\n\n");

        /* Developper command clear */
        }
        else if(game_selector(game_command, "cell") && game_command_dev)
        {

            /* Input */
            /* Separator */
            game_seperator();
            printf("Saisir les coordonnees d'une piece:\n");

            /* Enter loop */
            afficher_echiquier(game_v, COORDINATE_NULL);
            printf("\n\n\n");
            game_input_tmp = saisie_case();

            /* Separator */
            game_seperator();

            debug_cell(game_v, game_input_tmp);

            /* Enter loop */
            afficher_echiquier(game_v, COORDINATE_NULL);
            printf("\n\n\n");

        /* Surrend command */
        }
        else if(game_selector(game_command, "surrend"))
        {

            /* Separator */
            game_seperator();

            changer_joueur(game_v);
            printf("Le joueur ");

            if(game_v -> player == 0)
            {
                printf("1");
            }
            else if(game_v -> player == 1)
            {
                printf("2");
            }

            printf(" a gagner la partie.\n");

            /* Exit loop */
            afficher_echiquier(game_v, COORDINATE_NULL);
            game_play = 0;

        /* Move command */
        }
        else if(game_selector(game_command, "move"))
        {

            /* Input */
            do
            {
                /* Separator */
                game_seperator();
                printf("Saisir les coordonnees d'une piece:\n");

                /* Enter loop */
                afficher_echiquier(game_v, COORDINATE_NULL);
                printf("\n\n\n");
                game_input_tmp = saisie_case();
            }
            while(!movement_valid_input(game_v, game_input_tmp));

            printf("\n");

            /* Output */
            do
            {
                /* Separator */
                game_seperator();
                printf("Vous avez selectionner la piece '");
                piece_afficher(game_v -> board[game_input_tmp.x][game_input_tmp.y]);
                printf("' de coordonnees (%d;%d) du joueur ", game_input_tmp.x, game_input_tmp.y);
                printf("%d.", game_v -> board[game_input_tmp.x][game_input_tmp.y].color);
                printf("\nSaisir les coordonnees du movement:\n");

                /* Enter loop */
                afficher_echiquier(game_v,game_input_tmp);
                printf("\n\n\n");
                game_output_tmp = saisie_case();
            }
            while(!movement_valid_output(game_v, game_output_tmp));

            /* Separator */
            game_seperator();
            depalcement_valide(game_v, game_input_tmp, game_output_tmp);

            /* Enter loop */
            afficher_echiquier(game_v, COORDINATE_NULL);
            printf("\n\n\n");

        /* Back command */
        }
        else if(game_selector(game_command, "back"))
        {

            /* Separator */
            game_seperator();

            if(!file_empty(game_v -> played))
            {
                printf("L'annulation a ete effectue.\n");
                annuler_deplacement(game_v);
            }
            else
            {
                printf("L'annulation a echoue.\n");

            }

            /* Enter loop */
            afficher_echiquier(game_v, COORDINATE_NULL);
            printf("\n\n\n");

        /* Save command */
        }
        else if(game_selector(game_command, "save"))
        {
            /* Separator */
            game_seperator();

            printf("Sauvegarde.\n");

            /* Enter loop */
            afficher_echiquier(game_v, COORDINATE_NULL);
            printf("\n\n\n");

            printf("Entrer le nom de la partie: ");
            fgets(game_save_name, MAX_CHAR, stdin);

            /* Separator */
            game_seperator();

            /* Enter loop */
            afficher_echiquier(game_v, COORDINATE_NULL);
            printf("\n\n\n");

            printf("Entrer l'emplacement de la sauvegarder: ");

            fgets(game_save_path, MAX_CHAR, stdin);

            /* Separator */
            game_seperator();

            partie_sauvegarder(game_v, game_save_name, game_save_path);

            printf("La partie a ete sauvergarder.\n");

            /* Exit loop */
            afficher_echiquier(game_v, COORDINATE_NULL);

            game_play = game_exit(game_v);

        /* Exit command */
        }
        else if(game_selector(game_command, "exit"))
        {

            /* Separator */
            game_seperator();

            printf("Quitter.\n");

            /* Enter loop */
            afficher_echiquier(game_v, COORDINATE_NULL);
            printf("\n\n");
            printf("Etes vous sur de quitter sans sauvegarder? (oui/non)\n");

            if(scanf("%19s", game_exit_confirmation) != 1){
                /* Separator */
                game_seperator();

                printf("Entrer au moins un caractere.\n");

                /* Enter loop */
                afficher_echiquier(game_v, COORDINATE_NULL);
                printf("\n\n\n");
            }

            if(strcmp(game_exit_confirmation,"oui") == 0)
            {

                /* Separator */
                game_seperator();
                printf("Merci d'avoir jouer a ce jeu.\n");

                /* Enter loop */
                afficher_echiquier(game_v, COORDINATE_NULL);

                game_play = game_exit(game_v);
            }
            else
            {
                /* Separator */
                game_seperator();

                printf("Sauvegarde.\n");

                /* Enter loop */
                afficher_echiquier(game_v, COORDINATE_NULL);
                printf("\n\n\n");

                printf("Entrer le nom de la partie:");
                fgets(game_save_name, MAX_CHAR, stdin);

                /* Separator */
                game_seperator();

                /* Enter loop */
                afficher_echiquier(game_v, COORDINATE_NULL);
                printf("\n\n\n");

                printf("Entrer l'emplacement de la sauvegarder:");

                fgets(game_save_path, MAX_CHAR, stdin);

                /* Separator */
                game_seperator();

                printf("La partie a ete sauvergarder.");

                partie_sauvegarder(game_v, game_save_name, game_save_path);

                /* Enter loop */
                afficher_echiquier(game_v, COORDINATE_NULL);

                game_play = game_exit(game_v);
            }

        /* Unknown command */
        }
        else
        {

            /* Separator */
            game_seperator();

            printf("'%s' n'est pas reconnu comme une commande,\nsaisissez 'help' pour en savoir plus sur les commandes.\n", game_command);

            /* Enter loop */
            afficher_echiquier(game_v, COORDINATE_NULL);
            printf("\n\n\n");
        }
    }
}

/**
 * replay load
 */

void replay_charger()
{
	//======================================================================
	// Main
	//======================================================================

}

/**
 * replay play
 */

void replay_jouer()
{
	//======================================================================
	// Main
	//======================================================================

}
