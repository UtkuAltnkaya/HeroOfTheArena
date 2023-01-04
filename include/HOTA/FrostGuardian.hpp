#ifndef FROST_GUARDIAN_HPP
#define FROST_GUARDIAN_HPP

#include "HOTA/Boss.hpp"
#include "HOTA/Animation.hpp"
#include <string>

class FrostGuardian : public Boss
{
private:
    void init_var();
    void init_ani_stats();
    void init_stats();

public:
    FrostGuardian();
    ~FrostGuardian();
};

#endif
