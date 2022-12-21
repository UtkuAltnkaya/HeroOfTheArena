#include "HOTA/Npc.hpp"

Npc::Npc() : Npc{""}
{
}

Npc::Npc(const std::string &path) : Physics{path, 200, 200}, ani_name{AnimationNames::IDLE}
{
}

Npc::~Npc()
{
}

void Npc::init_all_animations()
{
  this->insert_new_animation(AnimationNames::IDLE, "idle", "idle_", this->idle_num, true);
  this->insert_new_animation(AnimationNames::GREETING, "greeting", "greeting_", this->greeting_num, true);
  this->insert_new_animation(AnimationNames::WORK_ONE, "work_1", "work_", this->work_one_num, true);
  this->insert_new_animation(AnimationNames::WORK_TWO, "work_2", "work_", this->work_two_num, false);
  this->set_and_calculate_position();
}

void Npc::update(const bool &is_collide)
{
  this->animation->update(this->is_ani_over);
  this->select_npc_animation(is_collide);
  this->select_animation(this->ani_name);
}

void Npc::render(sf::RenderTarget &target)
{
  this->animation->render(target);
}

void Npc::select_npc_animation(const bool &is_collide)
{
  if (is_collide)
  {
    this->ani_name = AnimationNames::GREETING;
    return;
  }
  this->ani_name = AnimationNames::IDLE;
}
