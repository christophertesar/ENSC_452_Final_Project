#include "input.h"
#include <string.h>

#define MENU_OPTION_NAME_SIZE 	20
#define STRING_IS_EQUAL 		0
#define PLAY_MENU_TITLE 		"Play"
#define SETTINGS_MENU_TITLE 	"Settings"
#define HISCORE_MENU_TITLE 		"Hi-Score"

struct menu_options{
	char option_name[MENU_OPTION_NAME_SIZE];
	struct menu_options* next;
	struct menu_options* prev;
};


struct menu_options* generate_menu_options();
struct menu_options* generate_play_menu_options();
struct menu_options* generate_options_menu();
void main_menu();
