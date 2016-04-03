/**
 * @since 4.6
 *
 * @package Chess Game
 * @category Debug Main
 * @author William Phetsinorath
 */

#include<stdio.h>
#include<stdlib.h>
#include"loader.h"

void debug_location(x_v){
    printf("DEBUG | Working there %d.",x_v);
}

void debug_file(game_t * game_v){
    int i;
    file_list_t * file_list_tmp=game_v->piecePlay;

    printf("DEBUG | File\n");

    file_link_t * file_link_tmp;
    printf("Longueur: %d\n",file_list_tmp->fileListLength);
    if(!file_empty(file_list_tmp)){
        for(file_link_tmp=file_list_tmp->fileListFirst,i=0;file_link_tmp!=NULL;i++,file_link_tmp=file_link_tmp->fileLinkNext){
            printf("Maillon %d | (%d;%d) ",i,file_link_tmp->fileLinkMovement.movementInput.x, file_link_tmp->fileLinkMovement.movementInput.y);
            printf("(%d;%d)\n",file_link_tmp->fileLinkMovement.movementOutput.x,file_link_tmp->fileLinkMovement.movementOutput.y);
        }
    }else{
        printf("La file ne contient rien.");
    }
    printf("\n");
}

void debug_pile(game_t * game_v){
    int i;
    pile_list_t * pile_list_tmp=game_v->pieceCatch;

    printf("DEBUG | Pile\n");

    pile_link_t * pile_link_tmp;
    printf("Taille: %d\n",pile_list_tmp->pileListLength);
    if(!pile_empty(pile_list_tmp)){
        for(pile_link_tmp=pile_list_tmp->pileListFirst,i=0;pile_link_tmp!=NULL;i++,pile_link_tmp=pile_link_tmp->pileLinkNext){
            printf("Maillon %d | '",i);
            piece_afficher(pile_link_tmp->pileLinkPiece);
            printf("' (%d;%d)\n",pile_link_tmp->pileLinkPiece.pieceType,pile_link_tmp->pileLinkPiece.pieceColor);
        }
    }else{
        printf("La pile ne contient rien.");
    }
    printf("\n");
}
