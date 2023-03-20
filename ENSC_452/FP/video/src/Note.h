#include <stdio.h>

#ifndef NOTE_H
#define NOTE_H

class Note{

public:
	Note();
	uint32_t get_x_size();
	uint32_t get_y_size();
	uint32_t get_pos();

	void set_pos(uint32_t);
	void increment_pos();

private:
	uint32_t note_x_size;
	uint32_t note_y_size;
	uint32_t note_pos;
};

#endif
