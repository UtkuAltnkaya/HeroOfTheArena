#ifndef BLADE_KEEPER_HPP
#define BLADE_KEEPER_HPP

#include "HOTA/Hero.hpp"
#include "HOTA/Animation.hpp"
#include <string>

class BladeKeeper : public Hero
{
private:
    void init_var();
    void init_ani_stats();
    void init_stats();

public:
    BladeKeeper();
    ~BladeKeeper();
};

#endif