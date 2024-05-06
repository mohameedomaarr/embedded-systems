#ifndef FIFO_H_INCLUDED
#define FIFO_H_INCLUDED

#include "stdio.h"
#include "stdint.h"
#include <stdlib.h>

//user config element_type(uint8_t , uint16_t , uint32_t,...)
#define element_type uint8_t

//create buffer
#define width1 5
element_type uart_buff[width1];

//fifo data types
typedef struct{
    unsigned int length;
    unsigned int count;
    element_type*head;
    element_type*tail;
    element_type*base;
}fifo_t;

typedef enum{
    fifo_no_error,
    fifo_full,
    fifo_empty,
    fifo_null
}fifo_status;

//fifo APIs
fifo_status fifo_init(fifo_t*fifo,element_type*buf,unsigned int length);
fifo_status fifo_enqueue(fifo_t*fifo,element_type item);
fifo_status fifo_dequeue(fifo_t*fifo,element_type *item);
fifo_status fifo_is_full(fifo_t*fifo);
void fifo_print(fifo_t*fifo);

#endif // FIFO_H_INCLUDED
