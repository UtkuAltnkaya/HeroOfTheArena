#include "HOTA/Music.hpp"
#include <SFML/Audio.hpp>

Music::Music()
{
    this->init_music();
}
float Music::volume = 10; // Static music volume
Music::Music(std::string path)
{ // Getting music path from calling class
    this->path = "music/" + path;
    this->init_music();
}
Music::~Music()
{
    delete this->playingMusic;
}

void Music::init_music()
{ // Initialize variables
    this->is_music_playing = false;
    this->playingMusic = new sf::Music;
    this->playingMusic->openFromFile(path);
    this->playingMusic->setLoop(true);
    this->playingMusic->setVolume(5);
}

void Music::play()
{ // Start the music
    this->playingMusic->play();
    this->is_music_playing = true;
}
void Music::stop_music()
{ // Stop the music
    this->playingMusic->stop();
    this->is_music_playing = false;
}

void Music::set_volume(float volume)
{ // Set volume of music with a static variable
    this->volume = volume;
    float temp = volume;
    this->playingMusic->setVolume(temp);
}

float Music::get_volume()
{
    return this->volume;
}

bool Music::get_is_music_playing()
{
    return this->is_music_playing;
}