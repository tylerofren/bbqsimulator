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
    sf::Text winScreen;


    // Initialization
    void initializeWindow();
    void initializeText();
    void initializeMaps();
    void initializeLevels();
    void initializePlayer();
    void initializeSausages();
    void initializePlayerOutline(); // Player outline is for the win condition

    // Maps
    Map* maps[10];
    int currentMap;


    // Player
    Player* player;
    sf::Sprite playerOutline;
    sf::Texture playerOutlineTexture;

    // Sausages
    Sausage* sausage;
    Sausage* sausage2;


    bool sausageIntersects();
    bool forkIntersects();

    void updateSausages();
    void updateSausages2();

    void winLossConditions();

    // Arrays

    std::vector<std::vector<std::vector<int>>> levels;

    // Boolean
    bool menuIsOpened;
    // // Level Booleans
    bool levelIsOpened[10];

    void resetLevels();

    // Lost screen
    bool lostScreenIsOpened;
    bool sausagesPerfectlyCooked;
    bool winScreenIsOpened;

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