/**
 * @tableofcontents
 *
 * 1. prototype
 *
 * @since 2.3
 *
 * @package Chess Game
 * @category Movement Header
 * @author William Phetsinorath
 *         Rakib Sheikh
 */

#ifndef DEF_STRUCTURE_MOVEMENT
#define DEF_STRUCTURE_MOVEMENT

/**
 * @section 1 prototype
 *
 * 1. movement.c
 *    1.1 movement.h
 */
void depalcement_valide();
int movement_valid_helper();
int movement_valid_input();
int movement_valid_output();
int deplacement_valide_pion();
int deplacement_valide_tour();
int deplacement_valide_cavalier();
int deplacement_valide_four();
int deplacement_valide_roi();
int deplacement_valide_reine();

#endif
