#pragma once
#include <SFML/Audio.hpp>
#include <string>



class Sound {
public:
    Sound();
    ~Sound();
    void Play(std::string filename);
private:
    sf::SoundBuffer buffer;
    sf::Sound sound;
};


