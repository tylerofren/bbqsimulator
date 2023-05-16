#include <SFML/Graphics.hpp>


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

}












#endif