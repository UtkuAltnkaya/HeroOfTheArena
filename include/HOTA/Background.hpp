#ifndef BACKGROUND_HPP
#define BACKGROUND_HPP

#include <vector>
#include <string>
#include <SFML/Graphics.hpp>

class Background
{
private:
  std::vector<sf::Texture *> texture;
  std::vector<sf::Sprite *> sprite;
  std::string path;
  size_t size;

  void init_texture_vec();
  void init_sprite_vec();
  void init_var(std::string &, std::string &, std::string &, size_t &);

public:
  Background(std::string, std::string, std::string, size_t);
  ~Background();

  void render(sf::RenderTarget &);
};

#endif