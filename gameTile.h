#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>

using namespace std;

#ifndef GAMETILE_H
#define GAMETILE_H

/*
    Class that creates tiles to put in your Map
*/
class GameTile
{
private:
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Vector2f position;
    bool isPassable;
    bool isSausagePassable;
    bool isGrill;
    ofstream errorFile;
public:
    // ----- Constructors -----
    GameTile();
    GameTile(const std::string&, float, float, bool, bool, bool);
    // ----- Accessors -----
    sf::Sprite& getSprite();
    bool getPassable();
    bool getSausagePassable();
    bool getIsGrill();
};

#endif