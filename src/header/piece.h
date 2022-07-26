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
 *         Rakib Sheikh
 *		   Sabri Rezak Salem
 */

#ifndef DEF_STRUCTURE_PIECE
#define DEF_STRUCTURE_PIECE

typedef enum{WHITE_PIECE, BLACK_PIECE, EMPTY_PIECE} piece_color_e;
typedef enum{EMPTY, PAWN, ROCK, KNIGHT, BISHOP, QUEEN, KING, SELECT} piece_type_e;

/* @section 1. piece */
typedef struct piece_s{
    piece_color_e color;
    piece_type_e  type;
} piece_t;


//======================================================================
// Prototype
//======================================================================
piece_t piece_creer();
int     piece_couleur();
piece_t piece_identifier(char);
char    piece_caractere();
void    piece_afficher();

#endif
