#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

using namespace std;

int main()
{
    
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Game");

    while(window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window.close();
        }
    }






    return 0;
}