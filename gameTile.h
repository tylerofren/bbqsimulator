#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

#ifndef GAMETILE_H
#define GAMETILE_H

/*
    Class that creates tiles to put in your level
*/

class GameTile
{

public:
sf::Texture texture;
sf::Sprite sprite;
GameTile(std::string, float, float);

sf::Sprite getSprite();


};









#endif