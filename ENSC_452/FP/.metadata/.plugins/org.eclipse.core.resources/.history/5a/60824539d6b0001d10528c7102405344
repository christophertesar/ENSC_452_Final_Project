#include "input.h"
#include "AudioControl.h"
#include <string.h>

#if !defined(MAIN_MENU_H)
#define MAIN_MENU_H 1

#define MENU_OPTION_NAME_SIZE 	20
#define STRING_IS_EQUAL 		0
#define PLAY_MENU_TITLE 		"Play"
#define SETTINGS_MENU_TITLE 	"Settings"
#define HISCORE_MENU_TITLE 		"Hi-Score"

extern uint8_t americanfootball_left[];
extern int americanfootball_left_size;
extern uint8_t americanfootball_right[];
extern int americanfootball_right_size;

struct menu_options{
	char option_name[MENU_OPTION_NAME_SIZE];
	struct menu_options* next;
	struct menu_options* prev;
};

struct menu_options* generate_menu_options();
struct menu_options* generate_play_menu_options();
struct menu_options* generate_options_menu();


class Game{
public:
	Game(AudioControl*);
	void main_menu();
	struct menu_options* generate_menu_options();
	void delete_menu_options(struct menu_options*);
	struct menu_options* generate_play_menu_options();
	struct menu_options* generate_settings_menu_options();
	void play_game_menu();
	void hiscore();
	void options();
	void play_game(char* level_name);
	void gameplay(char* level_name);
	void game_over();
	void increase_game_volume();
	void decrease_game_volume();
private:
	AudioControl* audio_controller;
};



#endif
