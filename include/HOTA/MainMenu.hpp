
#ifndef MAIN_MENU_HPP
#define MAIN_MENU_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include "HOTA/CharacterMenu.hpp"
#include "HOTA/Music.hpp"
#define MAX_NUMBER_OF_ITEMS 3
using namespace std;

class MainMenu
{
private:
  int selectedItemIndex{0};
  sf::Font font;
  sf::Text menu[MAX_NUMBER_OF_ITEMS];

  sf::Font titleFont;
  sf::Text title;
  Musics *music;
  CharMenu *char_menu;

  bool open;
  void init_char_menu();
  void MoveUp();
  void MoveDown();
  void selected_option();
  void move_it(sf::Event &event);

public:
  MainMenu(float width, float height);
  ~MainMenu();

  void render(sf::RenderWindow &window, Hero *&hero);
  void update();
  void MenuUpDown(sf::Event &, Hero *&hero, Boss *&boss, Npc *&npc);

  bool GetOpen();
  void SetOpen(bool changeOpen);
};

#endif