#include "HOTA/FireKnight.hpp"

FireKnight::FireKnight() : Hero{"image/Fire Knight", 5000, 200, 500, 0, 0, 150, 150}
{
    this->init_var();
}

FireKnight::~FireKnight()
{
}

void FireKnight::init_var()
{
    this->init_ani_stats();
    this->init_all_animations();
    this->init_stats();
    this->init_position();
    this->ui->init_character_photo(this->path, "fire_knight");
    this->ui->init_health_or_mana_bar(this->health);
    this->ui->init_health_or_mana_bar(this->mana, 100, "ManaUI");
}

void FireKnight::init_ani_stats()
{
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
    this->defend_position_num = 7;
    this->death_position_num = 11;
}

void FireKnight::init_stats()
{
    this->health -= 1000;
    this->damage += 600;
    this->mana += 0;
}
