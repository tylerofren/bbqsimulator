#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Menu.cpp"


#ifndef GAME_H
#define GAME_H

class Game
{
private:
    // Window variables
    sf::RenderWindow menuWindow;
    sf::RenderWindow window;
    sf::Event ev;

    sf::Event event1;

    // Game logic
    bool endGame;

    // Private functions
    // Initialization

    void initializeWindow();
    void initializeGame();



    // Start
    void startGame();

    // Levels
    void initializeLevel1();
    sf::RenderWindow Level1;





public:
    // Constructors
    Game();


    // Accessors
    const bool running() const;
    const bool getEndGame() const;

    // Functions
    void pollEvents();
    void update();
    void render();
    

};












#endif