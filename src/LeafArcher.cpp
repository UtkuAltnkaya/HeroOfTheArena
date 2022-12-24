#include "HOTA/LeafArcher.hpp"
#include <iostream>

LeafArcher::LeafArcher() : Hero{"image/Leaf Archer", 5000, 200, 500, 0, 0, 100, 100}
{
  this->init_var();
}

LeafArcher::~LeafArcher()
{
}

void LeafArcher::init_var()
{
  this->init_ani_stats();
  this->init_all_animations();
  this->init_stats();
  this->init_position();
  this->ui->init_character_photo(this->path, "leaf_archer");
  this->ui->init_health_or_mana_bar(this->health);
  this->ui->init_health_or_mana_bar(this->mana, 100, "ManaUI");
}

void LeafArcher::init_ani_stats()
{
  this->atk_one_num = 15;
  this->atk_two_num = 20;
  this->atk_sp_num = 17;
  this->death_num = 19;
  this->defend_num = 19;
  this->idle_num = 9;
  this->jump_num = 22;
  this->roll_num = 8;
  this->run_num = 10;
  this->take_dmg_num = 6;
  this->jump_up_num = 3;
  this->jump_down_num = 3;
  this->defend_position_num = 12;
}

void LeafArcher::init_stats()
{
  this->health -= 2200;
  this->damage += 600;
  this->mana += 500;
  // this->defense -= 50;
  //  this->crit_chance += 0.25;
}

void LeafArcher::skill()
{
  // TODO
}

void LeafArcher::upgrade()
{
  // TODO
}

/*
  We had a problem the animation was working only when the button is pressed and it was continuously being called.
  We have added a attribute named is_ani_over to check whether the animation is over or not. And we passed the attribute to the animation update method with Pass by reference.
  Since we want to make our animation fully done when it's pressed once by user for specific animations, We check if animation is over and then after the animation
  character takes the idle position and the animation that we want to be done once stops.
*/