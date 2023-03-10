/*
 * adventures_with_ip.c
 *
 * Main source file. Contains main() and menu() functions.
 */
#include "adventures_with_ip.h"
#include "main_menu.h"

#define sev() __asm("sev")
#define ARM1_STARTADR 0xFFFFFFF0
#define ARM1_BASEADDR 0x10080000
#define COMM_VAL (*(volatile unsigned long *)(0xFFFF0000))

/* ---------------------------------------------------------------------------- *
 * 									main()										*
 * ---------------------------------------------------------------------------- *
 * Runs all initial setup functions to initialise the audio codec and IP
 * peripherals, before calling the interactive menu system.
 * ---------------------------------------------------------------------------- */
int main(void)
{
	xil_printf("Entering Main\r\n");
	//Configure the IIC data structure
	IicConfig(XPAR_XIICPS_0_DEVICE_ID);

	//Configure the Audio Codec's PLL
	AudioPllConfig();

	//Configure the Line in and Line out ports.
	//Call LineInLineOutConfig() for a configuration that
	//enables the HP jack too.
	AudioConfigureJacks();
	xil_printf("ADAU1761 configured\n\r");
	gpio_init();
	xil_printf("GPIO peripheral configured\r\n");

	COMM_VAL = 0;
	//Disable cache on OCM
	// S=b1 TEX=b100 AP=b11, Domain=b1111, C=b0, B=b0
	Xil_SetTlbAttributes(0xFFFF0000, 0x14de2);

	xil_printf("ARM0: writing startaddress for ARM1\n\r");
	Xil_Out32(ARM1_STARTADR, ARM1_BASEADDR);
	dmb(); //waits until write has finished

	//Wake up core 1
	sev();
	xil_printf("Woke up ARM Core 1\r\n");


//	while(1){
//		xil_printf("Hello World - ARM0\n\r");
//		sleep(1);
//		COMM_VAL = 1;
//		while(COMM_VAL == 1){
//		}
//	}
	/* Display interactive menu interface via terminal */
	main_menu();
    return 0;
}
