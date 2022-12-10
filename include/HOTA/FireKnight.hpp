#ifndef FIRE_KNIGHT_HPP
#define FIRE_KNIGHT_HPP

#include "HOTA/Hero.hpp"
#include "HOTA/Animation.hpp"
#include <string>

class FireKnight : public Hero
{
private:
    void init_var();
    void init_ani_stats();
    void init_stats();

public:
    FireKnight();
    ~FireKnight();
    void skill();
    void upgrade();
};

#endif
