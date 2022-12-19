#ifndef UI_HPP
#define UI_HPP

#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include "UiHeart.hpp"

class Ui
{
private:
  std::vector<UiHeart *> health_bar;
  struct
  {
    sf::Sprite *sprite;
    sf::Texture *texture;
  } character_photo;

  void init_heart(const int &size, const float &multiplier, const sf::IntRect &rect, sf::Vector2f &position);

public:
  Ui();
  ~Ui();

  void init_character_photo(const std::string &folder, const std::string &png, const sf::Vector2f &position = sf::Vector2f{40.f, 40.f});
  void init_health(const int &health);

  void reduce_health(const int &atk_power);
  void render(sf::RenderTarget &target);
};

#endif