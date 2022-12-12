#include "HOTA/DemonSlime.hpp"
#include <iostream>

DemonSlime::DemonSlime() : Boss{"image", 5000, 200, 500, 250, 0.1f}
{
    this->init_var();
}

DemonSlime::~DemonSlime()
{
}

void DemonSlime::init_var()
{
    this->init_ani_stats();
    this->init_animations();
    this->init_stats();
}

void DemonSlime::init_ani_stats()
{

    this->path += "/DemonSlime";
    this->atk_one_num = 15;
    this->atk_two_num = 0;
    this->atk_sp_num = 0;
    this->death_num = 22;
    this->defend_num = 0;
    this->idle_num = 6;
    this->jump_num = 0;
    this->roll_num = 0;
    this->run_num = 12;
    this->take_dmg_num = 5;
    this->size = 5;
}

void DemonSlime::init_stats()
{
    this->health -= 2800;
    this->damage += 50;
    this->mana += 200;
    this->defense -= 50;
    this->crit_chance += 0.25;
}

void DemonSlime::skill()
{
    // TODO
}

void DemonSlime::upgrade()
{
    // TODO
}
