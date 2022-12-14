#include "HOTA/GroundMonk.hpp"

GroundMonk::GroundMonk() : Hero{"image/Ground Monk", 5000, 200, 500, 0, 0, 10, 100}
{
    this->init_var();
}

GroundMonk::~GroundMonk()
{
}

void GroundMonk::init_var()
{
    this->init_ani_stats();
    this->init_all_animations();
    this->init_stats();
    this->init_position();
    this->ui->init_character_photo(this->path, "ground_monk");
    this->ui->init_health_or_mana_bar(this->health);
    this->ui->init_health_or_mana_bar(this->mana, 100, "ManaUI");
}

void GroundMonk::init_ani_stats()
{
    this->atk_one_num = 6;
    this->atk_two_num = 23;
    this->atk_sp_num = 25;
    this->death_num = 18;
    this->defend_num = 13;
    this->idle_num = 6;
    this->jump_num = 6;
    this->roll_num = 6;
    this->run_num = 8;
    this->take_dmg_num = 6;
    this->jump_down_num = 3;
    this->jump_up_num = 3;
    this->defend_position_num = 9;
    this->death_position_num = 16;
}

void GroundMonk::init_stats()
{
    this->health -= 1000;
    this->damage += 600;
    this->mana += 0;
}
