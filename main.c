/**
* @since 4.0
* @version 4.6
*
* @package Chess Game
* @category Main
* @author William Phetsinorath
*/

#include<stdio.h>
#include<stdlib.h>
#include"src/loader.h"

int main()
{
    game_t * game_new=partie_nouvelle();
    partie_jouer(game_new);
    return EXIT_SUCCESS;
}
