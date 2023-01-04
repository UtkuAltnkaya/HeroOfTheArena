#include "HOTA/Fight.hpp"
#include "HOTA/RangerFight.hpp"
#include "HOTA/Game.hpp"

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
  delete this->music;

  if (this->boss)
  {
    delete this->boss;
  }
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
  this->fight = nullptr; // initializing all variables to their base values
  this->window = nullptr;
  this->background = nullptr;
  this->hero = nullptr;
  this->boss = nullptr;
  this->npc = nullptr;
  this->video_mode.width = 512 * 3;
  this->video_mode.height = 256 * 3;

  this->game_over = false;
  this->music_playing = false;
  this->music = new Music("Battle Encounter.ogg");
}

void Game::init_window()
{
  // window that we draw characters and other things
  this->window = new sf::RenderWindow(this->video_mode, "Hero of the Arena");
  this->window->setFramerateLimit(60);
  // this->window->setVerticalSyncEnabled(false);
}

void Game::init_background()
{
  // initializing background image
  this->background = new Animation{"image/background", "Hills", "Hills Layer 0", 6, true};
}

void Game::init_main_menu()
{
  // initializing main menu of the game
  this->main_menu = new MainMenu(this->video_mode.width, this->video_mode.height);
}

// Public
void Game::run()
{
  while (this->window->isOpen())
  {
    // updating and rendering animations and the other objects
    this->update();
    this->render();
  }
}

void Game::update()
{
  this->poll_events();
  if (this->main_menu) // main menu display condition
  {
    this->main_menu->update();
  }
  if (this->hero) // if hero is created then display the arena
  {
    this->play_music();
    if (this->boss) // if boss is created check for the collide
    {
      this->boss->update(); // update boss animation
      if (this->hero->is_collide(this->boss) && !this->fight)
      {
        // if our hero and boss collided start the fight
        this->init_fight();
      }
    }

    this->hero->update(); // update hero animations

    if (this->fight && this->fight->get_is_fight_over()) // fight is finished
    {
      if (this->boss->get_health() <= 0) // boss is dead
      {
        this->create_npc(); // create the npc that celebrate us
      }
      else
      { // We lost game basically
        this->game_over = true;
        this->font.loadFromFile("Fonts/PixExtrusion.ttf");
        this->end_text.setFont(font);
        this->end_text.setCharacterSize(80);
        // Setting game over text
        this->end_text.setColor(sf::Color(121, 109, 116));
        this->end_text.setString("GAME OVER!");
        this->end_text.setPosition(sf::Vector2f(500, 120));
      }
      delete this->fight; // Deleting fight and boss
      delete this->boss;
      this->fight = nullptr;
      this->boss = nullptr;
    }
    if (this->npc) // If npc is created update it's animations
    {
      this->npc->update();
    }
  }
}

void Game::init_fight()
{
  if (this->hero->get_path() == "image/Leaf Archer")
  { // If our selected character is ranger create rangerFight
    this->fight = new RangerFight{dynamic_cast<LeafArcher *>(hero), boss};
  }
  else
  { // If it is melee create normal fight
    this->fight = new Fight{this->hero, this->boss};
  }
}

void Game::render()
{
  this->window->clear(); // Clearing old images
  this->background->render_background(*this->window);
  if (this->main_menu) // Displaying main menu
  {
    this->main_menu->render(*this->window, this->hero);
  }
  if (this->hero) // Displaying hero
  {
    this->delete_main_menu(); // Delete main menu once arena is created
    if (this->boss)           // If boss is not NULL display boss
    {
      this->boss->render(*this->window);
    }
    this->hero->render(*this->window);
    if (this->npc) //  Display npc
    {
      this->npc->render(*this->window);
    }
    if (this->game_over) // Display game over text
    {
      this->window->draw(end_text);
    }
  }

  this->window->display(); // Display the window so we can see the changes
}

void Game::poll_events()
{
  while (this->window->pollEvent(this->event))
  {
    // Getting the key event from the user keyboard
    if (this->event.type == sf::Event::Closed)
    {
      this->window->close(); // Close the window
    }
    if (this->main_menu)
    { // Events for main menu
      this->main_menu->MenuUpDown(this->event, this->hero, this->boss, this->npc);
    }
    if (this->hero)
    { // Event for the hero
      this->hero->poll_events_loop(event);
    }
  }

  if (this->hero)
  { // Poll events for the hero and boss
    this->hero->poll_events(this->event, this->boss);
  }
  if (this->fight)
  { // Poll events specialized for the fight
    this->fight->poll_events();
  }
}

void Game::delete_main_menu()
{
  if (this->main_menu)
  { // Delete main menu if it is not deleted already
    delete this->main_menu;
    this->main_menu = nullptr;
    this->music->set_volume(this->music->get_volume());
  }
}

void Game::play_music()
{
  if (!this->music_playing)
  { // Start the music if it is not playing
    this->music->play();
    this->music_playing = true;
  }
}

void Game::create_npc()
{
  this->npc = new BlackSmith();
}