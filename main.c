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
    game_t * game_new=debug_game();
    partie_jouer(game_new);
    return EXIT_SUCCESS;
}
