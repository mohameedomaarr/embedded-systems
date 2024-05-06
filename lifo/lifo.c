/*
 * lifo.c
 *
 *  Created on: May 5, 2024
 *      Author: moham
 */

#include"lifo.h"

lifo_status lifo_add_item(lifo_buf_t * lifo_buf,unsigned int item){
	// check lifo valid
	if((lifo_buf->base==NULL) || (lifo_buf->head==NULL))
		return lifo_null;
	//check lifo full
	//if(lifo_buf->head >= (lifo_buf->(base+lifo_buf->length*4)))
	if(lifo_buf->count==lifo_buf->length)
		return lifo_full;
	//add value
	if(lifo_buf->count==(lifo_buf->length-1)){
        *(lifo_buf->head)=item;
        lifo_buf->count++;
	}else{
        *(lifo_buf->head)=item;
        lifo_buf->head++;
        lifo_buf->count++;
	}


	return lifo_no_err;
}

//pop func
lifo_status lifo_get_item(lifo_buf_t* lifo_buf,unsigned int * item){
	// check lifo valid
	if(!lifo_buf->base || !lifo_buf->head)
		return lifo_null;


    *item=*(lifo_buf->head);
    lifo_buf->count--;
    lifo_buf->head--;

	//check lifo empty
	if(lifo_buf->count==0)
        return lifo_empty;

	return lifo_no_err;
}


lifo_status lifo_init(lifo_buf_t* lifo_buf,unsigned int * buf,unsigned int length){
	if(buf == NULL)
		return lifo_null;

	lifo_buf->base =buf;
	lifo_buf->count=0;
	lifo_buf->head =buf;
	lifo_buf->length=length;

	return lifo_no_err;
}
