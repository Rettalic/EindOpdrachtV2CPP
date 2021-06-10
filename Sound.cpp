#include "Sound.h"

Sound::Sound() {

}

Sound::~Sound() {

}

void Sound::Play(std::string filename) {
    buffer.loadFromFile("../Sounds/" + filename);
    sound.setBuffer(buffer);
    sound.play();
}