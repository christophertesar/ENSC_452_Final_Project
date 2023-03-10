#include <stdio.h>

#ifndef AUDIOCONTROL_H
#define AUDIOCONTROL_H

class AudioControl{

public:
	AudioControl(uint32_t, const uint8_t*, const uint8_t*);
	AudioControl();
	void incrementVolume(void);
	void decreaseVolume(void);
	void incrementIndex(void);
	void changeSong(const uint8_t* current_song_left_channel, const uint8_t* current_song_right_channel, uint32_t max_index);
	void startSong(void);
	void stopSong(void);
	void restartSong(void);
	uint32_t getVolume();
	uint32_t getIndex();
	bool isSongPlaying();
	const uint8_t* getCurrentSongLeftChannel();
	const uint8_t* getCurrentSongRightChannel();

private:
	bool song_playing;
	uint32_t volume;
	uint32_t index;
	uint32_t max_index;
	const uint8_t* current_song_left_channel;
	const uint8_t* current_song_right_channel;
};

#endif
