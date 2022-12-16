#ifndef MUSICS_HPP
#define MUSICS_HPP

#include <SFML/Audio.hpp>
#include <vector>
class Musics
{
private:
    bool menuOpen;
    bool charMenuOpen;
    bool gameOpen;
    sf::Music *playingMusic;
    std::vector<sf::Music *> musics;

    void init_var();
    void init_musics();

public:
    Musics();
    ~Musics();
    void stopMusic();
    void play();

    bool get_menuOpen();
    bool get_charMenuOpen();
    bool get_gameOpen();

    void set_menuOpen(bool open);
    void set_charMenuOpen(bool open);
    void set_gameOpen(bool open);
    void set_music();
};

#endif
