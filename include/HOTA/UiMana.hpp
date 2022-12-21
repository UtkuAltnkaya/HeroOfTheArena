#ifndef UI_MANA_HPP
#define UI_MANA_HPP

#include <SFML/Graphics.hpp>

class UiMana
{
private:
  sf::Texture *texture;
  sf::Sprite *sprite;

  sf::Vector2f scale;
  sf::Vector2f position;
  sf::IntRect rect;
  sf::IntRect inital_rec;

  void init_texture();
  void init_sprite();

public:
  UiMana(const sf::Vector2f &position, const sf::IntRect &rect);
  ~UiMana();
  void render(sf::RenderTarget &target);
};

#endif