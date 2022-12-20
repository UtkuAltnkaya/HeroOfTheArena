#ifndef UI_HEART_HPP
#define UI_HEART_HPP

#include <SFML/Graphics.hpp>

class UiHeart
{
private:
  sf::Texture *texture; // TODO: Static ?
  sf::Sprite *sprite;

  sf::Vector2f scale;
  sf::Vector2f position;
  sf::IntRect rect;
  sf::IntRect inital_rec;

  bool is_heart_over;

  void init_texture();
  void init_sprite();

public:
  UiHeart(const sf::Vector2f &position, const sf::IntRect &rect);
  ~UiHeart();

  void decrease_heart();
  void set_full_heart();
  void rotate_heart();
  const bool &get_is_heart_over();

  void render(sf::RenderTarget &target);
};

#endif