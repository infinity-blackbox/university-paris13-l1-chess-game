/**
 * @tableofcontents
 *
 * 1. file link
 *    1.1 coordinate
 *    1.2 file link
 * 2. file list
 * 3. prototype
 *
 * @since 4.0
 *
 * @package Chess Game
 * @category File Header
 * @author William Phetsinorath
 *         Rakib Sheikh
 */

#ifndef DEF_STRUCTURE_FILE
#define DEF_STRUCTURE_FILE
#include"game.h"

/* @section 1.1 coordinate */
typedef struct coordinate_s{
    int x;
    int y;
}coordinate_t;

/* @section 1.2 file link */
typedef struct movment_s{
    int value;
    coordinate_t input;
    coordinate_t ouput;
} movement_t;

/* @section 1. file link */
typedef struct file_link_s{
    movement_t movement;
    struct file_link_s * next;
}file_link_t;

/* @section 2. file list */
typedef struct file_list_s{
    file_link_t * first;
    file_link_t * last;
    int length;
}file_list_t;

/**
 * @section 3 prototype
 *
 * 1. file.c
 *    1.1 file.h
 */
file_link_t * file_link_create();
void file_link_destruct();

void file_list_add();
file_link_t * file_list_extract();

file_list_t * file_create();
void file_destruct();
int file_empty();
int file_length();
void file_thread();
movement_t file_unthread();

#endif
