#ifndef UI_HPP
#define UI_HPP

#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

struct TextureAndSprite
{
  sf::Sprite *sprite;
  sf::Texture *texture;
};

struct TextureAndSpriteAndRectangle
{
  sf::Sprite *sprite;
  sf::Texture *texture;
  sf::IntRect rectangle;
};

class Ui
{
private:
  std::string folder;
  std::string png;
  TextureAndSprite *character_photo;
  TextureAndSpriteAndRectangle *mana_bar;

  std::vector<TextureAndSpriteAndRectangle *> *health_bar;

  sf::Texture *init_texture(const std::string &path);
  sf::Sprite *init_sprite(const sf::Texture *texture, const sf::Vector2f &scale, const sf::Vector2f &position);

  void init_heart(const int &size, const sf::Vector2f &scale, sf::Vector2f &position, const float &multiplier);

public:
  Ui(const std::string &folder, const std::string &png);
  ~Ui();

  void init_character_photo(const std::string &folder, const std::string &png);
  void init_health(const int &health);
  void update();
  void render(sf::RenderTarget &target);
};

#endif