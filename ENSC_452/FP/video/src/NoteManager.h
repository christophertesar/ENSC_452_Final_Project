#include <stdio.h>
#include <queue>
#include "Note.h"

#ifndef NOTEMANAGER_H
#define NOTEMANAGER_H

class NoteManager{

public:
	NoteManager();
	void add_note_to_lane(int); //int specifies which lane.
	bool scan_lanes(); //checks the front of queue of all lanes. If a note pos is near the line, return true. Removes note from queue.
	void draw_notes(); //Goes through the entire queue and draws the notes.

private:
	std::queue<Note> lane_a;
	std::queue<Note> lane_s;
	std::queue<Note> lane_d;
	std::queue<Note> lane_f;
};

#endif