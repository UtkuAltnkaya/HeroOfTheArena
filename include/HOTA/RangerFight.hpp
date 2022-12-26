#ifndef RANGER_FIGHT
#define RANGER_FIGHT

#include "HOTA/LeafArcher.hpp"
#include "HOTA/BaseFight.hpp"

class RangerFight : public BaseFight
{
private:
  LeafArcher *hero;
  Boss *boss;

  bool is_hero_hit;
  sf::Keyboard::Key key_archer;

  void hero_attack();
  void hero_attack_control();
  void arrow_hit_moment();
  void just_before_boss_turn();

  // void boss_attack();

public:
  RangerFight(LeafArcher *hero, Boss *boss);
  ~RangerFight();
  void poll_events() override;
};

#endif // RANGER_FIGHT
