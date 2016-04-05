/**
 * @since 2.3
 *
 * @package Chess Game
 * @category Piece Main
 * @author William Phetsinorath
 */

#include<stdio.h>
#include<stdlib.h>
#include"loader.h"

/**
 * piece creator
 *
 * @return struct piece_s
 */
piece_t piece_creer(piece_color_e piece_color_v, piece_type_e piece_type_v){
    piece_t res;
    res.color = piece_color_v;
    res.type = piece_type_v;
    return res;
}

/**
 * piece color detector
 *
 * @return int
 */
int piece_couleur(piece_t piece_v){
    return piece_v.color;
}

/**
 * piece identifier
 *
 * @return struct piece_s
 */
piece_t piece_identifier(char caracter_v){
    if(caracter_v<=90 && caracter_v>=65){
        switch(caracter_v){
            {
                case 'P':
                return piece_creer(BLACK_PIECE,PAWN);
            }
            {
                case 'T':
                return piece_creer(BLACK_PIECE,ROCK);
            }
            {
                case 'C':
                return piece_creer(BLACK_PIECE,KNIGHT);
            }
            {
                case 'F':
                return piece_creer(BLACK_PIECE,BISHOP);
            }
            {
                case 'R':
                return piece_creer(BLACK_PIECE,QUEEN);
            }
            {
                case 'E':
                return piece_creer(BLACK_PIECE,KING);
            }
            }
    }else{
        switch(caracter_v){
            {
                case 'p':
                return piece_creer(WHITE_PIECE,PAWN);
            }
            {
                case 't':
                return piece_creer(WHITE_PIECE,ROCK);
            }
            {
                case 'c':
                return piece_creer(WHITE_PIECE,KNIGHT);
            }
            {
                case 'f':
                return piece_creer(WHITE_PIECE,BISHOP);
            }
            {
                case 'r':
                return piece_creer(WHITE_PIECE,QUEEN);
            }
            {
                case 'e':
                return piece_creer(WHITE_PIECE,KING);
            }
        }
    }
    return piece_creer(EMPTY_PIECE,EMPTY); /* Anti return non void warning : code block */
}

/**
 * piece type detector
 *
 * @return int
 */
char piece_caractere(piece_t piece_v){
    if(!piece_couleur(piece_v)){
        switch(piece_v.type){
            {
                case 1:
                return 'P';
            }
            {
                case 2:
                return 'T';
            }
            {
                case 3:
                return 'C';
            }
            {
                case 4:
                return 'F';
            }
            {
                case 5:
                return 'R';
            }
            {
                case 6:
                return 'E';
            }
            {
                case 7:
                return '*';
            }
            {
                default:
                return '.';
            }
        }
    }else{
        switch(piece_v.type){
            {
                case 1:
                return 'p';
            }
            {
                case 2:
                return 't';
            }
            {
                case 3:
                return 'c';
            }
            {
                case 4:
                return 'f';
            }
            {
                case 5:
                return 'r';
            }
            {
                case 6:
                return 'e';
            }
            {
                case 7:
                return '*';
            }
            {
                default:
                return '.';
            }
        }
    }
    return '.'; /* Anti return non void warning : code block */
}

/**
 * piece displayer
 */
void piece_afficher(piece_t piece_v){
    printf("%c",piece_caractere(piece_v));
}
