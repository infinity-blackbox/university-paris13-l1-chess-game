/**
 * @since 4.6
 *
 * @package Chess Game
 * @category Debug Main
 * @author William Phetsinorath
 *         Rakib Sheikh
 *		   Sabri Rezak Salem
 */

#include<stdio.h>
#include<stdlib.h>
#include"loader.h"

/**
 * global
 */
int i, x, y;

/**
 * debug file
 *
 * Parameters:
 *     game_t - game_v
 */
void debug_file(game_t * game_v)
{
	//======================================================================
	// Variables
	//======================================================================
    file_list_t *   file_list_tmp;
    file_link_t *   file_link_tmp;

    /* Initialize */
    file_list_tmp = game_v -> played;

	//======================================================================
	// Main
	//======================================================================
    printf("DEBUG | File\n");
    printf("Longueur: %d\n", file_list_tmp -> length);

    if(!file_empty(file_list_tmp))
    {

        for(file_link_tmp = file_list_tmp -> first, i = 0; file_link_tmp != NULL; i++, file_link_tmp = file_link_tmp -> next)
        {
            printf("Maillon %d | ", i);
            printf("(%d;%d) ",      file_link_tmp -> movement.input.x, file_link_tmp -> movement.input.y);
            printf("(%d;%d)\n",     file_link_tmp -> movement.ouput.x, file_link_tmp -> movement.ouput.y);
        }

    }
    else
    {
        printf("La file ne contient rien.");
    }

    printf("\n");
}

/**
 * debug pile
 *
 * Parameters:
 *     game_t - game_v
 */
void debug_pile(game_t * game_v)
{
	//======================================================================
	// Variables
	//======================================================================
    pile_list_t *   pile_list_tmp;
    pile_link_t *   pile_link_tmp;

    /* Initialize */
    pile_list_tmp = game_v -> catched;

	//======================================================================
	// Main
	//======================================================================
    printf("DEBUG | Pile\n");
    printf("Taille: %d\n", pile_list_tmp -> length);

    if(!pile_empty(pile_list_tmp))
    {

        for(pile_link_tmp = pile_list_tmp -> first, i = 0; pile_link_tmp != NULL; i++, pile_link_tmp = pile_link_tmp -> next)
        {
            printf("Maillon %d | '", i);
            piece_afficher(          pile_link_tmp -> piece);
            printf("' (%d;%d)\n",    pile_link_tmp -> piece.type, pile_link_tmp -> piece.color);
        }

    }
    else
    {
        printf("La pile ne contient rien.");
    }

    printf("\n");
}



/**
 * debug game
 *
 * Parameters:
 *     game_t - game_v
 */
game_t * debug_game()
{
	//======================================================================
	// Variables
	//======================================================================
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

    res         -> board[4][4] = piece_creer(WHITE_PIECE, ROCK);

    return res;
}
