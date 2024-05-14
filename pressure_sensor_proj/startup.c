#include <stdint.h>
#define STACK_START_SP 0x20000000

extern int main(void);
void Reset_handler(void);
void Default_Handler(void);
void NMI_handler(void) __attribute__((weak, alias("Default_Handler")));
;
void H_Fault_handler(void) __attribute__((weak, alias("Default_Handler")));
;
void MM_Fault_handler(void) __attribute__((weak, alias("Default_Handler")));
;
void Bus_handler(void) __attribute__((weak, alias("Default_Handler")));
;
void Usage_handler(void) __attribute__((weak, alias("Default_Handler")));
;
extern uint32_t _stack_top;
extern unsigned int _S_Data;
extern unsigned int _E_Data;
extern unsigned int _E_text;
extern unsigned int _S_bss;
extern unsigned int _E_bss;

uint32_t vectors[] __attribute__((section(".vectors"))) =
    {
        (uint32_t)&_stack_top,
        (uint32_t)&Reset_handler,
        (uint32_t)&NMI_handler,
        (uint32_t)&H_Fault_handler,
        (uint32_t)&MM_Fault_handler,
        (uint32_t)&Bus_handler,
        (uint32_t)&Usage_handler};

void Default_Handler()
{
    Reset_handler();
}
void Reset_handler()
{
    unsigned int Data_Size = (unsigned char *)(&_E_Data) - (unsigned char *)(&_S_Data);
    unsigned char *p_src = (unsigned char *)(&_E_text);
    unsigned char *p_dst = (unsigned char *)(&_S_Data);
    // ROM TO RAM COPYING ....
    for (int i = 0; i < Data_Size; i++)
    {
        *((unsigned char *)p_dst++) = *((unsigned char *)p_src++);
    }

    unsigned int Bss_Size = (unsigned char *)(&_E_bss) - (unsigned char *)(&_S_bss);
    for (int i = 0; i < Data_Size; i++)
    {
        *((unsigned char *)p_dst++) = (unsigned char *)0;
    }

    main();
}
