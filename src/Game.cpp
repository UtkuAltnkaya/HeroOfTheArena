#include "HOTA/Game.hpp"
#include <iostream>

Game::Game()
{
  this->init_var();
  this->init_window();
  this->init_background();
  this->init_main_menu();

  this->init_player();
}

Game::~Game()
{
  delete this->window;
  delete this->player;
  delete this->background;
  delete this->main_menu;
}

// Private
void Game::init_var()
{
  this->window = nullptr;
  this->player = nullptr;
  this->background = nullptr;
  this->hero = nullptr;
  this->video_mode.width = 512 * 3;
  this->video_mode.height = 256 * 3;
  this->animation_name = "idle";
}

void Game::init_window()
{
  this->window = new sf::RenderWindow(this->video_mode, "Hero of the Arena");
  this->window->setFramerateLimit(60);
  // this->window->setVerticalSyncEnabled(false);
}

void Game::init_player()
{
  // this->player = new Player();
}

void Game::init_background()
{
  this->background = new Background("background", "Hills", "Hills Layer 0", 6);
  // this->bg_ani.insert(std::pair<std::string, Background *>("lvl_1", new Background("background", "hills", "HillsLayer0", 6)));
  // this->bg_ani.insert(std::pair<std::string, Background *>("lvl_2", new Background("background", "woods", "Layer", 4)));
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
    this->hero->update();
  }

  // this->player->update(this->animation_name);
}

void Game::render()
{
  this->window->clear();
  this->background->render(*this->window);
  this->main_menu->render(*this->window);
  if (this->hero)
  {
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
    this->main_menu->MenuUpDown(this->event, this->hero);
  }

  if (this->hero)
  {
    this->hero->poll_events(this->event);
  }

  // if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) // TODO
  // {
  //   this->animation_name = "run";
  //   if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
  //   {
  //     this->animation_name = "roll";
  //   }
  // }
  // else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
  // {
  //   this->animation_name = "run_left";
  //   if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
  //   {
  //     this->animation_name = "roll_left";
  //   }
  // }
}
