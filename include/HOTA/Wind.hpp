#ifndef WIND_HPP
#define WIND_HPP

#include "HOTA/Hero.hpp"
#include "HOTA/Animation.hpp"
#include <string>

class Wind : public Hero
{
private:
    void init_var();
    void init_ani_stats();
    void init_stats();

public:
    Wind();
    ~Wind();
    void skill();
    void upgrade();
};

#endif