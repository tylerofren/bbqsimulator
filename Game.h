#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>



#include "Map.cpp"

#ifndef GAME_H
#define GAME_H

class Game
{
private:
    // Window variables

    sf::RenderWindow window;
    sf::Event ev;

    // UI
    sf::Font font;
    sf::Text gameTitle;
    sf::Text levelSelect;
    sf::Text lostScreen;
    sf::Text lostScreen2;


    // Initialization
    void initializeWindow();
    void initializeText();
    void initializeMaps();
    void initializeLevels();
    void initializePlayer();
    void initializeSausages();

    // Maps
    Map* maps[10];
    int currentMap;


    // Player
    Player* player;

    // Sausages
    Sausage* sausage;
    Sausage* sausage2;

    bool sausageIntersects();
    bool forkIntersects();

    void updateSausages();

    // Arrays

    std::vector<std::vector<int>> levelOne;

    // Boolean
    bool menuIsOpened;
    // // Level Booleans
    bool levelOneIsOpened;

    // Lost screen
    bool lostScreenIsOpened;

    // Error file
    ofstream errorFile;

    






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