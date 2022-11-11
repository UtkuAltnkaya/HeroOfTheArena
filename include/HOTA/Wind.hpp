#ifndef WIND_HPP
#define WIND_HPP

#include "HOTA/Hero.hpp"
#include "HOTA/Animation.hpp"
#include <string>

class Wind : public Hero
{
private:
    void init_var();
    void init_ani();
    void init_ani_stats();
    void init_stats();

    /**
     * atk2 -> hit_entangle
     * atk3 -> shower_effect
     */

public:
    Wind();
    ~Wind();
    void skill();
    void upgrade();
    void update();
    void render(sf::RenderTarget &target);
    void move_character();
    void atk_character();
};

#endif