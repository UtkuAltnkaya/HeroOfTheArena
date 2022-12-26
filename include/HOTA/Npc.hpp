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
  sf::Text end_text;
  sf::Font font;

  void select_npc_animation();

public:
  Npc();
  Npc(const std::string &path);
  virtual ~Npc();
  void update();
  void render(sf::RenderTarget &target);
};

#endif