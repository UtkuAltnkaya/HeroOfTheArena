#include "HOTA/GroundMonk.hpp"
#include <iostream>

GroundMonk::GroundMonk() : Hero{"image", 5000, 200, 500, 250, 0.1f}
{
    this->init_var();
}

GroundMonk::~GroundMonk()
{
}

void GroundMonk::init_var()
{
    this->init_ani_stats();
    this->init_animations();
    this->init_stats();
}

void GroundMonk::init_ani_stats()
{

    this->path += "/Ground Monk";
    this->atk_one_num = 6;
    this->atk_two_num = 12;
    this->atk_sp_num = 25;
    this->death_num = 18;
    this->defend_num = 13;
    this->idle_num = 6;
    this->jump_num = 6;
    this->roll_num = 6;
    this->run_num = 8;
    this->take_dmg_num = 6;
}

void GroundMonk::init_stats()
{
    this->health -= 1800;
    this->damage += 100;
    this->mana += 200;
    this->defense -= 50;
    this->crit_chance += 0.25;
}

void GroundMonk::skill()
{
    // TODO
}

void GroundMonk::upgrade()
{
    // TODO
}
