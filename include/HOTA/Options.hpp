#ifndef OPTIONS_HPP
#define OPTIONS_HPP

#include <SFML/Graphics.hpp>
#include "HOTA/Music.hpp"
class Options
{

private:
    bool is_open;
    int selected_index;
    sf::RectangleShape boxes;
    sf::Text sfx;

    void init_var(sf::Font &font);
    void move_left();
    void move_right();

public:
    Options(sf::Font &font);
    ~Options();

    void move_left_right(sf::Event &, Music *&, bool &);
    void render(sf::RenderWindow &);
    bool get_is_open();
    void set_is_open(bool is_open);
};

#endif