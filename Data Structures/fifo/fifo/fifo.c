
#include "fifo.h"

fifo_status fifo_init(fifo_t*fifo,element_type*buf,unsigned int length){
    if(fifo==NULL)
        return fifo_null;
    fifo->base=buf;
    fifo->head=buf;
    fifo->tail=buf;
    fifo->length=length;
    fifo->count=0;

    return fifo_no_error;

}
fifo_status fifo_enqueue(fifo_t*fifo,element_type item){
    if(!fifo->base || !fifo->head || !fifo->tail)
        return fifo_null;
    if(fifo_is_full(fifo)==fifo_full)
        return fifo_full;

    *(fifo->head)=item;
    fifo->count++;

    //circular fifo
    if(fifo->head == (fifo->base+(fifo->length * sizeof(element_type)))){
       fifo->head=fifo->base;
    }
    else{
        fifo->head++;
    }


    return fifo_no_error;
}
fifo_status fifo_dequeue(fifo_t*fifo,element_type *item){
        if(!fifo->base || !fifo->head || !fifo->tail)
            return fifo_null;

        if(fifo->count==0)
            return fifo_empty;


        *item=*(fifo->tail);
        fifo->count--;

        if(fifo->tail==(fifo->base+(fifo->length*sizeof(element_type))))
            fifo->tail=fifo->base;
        else
            fifo->tail++;

    return fifo_no_error;
}

fifo_status fifo_is_full(fifo_t*fifo){
     if(!fifo->base || !fifo->head || !fifo->tail)
        return fifo_null;

     if(fifo->count==fifo->length)
        return fifo_full;

     return fifo_no_error;
}

void fifo_print(fifo_t*fifo){
    element_type *temp;
    int  i;
    if(fifo->count==0){
        printf("fifo is empty \n");
    }else{
        temp=(fifo->tail);
        printf("\n ==========fifo print============ \n");
        for(i=0;i<(fifo->count);i++){
            printf("\t %x \n",temp[i]);
        }
    }
    printf("===========\n");
}
