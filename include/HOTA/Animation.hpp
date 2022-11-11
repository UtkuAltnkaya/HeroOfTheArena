#ifndef ANIMATION_HPP
#define ANIMATION_HPP

#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

class Animation
{
private:
  bool is_repeat;
  std::vector<sf::Texture *> *texture;
  std::vector<sf::Sprite *> *sprite;
  sf::Clock *clock;

  std::string path;
  size_t size;
  size_t que;

  void init_texture();
  void init_sprite();
  void init_clock();
  void init_var(std::string &, std::string &, std::string &, size_t &, bool &is_repeat);

public:
  Animation(std::string, std::string, std::string, size_t, bool is_repeat);
  ~Animation();
  void render(sf::RenderTarget &);
  void update(bool is_repeat);
  void update_once();
  std::vector<sf::Sprite *> *get_sprite();
};

#endif