#ifndef WATER_HPP
#define WATER_HPP

#include "HOTA/Hero.hpp"
#include "HOTA/Animation.hpp"
#include <string>

class Water : public Hero
{
private:
    void init_var();
    void init_ani_stats();
    void init_stats();

public:
    Water();
    ~Water();
    void skill();
    void upgrade();
};

#endif