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
  // Initiliaze  all npc animiations
  this->insert_new_animation(AnimationNames::IDLE, "idle", "idle_", this->idle_num, true);
  this->insert_new_animation(AnimationNames::GREETING, "greeting", "greeting_", this->greeting_num, true);
  this->insert_new_animation(AnimationNames::WORK_ONE, "work_1", "work_", this->work_one_num, true);
  this->insert_new_animation(AnimationNames::WORK_TWO, "work_2", "work_", this->work_two_num, false);
  this->set_and_calculate_position();
  this->font.loadFromFile("Fonts/PixExtrusion.ttf");
  end_text.setFont(font);
  end_text.setCharacterSize(80);

  end_text.setColor(sf::Color(121, 109, 116));
  end_text.setString("CONGRATULATIONS!");
  end_text.setPosition(sf::Vector2f(300, 120));
}

void Npc::update()
{ // Update npc animations
  this->animation->update(this->is_ani_over);
  this->select_npc_animation();
  this->select_animation(this->ani_name);
}

void Npc::render(sf::RenderTarget &target)
{ // Display npc to the screen
  this->animation->render(target);
  target.draw(this->end_text);
}

void Npc::select_npc_animation()
{
  // Npc animation name
  this->ani_name = AnimationNames::GREETING;
}
