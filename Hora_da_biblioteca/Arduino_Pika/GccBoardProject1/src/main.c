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

#define CONF_UART              UART0 //inicialização do UART
#define CONF_UART_BAUDRATE     9600
#define CONF_UART_CHAR_LENGTH  US_MR_CHRL_8_BIT
#define CONF_UART_PARITY       US_MR_PAR_NO
#define CONF_UART_STOP_BITS    US_MR_NBSTOP_1_BIT

#define PA19 (1<<19)
#define PA20 (1<<20)

void inicializacao_UART (){
	
	static usart_serial_options_t usart_options = {
		.baudrate = CONF_UART_BAUDRATE,
		.charlength = CONF_UART_CHAR_LENGTH,
		.paritytype = CONF_UART_PARITY,
		.stopbits = CONF_UART_STOP_BITS
	};
	usart_serial_init(CONF_UART, &usart_options);
	stdio_serial_init((Usart *)CONF_UART, &usart_options); //define a USART como dispositivo de entrada/saída padrão do sistema, estamos adicionando mais uma camada de abstração
}

int main (void)
{
	(sysclk_init());

	board_init();
	PIOA->PIO_PER |= (PA19 | PA20);
	PIOA->PIO_OER |= (PA19 | PA20);
	inicializacao_UART ();
	//puts pula linha
	puts(" Sistema Iniciado \r");
	puts("********************///////MENU///////***********************\r");
	puts(" A: Verde ON; B: Azul ON; C: Verde OFF; D: Azul OFF m: Ajuda\r");
	
	while(1) {
		int key = getchar();
		switch (key) {
			case 'a':
				puts("LED Verde Ligado!\r");
				PIOA->PIO_CODR |= PA20; //acende o LED 20
				//ioport_toggle_pin_level()
			break;
				
			case 'b':
				PIOA->PIO_CODR |= PA19; //acende o LED 20
				puts("LED Azul Ligado!\r");
			break;
				
			case 'c':	
				PIOA->PIO_SODR |= PA20;
				puts("LED Verde desligado!\r");
			break;

			case 'd':
				PIOA->PIO_SODR |= PA19;
				puts("LED Azul desligado!\r");
			break;
			
			case 'm':
				puts("********************///////MENU///////***********************\r");
				puts(" A: Verde ON; B: Azul ON; C: Verde OFF; D: Azul OFF m: Ajuda\r");	
			break;	
		}
	}
	
}
