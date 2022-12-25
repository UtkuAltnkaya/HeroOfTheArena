#include "HOTA/Game.hpp"
#include <iostream>

Game::Game()
{
  this->init_var();
  this->init_window();
  this->init_background();
  this->init_main_menu();
}

Game::~Game()
{
  delete this->window;
  delete this->background;
  delete this->boss;
  delete this->music;
  if (this->main_menu)
  {
    delete this->main_menu;
  }
  if (this->npc)
  {
    delete this->npc;
  }
  if (this->fight)
  {
    delete fight;
  }
  if (this->hero)
  {
    delete hero;
  }
}

// Private
void Game::init_var()
{
  this->fight = nullptr;
  this->window = nullptr;
  this->background = nullptr;
  this->hero = nullptr;
  this->boss = nullptr;
  this->npc = nullptr;
  this->video_mode.width = 512 * 3;
  this->video_mode.height = 256 * 3;

  this->music_playing = false;
  this->music = new Musics("moonlight.ogg");

  //  this->music.stopMusic();
}

void Game::init_window()
{
  this->window = new sf::RenderWindow(this->video_mode, "Hero of the Arena");
  this->window->setFramerateLimit(60);
  // this->window->setVerticalSyncEnabled(false);
}

void Game::init_background()
{
  this->background = new Animation{"image/background", "Hills", "Hills Layer 0", 6, true};
}

void Game::init_main_menu()
{
  this->main_menu = new MainMenu(this->video_mode.width, this->video_mode.height);
}

// Public
void Game::run()
{
  while (this->window->isOpen())
  {

    this->update();
    this->render();
  }
}

void Game::update()
{
  this->poll_events();
  if (this->main_menu)
  {
    this->main_menu->update();
  }
  if (this->hero)
  {
    this->play_music();
    this->boss->update();
    this->hero->update();

    if (!this->fight)
    {
      // std::cout << "1" << std::endl;
      this->npc->update(this->hero->is_collide(this->npc));
      // std::cout << "2" << std::endl;
    }

    if (this->hero->is_collide(this->boss) && !this->fight)
    {
      // std::cout << "3" << std::endl;
      this->init_fight();
      // std::cout << "4" << std::endl;
    }
    if (this->fight && this->fight->get_is_fight_over())
    {
      std::cout << "BEFORE-DELETE" << std::endl;
      this->create_npcs();
      delete this->fight;
      this->fight = nullptr;
      std::cout << "AFTER-DELETE" << std::endl;
    }
  }
}

void Game::init_fight()
{
  this->fight = new Fight{this->hero, this->boss};
  delete this->npc;
  this->npc = nullptr;
}
void Game::render()
{
  this->window->clear();
  this->background->render_background(*this->window);
  if (this->main_menu)
  {
    this->main_menu->render(*this->window, this->hero);
  }
  if (this->hero)
  {
    this->delete_main_menu();
    this->boss->render(*this->window);
    this->hero->render(*this->window);

    if (!(this->fight))
    {
      // std::cout << "5" << std::endl;
      this->npc->render(*this->window);
      // std::cout << "6" << std::endl;
    }
  }
  this->window->display();
}

void Game::poll_events()
{
  while (this->window->pollEvent(this->event))
  {
    if (this->event.type == sf::Event::Closed)
    {
      this->window->close();
    }
    if (this->main_menu)
    {
      this->main_menu->MenuUpDown(this->event, this->hero, this->boss, this->npc);
    }
    if (this->hero)
    {
      this->hero->poll_events_loop(event);
    }
  }

  if (this->hero)
  {
    this->hero->poll_events(this->event, this->boss);
  }
  if (this->fight)
  {
    // std::cout << "7" << std::endl;
    this->fight->poll_events();
    // std::cout << "8" << std::endl;
  }
}

void Game::delete_main_menu()
{
  if (this->main_menu)
  {
    delete this->main_menu;
    this->main_menu = nullptr;
    this->music->set_volume(this->music->get_volume());
  }
}

void Game::play_music()
{
  if (!this->music_playing)
  {
    this->music->play();
    this->music_playing = true;
  }
}

void Game::create_npcs()
{
  if (!this->npc && this->fight->get_is_fight_over())
  {
    this->npc = new BlackSmith();
  }
}