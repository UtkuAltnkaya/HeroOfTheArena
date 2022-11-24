#ifndef ANIMATION_HPP
#define ANIMATION_HPP

#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

class Animation
{
private:
  std::vector<sf::Texture *> *texture;
  std::vector<sf::Sprite *> *sprite;
  sf::Clock *clock;

  std::string path;
  std::string type;
  std::string ani;
  std::string ani_name;
  size_t size;
  size_t que;

  bool is_repeat;

  void init_texture();
  void init_sprite();
  void init_clock();
  void init_var(std::string &, std::string &, std::string &, size_t &, bool &is_repeat);

public:
  Animation(std::string, std::string, std::string, size_t, bool is_repeat);
  //Animation(const Animation &animation);
  ~Animation();
  void render(sf::RenderTarget &);
  void update(bool &is_ani_over);
  std::vector<sf::Sprite *> *get_sprite();
};

#endif