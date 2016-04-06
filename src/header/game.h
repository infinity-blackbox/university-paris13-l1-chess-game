/**
 * @tableofcontents
 *
 * 1. game
 *
 * @since 4.0
 *
 * @package Chess Game
 * @category Game Header
 * @author William Phetsinorath
 *         Rakib Sheikh
 *		   Sabri Rezak Salem
 */

#ifndef DEF_STRUCTURE_GAME
#define DEF_STRUCTURE_GAME
#include"file.h"
#include"pile.h"
#include"piece.h"

/* @section 1. game */

typedef struct game_s{
    piece_t board[8][8];
    file_list_t * played;
    pile_list_t * catched;
    int player;
} game_t;

/**
 * @section 2 prototype
 *
 * 1. game.c
 *    1.1 game.h
 */
 
 int case_vide();
 void modifier_case();
 void changer_joueur();
 void depalcement();
 void annuler_deplacement();

 coordinate_t saisie_case();

 void afficher_echiquier();

 game_t * partie_creer();
 void partie_detruire();
 void partie_sauvegarder();
 void partie_charger();
 game_t * partie_nouvelle();

 void game_seperator();
 int game_selector();

 void partie_jouer();
 void replay_charger();
 void replay_jouer();

#endif
