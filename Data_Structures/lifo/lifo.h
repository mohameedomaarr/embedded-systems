/*
 * lifo.h
 *
 *  Created on: May 5, 2024
 *      Author: moham
 */


#ifndef LIFO_H_
#define LIFO_H_

#include "stdio.h"
#include "stdlib.h"

typedef struct {
	unsigned int length;
	unsigned int count;
	unsigned int * base;
	unsigned int * head;
}lifo_buf_t;

typedef enum {
	lifo_no_err,
	lifo_full,
	lifo_empty,
	lifo_null
}lifo_status;

lifo_status lifo_add_item(lifo_buf_t * lifo_buf,unsigned int item);
lifo_status lifo_get_item(lifo_buf_t * lifo_buf,unsigned int * item);
lifo_status lifo_init(lifo_buf_t * lifo_buf,unsigned int * buf,unsigned int length);

#endif /* LIFO_H_ */
