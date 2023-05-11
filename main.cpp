#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>



using namespace std;


const int rows = 5;
const int cols = 5;

int main()
{
    
    sf::RenderWindow window(sf::VideoMode(500, 500), "Stephens Sausage Roll");

    /*
    string mapLayout[rows][cols];
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
          cout << "Enter a string for row " << i << ", column "  << j << ": ";
          cin >> mapLayout[i][j];
        }
    }
    */


    sf::Texture texture;
    if(!texture.loadFromFile("WaterPlaceholder.png"))
    {
        cout << "failed to load image" << endl;
        exit(1);
    }

    sf::Sprite sprite;
    sprite.setTexture(texture);


    
    while(window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window.close();
        }
        window.clear(sf::Color(255, 255, 255));
        window.draw(sprite);
        window.display();
    }
    





    return 0;
}