/**
 * \file
 *
 * \brief Empty user application template
 *
 */

/**
 * \mainpage User Application template doxygen documentation
 *
 * \par Empty user application template
 *
 * Bare minimum empty user application template
 *
 * \par Content
 *
 * -# Include the ASF header files (through asf.h)
 * -# "Insert system clock initialization code here" comment
 * -# Minimal main function that starts with a call to board_init()
 * -# "Insert application code here" comment
 *
 */

/*
 * Include header files for all drivers that have been imported from
 * Atmel Software Framework (ASF).
 */
/*
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */
#include <asf.h>
#define PA19 (1<<19)
#define PA20 (1<<20)
#define PC20 (1<<20)
#define PB3 (1<<14)

int main (void)
{
	/* Insert system clock initialization code here (sysclk_init()). */
	sysclk_init();
	board_init();

	/* Insert application code here, after the board has been initialized. */



		PIOA->PIO_PER |= (PA19 | PA20); //chama o registrador certo e escreve o bit 1 deslocando o 1 19 posições para o ponto certo do bus
		PIOC->PIO_PER |= (PC20);
	//pode ser feito PIOA->PIO_PER = (1<<19); | (1<<20) realizando uma operação ou resultando em 001100000000000
		PIOA->PIO_OER |= (PA19 | PA20);
		PIOC->PIO_OER |= (PC20);
		PIOA->PIO_SODR |= PA20; //acende o LED 20
		PIOA->PIO_SODR |= PA19; //apaga o LED 19
		PIOC->PIO_CODR |= PC20; //é um mosfet, inverte o comando

		PIOB->PIO_PER |= (PB3);
		PIOB->PIO_ODR |= (PB3);

	/*while(1){
	 
		PIOA->PIO_CODR |= PA20; //acende o LED 20
		PIOA->PIO_SODR |= PA19; //apaga o LED 19
		PIOC->PIO_CODR |= PC20;
		delay_s(1);
		PIOC->PIO_CODR |= PC20;
		PIOA->PIO_CODR |= PA19;
		PIOA->PIO_SODR |= PA20; //Apaga o LED 20
		delay_s(1);
		PIOA->PIO_SODR |= PA20; //acende o LED 20
		PIOA->PIO_SODR |= PA19; //apaga o LED 19
		PIOC->PIO_SODR |= PC20;
		
		delay_s(1);
	} */

	while (1)
	{

	if (((PIOB->PIO_PDSR & PB3) == PB3 ))
	{
		PIOA->PIO_CODR |= PA20; //acende o LED 20
		PIOA->PIO_SODR |= PA19; //apaga o LED 19
		PIOC->PIO_CODR |= PC20;
		delay_ms(100);
		PIOC->PIO_CODR |= PC20;
		PIOA->PIO_CODR |= PA19;
		PIOA->PIO_SODR |= PA20; //Apaga o LED 20
		delay_ms(100);
		PIOA->PIO_SODR |= PA20; //acende o LED 20
		PIOA->PIO_SODR |= PA19; //apaga o LED 19
		PIOC->PIO_SODR |= PC20;
		} else {
		PIOA->PIO_SODR |= PA20;
		PIOA->PIO_SODR |= PA19;
		PIOC->PIO_SODR |= PC20;

	}
	}
	
	

}
