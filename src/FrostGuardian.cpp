#include "HOTA/FrostGuardian.hpp"
#include <iostream>

FrostGuardian::FrostGuardian() : Boss{"image", 5000, 200, 500, 250, 0.1f}
{
    this->init_var();
}

FrostGuardian::~FrostGuardian()
{
}

void FrostGuardian::init_var()
{
    this->init_ani_stats();
    this->init_animations();
    this->init_stats();
}

void FrostGuardian::init_ani_stats()
{

    this->path += "/FrostGuardian";
    this->atk_one_num = 14;
    this->atk_two_num = 0;
    this->atk_sp_num = 0;
    this->death_num = 16;
    this->defend_num = 0;
    this->idle_num = 6;
    this->jump_num = 0;
    this->roll_num = 0;
    this->run_num = 10;
    this->take_dmg_num = 7;
    this->size = 4;
}

void FrostGuardian::init_stats()
{
    this->health -= 2800;
    this->damage += 50;
    this->mana += 200;
    this->defense -= 50;
    this->crit_chance += 0.25;
}

void FrostGuardian::skill()
{
    // TODO
}

void FrostGuardian::upgrade()
{
    // TODO
}
