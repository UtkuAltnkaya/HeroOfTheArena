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
  std::string ani_name;

public:
  Npc();
  Npc(std::string path);
  ~Npc();
  void update();
  void render(sf::RenderTarget &target);
  void animate_greeting();
  void animate_idle();
};

#endif