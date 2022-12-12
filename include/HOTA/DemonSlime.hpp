#ifndef DEMON_SLIME_HPP
#define DEMON_SLIME_HPP

#include "HOTA/Boss.hpp"
#include "HOTA/Animation.hpp"
#include <string>

class DemonSlime : public Boss
{
private:
    void init_var();
    void init_ani_stats();
    void init_stats();

public:
    DemonSlime();
    ~DemonSlime();
    void skill();
    void upgrade();
};

#endif
