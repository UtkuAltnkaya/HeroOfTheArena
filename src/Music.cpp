#include "HOTA/Music.hpp"
#include <SFML/Audio.hpp>
#include <iostream>
Musics::Musics()
{
    init_var();
}

Musics::Musics(std::string path)
{
    this->path = "music/" + path;
    init_var();
}
Musics::~Musics()
{
    delete this->playingMusic;
}

void Musics::init_var()
{
    this->init_musics();
}

void Musics::init_musics()
{
    this->playingMusic = new sf::Music;
    this->playingMusic->openFromFile(path);
}
void Musics::set_music()
{
    playingMusic->setLoop(true);
    playingMusic->setVolume(5);
}

void Musics::play()
{
    playingMusic->play();
}
void Musics::stopMusic()
{
    this->playingMusic->stop();
}
