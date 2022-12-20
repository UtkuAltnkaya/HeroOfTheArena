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
    static float volume;
    void init_musics();
    bool is_music_playing;

public:
    Musics();
    Musics(std::string);
    ~Musics();
    void stopMusic();
    void play();
    void set_volume(float);
    float get_volume();
    bool get_is_music_playing();
};

#endif
