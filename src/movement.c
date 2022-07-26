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
 * global
 */
coordinate_t movement_checker_tmp;

/**
 * movement board validator
 *
 * Parameters:
 *     game_t       - game_v
 *     coordinate_t - coordinate_input_v
 *     coordinate_t - coordinate_output_v
 */
void depalcement_valide(game_t * game_v, coordinate_t coordinate_input_v, coordinate_t coordinate_output_v)
{
	//======================================================================
	// Main
	//======================================================================
    if((coordinate_input_v.x != coordinate_output_v.x || coordinate_input_v.y != coordinate_output_v.y) && (game_v -> board[coordinate_input_v.x][coordinate_input_v.y].color != game_v -> board[coordinate_output_v.x][coordinate_output_v.y].color))
    {

        switch(game_v -> board[coordinate_input_v.x][coordinate_input_v.y].type)
        {
            {
            case 1:

                if(deplacement_valide_pion(game_v, coordinate_input_v, coordinate_output_v))
                {
                    deplacement(game_v, coordinate_input_v, coordinate_output_v);
                    printf("Le poin a ete deplace de (%d;%d) a (%d;%d) avec succes.\n",coordinate_input_v.x, coordinate_input_v.y, coordinate_output_v.x,coordinate_output_v.y);
                }
                else
                {
                    printf("Le deplacement du pion a echouer.\n");
                }

                break;
            }
            {
            case 2:

                if(deplacement_valide_tour(game_v, coordinate_input_v, coordinate_output_v))
                {
                    deplacement(game_v, coordinate_input_v, coordinate_output_v);
                    printf("La tour a ete deplace de (%d;%d) a (%d;%d) avec succes.\n",coordinate_input_v.x, coordinate_input_v.y, coordinate_output_v.x,coordinate_output_v.y);
                }
                else
                {
                    printf("Le deplacement de la tour a echouer.\n");
                }

                break;
            }
            {
            case 3:

                if(deplacement_valide_cavalier(game_v, coordinate_input_v, coordinate_output_v))
                {
                    deplacement(game_v, coordinate_input_v, coordinate_output_v);
                    printf("Le cavalier a ete deplace de (%d;%d) a (%d;%d) avec succes.\n",coordinate_input_v.x, coordinate_input_v.y, coordinate_output_v.x,coordinate_output_v.y);
                }
                else
                {
                    printf("Le deplacement du cavalier a echouer.\n");
                }

                break;
            }
            {
            case 4:

                if(deplacement_valide_four(game_v, coordinate_input_v, coordinate_output_v))
                {
                    deplacement(game_v, coordinate_input_v, coordinate_output_v);
                    printf("Le four a ete deplace de (%d;%d) a (%d;%d) avec succes.\n",coordinate_input_v.x, coordinate_input_v.y, coordinate_output_v.x,coordinate_output_v.y);
                }
                else
                {
                    printf("Le deplacement du four a echouer.\n");
                }

                break;
            }
            {
            case 5:

                if(deplacement_valide_reine(game_v, coordinate_input_v, coordinate_output_v))
                {
                    deplacement(game_v, coordinate_input_v, coordinate_output_v);
                    printf("La reine a ete deplace de (%d;%d) a (%d;%d) avec succes.\n",coordinate_input_v.x, coordinate_input_v.y, coordinate_output_v.x,coordinate_output_v.y);
                }
                else
                {
                    printf("Le deplacement de la reine a echouer.\n");
                }

                break;
            }
            {
            case 6:

                if(deplacement_valide_roi(game_v, coordinate_input_v, coordinate_output_v))
                {
                    deplacement(game_v, coordinate_input_v, coordinate_output_v);
                    printf("Le roi a ete deplace de (%d;%d) a (%d;%d) avec succes.\n",coordinate_input_v.x, coordinate_input_v.y, coordinate_output_v.x,coordinate_output_v.y);
                }
                else
                {
                    printf("Le deplacement du roi a echouer.\n");
                }

                break;
            }
            {
            default:
                break;
            }
        }
    }
	else
	{
		printf("Le deplacement a ete annulee.\n");
	}

}

/**
 * movement board validator
 *
 * Parameters:
 *     game_t       - game_v
 *     coordinate_t - coordinate_v
 *
 * @return int
 */
int movement_valid_input(game_t * game_v, coordinate_t coordinate_v)
{
	//======================================================================
	// Main
	//======================================================================
    if        (coordinate_v.x < 8 && coordinate_v.y < 8)
    {

        if    (game_v -> board[coordinate_v.x][coordinate_v.y].type != 0)
        {

            if(game_v -> player == game_v -> board[coordinate_v.x][coordinate_v.y].color)
            {
                return 1;

            }

        }
    }

    return 0;
}

/**
 * movement board validator
 *
 * Parameters:
 *     game_t       - game_v
 *     coordinate_t - coordinate_v
 *
 * @return int
 */
int movement_valid_output(game_t * game_v, coordinate_t coordinate_v)
{
	//======================================================================
	// Main
	//======================================================================
    if(coordinate_v.x < 8 && coordinate_v.y < 8)
    {
        return 1;
    }

    return 0;
}

/**
 * movement pawn validator
 *
 * Parameters:
 *     game_t       - game_v
 *     coordinate_t - coordinate_input_v
 *     coordinate_t - coordinate_output_v
 *
 * @return int
 */
int deplacement_valide_pion(game_t * game_v, coordinate_t coordinate_input_v, coordinate_t coordinate_output_v)
{
	//======================================================================
	// Variables
	//======================================================================
    int movement_tmp;

    /* Initialize */
    movement_tmp = coordinate_output_v.x-coordinate_input_v.x;

	//======================================================================
	// Main
	//======================================================================
    if             (coordinate_input_v.x == 1 || coordinate_input_v.x == 6)
    {
        /* horizontal checking */
        if         (coordinate_input_v.y == coordinate_output_v.y)
        {
            /* vertical checking */
            if     (game_v -> board[coordinate_input_v.x][coordinate_input_v.y].color == BLACK_PIECE)
            {
                if (movement_tmp >= -2 || movement_tmp == -1)
                {
                    return 1;
                }
            }
            else if(game_v -> board[coordinate_input_v.x][coordinate_input_v.y].color == WHITE_PIECE)
            {
                if (movement_tmp <= 2 || movement_tmp == 1)
                {
                    return 1;
                }
            }

            return 0;
        }

        return 0;
    }
    else
    {

        /* horizontal checking */
        if         (coordinate_input_v.y == coordinate_output_v.y)
        {

            /* vertical checking */
            if     (game_v -> board[coordinate_input_v.x][coordinate_input_v.y].color == BLACK_PIECE)
            {
                if (movement_tmp == -1)
                {
                    return 1;
                }
            }
            else if(game_v -> board[coordinate_input_v.x][coordinate_input_v.y].color == WHITE_PIECE)
            {
                if (movement_tmp == 1)
                {
                    return 1;
                }
            }
            return 0;
        }

        /* Diagonal Meat eater */

        if     ((game_v -> board[coordinate_input_v.x][coordinate_input_v.y].color == WHITE_PIECE) && (game_v -> board[coordinate_output_v.x][coordinate_output_v.y].color == BLACK_PIECE))
        {
            return 1;
        }
        else if((game_v -> board[coordinate_input_v.x][coordinate_input_v.y].color == BLACK_PIECE) && (game_v -> board[coordinate_output_v.x][coordinate_output_v.y].color == WHITE_PIECE))
        {
            return 1;
        }
        return 0;
    }

    return 0;
}

/**
 * movement rock validator
 *
 * Parameters:
 *     game_t       - game_v
 *     coordinate_t - coordinate_input_v
 *     coordinate_t - coordinate_output_v
 *
 * @return int
 */
int deplacement_valide_tour(game_t * game_v, coordinate_t coordinate_input_v, coordinate_t coordinate_output_v)
{
	//======================================================================
	// Main
	//======================================================================
    if(coordinate_input_v.y == coordinate_output_v.y || coordinate_input_v.x == coordinate_output_v.x)
    {
        return 1;
    }

    return 0;
}

/**
 * movement knight validator
 *
 * Parameters:
 *     game_t       - game_v
 *     coordinate_t - coordinate_input_v
 *     coordinate_t - coordinate_output_v
 *
 * @return int
 */
int deplacement_valide_cavalier(game_t * game_v, coordinate_t coordinate_input_v, coordinate_t coordinate_output_v)
{
	//======================================================================
	// Main
	//======================================================================
    if    (coordinate_input_v.x-1 == coordinate_output_v.x || coordinate_input_v.x+1 == coordinate_output_v.x)
    {

        if(coordinate_input_v.y-2 == coordinate_output_v.y || coordinate_input_v.y+2 == coordinate_output_v.y)
        {
            return 1;
        }

    }

    if    (coordinate_input_v.y-1 == coordinate_output_v.y || coordinate_input_v.y+1 == coordinate_output_v.y)
    {

        if(coordinate_input_v.x-2 == coordinate_output_v.x || coordinate_input_v.x+2 == coordinate_output_v.x)
        {
            return 1;
        }

    }

    return 0;
}

/**
 * movement bishop validator
 *
 * Parameters:
 *     game_t       - game_v
 *     coordinate_t - coordinate_input_v
 *     coordinate_t - coordinate_output_v
 *
 * @return int
 */
int deplacement_valide_four(game_t * game_v, coordinate_t coordinate_input_v, coordinate_t coordinate_output_v)
{
	//======================================================================
	// Variables
	//======================================================================
    int movement_1_tmp;
    int movement_2_tmp;
    int movement_1_bis_tmp;
    int movement_2_bis_tmp;

    /* Initialize */
    movement_1_tmp     = (coordinate_output_v.x + coordinate_output_v.y);
    movement_2_tmp     = (coordinate_input_v.x+coordinate_input_v.y);
    movement_1_bis_tmp = (coordinate_input_v.x-coordinate_input_v.y);
    movement_2_bis_tmp = (coordinate_output_v.x-coordinate_output_v.y);

	//======================================================================
	// Main
	//======================================================================
    if(movement_1_tmp == movement_2_tmp || movement_2_bis_tmp == movement_1_bis_tmp)
    {
        return 1;
    }

    return 0;
}

/**
 * movement king validator
 *
 * Parameters:
 *     game_t       - game_v
 *     coordinate_t - coordinate_input_v
 *     coordinate_t - coordinate_output_v
 *
 * @return int
 */
int deplacement_valide_roi(game_t * game_v, coordinate_t coordinate_input_v, coordinate_t coordinate_output_v)
{
	//======================================================================
	// Main
	//======================================================================
    /* vertical checking */
    if    (coordinate_input_v.x-1 == coordinate_output_v.x || coordinate_input_v.x+1 == coordinate_output_v.x || coordinate_input_v.x == coordinate_output_v.x)
    {

        if(coordinate_input_v.y-1 == coordinate_output_v.y || coordinate_input_v.y+1 == coordinate_output_v.y || coordinate_input_v.y == coordinate_output_v.y)
        {
            return 1;
        }

    }

    return 0;
}

/**
 * movement queen validator
 *
 * Parameters:
 *     game_t       - game_v
 *     coordinate_t - coordinate_input_v
 *     coordinate_t - coordinate_output_v
 *
 * @return int
 */
int deplacement_valide_reine(game_t * game_v, coordinate_t coordinate_input_v, coordinate_t coordinate_output_v)
{
	//======================================================================
	// Main
	//======================================================================
    if(deplacement_valide_four(game_v, coordinate_input_v, coordinate_output_v) || deplacement_valide_tour(game_v, coordinate_input_v, coordinate_output_v))
    {
        return 1;
    }

    return 0;
}

/**
 * movement board validator for helper
 *
 * Parameters:
 *     game_t       - game_v
 *     coordinate_t - coordinate_input_v
 *     coordinate_t - coordinate_output_v
 *
 * @return int
 */
int movement_valid_helper(game_t * game_v, coordinate_t coordinate_input_v, coordinate_t coordinate_output_v)
{
	//======================================================================
	// Main
	//======================================================================
    switch(game_v -> board[coordinate_input_v.x][coordinate_input_v.y].type)
    {
        {
        case 1:

            if(deplacement_valide_pion(game_v, coordinate_input_v, coordinate_output_v))
            {
                return 1;
            }
            else
            {
                return 0;
            }

            break;
        }
        {
        case 2:

            if(deplacement_valide_tour(game_v, coordinate_input_v, coordinate_output_v))
            {
                return 1;
            }
            else
            {
                return 0;
            }

            break;
        }
        {
        case 3:

            if(deplacement_valide_cavalier(game_v, coordinate_input_v, coordinate_output_v))
            {
                return 1;
            }
            else
            {
                return 0;
            }

            break;
        }
        {
        case 4:

            if(deplacement_valide_four(game_v, coordinate_input_v, coordinate_output_v))
            {
                return 1;
            }
            else
            {
                return 0;
            }

            break;
        }
        {
        case 5:

            if(deplacement_valide_reine(game_v, coordinate_input_v,coordinate_output_v))
            {
                return 1;
            }
            else
            {
                return 0;
            }

            break;
        }
        {
        case 6:

            if(deplacement_valide_roi(game_v, coordinate_input_v, coordinate_output_v))
            {
                return 1;
            }
            else
            {
                return 0;
            }

            break;
        }
        {
        default:
            return 0;
        }
    }

    return 0;
}
