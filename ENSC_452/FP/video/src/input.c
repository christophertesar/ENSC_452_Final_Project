#include "input.h"

char wait_for_keyboard_input(){
	while(!XUartPs_IsReceiveData(XPAR_PS7_UART_1_BASEADDR)){
	}
	return XUartPs_ReadReg(XPAR_PS7_UART_1_BASEADDR, XUARTPS_FIFO_OFFSET);
}
