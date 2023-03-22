#include <stdio.h>

#ifndef AUDIOPROTOCOL_H
#define AUDIOPROTOCOL_H

/*
 * Protocol to send commands to ARM Core 1 to handle audio. Core 1 should have an instance of AudioControl(). Core 0 will be writing commands
 * to memory location SIGNAL_BASE, and core 1 will continuously be polling for new commands.
 *
 * ALWAYS SET THE COMMANDS FIRST BEFORE SETTING THE SIGNAL BIT!
 */

//Location in memory to look for signals.
#define SIGNAL_BASE 		0x10080000

#define SIGNAL 				0x00000001
#define START_SONG 			0x00000002
#define STOP_SONG  			0x00000004
#define INCREMENT_VOLUME 	0x00000008
#define DECREMENT_VOLUME 	0x00000010
#define RESTART_SONG		0x00000020
#define CHANGE_TO_SONG_1	0x00000040
#define CHANGE_TO_SONG_2	0x00000080
#define CHANGE_TO_SONG_3	0x00000100

#endif