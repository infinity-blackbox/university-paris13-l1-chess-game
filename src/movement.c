/**
 * @since 4.0
 *
 * @package Chess Game
 * @category Movement Main
 * @author William Phetsinorath
 *         Rakib Sheikh
 *		   Sabri Rezak Salem
 */

#include<stdio.h>
#include<stdlib.h>
#include"loader.h"

/**
 * movement board validator
 *
 * @return int
 */
 void depalcement_valide(game_t * game_v,coordinate_t coordinate_input_v,coordinate_t coordinate_output_v){
    int movement_pawn_tmp=coordinate_output_v.x-coordinate_input_v.x;

    if(coordinate_input_v.x != coordinate_output_v.x || coordinate_input_v.y != coordinate_output_v.y){
    switch(game_v->board[coordinate_input_v.x][coordinate_input_v.y].type){
        {
            case 1:
            if(deplacement_valide_pion(coordinate_input_v,coordinate_output_v)){
                if(game_v->board[coordinate_input_v.x][coordinate_input_v.y].color == WHITE_PIECE){
                    if(movement_pawn_tmp == 1 || (movement_pawn_tmp <=2 && movement_pawn_tmp > 0)){
                        depalcement(game_v, coordinate_input_v, coordinate_output_v);
                        printf("Le pion a ete deplace de (%d;%d) a (%d;%d) avec succes.\n",coordinate_input_v.x,coordinate_input_v.y,coordinate_output_v.x,coordinate_output_v.y);
                    }else{
                        printf("Le deplacement a echouer.\n");
                    }
                }else if(game_v->board[coordinate_input_v.x][coordinate_input_v.y].color == BLACK_PIECE){
                    if(movement_pawn_tmp == -1 || (movement_pawn_tmp >= -2 && movement_pawn_tmp < 0)){
                        depalcement(game_v, coordinate_input_v, coordinate_output_v);
                        printf("Le pion a ete deplace de (%d;%d) a (%d;%d) avec succes.\n",coordinate_input_v.x,coordinate_input_v.y,coordinate_output_v.x,coordinate_output_v.y);
                    }else{
                        printf("Le deplacement a echouer.\n");
                    }
                }else{
                    printf("Le deplacement a echouer.\n");
                }
            }else{
                printf("Le deplacement a echouer.\n");
            }
            break;
        }
        {
            case 2:
            if(deplacement_valide_tour(coordinate_input_v,coordinate_output_v)){
                depalcement(game_v, coordinate_input_v, coordinate_output_v);
                printf("La tour a ete deplace de (%d;%d) a (%d;%d) avec succes.\n",coordinate_input_v.x,coordinate_input_v.y,coordinate_output_v.x,coordinate_output_v.y);
            }else{
                printf("Le deplacement a echouer.\n");
            }
            break;
        }
        {
            case 3:
            if(deplacement_valide_cavalier(coordinate_input_v,coordinate_output_v)){
                depalcement(game_v, coordinate_input_v, coordinate_output_v);
                printf("Le cavalier a ete deplace de (%d;%d) a (%d;%d) avec succes.\n",coordinate_input_v.x,coordinate_input_v.y,coordinate_output_v.x,coordinate_output_v.y);
            }else{
                printf("Le deplacement a echouer.\n");
            }
            break;
        }
        {
            case 4:
            if(deplacement_valide_four(coordinate_input_v,coordinate_output_v)){
                depalcement(game_v, coordinate_input_v, coordinate_output_v);
                printf("Le four a ete deplace de (%d;%d) a (%d;%d) avec succes.\n",coordinate_input_v.x,coordinate_input_v.y,coordinate_output_v.x,coordinate_output_v.y);
            }else{
                printf("Le deplacement a echouer.\n");
            }
            break;
        }
        {
            case 5:
            if(deplacement_valide_roi(coordinate_input_v,coordinate_output_v)){
                depalcement(game_v, coordinate_input_v, coordinate_output_v);
                printf("Le roi a ete deplace de (%d;%d) a (%d;%d) avec succes.\n",coordinate_input_v.x,coordinate_input_v.y,coordinate_output_v.x,coordinate_output_v.y);
            }else{
                printf("Le deplacement a echouer.\n");
            }
            break;
        }
        {
            case 6:
            if(deplacement_valide_reine(coordinate_input_v,coordinate_output_v)){
                depalcement(game_v, coordinate_input_v, coordinate_output_v);
                printf("La reine a ete deplace de (%d;%d) a (%d;%d) avec succes.\n",coordinate_input_v.x,coordinate_input_v.y,coordinate_output_v.x,coordinate_output_v.y);
            }else{
                printf("Le deplacement a echouer.\n");
            }
            break;
        }
        {
            default:
            break;
        }
    }
    }
 }

/**
 * movement board validator
 *
 * @return int
 */
int movement_valid_input(game_t * game_v, coordinate_t coordinate_v){
    if(coordinate_v.x<8 && coordinate_v.y<8){
            if(game_v->board[coordinate_v.x][coordinate_v.y].type != 0){
                if(game_v->player == game_v->board[coordinate_v.x][coordinate_v.y].color){
                    return 1;
                }
            }
    }
    return 0;
}

/**
 * movement board validator
 *
 * @return int
 */
int movement_valid_output(game_t * game_v, coordinate_t coordinate_v){
    if(coordinate_v.x<8 && coordinate_v.y<8){
        return 1;
    }
    return 0;
}

/**
 * movement pawn validator
 *
 * @return int
 */
int deplacement_valide_pion(coordinate_t coordinate_input_v,coordinate_t coordinate_output_v){
    int movement_tmp=coordinate_output_v.x-coordinate_input_v.x;

    if(coordinate_input_v.x == 1 || coordinate_input_v.x == 6){
        /* horizontal checking */
        if(coordinate_input_v.y == coordinate_output_v.y){
            /* vertical checking */
            if(movement_tmp >= -2){
                return 1;
            }else if(movement_tmp <= 2){

            }
            return 0;
        }
        return 0;
    }else{
        /* horizontal checking */
        if(coordinate_input_v.y == coordinate_output_v.y){
            /* vertical checking */
            if( movement_tmp == -1){
                return 1;
            }else if(movement_tmp == 1){
                return 1;
            }
            return 0;
        }
        return 0;
    }
}

/**
 * movement rock validator
 *
 * @return int
 */
int deplacement_valide_tour(coordinate_t coordinate_input_v,coordinate_t coordinate_output_v){
    if(coordinate_input_v.y == coordinate_output_v.y || coordinate_input_v.x == coordinate_output_v.x){
        return 1;
    }
    return 0;
}

/**
 * movement knight validator
 *
 * @return int
 */
int deplacement_valide_cavalier(coordinate_t coordinate_input_v,coordinate_t coordinate_output_v){
    if(coordinate_input_v.x-1 == coordinate_output_v.x || coordinate_input_v.x+1 == coordinate_output_v.x){
        if(coordinate_input_v.y-2 == coordinate_output_v.y || coordinate_input_v.y+2 == coordinate_output_v.y){
            return 1;
        }
    }
    if(coordinate_input_v.y-1 == coordinate_output_v.y || coordinate_input_v.y+1 == coordinate_output_v.y){
        if(coordinate_input_v.x-2 == coordinate_output_v.x || coordinate_input_v.x+2 == coordinate_output_v.x){
            return 1;
        }
    }
    return 0;
}

/**
 * movement bishop validator
 *
 * @return int
 */
 
 /* Check */

int check (game_t * game_v,coordinate_t coordinate_output_v){
    if(!case_vide(game_v->board[coordinate_output_v.x][coordinate_output_v.y])){
        return 1;
    } else {
        return 0; 
    }
}
 
int deplacement_valide_four(coordinate_t coordinate_input_v,coordinate_t coordinate_output_v){
    
    int movement_1_tmp      =   (coordinate_output_v.x + coordinate_output_v.y);
    int movement_2_tmp      =   (coordinate_input_v.x+coordinate_input_v.y);
    int movement_1_bis_tmp  =   (coordinate_input_v.x-coordinate_input_v.y);
    int movement_2_bis_tmp  =   (coordinate_output_v.x-coordinate_output_v.y);
    

    if(movement_1_tmp == movement_2_tmp || movement_2_bis_tmp == movement_1_bis_tmp  ){
      check(game_v,coordinate_output_v);
      
       
       /*  return 1, */
        /* Check if case are \0 */
        /* -------PROTOTYPE-----*/
        /*while( != ){
            return 1;
        }*/
        /* return 1; */
    }
    return 0;
}

/**
 * movement king validator
 *
 * @return int
 */
int deplacement_valide_roi(coordinate_t coordinate_input_v,coordinate_t coordinate_output_v){
    /* vertical checking */
    if(coordinate_input_v.x-1 == coordinate_output_v.x || coordinate_input_v.x+1 == coordinate_output_v.x){
        if(coordinate_input_v.y-1 == coordinate_output_v.y || coordinate_input_v.y+1 == coordinate_output_v.y){
            return 1;
        }
    }
    return 0;
}

/**
 * movement queen validator
 *
 * @return int
 */
int deplacement_valide_reine(coordinate_t coordinate_input_v,coordinate_t coordinate_output_v){
    if(deplacement_valide_four(coordinate_input_v,coordinate_output_v) || deplacement_valide_tour(coordinate_input_v,coordinate_output_v)){
        return 1;
    }
    return 0;
}

/**
 * movement board validator for helper
 *
 * @return int
 */
 int movement_valid_helper(game_t * game_v,coordinate_t coordinate_input_v,coordinate_t coordinate_output_v){
    int movement_pawn_tmp=coordinate_output_v.x-coordinate_input_v.x;

    switch(game_v->board[coordinate_input_v.x][coordinate_input_v.y].type){
        {
            case 1:
            if(deplacement_valide_pion(coordinate_input_v,coordinate_output_v)){
                if(game_v->board[coordinate_input_v.x][coordinate_input_v.y].color == WHITE_PIECE){
                    if(movement_pawn_tmp == 1 || (movement_pawn_tmp <=2 && movement_pawn_tmp > 0)){
                        return 1;
                    }else{
                        return 0;
                    }
                }else if(game_v->board[coordinate_input_v.x][coordinate_input_v.y].color == BLACK_PIECE){
                    if(movement_pawn_tmp == -1 || (movement_pawn_tmp >= -2 && movement_pawn_tmp < 0)){
                        return 1;
                    }else{
                        return 0;
                    }
                }
            }else{
                return 0;
            }
            break;
        }
        {
            case 2:
            if(deplacement_valide_tour(coordinate_input_v,coordinate_output_v)){
                return 1;
            }else{
                return 0;
            }
            break;
        }
        {
            case 3:
            if(deplacement_valide_cavalier(coordinate_input_v,coordinate_output_v)){
                return 1;
            }else{
                return 0;
            }
            break;
        }
        {
            case 4:
            if(deplacement_valide_four(coordinate_input_v,coordinate_output_v)){
                return 1;
            }else{
                return 0;
            }
            break;
        }
        {
            case 5:
            if(deplacement_valide_roi(coordinate_input_v,coordinate_output_v)){
                return 1;
            }else{
                return 0;
            }
            break;
        }
        {
            case 6:
            if(deplacement_valide_reine(coordinate_input_v,coordinate_output_v)){
                return 1;
            }else{
                return 0;
            }
            break;
        }
        {
            default:
                /* do nothing */
            break;
        }
    }
   return 0;
 }
