#include <stdio.h>
#include <xil_io.h>
#include <sleep.h>
#include "xiicps.h"
#include <xil_printf.h>
#include <xparameters.h>
#include "xgpio.h"
#include "xuartps.h"
#include "stdlib.h"

#define ENTER 0x0D
#define NUMER_OF_MENUS 3

// Waits for user to input character into the keyboard.
char wait_for_keyboard_input();
