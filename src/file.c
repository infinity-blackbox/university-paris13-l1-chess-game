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
    file_link_t * res=(file_link_t*)malloc(sizeof(file_link_t));
    res->fileLinkMovement=movement_v;
    res->fileLinkNext=NULL;
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
    file_link_t * file_link_tmp=file_link_create(movement_v);
    if(file_empty(file_list_v)){
        file_list_v->fileListFirst=file_link_tmp;
    }else{
        file_list_v->fileListLast->fileLinkNext=file_link_tmp;
    }
    file_list_v->fileListLast=file_link_tmp;
    file_list_v->fileListLength++;
}

/**
 * file list extract link (head)
 */
file_link_t * file_list_extract(file_list_t * file_list_v){
    file_link_t * res=NULL;
    if(!file_empty(file_list_v)){
        res=file_list_v->fileListFirst;
        file_list_v->fileListFirst=res->fileLinkNext;
        res->fileLinkNext=NULL;
        file_list_v->fileListLength--;
        if(file_empty(file_list_v)){
            file_list_v->fileListLast=NULL;
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
    file_list_t * res=(file_list_t*)malloc(sizeof(file_list_t));
    res->fileListFirst=NULL;
    res->fileListLast=NULL;
    res->fileListLength=0;
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
    if(file_list_v->fileListLength==0){
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
    return file_list_v->fileListLength;
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
    file_link_t * file_link_tmp=file_list_extract(file_list_v);
    movement_t res=file_link_tmp->fileLinkMovement;
    file_link_destruct(file_link_tmp);
    return res;
}
