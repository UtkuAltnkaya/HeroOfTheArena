#ifndef GROUND_MONK_HPP
#define GROUND_MONK_HPP

#include "HOTA/Hero.hpp"
#include "HOTA/Animation.hpp"
#include <string>

class GroundMonk : public Hero
{
private:
    void init_var();
    void init_ani_stats();
    void init_stats();

public:
    GroundMonk();
    ~GroundMonk();
    void skill();
    void upgrade();
};

#endif