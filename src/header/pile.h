/**
 * @tableofcontents
 *
 * 1. pile link
 * 2. pile list
 * 3. prototype
 *
 * @since 2.3
 *
 * @package Chess Game
 * @category Pile Header
 * @author William Phetsinorath
 *         Rakib Sheikh
 *		   Sabri Rezak Salem
 */

#ifndef DEF_STRUCTURE_PILE
#define DEF_STRUCTURE_PILE
#include"piece.h"

/* @section 1. pile link */

typedef struct pile_link_s{
    piece_t piece;
    struct pile_link_s * next;
}pile_link_t;

/* @section 2. pile list */

typedef struct pile_list_s{
    pile_link_t * first;
    pile_link_t * last;
    int length;
}pile_list_t;

/**
 * @section 3 prototype
 *
 * 1. pile.c
 *    1.1 pile_list.h
 */
 
pile_link_t * pile_link_create();
void pile_link_destruct();

void pile_list_add();
pile_link_t * pile_list_extract();

pile_list_t * pile_create();
void pile_destruct();
int pile_empty();
int pile_length();
void pile_stacking();
piece_t pile_unstacking();

#endif
