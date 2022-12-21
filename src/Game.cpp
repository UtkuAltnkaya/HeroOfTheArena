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
      this->npc->update(this->hero->is_collide(this->npc));
    }

    if (this->hero->is_collide(this->boss) && !this->fight)
    {
      this->init_fight();
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
      this->npc->render(*this->window);
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
    this->fight->poll_events();
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