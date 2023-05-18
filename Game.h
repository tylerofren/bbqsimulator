#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Map.cpp"

#ifndef GAME_H
#define GAME_H

class Game
{
private:
    // Window variables
    sf::RenderWindow menuWindow;
    sf::RenderWindow window;
    sf::Event ev;

    // UI
    sf::Font font;
    sf::Text gameTitle;
    sf::Text levelSelect;


    // Initialization
    void initializeWindow();
    void initializeText();
    void initalizeMaps();
    void initializeLevels();

    // Maps
    Map* maps[10];

    // Arrays
    int levelOne[10][10];

    // Boolean
    bool menuIsOpened;
    // // Level Booleans
    bool levelOneIsOpened;







public:
    // Constructors
    Game();


    // Accessors
    const bool running() const;

    // Functions
    void pollEvents();
    void update();
    void render();
    

};












#endif