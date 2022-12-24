#include "HOTA/Water.hpp"
#include <iostream>

Water::Water() : Hero{"image/Water", 5000, 200, 500, 0, 0, 100, 100}
{
    this->init_var();
}

Water::~Water()
{
}

void Water::init_var()
{
    this->init_ani_stats();
    this->init_all_animations();
    this->init_stats();
    this->init_position();
    this->ui->init_character_photo(this->path, "water");
    this->ui->init_health_or_mana_bar(this->health);
    this->ui->init_health_or_mana_bar(this->mana, 100, "ManaUI");
}

void Water::init_ani_stats()
{
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
    this->jump_down_num = 3;
    this->jump_up_num = 3;
}

void Water::init_stats()
{
    this->health -= 2200;
    this->damage += 600;
    this->mana += 500;
    // this->defense -= 50;
    //  this->crit_chance += 0.25;
}

void Water::skill()
{
    // TODO
}

void Water::upgrade()
{
    // TODO
}
