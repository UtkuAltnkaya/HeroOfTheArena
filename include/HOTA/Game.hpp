#ifndef GAME_HPP
#define GAME_HPP

#include "HOTA/Background.hpp"
#include "HOTA/MainMenu.hpp"

class Game
{
private:
  sf::RenderWindow *window;

  sf::VideoMode video_mode;
  sf::Event event;

  Background *background;
  Hero *hero;

  MainMenu *main_menu;

  std::string animation_name;
  std::string bg_name;

  int index;
  void init_var();
  void init_window();
  void init_background();
  void init_main_menu();

public:
  Game();
  ~Game();

  void run();
  void poll_events();
  void update();
  void render();
};

#endif