#ifndef GAME_HPP
#define GAME_HPP

#include "HOTA/Animation.hpp"
#include "HOTA/MainMenu.hpp"

class Game
{
private:
  Animation *background;
  Hero *hero;
  MainMenu *main_menu;

  sf::RenderWindow *window;
  sf::VideoMode video_mode;
  sf::Event event;

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