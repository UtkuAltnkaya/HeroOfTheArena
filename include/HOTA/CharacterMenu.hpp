#ifndef CHARACTER_MENU_HPP
#define CHARACTER_MENU_HPP

#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include "HOTA/Hero.hpp"
#include "HOTA/LeafArcher.hpp"

#define Max_Items 6
class CharMenu
{
private:
    std::vector<std::string> chars = {"BladeKeeper", "Fire Knight", "Ground Monk", "Leaf Archer", "Water", "Wind"}; // TODO
    std::vector<int> characterIdleNums = {8, 8, 6, 9, 8, 8};
    std::vector<int> characterAtkNums = {6, 11, 6, 10, 7, 8};
    std::vector<sf::Texture *> texture;
    std::vector<sf::Sprite *> sprite;
    std::vector<sf::RectangleShape> Border;
    std::string path;
    int que = 1;
    int animate = 0;
    int selectedItem = 0;

    int charSize = chars.size();
    bool open;
    sf::Clock *clock;

    void init_texture_vec(int);
    void init_sprite_vec(int);
    void init_var(std::string &, std::string &);
    void init_clock();

    void MoveRight();
    void MoveLeft();
    void MoveUp();
    void MoveDown();

public:
    CharMenu(std::string, std::string);
    ~CharMenu();
    void render(sf::RenderTarget &);

    void set_open(bool open);
    bool get_open();

    void MoveLeftRight(sf::Event &event, Hero *&hero);
    void Animated(sf::RenderTarget &);
    void Update();
};

#endif