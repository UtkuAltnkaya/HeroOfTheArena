#include "HOTA/BlackSmith.hpp"

BlackSmith::BlackSmith() : Npc{"image/BlackSmith"}
{
  this->init_var();
}

BlackSmith::~BlackSmith()
{
}

void BlackSmith::init_var()
{
  this->init_ani_stats();
  this->init_all_animations();
  this->init_position();
}

void BlackSmith::init_ani_stats()
{
  this->idle_num = 4;
  this->greeting_num = 4;
  this->work_one_num = 5;
  this->work_two_num = 6;

  this->character_height = 96;
  this->character_width = 96;
  this->initial_positions.x = this->window_width * 0.5 - this->character_width + 30;
}
