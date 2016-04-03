/**
 * @tableofcontents
 *
 * 1. piece
 * 2. prototype
 *
 * @since 2.3
 *
 * @package Chess Game
 * @category Piece Header
 * @author William Phetsinorath
 */

#ifndef DEF_STRUCTURE_PIECE
#define DEF_STRUCTURE_PIECE

typedef enum{WHITE_PIECE, BLACK_PIECE, EMPTY_PIECE} piece_color_e;
typedef enum{EMPTY, PAWN, ROCK, KNIGHT, BISHOP, QUEEN, KING, SELECT} piece_type_e;

/* @section 1. piece */
typedef struct piece_s{
    piece_color_e pieceColor;
    piece_type_e pieceType;
} piece_t;

/**
 * @section 2 prototype
 *
 * 1. piece.c
 *    1.1 piece.h
 */
piece_t piece_creer();
int piece_couleur();
piece_t piece_identifier(char);
char piece_caractere();
void piece_afficher();

#endif
