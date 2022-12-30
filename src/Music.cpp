#include "HOTA/Music.hpp"
#include <SFML/Audio.hpp>

Musics::Musics()
{
    this->init_musics();
}
float Musics::volume = 10; // Static music volume
Musics::Musics(std::string path)
{ // Getting music path from calling class
    this->path = "music/" + path;
    this->init_musics();
}
Musics::~Musics()
{
    delete this->playingMusic;
}

void Musics::init_musics()
{ // Initialize variables
    this->is_music_playing = false;
    this->playingMusic = new sf::Music;
    this->playingMusic->openFromFile(path);
    this->playingMusic->setLoop(true);
    this->playingMusic->setVolume(5);
}

void Musics::play()
{ // Start the music
    this->playingMusic->play();
    this->is_music_playing = true;
}
void Musics::stopMusic()
{ // Stop the music
    this->playingMusic->stop();
    this->is_music_playing = false;
}

void Musics::set_volume(float volume)
{ // Set volume of music with a static variable
    this->volume = volume;
    float temp = volume;
    this->playingMusic->setVolume(temp);
}

float Musics::get_volume()
{
    return this->volume;
}

bool Musics::get_is_music_playing()
{
    return this->is_music_playing;
}