#include "AudioControl.h"

AudioControl::AudioControl(){};

AudioControl::AudioControl(uint32_t max_index, const uint8_t* current_song_left_channel, const uint8_t* current_song_right_channel){
	volume = 1;
	index = 0;
	this->max_index = max_index;
	this->song_playing = true;
	this->current_song_left_channel = current_song_left_channel;
	this->current_song_right_channel = current_song_right_channel;
}

uint32_t AudioControl::getVolume(){
	return this->volume;
}

void AudioControl::incrementVolume(){
	if (volume < 5)
		volume++;
}

void AudioControl::decreaseVolume(){
	if (volume > 0)
		volume--;
}

void AudioControl::incrementIndex(){
	index++;
	index = index % max_index;
}

uint32_t AudioControl::getIndex(){
	return this->index;
}

void AudioControl::changeSong(const uint8_t* current_song_left_channel, const uint8_t* current_song_right_channel, uint32_t max_index){
	this->current_song_left_channel = current_song_left_channel;
	this->current_song_right_channel = current_song_right_channel;
	this->index = 0;
	this->max_index = max_index;
}

bool AudioControl::isSongPlaying(){
	return this->song_playing;
}

void AudioControl::startSong(){
	this->song_playing = true;
}

void AudioControl::stopSong(){
	this->song_playing = false;
}

void AudioControl::restartSong(){
	index = 0;
}

const uint8_t* AudioControl::getCurrentSongLeftChannel(){
	return this->current_song_left_channel;
}

const uint8_t* AudioControl::getCurrentSongRightChannel(){
	return this->current_song_right_channel;
}

