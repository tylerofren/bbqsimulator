#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>


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
    sf::Text text;

    // Game logic
    bool endGame;

    // Private functions
    // Initialization
    void initializeGame();
    void initializeWindow();
    void initializeFonts();
    void initializeText();
    void startGame();





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