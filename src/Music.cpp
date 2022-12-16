#include "HOTA/Music.hpp"
#include <SFML/Audio.hpp>
#include <iostream>
Musics::Musics()
{
    init_var();
}

Musics::~Musics()
{
    delete this->playingMusic;
}

void Musics::init_var()
{

    this->menuOpen = true;
    this->charMenuOpen = true;
    this->gameOpen = true;
    this->init_musics();
    this->set_music();
}

void Musics::init_musics()
{
    sf::Music *tempMusic;
    tempMusic = new sf::Music;
    tempMusic->openFromFile("music/Battle Encounter.ogg");
    this->musics.push_back(tempMusic);
    sf::Music *tempMusic1;
    tempMusic1 = new sf::Music;
    tempMusic1->openFromFile("music/moonlight.ogg");
    this->musics.push_back(tempMusic1);
    sf::Music *tempMusic2;
    tempMusic2 = new sf::Music;
    tempMusic2->openFromFile("music/moonlight.ogg");
    this->musics.push_back(tempMusic2);
    /*
    this->musics.push_back([]() -> sf::Music *
                           {
        sf::Music *music;
        music = new sf::Music{};
        music->openFromFile("music/Battle Encounter.ogg");
        return new sf::Music; });
    this->musics.push_back([]() -> sf::Music *
                           {
        sf::Music *music;
        music = new sf::Music;
        music->openFromFile("music/moonlight.ogg");
        return music; });
    this->musics.push_back([]() -> sf::Music *
                           {
        sf::Music *music;
        music = new sf::Music;
        music->openFromFile("music/moonlight.ogg");
        return music; });
        */
}
void Musics::set_music()
{
    this->playingMusic = this->musics[charMenuOpen + menuOpen + gameOpen - 1];
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

// getter

bool Musics::get_menuOpen()
{
    return this->menuOpen;
}

bool Musics::get_charMenuOpen()
{
    return this->charMenuOpen;
}

bool Musics::get_gameOpen()
{
    return this->gameOpen;
}

// setters

void Musics::set_menuOpen(bool open)
{
    this->menuOpen = open;
}

void Musics::set_charMenuOpen(bool open)
{
    this->charMenuOpen = open;
}

void Musics::set_gameOpen(bool open)
{
    this->gameOpen = open;
}