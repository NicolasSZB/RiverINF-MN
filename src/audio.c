#include "audio.h"
#include <stdio.h>

static Sound sndShoot;
static Sound sndExplosion;
static Sound sndFuel;

static Music bgMusic;

void initAudio(void){
    InitAudioDevice();

    if(IsAudioDeviceReady()){
        sndShoot = LoadSound("sounds/shoot.wav");
        sndExplosion = LoadSound("sounds/explosion.wav");
        sndFuel = LoadSound("sounds/fuel.wav");

        bgMusic = LoadMusicStream("sounds/soundtrack.mp3");
        bgMusic.looping = true;

        SetMusicVolume(bgMusic, 0.05f);

        SetSoundVolume(sndShoot, 0.5f);
        SetSoundVolume(sndExplosion, 0.6f);
        SetSoundVolume(sndFuel, 0.5f);
    } else
        printf("Erro ao iniciar dispositivo de audio!");
}

void closeAudio(void){
    UnloadSound(sndShoot);
    UnloadSound(sndExplosion);
    UnloadSound(sndFuel);

    UnloadMusicStream(bgMusic);

    CloseAudioDevice();
}

void playMusic(void){
    if(IsAudioDeviceReady())
        PlayMusicStream(bgMusic);
}

void updateMusic(void){
    if(IsAudioDeviceReady())
        UpdateMusicStream(bgMusic);
}

void playShootSound(void){
    if(IsAudioDeviceReady())
        PlaySound(sndShoot);
}

void playExplosionSound(void){
    if(IsAudioDeviceReady())
        PlaySound(sndExplosion);
}

void playFuelSound(void){
    if(IsAudioDeviceReady())
        PlaySound(sndFuel);
}
