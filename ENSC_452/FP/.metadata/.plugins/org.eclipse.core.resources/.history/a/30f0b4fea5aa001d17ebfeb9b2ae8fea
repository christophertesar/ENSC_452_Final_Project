
//Empty C++ Application
#include <stdio.h>
#include <sleep.h>
#include "xil_types.h"
#include "xtmrctr.h"
#include "xparameters.h"

#include "xil_io.h"
#include "xil_mmu.h"
#include "xil_exception.h"
#include "xpseudo_asm.h"
#include "xil_exception.h"
#include "xil_cache.h"
#include "xscugic.h"
#include <cstdlib>

#include "xuartps.h"
#include <string>
#define UART_BASEADDR XPAR_PS7_UART_1_BASEADDR
#define COMM_VAL (*(volatile unsigned long *)(0xFFFF0000))
extern u32 MMUTable;

volatile bool TIMER_INTR_FLG;
XScuGic InterruptController; /* Instance of the Interrupt Controller */
static XScuGic_Config *GicConfig;/* The configuration parameters of thecontroller */
int NUM_BYTES_BUFFER = 5242880;

void Timer_InterruptHandler(XTmrCtr *data, u8 TmrCtrNumber)
{
	XTmrCtr_Stop(data,TmrCtrNumber);
	XTmrCtr_Reset(data,TmrCtrNumber);
	//Update Stuff
	TIMER_INTR_FLG = true;
}

int SetUpInterruptSystem(XScuGic *XScuGicInstancePtr){
	Xil_ExceptionRegisterHandler(XIL_EXCEPTION_ID_INT,
	(Xil_ExceptionHandler) XScuGic_InterruptHandler,
	XScuGicInstancePtr);
	Xil_ExceptionEnable();
	return XST_SUCCESS;
}

/*Setup all interrupts of the system*/
int ScuGicInterrupt_Init(u16 DeviceId,XTmrCtr *TimerInstancePtr)
{
	int Status;
	GicConfig = XScuGic_LookupConfig(DeviceId);
	if (NULL == GicConfig) {
		return XST_FAILURE;
	}
	Status = XScuGic_CfgInitialize(&InterruptController, GicConfig,
	GicConfig->CpuBaseAddress);
	if (Status != XST_SUCCESS) {
		return XST_FAILURE;
	}
	Status = SetUpInterruptSystem(&InterruptController);
	if (Status != XST_SUCCESS) {
		return XST_FAILURE;
	}
	/*Connect a device driver handler that will be called when an interrupt for the device occurs, the device driver handler performs the specific interrupt processing for the device*/
	Status = XScuGic_Connect(&InterruptController,
	61,
	(Xil_ExceptionHandler)XTmrCtr_InterruptHandler,
	(void *)TimerInstancePtr);
	if (Status != XST_SUCCESS) {
		return XST_FAILURE;
	}

	return XST_SUCCESS;
}

// use wmset to write faster
// write twice to get rid of artifacting (the fuzzyness at the bottom)
void load_initial_colours(int* image_buffer_pointer, int hex_1, int hex_2, int hex_3, int hex_4, int hex_5){

	// update the random hex generation
	// update the for loop to be 5 seperate loops
	// add horizontal as a new menu option

	for(int i=0; i<256*1024; i++)
	{
		image_buffer_pointer[i] = hex_1;
	}

	for(int i=256*1024; i<256*2*1024; i++)
	{
		image_buffer_pointer[i] = hex_2;
	}

	for(int i=256*2*1024; i<256*3*1024; i++)
	{
		image_buffer_pointer[i] = hex_3;
	}

	for(int i=256*3*1024; i<256*4*1024; i++)
	{
		image_buffer_pointer[i] = hex_4;
	}

	for(int i=256*4*1024; i<256*5*1024; i++)
	{
		image_buffer_pointer[i] = hex_4 + 0x123456;
	}

//	for(int i=0; i<1280*1024; i++)
//	{
//		if (i%1280 >= 0 && i%1280 < 256)
//		{
//			image_buffer_pointer[i] = std::__cxx11::stoul(hex_1, nullptr, 16);
//		}
//
//		else if (i%1280 >= 256 && i%1280 < 512)
//		{
//			image_buffer_pointer[i] = std::__cxx11::stoul(hex_2, nullptr, 16);
//		}
//
//		else if (i%1280 >= 512 && i%1280 < 768)
//		{
//			image_buffer_pointer[i] = std::__cxx11::stoul(hex_3, nullptr, 16);
//		}
//
//		else if (i%1280 >= 768 && i%1280 < 1024)
//		{
//			image_buffer_pointer[i] = std::__cxx11::stoul(hex_4, nullptr, 16);
//		}
//
//		else if (i%1280 >= 1024 && i%1280 < 1280)
//		{
//			image_buffer_pointer[i] = std::__cxx11::stoul(hex_5, nullptr, 16);
//		}
//	}
}

void menu(int* image_buffer_pointer){
	u8 inp = 0x00;
	u32 CntrlRegister;

	int hex_int_1;
	int hex_int_2;
	int hex_int_3;
	int hex_int_4;
//	int hex_int_5;

	hex_int_1 = rand();
	hex_int_2 = rand();
	hex_int_3 = rand();
	hex_int_4 = rand();
//	hex_int_5 = rand();

	XUartPs_WriteReg(UART_BASEADDR, XUARTPS_CR_OFFSET,
				  ((CntrlRegister & ~XUARTPS_CR_EN_DIS_MASK) |
				   XUARTPS_CR_TX_EN | XUARTPS_CR_RX_EN));

	xil_printf("\r\n\r\n");
	xil_printf("Welcome to the ENSC 452 video demo!\r\n");
	xil_printf("Enter 's' to load a new random colour sequence\r\n");
	xil_printf("----------------------------------------\r\n");

	// Wait for input from UART via the terminal
	while (!XUartPs_IsReceiveData(UART_BASEADDR));
				inp = XUartPs_ReadReg(UART_BASEADDR, XUARTPS_FIFO_OFFSET);
	// Select function based on UART input
	switch(inp){
	case 's':
		xil_printf("Loading random colours\r\n");
		xil_printf("Press 'q' to return to the main menu\r\n");

		// run twice to fix artifacting
		load_initial_colours(image_buffer_pointer, hex_int_1, hex_int_2, hex_int_3, hex_int_4, hex_int_4);
		load_initial_colours(image_buffer_pointer, hex_int_1, hex_int_2, hex_int_3, hex_int_4, hex_int_4);
		break;
	default:
		menu(image_buffer_pointer);
		break;
	} // switch
} // menu()


int main()
{
	XTmrCtr TimerInstancePtr;
	int xStatus;
	//-----------Setup Timer Interrupt---------------------------------------

	xStatus = XTmrCtr_Initialize(&TimerInstancePtr,XPAR_AXI_TIMER_0_DEVICE_ID);

	XTmrCtr_SetHandler(&TimerInstancePtr,
	(XTmrCtr_Handler)Timer_InterruptHandler,
	&TimerInstancePtr);

	//Reset Values
	XTmrCtr_SetResetValue(&TimerInstancePtr,
	0, //Change with generic value
	//0xFFF0BDC0);
	//0x23C34600);
	0xDC3CB9FF);
	//Interrupt Mode and Auto reload
	XTmrCtr_SetOptions(&TimerInstancePtr,
	XPAR_AXI_TIMER_0_DEVICE_ID,
	(XTC_INT_MODE_OPTION | XTC_AUTO_RELOAD_OPTION ));

	xStatus=ScuGicInterrupt_Init(XPAR_PS7_SCUGIC_0_DEVICE_ID,&TimerInstancePtr);

	Xil_SetTlbAttributes(0xFFFF0000,0x14de2);

	/*Enable the interrupt for the device and then cause (simulate) an interrupt so the handlers will be called*/
	XScuGic_Enable(&InterruptController, 61);
	XScuGic_SetPriorityTriggerType(&InterruptController, 61, 0xa0, 3);
	int loop = 0;
	int * image_buffer_pointer = (int *)0x00900000;
//	int * image1_pointer = (int *)0x018D2008;
//	int * image2_pointer = (int *)0x020BB00C;
//	int * image3_pointer = (int *)0x028A4010;
//	int * image4_pointer = (int *)0x0308D014;
//	int * image5_pointer = (int *)0x03876018;

	while(1){
		while(COMM_VAL == 0){
		};
		xil_printf("Hello World - ARM1\n\r");
		sleep(1);
		COMM_VAL = 0;
	}

	while(1) {
//		XTmrCtr_Start(&TimerInstancePtr,0);
//		while(TIMER_INTR_FLG == false){
//		}
//
//		TIMER_INTR_FLG = false;

		menu(image_buffer_pointer);

//		if(loop == 0){
//			memcpy(image_buffer_pointer, image1_pointer, NUM_BYTES_BUFFER);
//		}
//		else if(loop==1){
//			memcpy(image_buffer_pointer, image2_pointer, NUM_BYTES_BUFFER);
//		}
//		else if(loop==2){
//			memcpy(image_buffer_pointer, image3_pointer, NUM_BYTES_BUFFER);
//		}
//		else if(loop==3){
//			memcpy(image_buffer_pointer, image4_pointer, NUM_BYTES_BUFFER);
//		}
//		else if(loop==4){
//			memcpy(image_buffer_pointer, image5_pointer, NUM_BYTES_BUFFER);
//		}
//		loop++;
//		loop = loop % 5;
	}
	return 0;
}

