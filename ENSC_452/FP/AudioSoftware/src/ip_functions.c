/*
 * ip_functions.c
 *
 * Contains all functions which pertain to setup and use of IP periperals.
 */

#include "adventures_with_ip.h"
#include <math.h>


/* ---------------------------------------------------------------------------- *
 * 								audio_stream()									*
 * ---------------------------------------------------------------------------- *
 * This function performs audio loopback streaming by sampling the input audio
 * from the codec and then immediately passing the sample to the output of the
 * codec.
 *
 * The main menu can be accessed by entering 'q' on the keyboard.
 * ---------------------------------------------------------------------------- */
void audio_stream(){
	u32  in_left, in_right;

	while (!XUartPs_IsReceiveData(UART_BASEADDR)){
		// Read audio input from codec
		in_left = Xil_In32(I2S_DATA_RX_L_REG);
		in_right = Xil_In32(I2S_DATA_RX_R_REG);
		// Write audio output to codec
		Xil_Out32(I2S_DATA_TX_L_REG, in_left);
		Xil_Out32(I2S_DATA_TX_R_REG, in_right);
	}

	/* If input from the terminal is 'q', then return to menu.
	 * Else, continue streaming. */
	if(XUartPs_ReadReg(UART_BASEADDR, XUARTPS_FIFO_OFFSET) == 'q') menu();
	else audio_stream();
} // audio_stream()


void play_stream(u32* audio_storage_left, u32* audio_storage_right, int ptr_location, int sleep_length){
	for(int i = 0; i < ptr_location; i++){
		usleep(sleep_length);
		Xil_Out32(I2S_DATA_TX_L_REG, audio_storage_left[i]);
		Xil_Out32(I2S_DATA_TX_R_REG, audio_storage_right[i]);
	}
	free(audio_storage_left);
	free(audio_storage_right);
	menu();
}


void record_stream(u32* audio_storage_left, u32* audio_storage_right, int max_size, int ptr_location){
	int sample_period = 20;
	xil_printf("Press 'f' for fast and 's' for slow playback. Any other key for normal speed.\r\n");
	while(!XUartPs_IsReceiveData(UART_BASEADDR)){

	}
	char key = XUartPs_ReadReg(UART_BASEADDR, XUARTPS_FIFO_OFFSET);
	if (key == 'f'){
		sample_period = 35;
	}
	else if(key == 's'){
		sample_period = 15;
	}
	else{
		sample_period = 20;
	}
	xil_printf("Recording... Press any key to stop recording.\r\n");

	while(!XUartPs_IsReceiveData(UART_BASEADDR)){
			// Write audio input to buffer
			audio_storage_left[ptr_location] = Xil_In32(I2S_DATA_RX_L_REG);
			audio_storage_right[ptr_location] = Xil_In32(I2S_DATA_RX_R_REG);
			usleep(sample_period);
			ptr_location++;
			if (ptr_location > max_size){
				break;
			}
	}
	key = XUartPs_ReadReg(UART_BASEADDR, XUARTPS_FIFO_OFFSET); //Clears buffer
	xil_printf("Press 'p' to play audio, 'q' to return to main menu\r\n");
	while(1){
		while(!XUartPs_IsReceiveData(UART_BASEADDR)){

		}
		char key = XUartPs_ReadReg(UART_BASEADDR, XUARTPS_FIFO_OFFSET);
		if (key == 'p'){
			xil_printf("Playing Audio\r\n");
			play_stream(audio_storage_left, audio_storage_right, ptr_location, 20);
		}
		if(key == 'q'){
			free(audio_storage_left);
			free(audio_storage_right);
			menu();
		}
	}
}

void tone_stream(){
	int t = 0;
	int f = 1000;
	while(1){
		while (!XUartPs_IsReceiveData(UART_BASEADDR)){
			// Read audio input from codec
			t %= 48000;
			float temp = (float) t / 48000.0;
			float sinf_argument = 2 * M_PI * f * temp;
			u32 val = (u32) round(40000.0 * (sinf(sinf_argument) + 1.0));
			usleep(20);
			Xil_Out32(I2S_DATA_TX_L_REG, val);
			Xil_Out32(I2S_DATA_TX_R_REG, val);
			t++;
		}
		char key = XUartPs_ReadReg(UART_BASEADDR, XUARTPS_FIFO_OFFSET);
		if (key == 'w'){
			f += 100;
			xil_printf("Increasing frequency to %i\r\n", f);
		}
		if (key == 's'){
			f = (f <= 0) ? 0 : f-100;
			xil_printf("Decreasing frequency to %i\r\n", f);
		}
		if(key == 'q') menu();
	}
	menu();
}


/* ---------------------------------------------------------------------------- *
 * 								gpio_initi()									*
 * ---------------------------------------------------------------------------- *
 * Initialises the GPIO driver for the push buttons and switches.
 * ---------------------------------------------------------------------------- */
unsigned char gpio_init()
{
	int Status;

	Status = XGpio_Initialize(&Gpio, BUTTON_SWITCH_ID);
	if(Status != XST_SUCCESS) return XST_FAILURE;

	XGpio_SetDataDirection(&Gpio, SWITCH_CHANNEL, 0xFF);
	XGpio_SetDataDirection(&Gpio, BUTTON_CHANNEL, 0xFF);

	return XST_SUCCESS;
}

void menu(){};

/* ---------------------------------------------------------------------------- *
 * 								nco_initi()									*
 * ---------------------------------------------------------------------------- *
 * Initialises the NCO driver by looking up the configuration in the config
 * table and then initialising it.
 * ---------------------------------------------------------------------------- */
//void nco_init(void *InstancePtr){
//	XNco_Config *cfgPtr;
//	int status;
//
//	/* Initialise the NCO driver so that it's ready to use */
//
//	// Look up the configuration in the config table
//	cfgPtr = XNco_LookupConfig(NCO_ID);
//	if (!cfgPtr) {
//		print("ERROR: Lookup of NCO configuration failed.\n\r");
//	}
//
//	// Initialise the NCO driver configuration
//	status = XNco_CfgInitialize(InstancePtr, cfgPtr);
//	if (status != XST_SUCCESS) {
//		print("ERROR: Could not initialise NCO.\n\r");
//	}
//}
