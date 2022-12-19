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

  size_t size;
  size_t que;

  bool is_repeat;

  void init_texture();
  void init_sprite();
  void init_clock();
  void init_var(const std::string &type, const std::string &ani, const std::string &ani_name, const size_t &size, const bool &is_repeat);
  void init_var(size_t &, bool &is_repeat);

public:
  Animation(const std::string &type, const std::string &ani, const std::string &ani_name, const size_t &size, const bool &is_repeat);
  Animation(Animation &);
  ~Animation();
  void render(sf::RenderTarget &);
  void render_background(sf::RenderTarget &);

  void update(bool &is_ani_over);
  std::vector<sf::Sprite *> *get_sprite();
};

#endif