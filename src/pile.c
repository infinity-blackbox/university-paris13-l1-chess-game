/**
 * @since 4.0
 *
 * @package Chess Game
 * @category Pile Main
 * @author William Phetsinorath
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
    pile_link_t * res=(pile_link_t*)malloc(sizeof(pile_link_t));
    res->pileLinkPiece=piece_v;
    res->pileLinkNext=NULL;
    return res;
}

/**
 * pile link destructor
 */
void pile_link_destruct(pile_link_t * pile_link_v){
    free(pile_link_v);
}

/**
 * pile list add link (head)
 */
void pile_list_add(pile_list_t * pile_list_v, piece_t piece_v){
    pile_link_t * pile_link_tmp=pile_link_create(piece_v);
    if(pile_empty(pile_list_v)){
        pile_list_v->pileListLast=pile_link_tmp;
    }else{
        pile_link_tmp->pileLinkNext=pile_list_v->pileListFirst;
    }
    pile_list_v->pileListFirst=pile_link_tmp;
    pile_list_v->pileListLength++;
}

/**
 * pile list extract link (foot)
 */
pile_link_t * pile_list_extract(pile_list_t * pile_list_v){
    pile_link_t * res=NULL;
    if(!pile_empty(pile_list_v)){
        res=pile_list_v->pileListFirst;
        pile_list_v->pileListFirst=res->pileLinkNext;
        res->pileLinkNext=NULL;
        pile_list_v->pileListLength--;
        if(pile_empty(pile_list_v)){
            pile_list_v->pileListLast=NULL;
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
    pile_list_t * res=(pile_list_t*)malloc(sizeof(pile_list_t));
    res->pileListFirst=NULL;
    res->pileListLast=NULL;
    res->pileListLength=0;
    return res;
}

/**
 * pile list destructor
 */
void pile_destruct(pile_list_t * pile_list_v){
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
    if(pile_list_v->pileListLength==0){
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
    return pile_list_v->pileListLength;
}

/**
 * pile stacking
 */
void pile_stacking(pile_list_t * pile_list_v, piece_t piece){
    pile_list_add(pile_list_v, piece);
}

/**
 * pile unstacking
 */
piece_t pile_unstacking(pile_list_t * pile_list_v){
    pile_link_t * pile_link_tmp=pile_list_extract(pile_list_v);
    piece_t res=pile_link_tmp->pileLinkPiece;
    pile_list_extract(pile_link_tmp);
    return res;
}
