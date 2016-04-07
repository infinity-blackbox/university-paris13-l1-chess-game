/**
 * @version 4.8
 *
 * @package Chess Game
 * @category Piece Main
 * @author William Phetsinorath
 *         Rakib Sheikh
 *		   Sabri Rezak Salem
 */

#include<stdio.h>
#include<stdlib.h>
#include"src/loader.h"

int main(){

    /* Main */
    game_t * game_new;

    /* Initialize */
    game_new = partie_nouvelle();

    /* Main */
    partie_jouer(game_new);
    return EXIT_SUCCESS;
}
