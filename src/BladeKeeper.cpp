#include "HOTA/BladeKeeper.hpp"
#include <iostream>

BladeKeeper::BladeKeeper() : Hero{"image", 5000, 200, 500, 250, 0.1f}
{
    this->init_var();
}

BladeKeeper::~BladeKeeper()
{
}

void BladeKeeper::init_var()
{
    this->init_ani_stats();
    this->init_animations();
    this->init_stats();
}

void BladeKeeper::init_ani_stats()
{

    this->path += "/BladeKeeper";
    this->atk_one_num = 6;
    this->atk_two_num = 18;
    this->atk_sp_num = 11;
    this->death_num = 12;
    this->defend_num = 12;
    this->idle_num = 8;
    this->jump_num = 20;
    this->roll_num = 7;
    this->run_num = 8;
    this->take_dmg_num = 6;
    this->size = 3;
}

void BladeKeeper::init_stats()
{
    this->health -= 1800;
    this->damage += 100;
    this->mana += 200;
    this->defense -= 50;
    this->crit_chance += 0.25;
}

void BladeKeeper::skill()
{
    // TODO
}

void BladeKeeper::upgrade()
{
    // TODO
}
