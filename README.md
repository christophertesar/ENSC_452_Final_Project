## 1. Introduction
Guitar Hero Clone is a tribute to the popular rhythm game series. This project aims to recreate the experience of playing Guitar Hero by simulating guitar playing using a keyboard and listening to music while hitting notes in sync with the song. The game rewards players with points for accurately hitting notes and offers features such as score tracking, level selection, and pause functionality.

**Initial Goals:**
- Implement 4 types of falling notes.
- Display current score and high score.
- Enable pause functionality.
- Synchronize audio with falling notes.
- Utilize 2 processor cores and a custom hardware clock.
- Achieve video display at 1280 x 1024 resolution with a minimum of 60 fps.
- Ensure audio playback at 48 kHz.

## 2. Background
The project consists of two main components: audio and video. We utilize hardware blocks for VGA output and audio output via the Zedboard's audio jack. Tempo, measured in beats per minute (BPM), plays a crucial role in note generation, determined either by online sources or a metronome.

## 3. User Manual

### 3.1 Main Menu
- Navigate using "W" and "S" keys.
- Select options with the Enter key.

### 3.2 Settings Menu
- Adjust volume or return to the main menu.
- Use "W" and "S" keys to navigate.
- Select options with Enter.

### 3.3 Highscore Menu
- Displays top scores for each song.
- Scores update if beaten.
- Exit with any key.

### 3.4 Song Selection
- Choose from three levels.
- Navigate with "W" and "S" keys.
- Start gameplay with Enter.

### 3.5 Gameplay

#### 3.5.1 Core Gameplay
- Hit corresponding keys (A, S, D, F) as notes fall.
- Well-timed hits increase score and multiplier.
- Missed hits reset multiplier.

#### 3.5.2 Ending the Game
- Game ends if too many notes are missed or song finishes.
- Poor performance indicated by distorted sound.
- Game ends when poor performance points reach 13.

#### 3.5.3 Pausing the Game
- Press "P" to pause.
- Resume with countdown from 3 to 1.
- Brief freeze for 1.5 seconds.
