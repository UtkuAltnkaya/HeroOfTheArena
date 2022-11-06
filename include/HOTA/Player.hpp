#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "HOTA/Animation.hpp"
#include <map>

class Player
{
private:
  std::map<std::string, Animation *> player_ani;

  void init_animation();
  void init_var();
  void animate();

public:
  Player();
  ~Player();

  void update(std::string &);
  void render(sf::RenderTarget &, std::string &);
  void move(std::string);
};

#endif