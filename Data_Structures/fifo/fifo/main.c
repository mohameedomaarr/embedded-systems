
#include"fifo.h"

int main()
{
    fifo_t fifo_uart;
    element_type i ,temp=0;
    if(fifo_init(&fifo_uart,uart_buff,5)==fifo_no_error)
        printf("fifo init ---- done \n");


    for(i=1;i<7;i++){
        printf("fifo enqueue (%x) \n",i);
        if(fifo_enqueue(&fifo_uart,i)==fifo_no_error)
             printf("fifo enqueue ---- done \n");
        else
            printf("fifo enqueue ---- failed \n");

    }

    fifo_print(&fifo_uart);

    if(fifo_dequeue(&fifo_uart,&temp)==fifo_no_error)
        printf("fifo dequeue %d ---- done \n",temp);

    fifo_print(&fifo_uart);

    return 0;
}
