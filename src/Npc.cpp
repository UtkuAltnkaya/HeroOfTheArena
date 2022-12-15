#include "HOTA/Npc.hpp"

Npc::Npc() : Npc{""}
{
}

Npc::Npc(std::string path) : Physics{path, 50, 50}, ani_name{"idle"}
{
}

Npc::~Npc()
{
}

void Npc::init_all_animations()
{
  this->insert_new_animation("idle", "idle_", this->idle_num, true);
  this->insert_new_animation("greeting", "greeting_", this->greeting_num, true);
  this->insert_new_animation("work_1", "work_", this->work_one_num, true);
  this->insert_new_animation("work_2", "work_", this->work_two_num, false);
  this->set_and_calculate_position();
}

void Npc::update()
{
  this->animation->update(this->is_ani_over);
  this->select_animation(this->ani_name);
}

void Npc::render(sf::RenderTarget &target)
{
  this->animation->render(target);
}

void Npc::animate_greeting()
{
  this->ani_name = "greeting";
}

void Npc::animate_idle()
{
  this->ani_name = "idle";
}

// void Npc::animate_work_1()
// {

// }