/**
 * @since 4.0
 *
 * @package Chess Game
 * @category File Main
 * @author William Phetsinorath
 */

#include<stdio.h>
#include<stdlib.h>
#include"loader.h"

/**
 * file link creator
 *
 * @return struct file_link_s
 */
file_link_t * file_link_create(movement_t movement_v){
    file_link_t * res;
	
	res = (file_link_t*)malloc(sizeof(file_link_t));
    res->movement = movement_v;
    res->next = NULL;
    return res;
}

/**
 * file link destructor
 */
void file_link_destruct(file_link_t * file_link_v){
    free(file_link_v);
}

/**
 * file list add link (foot)
 */
void file_list_add(file_list_t * file_list_v, movement_t movement_v){
    file_link_t * file_link_tmp;
	
	file_link_tmp = file_link_create(movement_v);
    if(file_empty(file_list_v)){
        file_list_v->first = file_link_tmp;
    }else{
        file_list_v->last->next = file_link_tmp;
    }
    file_list_v->last = file_link_tmp;
    file_list_v->length++;
}

/**
 * file list extract link (head)
 */
file_link_t * file_list_extract(file_list_t * file_list_v){
    file_link_t * res;
	
	res = NULL;
    if(!file_empty(file_list_v)){
        res=file_list_v->first;
        file_list_v->first = res->next;
        res->next = NULL;
        file_list_v->length--;
        if(file_empty(file_list_v)){
            file_list_v->last = NULL;
        }
    }
    return res;
}

/**
 * file list creator
 *
 * @return struct file_link_s
 */
file_list_t * file_create(){
    file_list_t * res;
	
	res = (file_list_t*)malloc(sizeof(file_list_t));
    res->first = NULL;
    res->last = NULL;
    res->length = 0;
    return res;
}

/**
 * file list destructor
 */
void file_destruct(file_list_t * file_list_v){
    while(!file_empty(file_list_v)){
        file_link_destruct(file_list_extract(file_list_v));
    }
    free(file_list_v);
}

/**
 * file list empty detector
 *
 * @return int
 */
int file_empty(file_list_t * file_list_v){
    if(file_list_v->length == 0){
        return 1;
    }
    return 0;
}

/**
 * file list length detector
 *
 * @return int
 */
int file_length(file_list_t * file_list_v){
    return file_list_v->length;
}

/**
 * file thread
 */
void file_thread(file_list_t * file_list_v, movement_t movement_v){
    file_list_add(file_list_v, movement_v);
}

/**
 * file unthread
 */
movement_t file_unthread(file_list_t * file_list_v){
    file_link_t * file_link_tmp;
	
	file_link_tmp = file_list_extract(file_list_v);
    movement_t res = file_link_tmp->movement;
    file_link_destruct(file_link_tmp);
    return res;
}
