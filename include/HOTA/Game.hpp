#ifndef GAME_HPP
#define GAME_HPP

#include "HOTA/Animation.hpp"
#include "HOTA/MainMenu.hpp"
#include "HOTA/Music.hpp"
#include "HOTA/Npc.hpp"
#include "HOTA/BaseFight.hpp"
#include "HOTA/BlackSmith.hpp"

class Game
{
private:
  Animation *background;
  Hero *hero;
  MainMenu *main_menu;
  Boss *boss;
  Npc *npc;
  Musics *music;
  BaseFight *fight;
  sf::Font font;
  sf::Text end_text;
  bool game_over;
  bool music_playing;

  sf::RenderWindow *window;
  sf::VideoMode video_mode;
  sf::Event event;

  void init_var();
  void init_fight();
  void init_window();
  void init_background();
  void init_main_menu();
  void delete_main_menu();
  void play_music();
  void create_npc();
  void poll_events();
  void update();
  void render();

public:
  Game();
  ~Game();

  void run();
};

#endif