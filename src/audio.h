#ifndef AUDIO_H
#define AUDIO_H

#include "raylib.h"

void initAudio(void);

void closeAudio(void);

void playShootSound(void);
void playExplosionSound(void);
void playFuelSound(void);

void playMusic(void);
void updateMusic(void);

#endif // AUDIO_H
