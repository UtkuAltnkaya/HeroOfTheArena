#include "HOTA/FrostGuardian.hpp"

FrostGuardian::FrostGuardian() : Boss{"image", 5000, 200, 500, 0, 0}
{
    this->init_var();
}

FrostGuardian::~FrostGuardian()
{
}

void FrostGuardian::init_var()
{
    this->init_ani_stats();
    this->init_all_animations();
    this->init_stats();
    this->init_position();
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
    this->jump_down_num = 0;
    this->jump_up_num = 0;
    this->take_dmg_num = 7;

    this->initial_positions.x = 1000;
    this->character_width = 576;
    this->character_height = 384;
}

void FrostGuardian::init_stats()
{
    this->health -= 2800;
    this->damage += 50;
    this->mana += 200;
    // this->defense -= 50;
    // this->crit_chance += 0.25;
}

void FrostGuardian::skill()
{
    // TODO
}

void FrostGuardian::upgrade()
{
    // TODO
}
