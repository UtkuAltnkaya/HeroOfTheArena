#include "HOTA/Wind.hpp"
#include <iostream>

Wind::Wind() : Hero{"image/Wind", 5000, 200, 500, 0, 0, 100, 100}
{
    this->init_var();
}

Wind::~Wind()
{
}

void Wind::init_var()
{
    this->init_ani_stats();
    this->init_all_animations();
    this->init_stats();
    this->init_position();
    this->ui->init_character_photo(this->path, "wind");
    this->ui->init_health_or_mana_bar(this->health);
    this->ui->init_health_or_mana_bar(this->mana, 100, "ManaUI");
}

void Wind::init_ani_stats()
{
    this->atk_one_num = 8;
    this->atk_two_num = 26;
    this->atk_sp_num = 30;
    this->death_num = 20;
    this->defend_num = 8;
    this->idle_num = 8;
    this->jump_num = 6;
    this->roll_num = 6;
    this->run_num = 8;
    this->take_dmg_num = 6;
    this->jump_down_num = 3;
    this->jump_up_num = 3;
    this->defend_position_num = 4;
    this->death_position_num = 18;
}

void Wind::init_stats()
{
    this->health -= 2200;
    this->damage += 800;
    this->mana += 200;
    // this->defense_chance = 0;
    //  this->crit_chance += 0.25;
}

void Wind::skill()
{
    // TODO
}

void Wind::upgrade()
{
    // TODO
}
