#include "HOTA/Wind.hpp"
#include <iostream>

Wind::Wind() : Hero{"image", 5000, 200, 500, 250, 0.1f}
{
    this->init_var();
}

Wind::~Wind()
{
}

void Wind::init_var()
{
    this->init_ani_stats();
    this->init_animations();
    this->init_stats();
}

void Wind::init_ani_stats()
{
    this->path += "/Wind";
    this->atk_one_num = 8;
    this->atk_two_num = 18;
    this->atk_sp_num = 30;
    this->death_num = 19;
    this->defend_num = 8;
    this->idle_num = 8;
    this->jump_num = 6;
    this->roll_num = 6;
    this->run_num = 8;
    this->take_dmg_num = 6;
}

void Wind::init_stats()
{
    this->health -= 1800;
    this->damage += 100;
    this->mana += 200;
    this->defense -= 50;
    this->crit_chance += 0.25;
}

void Wind::skill()
{
    // TODO
}

void Wind::upgrade()
{
    // TODO
}
