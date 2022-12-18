#ifndef MUSICS_HPP
#define MUSICS_HPP

#include <SFML/Audio.hpp>
#include <string>
#include <vector>
class Musics
{
private:
    std::string path;
    sf::Music *playingMusic;

    void init_var();
    void init_musics();

public:
    Musics();
    Musics(std::string);
    ~Musics();
    void stopMusic();
    void play();

    void set_music();
};

#endif
