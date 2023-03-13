//Empty C++ Application
#include <stdio.h>
#include "xil_types.h"
#include "xtmrctr.h"
#include "xparameters.h"

#include "xil_cache.h"
#include "xil_io.h"
#include "xil_exception.h"
#include "xscugic.h"
#include "xil_mmu.h"
#include "sleep.h"
#include <cstdlib>

#include "xuartps.h"
#include <string>

#include "main_menu.h"

#define UART_BASEADDR XPAR_PS7_UART_1_BASEADDR
#define COMM_VAL (*(volatile unsigned long *)(0xFFFF0000))

volatile bool TIMER_INTR_FLG;
XScuGic InterruptController; /* Instance of the Interrupt Controller */
static XScuGic_Config *GicConfig;/* The configuration parameters of thecontroller */
int NUM_BYTES_BUFFER = 5242880;

extern uint8_t nice_menu[];
extern int nice_menu_size;

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
int ScuGicInterrupt_Init(u16 DeviceId, XTmrCtr *TimerInstancePtr)
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

	/*Enable the interrupt for the device and then cause (simulate) an interrupt so the handlers will be called*/
	XScuGic_Enable(&InterruptController, 61);
	XScuGic_SetPriorityTriggerType(&InterruptController, 61, 0xa0, 3);
	int loop = 0;
	int * vga_pointer = (int *)0x00900000;

	Xil_SetTlbAttributes(0xFFFF0000,0x14de2);

	Game game(vga_pointer);
	/* Display interactive menu interface via terminal */

	game.main_menu();

	return 0;
}
