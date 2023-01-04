#ifndef LEAF_ARCHER_HPP
#define LEAF_ARCHER_HPP

#include "HOTA/Hero.hpp"
#include "HOTA/Arrow.hpp"
#include <string>

class LeafArcher : public Hero
{
private:
  Arrow *arrow;

  void init_var();
  void init_ani_stats();
  void init_stats();
  void init_ui();

  void fight_start() override;

public:
  LeafArcher();
  ~LeafArcher();

  void update() override;
  void render(sf::RenderTarget &target) override;
  const bool &get_hit();
  void set_hit(const bool &is_hit);
};

#endif