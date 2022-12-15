
#ifndef MAIN_MENU_HPP
#define MAIN_MENU_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include "HOTA/CharacterMenu.hpp"

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
  CharMenu *char_menu;

  bool open;
  void init_char_menu();
  void MoveUp();
  void MoveDown();

public:
  MainMenu(float width, float height);
  ~MainMenu();

  void render(sf::RenderWindow &window);
  void update();
  void MenuUpDown(sf::Event &, Hero *&hero, Boss *&boss, Npc *&npc);

  bool GetOpen();
  void SetOpen(bool changeOpen);
};

#endif