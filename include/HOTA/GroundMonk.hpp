#ifndef GROUND_MONK_HPP
#define GROUND_MONK_HPP

#include "HOTA/Hero.hpp"
#include "HOTA/Animation.hpp"
#include <string>

class GroundMonk : public Hero
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
    GroundMonk();
    ~GroundMonk();
    void skill();
    void upgrade();
    void update(sf::RenderWindow &window);
    void render(sf::RenderTarget &target);
    void move_character(sf::RenderWindow &window);
    void atk_character();
};

#endif