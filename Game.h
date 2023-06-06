#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <cmath>

#include "Map.cpp"
#include "gameState.cpp"

#ifndef GAME_H
#define GAME_H

class Game
{
private:
    // ----- Window -----
    sf::RenderWindow window;
    sf::Event ev;

    // ----- Graphics -----
    // // Fonts
    sf::Font roundFont;
    sf::Font seriousFont;
    // // Texts
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
    // // Shapes
    sf::ConvexShape star;
    // // Menu background
    sf::Texture backgroundTexture;
    sf::Sprite background;
    // // Level select background
    sf::Texture levelSelectBackgroundTexture;
    sf::Sprite levelSelectBackground;

    // ----- Initialization -----
    void initializeWindow();
    void initializeText();
    void initializeMaps();
    void initializeLevels();
    void initializePlayer();
    void initializeSausages();
    void initializePlayerOutline();
    void initializeBackground();
    void initializeSounds();
    void initializeStars();

    // ----- Sounds -----
    sf::Sound woosh;
    sf::SoundBuffer wooshBuffer;

    sf::Sound steps;
    sf::SoundBuffer stepsBuffer;

    // ----- Maps -----
    Map* maps[10];
    int currentMap;

    // ----- Player -----
    Player* player;
    sf::Sprite playerOutline;
    sf::Texture playerOutlineTexture;

    // ----- Sausages -----
    Sausage* sausage;
    Sausage* sausage2;

    // ----- Game Logic -----
    void updateSausages();
    void updateSausages2();
    void winLossConditions();
    void resetCurrentLevel();
    void resetLevels();
    bool sausageIntersects();
    bool forkIntersects();
    bool sausagesPerfectlyCooked;
    bool menuIsOpened;
    bool levelSelectIsOpened;
    bool lostScreenIsOpened;
    bool winScreenIsOpened;
    bool overcookedScreenIsOpened;
    bool levelIsOpened[10];

    // ----- Arrays -----
    std::vector<std::vector<std::vector<int>>> levels;
    bool levelsComplete[10];
    sf::ConvexShape* stars[10];
    
    // ----- Undo -----
    std::vector<GameState*> gameStates;
    void resetGameStates();
    void addGameState();
    void undo();

    // Debug
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