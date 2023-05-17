#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

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
    sf::Text levels;


    // Initialization
    void initializeWindow();
    void initializeText();







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