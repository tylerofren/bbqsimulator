#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>



#include "Map.cpp"
#include "gameState.cpp"

#ifndef GAME_H
#define GAME_H

class Game
{
private:
    // Window variables

    sf::RenderWindow window;
    sf::Event ev;

    // UI
    // // Fonts
    sf::Font roundFont;
    sf::Font seriousFont;

    // Texts
    sf::Text gameTitle;
    sf::Text pressAnyButton;
    sf::Text copyrightDisclaimer;
    sf::Text levelSelect;
    sf::Text levelNumbers;
    sf::Text lostScreen;
    sf::Text lostScreen2;
    sf::Text winScreen;
    sf::Text winScreen2;
    sf::Text overcookedScreen;

    // Menu background
    sf::Texture backgroundTexture;
    sf::Sprite background;

    // Level select background
    sf::Texture levelSelectBackgroundTexture;
    sf::Sprite levelSelectBackground;


    // Initialization
    void initializeWindow();
    void initializeText();
    void initializeMaps();
    void initializeLevels();
    void initializePlayer();
    void initializeSausages();
    void initializePlayerOutline(); // Player outline is for the win condition
    void initializeBackground();

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
    

    void resetCurrentLevel();

    // Arrays

    std::vector<std::vector<std::vector<int>>> levels;

    // Boolean
    bool menuIsOpened;
    bool levelSelectIsOpened;
    // // Level Booleans
    bool levelIsOpened[10];

    void resetLevels();

    // Lost screen
    bool lostScreenIsOpened;
    bool sausagesPerfectlyCooked;
    bool winScreenIsOpened;
    bool overcookedScreenIsOpened;

    // Error file
    ofstream errorFile;

    
    // Undo function
    std::vector<GameState*> gameStates;
    void resetGameStates();
    void addGameState();
    void undo();





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