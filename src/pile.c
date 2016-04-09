/**
 * @since 4.0
 *
 * @package Chess Game
 * @category Pile Main
 * @author William Phetsinorath
 *         Rakib Sheikh
 *		   Sabri Rezak Salem
 */

#include<stdio.h>
#include<stdlib.h>
#include"loader.h"

/**
 * pile link creator
 *
 * @return struct file_link_s
 */
 
pile_link_t * pile_link_create(piece_t piece_v){
    
    /* Variables */
    
    pile_link_t * res;

    /* Initialize */
    
	res        = (pile_link_t*)malloc(sizeof(pile_link_t));
    res->piece = piece_v;
    res->next  = NULL;
    
    return res;
}

/**
 * pile link destructor
 */
 
void pile_link_destruct(pile_link_t * pile_link_v){
    
    /* Main */
    
    free(pile_link_v);
}

/**
 * pile list add link (head)
 */
 
void pile_list_add(pile_list_t * pile_list_v, piece_t piece_v){

    /* Variables */
    
    pile_link_t * pile_link_tmp;

    /* Initialize */
    
	pile_link_tmp = pile_link_create(piece_v);
    
    /* Main */
    
    if(pile_empty(pile_list_v)){
        pile_list_v->last = pile_link_tmp;
    }else{
        pile_link_tmp->next = pile_list_v->first;
    }
    
    pile_list_v->first=pile_link_tmp;
    pile_list_v->length++;
}

/**
 * pile list extract link (foot)
 */
 
pile_link_t * pile_list_extract(pile_list_t * pile_list_v){
    
    /* Variables */
    
    pile_link_t * res;

    /* Initialize */
    
	res = NULL;
    
    /* Main */
    
    if(!pile_empty(pile_list_v)){
        res = pile_list_v->first;
        pile_list_v->first = res->next;
        res->next = NULL;
        pile_list_v->length--;
        if(pile_empty(pile_list_v)){
            pile_list_v->last = NULL;
        }
    }
    
    return res;
}

/**
 * pile list creator
 *
 * @return struct pile_link_s
 */
 
pile_list_t * pile_create(){
    
    /* Variables */
    
    pile_list_t * res;

    /* Initialize */
    
	res         = (pile_list_t*)malloc(sizeof(pile_list_t));
    res->first  = NULL;
    res->last   = NULL;
    res->length = 0;
    
    /* Main */
    
    return res;
}

/**
 * pile list destructor
 */
 
void pile_destruct(pile_list_t * pile_list_v){
    
    /* Main */
    
    while(!pile_empty(pile_list_v)){
        pile_link_destruct(pile_list_extract(pile_list_v));
    }
    
    free(pile_list_v);
}

/**
 * pile list empty detector
 *
 * @return int
 */
 
int pile_empty(pile_list_t * pile_list_v){
    
    /* Main */
    
    if(pile_list_v->length == 0){
        return 1;
    }
    
    return 0;
}

/**
 * pile list length detector
 *
 * @return int
 */
 
int pile_length(pile_list_t * pile_list_v){
    
    /* Main */
    
    return pile_list_v->length;
}

/**
 * pile stacking
 */
 
void pile_stacking(pile_list_t * pile_list_v, piece_t piece){
    
    /* Main */
    
    pile_list_add(pile_list_v, piece);
}

/**
 * pile unstacking
 */
 
piece_t pile_unstacking(pile_list_t * pile_list_v){
    
    /* Variables */
    
    pile_link_t * pile_link_tmp;

    /* Initialize */
    
	pile_link_tmp = pile_list_extract(pile_list_v);
    piece_t res   = pile_link_tmp->piece;
    
    /* Main */
    
    pile_link_t *  pile_list_extract(pile_link_tmp);
    return res;
}
