/**
 * @since 4.9
 *
 * @package Chess Game
 * @category Restriction Main
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
 * movement restriction
 *
 * Parameters:
 *     game_t       - game_v
 *     coordinate_t - coordinate_input_v
 */
void movement_restriction(game_t * game_v, coordinate_t coordinate_input_v)
{
    //======================================================================
    // Main
    //======================================================================
    switch(game_v -> board[coordinate_input_v.x][coordinate_input_v.y].type)
    {
        {
        case 1:
            movement_restriction_general(game_v, coordinate_input_v);
            break;
        }
        {
        case 2:
            movement_restriction_rock   (game_v, coordinate_input_v);
            break;
        }
        {
        case 3:
            movement_restriction_general(game_v, coordinate_input_v);
            break;
        }
        {
        case 4:
            movement_restriction_bishop (game_v, coordinate_input_v);
            break;
        }
        {
        case 5:
            movement_restriction_queen  (game_v, coordinate_input_v);
            break;
        }
        {
        case 6:
            movement_restriction_general(game_v, coordinate_input_v);
            break;
        }
        {
        default:
            break;
        }
    }

}

/**
 * movement general restriction
 *
 * Parameters:
 *     game_t       - game_v
 *     coordinate_t - coordinate_input_v
 */
void movement_restriction_general(game_t * game_v, coordinate_t coordinate_input_v)
{
    //======================================================================
    // Variables
    //======================================================================
    int x, y;

    //======================================================================
    // Main
    //======================================================================
    for    (x = 0; x < 8; x++)
    {
        movement_checker_tmp.x = x;

        for(y = 0; y < 8; y++)
        {
            movement_checker_tmp.y = y;

            if(movement_valid_helper(game_v, coordinate_input_v, movement_checker_tmp))
            {

                if(game_v->board[x][y].type == EMPTY)
                {
                    game_v->board[x][y].type = SELECT;
                }

            }

        }

    }

}

/**
 * movement rock restriction
 *
 * Parameters:
 *     game_t       - game_v
 *     coordinate_t - coordinate_input_v
 */
void movement_restriction_rock(game_t * game_v, coordinate_t coordinate_input_v)
{
    //======================================================================
    // Main
    //======================================================================
    for(movement_checker_tmp.x = coordinate_input_v.x+1; game_v -> board[movement_checker_tmp.x][coordinate_input_v.y].type == EMPTY && movement_checker_tmp.x < 8; movement_checker_tmp.x++)
    {
        game_v -> board[movement_checker_tmp.x][coordinate_input_v.y].type = SELECT;
    }

    for(movement_checker_tmp.y = coordinate_input_v.y+1; game_v -> board[coordinate_input_v.x][movement_checker_tmp.y].type == EMPTY && movement_checker_tmp.y < 8; movement_checker_tmp.y++)
    {
        game_v -> board[coordinate_input_v.x][movement_checker_tmp.y].type = SELECT;
    }

    for(movement_checker_tmp.x = coordinate_input_v.x-1; game_v -> board[movement_checker_tmp.x][coordinate_input_v.y].type == EMPTY && movement_checker_tmp.x > 0; movement_checker_tmp.x--)
    {
        game_v -> board[movement_checker_tmp.x][coordinate_input_v.y].type = SELECT;
    }

    for(movement_checker_tmp.y = coordinate_input_v.y-1; game_v -> board[coordinate_input_v.x][movement_checker_tmp.y].type == EMPTY && movement_checker_tmp.y > 0; movement_checker_tmp.y--)
    {
        game_v -> board[coordinate_input_v.x][movement_checker_tmp.y].type = SELECT;
    }

}

/**
 * movement bishop restriction
 *
 * Parameters:
 *     game_t       - game_v
 *     coordinate_t - coordinate_input_v
 */
void movement_restriction_bishop(game_t * game_v, coordinate_t coordinate_input_v)
{
    //======================================================================
    // Main
    //======================================================================
    for(movement_checker_tmp.x = coordinate_input_v.x+1, movement_checker_tmp.y = coordinate_input_v.y+1; game_v -> board[movement_checker_tmp.x][movement_checker_tmp.y].type == EMPTY && movement_checker_tmp.x < 8 && movement_checker_tmp.y < 8; movement_checker_tmp.x++, movement_checker_tmp.y++)
    {
        game_v -> board[movement_checker_tmp.x][movement_checker_tmp.y].type = SELECT;
    }

    for(movement_checker_tmp.x = coordinate_input_v.x-1, movement_checker_tmp.y = coordinate_input_v.y-1; game_v -> board[movement_checker_tmp.x][movement_checker_tmp.y].type == EMPTY && movement_checker_tmp.x >= 0 && movement_checker_tmp.y >= 0; movement_checker_tmp.x--, movement_checker_tmp.y--)
    {
        game_v -> board[movement_checker_tmp.x][movement_checker_tmp.y].type = SELECT;
    }

    for(movement_checker_tmp.x = coordinate_input_v.x+1, movement_checker_tmp.y = coordinate_input_v.y-1; game_v -> board[movement_checker_tmp.x][movement_checker_tmp.y].type == EMPTY && movement_checker_tmp.x < 8 && movement_checker_tmp.y >= 0; movement_checker_tmp.x++, movement_checker_tmp.y--)
    {
        game_v -> board[movement_checker_tmp.x][movement_checker_tmp.y].type = SELECT;
    }

    for(movement_checker_tmp.x = coordinate_input_v.x-1, movement_checker_tmp.y = coordinate_input_v.y+1; game_v -> board[movement_checker_tmp.x][movement_checker_tmp.y].type == EMPTY && movement_checker_tmp.x >= 0 && movement_checker_tmp.y < 8; movement_checker_tmp.x--, movement_checker_tmp.y++)
    {
        game_v -> board[movement_checker_tmp.x][movement_checker_tmp.y].type = SELECT;
    }

}

/**
 * movement queen restriction
 *
 * Parameters:
 *     game_t       - game_v
 *     coordinate_t - coordinate_input_v
 */
void movement_restriction_queen(game_t * game_v, coordinate_t coordinate_input_v)
{
    //======================================================================
    // Main
    //======================================================================
    movement_restriction_bishop(game_v, coordinate_input_v);
    movement_restriction_rock  (game_v, coordinate_input_v);
}

/**
 * movement restriction destruct
 *
 * Parameters:
 *     game_t - game_v
 */
void movement_restriction_destruct(game_t * game_v)
{
    //======================================================================
    // Variables
    //======================================================================
    int x, y;

    //======================================================================
    // Main
    //======================================================================
    for(x = 0; x < 8; x++)
    {

        for(y = 0; y < 8; y++)
        {
            movement_checker_tmp.x = x;
            movement_checker_tmp.y = y;

            if(game_v -> board[movement_checker_tmp.x][movement_checker_tmp.y].type == SELECT)
            {
                game_v -> board[movement_checker_tmp.x][movement_checker_tmp.y].type = EMPTY;
            }

        }

    }

}
