#include "main_menu.h"

void play_game_menu();
void hiscore();
void options();
void play_game(char*);
void gameplay(char*);
void game_over();
void increase_game_volume();
void decrease_game_volume();

/* ---------------------------------------------------------------------------- *
 * 									menu()										*
 * ---------------------------------------------------------------------------- *
 Method to display the main menu and provide functionality using the main menu.
 * ---------------------------------------------------------------------------- */
void main_menu(){
	// Display the main menu.
	struct menu_options* cursor = generate_menu_options();
	while(1){
		char key = 0;
		xil_printf("Main Menu displayed.\r\n");
		while(key != ENTER){
			// If the user does up/down arrow, update the screen. If enter, change the game state.
			// Wait for user input.
			key = wait_for_keyboard_input();
			// Using the user input, obtain what the user wants to do.
			if (key == 'w'){
				//Generate appropriate screen, move cursor up one
				cursor = cursor->next;
				xil_printf("Cursor at: %s\r\n", cursor->option_name);
			}
			if (key == 's'){
				//Change state
				cursor = cursor->prev;
				xil_printf("Cursor at: %s\r\n", cursor->option_name);
			}
			if (key == ENTER){ //Enter key is pressed
				xil_printf("Cursor at: %s\r\n", cursor->option_name);
			}
		}
		// User can change the game state to: settings, start game, high scores.
		if (strcmp(cursor->option_name, PLAY_MENU_TITLE) == STRING_IS_EQUAL){
			play_game_menu();
		}
		else if (strcmp(cursor->option_name, SETTINGS_MENU_TITLE) == STRING_IS_EQUAL){
			options();
		}
		else if (strcmp(cursor->option_name, HISCORE_MENU_TITLE) == STRING_IS_EQUAL){
			hiscore();
		}
	}
}

struct menu_options* generate_menu_options(){
	struct menu_options* play = (struct menu_options*) malloc(sizeof(struct menu_options));
	struct menu_options* settings = (struct menu_options*) malloc(sizeof(struct menu_options));
	struct menu_options* hiscore = (struct menu_options*) malloc(sizeof(struct menu_options));

	strcpy(play->option_name, PLAY_MENU_TITLE);
	strcpy(settings->option_name, SETTINGS_MENU_TITLE);
	strcpy(hiscore->option_name, HISCORE_MENU_TITLE);

	play->next = settings;
	settings->next = hiscore;
	hiscore->next = play;

	play->prev = hiscore;
	settings->prev = play;
	hiscore->prev = settings;

	return play;
}

void delete_menu_options(struct menu_options* menu_option){
	//Function might be a lil sus
	for(int i = 0; i < 3; i++){
		struct menu_options* temp = menu_option->next;
		free(menu_option);
		menu_option = temp;
	}
	return;
}

struct menu_options* generate_play_menu_options(){
	struct menu_options* level_1= (struct menu_options*) malloc(sizeof(struct menu_options));
	struct menu_options* level_2 = (struct menu_options*) malloc(sizeof(struct menu_options));
	struct menu_options* level_3 = (struct menu_options*) malloc(sizeof(struct menu_options));

	strcpy(level_1->option_name, "level_1");
	strcpy(level_2->option_name, "level_2");
	strcpy(level_3->option_name, "level_3");

	level_1->next = level_2;
	level_2->next = level_3;
	level_3->next = level_1;

	level_1->prev = level_3;
	level_2->prev = level_1;
	level_3->prev = level_2;

	return level_1;
}

struct menu_options* generate_settings_menu_options(){
	struct menu_options* increase_volume = (struct menu_options*) malloc(sizeof(struct menu_options));
	struct menu_options* decrease_volume = (struct menu_options*) malloc(sizeof(struct menu_options));
	struct menu_options* exit = (struct menu_options*) malloc(sizeof(struct menu_options));

	strcpy(increase_volume->option_name, "increase_volume");
	strcpy(decrease_volume->option_name, "decrease_volume");
	strcpy(exit->option_name, "exit");

	increase_volume->next = decrease_volume;
	decrease_volume->next = exit;
	exit->next = increase_volume;

	increase_volume->prev = exit;
	decrease_volume->prev = increase_volume;
	exit->prev = decrease_volume;

	return increase_volume;
}

void play_game_menu(){
	struct menu_options* cursor = generate_play_menu_options();
	char key = 0;
	xil_printf("Play game menu displayed.\r\n");
	while(key != ENTER){
		// If the user does up/down arrow, update the screen. If enter, change the game state.
		// Wait for user input.
		key = wait_for_keyboard_input();
		// Using the user input, obtain what the user wants to do.
		if (key == 'w'){
			//Generate appropriate screen, move cursor up one
			cursor = cursor->prev;
			xil_printf("Cursor at: %s\r\n", cursor->option_name);
		}
		if (key == 's'){
			//Change state
			cursor = cursor->next;
			xil_printf("Cursor at: %s\r\n", cursor->option_name);
		}
		if (key == ENTER){ //Enter key is pressed
			xil_printf("Cursor at: %s\r\n", cursor->option_name);
		}
	}
	play_game(cursor->option_name);
}


void hiscore(){
	xil_printf("Hi-Score menu displayed. Press Enter to leave.\r\n");
	char key = 0;
	while(key != ENTER){
		// If the user does up/down arrow, update the screen. If enter, change the game state.
		// Wait for user input.
		key = wait_for_keyboard_input();
	}
}

void options(){
	xil_printf("Options menu displayed.\r\n");
	struct menu_options* cursor = generate_settings_menu_options();
	while(1){
		char key = 0;
		while(key != ENTER){
			// If the user does up/down arrow, update the screen. If enter, change the game state.
			// Wait for user input.
			key = wait_for_keyboard_input();
			// Using the user input, obtain what the user wants to do.
			if (key == 'w'){
				//Generate appropriate screen, move cursor up one
				cursor = cursor->prev;
				xil_printf("Cursor at: %s\r\n", cursor->option_name);
			}
			if (key == 's'){
				//Change state
				cursor = cursor->next;
				xil_printf("Cursor at: %s\r\n", cursor->option_name);
			}
			if (key == ENTER){ //Enter key is pressed
				xil_printf("Cursor at: %s\r\n", cursor->option_name);
			}
		}
		if (strcmp(cursor->option_name, "increase_volume") == STRING_IS_EQUAL){
			increase_game_volume();
		}
		else if (strcmp(cursor->option_name, "decrease_volume") == STRING_IS_EQUAL){
			decrease_game_volume();
		}
		else if (strcmp(cursor->option_name, "exit") == STRING_IS_EQUAL){
			break;
		}
	}
}

void play_game(char* level_name){
	gameplay(level_name);
	game_over();
}

void gameplay(char* level_name){
	xil_printf("Playing level: %s\r\n", level_name);
}

void game_over(){
	xil_printf("Level over. Displaying score.\r\n");
}

void increase_game_volume(){
	xil_printf("Increasing game volume.\r\n");
}

void decrease_game_volume(){
	xil_printf("Decreasing game volume.\r\n");
}



