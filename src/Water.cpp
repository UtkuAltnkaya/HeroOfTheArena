#include "HOTA/Water.hpp"
#include <iostream>

Water::Water() : Hero{"image", 5000, 200, 500, 250, 0.1f}
{
    this->init_var();
}

Water::~Water()
{
}

void Water::init_var()
{
    this->init_ani_stats();
    this->init_animations();
    this->init_stats();
}

void Water::init_ani_stats()
{

    this->path += "/Water";
    this->atk_one_num = 21;
    this->atk_two_num = 27;
    this->atk_sp_num = 32;
    this->death_num = 16;
    this->defend_num = 12;
    this->idle_num = 8;
    this->jump_num = 6;
    this->roll_num = 6; // TODO
    this->run_num = 8;
    this->take_dmg_num = 7;
}

void Water::init_stats()
{
    this->health -= 1800;
    this->damage += 100;
    this->mana += 200;
    this->defense -= 50;
    this->crit_chance += 0.25;
}

void Water::skill()
{
    // TODO
}

void Water::upgrade()
{
    // TODO
}
