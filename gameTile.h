#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>

using namespace std;

#ifndef GAMETILE_H
#define GAMETILE_H

/*
    Class that creates tiles to put in your level
*/

class GameTile
{
private:

    ofstream errorFile;

    sf::Texture texture;
    sf::Sprite sprite;
    sf::Vector2f position;
    bool isPassable;
    bool isSausagePassable;


public:



    GameTile();
    GameTile(const std::string&, float, float, bool, bool);
    sf::Sprite& getSprite();
    bool getPassable();
    bool getSausagePassable();




};









#endif