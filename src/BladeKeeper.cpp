#include "HOTA/BladeKeeper.hpp"
#include <iostream>

BladeKeeper::BladeKeeper() : Hero{"image/BladeKeeper", 5000, 200, 500, 0, 0, 100, 100}
{
    this->init_var();
}

BladeKeeper::~BladeKeeper()
{
}

void BladeKeeper::init_var()
{
    this->init_ani_stats();
    this->init_all_animations();
    this->init_stats();
    this->init_position();
    this->ui->init_character_photo(this->path, "blade_keeper");
    this->ui->init_health_or_mana_bar(this->health);
    this->ui->init_health_or_mana_bar(this->mana, 100, "ManaUI");
}

void BladeKeeper::init_ani_stats()
{
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
    this->jump_down_num = 3;
    this->jump_up_num = 3;
    this->defend_position_num = 7;
    this->death_position_num = 10;
}

void BladeKeeper::init_stats()
{
    this->health -= 3000; // 5000 - 3000
    this->damage += 1000; // 200 + 1000
    this->mana += 200;    // 500 + 200
    // this->defense -= 50;  // 250 - 50
    //  this->crit_chance += 0.25; // 0. + 0.25
}

void BladeKeeper::skill()
{
    // TODO
}

void BladeKeeper::upgrade()
{
    // TODO
}
