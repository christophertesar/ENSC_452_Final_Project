//Empty C++ Application
#include <stdio.h>
#include <string>
#include "xiicps.h"
#include <xil_printf.h>
#include "xil_types.h"
#include "xtmrctr.h"
#include "xparameters.h"
#include "xgpio.h"
#include "xuartps.h"
#include "stdlib.h"
#include "audio.h"
#include "xscutimer.h"

#include "xil_cache.h"
#include "xil_io.h"
#include "xil_exception.h"
#include "xscugic.h"
#include "xil_mmu.h"
#include "sleep.h"
#include <cstdlib>

#include "main_menu.h"
#include "AudioControl.h"

#define UART_BASEADDR XPAR_PS7_UART_1_BASEADDR
#define COMM_VAL (*(volatile unsigned long *)(0xFFFF0000))
#define sev() __asm("sev")
#define ARM1_STARTADR 0xFFFFFFF0
#define ARM1_BASEADDR 0x10080000

volatile bool TIMER_INTR_FLG;
XScuGic InterruptController; /* Instance of the Interrupt Controller */
static XScuGic_Config *GicConfig;/* The configuration parameters of thecontroller */
int NUM_BYTES_BUFFER = 5242880;

extern uint8_t nice_menu[];
extern int nice_menu_size;

//static void audio_timer_interrupt_handler(void*);
//
//static AudioControl audio_control = AudioControl(americanfootball_right_size/4, americanfootball_left, americanfootball_right);
//
void audio_timer_interrupt_handler(void *CallBackRef){
	xil_printf("hi");
}

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
	int Status;

	XScuTimer my_Timer;
	XScuTimer_Config *Timer_Config;

	// Declare two structs.  One for the General Interrupt
	// Controller (GIC) instance, and the other for config information
	XScuGic my_Gic;
	XScuGic_Config *Gic_Config;

	Gic_Config = XScuGic_LookupConfig(XPAR_PS7_SCUGIC_0_DEVICE_ID);

	// Initialise the GIC using the config information
	Status = XScuGic_CfgInitialize(&my_Gic, Gic_Config, Gic_Config->CpuBaseAddress);

	// Look up the the config information for the timer
	Timer_Config = XScuTimer_LookupConfig(XPAR_PS7_SCUTIMER_0_DEVICE_ID);

	// Initialise the timer using the config information
	Status = XScuTimer_CfgInitialize(&my_Timer, Timer_Config, Timer_Config->BaseAddr);

	Xil_ExceptionInit();

	Xil_ExceptionRegisterHandler(XIL_EXCEPTION_ID_IRQ_INT, (Xil_ExceptionHandler)XScuGic_InterruptHandler, &my_Gic);

	// Assign (connect) our interrupt handler for our Timer
	Status = XScuGic_Connect(&my_Gic, XPAR_SCUTIMER_INTR, (Xil_ExceptionHandler)audio_timer_interrupt_handler, (void *)&my_Timer);

	// Enable the interrupt *input* on the GIC for the timer's interrupt
	XScuGic_Enable(&my_Gic, XPAR_SCUTIMER_INTR);

	//XScuGic_SetPriorityTriggerType(&my_Gic, XPAR_SCUTIMER_INTR, 0x08, 3);

	// Enable the interrupt *output* in the timer.
	XScuTimer_EnableInterrupt(&my_Timer);

	Xil_ExceptionEnable();

	XScuTimer_LoadTimer(&my_Timer, 200000000);

	// Enable Auto reload mode on the timer.  When it expires, it re-loads
	// the original value automatically.  This means that the timing interval
	// is never skewed by the time taken for the interrupt handler to run
	XScuTimer_EnableAutoReload(&my_Timer);

	// Start the SCU timer running (it counts down)
	XScuTimer_Start(&my_Timer);

	int * vga_pointer = (int *)0x00900000;

	Xil_SetTlbAttributes(0xFFFF0000,0x14de2);

	Game game(vga_pointer);
	/* Display interactive menu interface via terminal */

	game.main_menu();

	return 0;
}
