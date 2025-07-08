#include <stdint.h>

#include "A31G12x.h"


#ifndef __WEAK
    #define __WEAK __attribute__((weak))
#endif


__WEAK void NMI_Handler				(void) { while(1) {} }
__WEAK void HardFault_Handler		(void) { while(1) {} }
__WEAK void SVC_Handler				(void) { while(1) {} }
__WEAK void PendSV_Handler			(void) { while(1) {} }

__WEAK void SysTick_Handler			(void) { while(1) {} }

__WEAK void LVI_Handler        		(void) { while(1) {} }
__WEAK void WUT_Handler        		(void) { while(1) {} }
__WEAK void WDT_Handler        		(void) { while(1) {} }
__WEAK void EINT0_Handler      		(void) { while(1) {} }
__WEAK void EINT1_Handler      		(void) { while(1) {} }
__WEAK void EINT2_Handler      		(void) { while(1) {} }
__WEAK void EINT3_Handler      		(void) { while(1) {} }
__WEAK void TIMER10_Handler    		(void) { while(1) {} }
__WEAK void TIMER11_Handler    		(void) { while(1) {} }
__WEAK void TIMER12_Handler    		(void) { while(1) {} }
__WEAK void I2C0_Handler       		(void) { while(1) {} }
__WEAK void USART10_Handler    		(void) { while(1) {} }
__WEAK void WT_Handler         		(void) { while(1) {} }
__WEAK void TIMER30_Handler    		(void) { while(1) {} }
__WEAK void I2C1_Handler       		(void) { while(1) {} }
__WEAK void TIMER20_Handler    		(void) { while(1) {} }
__WEAK void TIMER21_Handler    		(void) { while(1) {} }
__WEAK void USART11_Handler    		(void) { while(1) {} }
__WEAK void ADC_Handler        		(void) { while(1) {} }
__WEAK void UART0_Handler      		(void) { while(1) {} }
__WEAK void UART1_Handler      		(void) { while(1) {} }
__WEAK void TIMER13_Handler    		(void) { while(1) {} }
__WEAK void TIMER14_Handler    		(void) { while(1) {} }
__WEAK void TIMER15_Handler    		(void) { while(1) {} }
__WEAK void TIMER16_Handler    		(void) { while(1) {} }
__WEAK void I2C2_Handler       		(void) { while(1) {} }
__WEAK void USART12_Handler    		(void) { while(1) {} }
__WEAK void USART13_Handler    		(void) { while(1) {} }



void Reset_Handler				(void);

void NMI_Handler				(void);
void HardFault_Handler			(void);
void SVC_Handler				(void);
void PendSV_Handler				(void);

void SysTick_Handler			(void);

void LVI_Handler        		(void);
void WUT_Handler        		(void);
void WDT_Handler        		(void);
void EINT0_Handler      		(void);
void EINT1_Handler      		(void);
void EINT2_Handler      		(void);
void EINT3_Handler      		(void);
void TIMER10_Handler    		(void);
void TIMER11_Handler    		(void);
void TIMER12_Handler    		(void);
void I2C0_Handler       		(void);
void USART10_Handler    		(void);
void WT_Handler         		(void);
void TIMER30_Handler    		(void);
void I2C1_Handler       		(void);
void TIMER20_Handler    		(void);
void TIMER21_Handler    		(void);
void USART11_Handler    		(void);
void ADC_Handler        		(void);
void UART0_Handler      		(void);
void UART1_Handler      		(void);
void TIMER13_Handler    		(void);
void TIMER14_Handler    		(void);
void TIMER15_Handler    		(void);
void TIMER16_Handler    		(void);
void I2C2_Handler       		(void);
void USART12_Handler    		(void);
void USART13_Handler    		(void);



extern unsigned int __INITIAL_SP;
typedef void	(* const pHandler)(void);

pHandler __isr_vectors[] __VECTOR_TABLE_ATTRIBUTE = {

    (pHandler) &__INITIAL_SP,	//		Top of Stack


    Reset_Handler,			//		Reset Handler

	NMI_Handler,			//		-14 NMI Handler
	HardFault_Handler,    	//		-13 Hard Fault Handler

	0,                    	//		-12 Reserved
	0,                    	//		-11 Reserved
	0,                    	//		-10 Reserved
	0,                    	//      -9  Reserved
	0,                    	//      -8  Reserved
	0,                    	//      -7  Reserved
	0,                    	//      -6  Reserved
	SVC_Handler,          	//      -5  SVCall Handler
	0,                    	//      -4  Reserved
	0,                    	//      -3  Reserved
	PendSV_Handler,       	//      -2  PendSV Handler
	SysTick_Handler,      	//      -1  SysTick Handler

	//External Interrupts
	LVI_Handler,			//	IRQ 0
	WUT_Handler,    		//	IRQ 1
	WDT_Handler,    		//	IRQ 2
	EINT0_Handler,  		//	IRQ 3
	EINT1_Handler,  		//	IRQ 4
	EINT2_Handler,  		//	IRQ 5
	EINT3_Handler,  		//	IRQ 6
	TIMER10_Handler,		//	IRQ 7
	TIMER11_Handler,		//	IRQ 8
	TIMER12_Handler,		//	IRQ 9
	I2C0_Handler,			//	IRQ 10
	USART10_Handler,		//	IRQ 11
	WT_Handler,				//	IRQ 12
	TIMER30_Handler,		//	IRQ 13
	I2C1_Handler,			//	IRQ 14
	TIMER20_Handler,		//	IRQ 15
	TIMER21_Handler,		//	IRQ 16
	USART11_Handler,		//	IRQ 17
	ADC_Handler,			//	IRQ 18
	UART0_Handler,			//	IRQ 19
	UART1_Handler,			//	IRQ 20
	TIMER13_Handler,		//	IRQ 21
	TIMER14_Handler,		//	IRQ 22
	TIMER15_Handler,		//	IRQ 23
	TIMER16_Handler,		//	IRQ 24
	I2C2_Handler,			//	IRQ 25
	USART12_Handler,		//	IRQ 26
	USART13_Handler,		//	IRQ 27
   //RESERVED_Handler,		//	IRQ 28
   //RESERVED_Handler,		//	IRQ 29
   //RESERVED_Handler,		//	IRQ 30
   //RESERVED_Handler,		//	IRQ 31
};


extern void __PROGRAM_START(void);

void Reset_Handler(void)
{
	__PROGRAM_START();

    while (1) {}
}
