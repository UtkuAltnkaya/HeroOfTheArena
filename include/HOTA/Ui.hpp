#ifndef UI_HPP
#define UI_HPP

#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include "UiHeartAndMana.hpp"

class Ui
{
private:
  std::vector<UiHeartAndMana *> health_bar;
  std::vector<UiHeartAndMana *> mana_bar;

  struct
  {
    sf::Sprite *sprite;
    sf::Texture *texture;
  } character_photo;

  void init_heart_or_mana(const int &size, const float &multiplier, const sf::IntRect &rect, sf::Vector2f &position, const std::string &type);
  void reduce_hero_health();
  void reduce_boss_health();

public:
  Ui();
  ~Ui();

  void init_character_photo(const std::string &folder, const std::string &png, const sf::Vector2f &position = sf::Vector2f{40.f, 40.f});
  void init_health_or_mana_bar(const int &number, const int &denominator = 400, const std::string &type = "HealthUI", sf::Vector2f &&position = sf::Vector2f{150.f, 45.f});

  void reduce_health(const int &atk_power, const bool &is_hero);
  void reduce_hero_mana(const int &amount);
  void rotate_health();
  void render(sf::RenderTarget &target);
};

#endif