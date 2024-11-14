
void
__initialize_hardware(void)
{

}

#include "lifo.h"


unsigned int buffer1[5]; //5*4=20 byte


int main()
{
	unsigned int temp=0;
	lifo_buf_t uart_lifo , i2c_lifo;
	//static allocation
	lifo_init(&uart_lifo,buffer1,5);
	//dynamic allocation
	unsigned int * buffer2=(unsigned int *)malloc(5*sizeof(unsigned int));
	lifo_init(&i2c_lifo,buffer2,5);


	for(unsigned int i=0;i<6;i++){
		if(lifo_add_item(&uart_lifo,i)==lifo_no_err)
		printf("uart lifo add : %d \n",i);
	}
	for(unsigned int i=0;i<6;i++){
		if(lifo_get_item(&uart_lifo,&temp)==lifo_no_err)
		printf("uart lifo get : %d \n",temp);
	}


}
