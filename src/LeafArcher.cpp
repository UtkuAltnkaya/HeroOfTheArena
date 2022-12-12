#include "HOTA/LeafArcher.hpp"
#include <iostream>

LeafArcher::LeafArcher() : Hero{"image", 5000, 200, 500, 250, 0.1f}
{
  this->init_var();
}

LeafArcher::~LeafArcher()
{
}

void LeafArcher::init_var()
{
  this->init_ani_stats();
  this->init_animations();
  this->init_stats();
}

void LeafArcher::init_ani_stats()
{

  this->path += "/Leaf Archer";
  this->atk_one_num = 15;
  this->atk_two_num = 12;
  this->atk_sp_num = 17;
  this->death_num = 19;
  this->defend_num = 19;
  this->idle_num = 9;
  this->jump_num = 22;
  this->roll_num = 8;
  this->run_num = 10;
  this->take_dmg_num = 6;
  this->size = 3;
}

void LeafArcher::init_stats()
{
  this->health -= 1800;
  this->damage += 100;
  this->mana += 200;
  this->defense -= 50;
  this->crit_chance += 0.25;
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