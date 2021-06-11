#include "Sound.h"

Sound::Sound() { }

Sound::~Sound() { }

void Sound::Play(std::string filename) {
    buffer.loadFromFile("../textures/" + filename);
    sound.setBuffer(buffer); //zet een buffer zodat alles netjes wordt ingeladen voordat het gespeeld wordt.
    sound.play();
}