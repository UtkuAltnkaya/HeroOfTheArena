#ifndef UI_HEART_AND_MANA_HPP
#define UI_HEART_AND_MANA_HPP

#include <SFML/Graphics.hpp>

class UiHeartAndMana
{
private:
  std::string png_name;

  sf::Texture *texture; // TODO: Static ?
  sf::Sprite *sprite;

  sf::Vector2f scale;
  sf::Vector2f position;
  sf::IntRect rect;
  sf::IntRect inital_rec;

  bool is_over;
  bool is_full;

  void init_texture();
  void init_sprite();

public:
  UiHeartAndMana(const sf::Vector2f &position, const sf::IntRect &rect, const sf::Vector2f &scale, const std::string &png_name);
  ~UiHeartAndMana();

  void increase();
  void decrease();
  void set_full();
  void rotate();
  const bool &get_is_over();
  const bool &get_is_full();

  void render(sf::RenderTarget &target);
};

#endif