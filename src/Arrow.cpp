#include "HOTA/Arrow.hpp"
#include "HOTA/AnimationNames.hpp"
#include <iostream>
#include <chrono>

Arrow::Arrow(const std::string &path, const int &actual_width, const int &actual_height) : Physics{path, actual_width, actual_height}, animation_name{AnimationNames::NONE}, is_ani_over{false}, hit{false}, thread{nullptr}
{
  this->character_width = 768;
  this->character_height = 384;
}

Arrow::~Arrow()
{
  if (this->thread)
  {
    delete thread;
  }
}

void Arrow::init_all_animations()
{
  this->insert_new_animation(AnimationNames::ARROW, "arrow", "arrow_", 1, true);
  this->insert_new_animation(AnimationNames::ARROW_ONE, "arrow_hit_entangle", "arrow_hit_entangle_", 8, false);
  this->insert_new_animation(AnimationNames::ARROW_TWO, "arrow_shower_effect", "arrow_shower_effect_", 18, false);
}

void Arrow::calculate_arrow_position(const sf::Vector2f &leaf_position)
{
  this->initial_positions.x = leaf_position.x + this->character_width * 0.25 - 25;
  this->initial_positions.y = (leaf_position.y + leaf_position.y * 0.25 + 2);
  this->init_position();
  this->set_all_animation_position(this->initial_positions);
}

void Arrow::move_first_arrow()
{
  while (this->get_position_x() < 800)
  {
    this->move_left_right(sf::Keyboard::D, 20.f);
    std::this_thread::sleep_for(std::chrono::milliseconds(5));
  }
  this->animation_name = AnimationNames::ARROW_ONE;
  // TODO
}

void Arrow::finished_arrow_animation()
{
  if (this->animation_name == AnimationNames::ARROW_ONE || this->animation_name == AnimationNames::ARROW_TWO)
  {
    if (this->is_ani_over)
    {
      this->join_thread();
      this->back_to_start();
    }
  }
}

void Arrow::back_to_start()
{
  this->hit = true;
  this->is_ani_over = false;
  this->animation = nullptr;
  this->animation_name = AnimationNames::NONE;
  this->set_position(this->initial_positions);
}

void Arrow::join_thread()
{
  if (this->animation_name == AnimationNames::ARROW_ONE)
  {
    if (this->thread)
    {
      this->thread->join();
      delete this->thread;
      this->thread = nullptr;
    }
  }
}

void Arrow::update(const AnimationNames &leaf_animation, const size_t &que)
{

  if (this->animation_name == AnimationNames::NONE && leaf_animation == AnimationNames::ONE_ATK && que == 7)
  {
    this->animation_name = AnimationNames::ARROW;
    this->thread = new std::thread{&Arrow::move_first_arrow, this};
  }

  if (leaf_animation == AnimationNames::TWO_ATK && que == 10)
  {
    this->animation_name = AnimationNames::ARROW_TWO;
    this->set_position(sf::Vector2f{850, this->initial_positions.y - 85});
  }

  if (this->animation)
  {
    this->animation->update(this->is_ani_over);
  }

  if (this->animation_name != AnimationNames::NONE)
  {
    this->finished_arrow_animation();
    this->select_animation(animation_name);
  }
}

void Arrow::render(sf::RenderTarget &target)
{
  if (this->animation)
  {
    this->animation->render(target);
  }
}

const bool &Arrow::get_hit()
{
  return this->hit;
}
void Arrow::set_hit(const bool &is_hit)
{
  this->hit = is_hit;
}