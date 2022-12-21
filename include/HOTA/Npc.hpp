#ifndef NPC_HPP

#define NPC_HPP

#include "HOTA/Physics.hpp"

class Npc : public Physics
{
protected:
  size_t greeting_num;
  size_t work_one_num;
  size_t work_two_num;

  void init_all_animations();

private:
  bool is_ani_over;
  AnimationNames ani_name;

  void select_npc_animation(const bool &is_collide);

public:
  Npc();
  Npc(const std::string &path);
  virtual ~Npc();
  void update(const bool &is_collide);
  void render(sf::RenderTarget &target);
};

#endif