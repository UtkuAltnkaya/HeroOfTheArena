#ifndef ARROW_HPP
#define ARROW_HPP

#include "HOTA/Physics.hpp"
#include <thread>

class Arrow : public Physics
{
private:
  AnimationNames animation_name;
  bool is_ani_over;
  bool hit;

  std::thread *thread;

  void move_first_arrow();
  void finished_arrow_animation();
  void join_thread();
  void back_to_start();

public:
  Arrow(const std::string &path, const int &actual_width, const int &actual_height);
  virtual ~Arrow();
  void init_all_animations() override;
  void calculate_arrow_position(const sf::Vector2f &leaf_position);
  void update(const AnimationNames &leaf_animation, const size_t &que);
  void render(sf::RenderTarget &target);

  const bool &get_hit();
};

#endif