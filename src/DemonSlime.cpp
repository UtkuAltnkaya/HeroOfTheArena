#include "HOTA/DemonSlime.hpp"
#include <iostream>

DemonSlime::DemonSlime() : Boss{"image/DemonSlime", 5000, 200, 500, 0, 0}
{
    this->init_var();
}

DemonSlime::~DemonSlime()
{
}

void DemonSlime::init_var()
{
    this->init_ani_stats();
    this->init_all_animations();
    this->init_stats();
    this->init_position();
}

void DemonSlime::init_ani_stats()
{
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
    this->jump_down_num = 0;
    this->jump_up_num = 0;

    this->initial_positions.x = 800;
    this->character_width = 864;
    this->character_height = 480;
}

void DemonSlime::init_stats()
{
    this->health += 1000;
    this->damage += 200;
    this->mana += 100;
    // this->defense_chance -= 50;
    // this->crit_chance += 0.25;
}

void DemonSlime::skill()
{
    // TODO
}

void DemonSlime::upgrade()
{
    // TODO
}
