#ifndef Music_HPP
#define Music_HPP

#include <SFML/Audio.hpp>
#include <string>
#include <vector>
class Music
{
private:
    std::string path;
    sf::Music *playingMusic;
    static float volume;
    void init_music();
    bool is_music_playing;

public:
    Music();
    Music(std::string);
    ~Music();
    void stop_music();
    void play();
    void set_volume(float);
    float get_volume();
    bool get_is_music_playing();
};

#endif
