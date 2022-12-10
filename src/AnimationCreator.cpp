#include "HOTA/AnimationCreator.hpp"
#include <iostream>

AnimationCreator::AnimationCreator() : AnimationCreator{""}
{
}

AnimationCreator::AnimationCreator(std::string path) : path{path}, animation{nullptr}
{
  this->idle_animation = nullptr;
  this->atk_one_animation = nullptr;
  this->atk_two_animation = nullptr;
  this->run_animation = nullptr;
  this->run_left_animation = nullptr;
}

AnimationCreator::~AnimationCreator()
{
  delete this->idle_animation;
  delete this->atk_one_animation;
  delete this->atk_two_animation;
  delete this->atk_sp_animation;
  delete this->defend_animation;
  delete this->run_animation;
  delete this->run_left_animation;
  delete this->animation;
}

void AnimationCreator::init_animations()
{
  this->animation = this->idle_animation = new Animation(this->path, "idle", "idle_", this->idle_num, true);
  this->atk_one_animation = new Animation{this->path, "1_atk", "atk_", this->atk_one_num, false};
  this->atk_two_animation = new Animation{this->path, "2_atk", "atk_", this->atk_two_num, false};
  this->atk_sp_animation = new Animation{this->path, "sp_atk", "sp_atk_", this->atk_sp_num, false};
  this->defend_animation = new Animation{this->path, "defend", "defend_", this->defend_num, false};
  this->run_animation = new Animation{this->path, "run", "run_", this->run_num, true};
  this->run_left_animation = new Animation{this->path, "run_left", "run_", this->run_num, true};
  // TODO jump

  this->set_all_animation_position(sf::Vector2f{-10, (256 * 3) - (128 * 3) - 30}); // Set chars position
}

void AnimationCreator::select_animation(std::string animation_name)
{
  if (animation_name == "idle")
  {
    this->animation = this->idle_animation;
  }
  else if (animation_name == "1_atk")
  {
    this->animation = this->atk_one_animation;
  }
  else if (animation_name == "2_atk")
  {
    this->animation = this->atk_two_animation;
  }
  else if (animation_name == "sp_atk")
  {
    this->animation = this->atk_sp_animation;
  }
  else if (animation_name == "defend")
  {
    this->animation = this->defend_animation;
  }
  else if (animation_name == "run")
  {
    this->animation = this->run_animation;
  }
  else if (animation_name == "run_left")
  {
    this->animation = this->run_left_animation;
  }
  else
  {
    this->animation = this->idle_animation;
  }
}
void AnimationCreator::set_all_animation_position(sf::Vector2f last_position)
{
  this->set_animation_position(this->idle_animation, last_position);
  this->set_animation_position(this->atk_one_animation, last_position);
  this->set_animation_position(this->atk_two_animation, last_position);
  this->set_animation_position(this->atk_sp_animation, last_position);
  this->set_animation_position(this->defend_animation, last_position);
  this->set_animation_position(this->run_left_animation, last_position);
  this->set_animation_position(this->run_animation, last_position);
}

void AnimationCreator::set_animation_position(Animation *animation, sf::Vector2f &last_position)
{
  for (auto &&i : *animation->get_sprite())
  {
    i->setPosition(last_position);
  }
}