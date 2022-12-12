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
  delete this->main_menu;
  delete this->boss;
}

// Private
void Game::init_var()
{
  this->window = nullptr;
  this->background = nullptr;
  this->hero = nullptr;
  this->boss = nullptr;
  this->video_mode.width = 512 * 3;
  this->video_mode.height = 256 * 3;
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
  this->main_menu->update();
  if (this->hero)
  {
    this->boss->update();
    this->hero->update();
  }
}

void Game::render()
{
  this->window->clear();
  this->background->render_background(*this->window);
  this->main_menu->render(*this->window);
  if (this->hero)
  {

    this->boss->render(*this->window);
    this->hero->render(*this->window);
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
    this->main_menu->MenuUpDown(this->event, this->hero, this->boss);
    if (this->hero)
    {
      this->hero->poll_events_loop(event);
    }
  }

  if (this->hero)
  {
    this->hero->poll_events(this->event);
  }
}
