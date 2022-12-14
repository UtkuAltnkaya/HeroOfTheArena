#include "HOTA/FireKnight.hpp"
#include <iostream>

FireKnight::FireKnight() : Hero{"image", 5000, 200, 500, 250, 0.1f}
{
    this->init_var();
}

FireKnight::~FireKnight()
{
}

void FireKnight::init_var()
{
    this->init_ani_stats();
    this->init_animations();
    this->init_stats();
    this->init_position();
}

void FireKnight::init_ani_stats()
{
    this->path += "/Fire Knight";
    this->atk_one_num = 11;
    this->atk_two_num = 28;
    this->atk_sp_num = 18;
    this->death_num = 13;
    this->defend_num = 10;
    this->idle_num = 8;
    this->jump_num = 20;
    this->roll_num = 8;
    this->run_num = 8;
    this->take_dmg_num = 6;
    this->jump_down_num = 3;
    this->jump_up_num = 3;
}

void FireKnight::init_stats()
{
    this->health -= 1800;
    this->damage += 100;
    this->mana += 200;
    this->defense -= 50;
    this->crit_chance += 0.25;
}

void FireKnight::skill()
{
    // TODO
}

void FireKnight::upgrade()
{
    // TODO
}
