#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>

using namespace std;

#ifndef SAUSAGE_H
#define SAUSAGE_H

class Sausage
{
private:
// Sausage properties
sf::Sprite sprite;
sf::Texture texture;
sf::Vector2f position;
bool horizontal;

/*
Cooking variables, do these later, movement first
bool topRightIsCooked;
bool topLeftIsCooked;
bool botRightIsCooked;
bool botLeftIsCooked;

int cookState;
*/

// Error file
ofstream errorFile;






public:
Sausage();
Sausage(float, float, bool);


// Accessors
sf::Sprite getSprite();
sf::Vector2f getPosition();
sf::Vector2i getRows() const;
sf::Vector2i getColumns() const;
bool isHorizontal();

// Modifiers
void setPosition(const sf::Vector2f);
void setHorizontal(bool);









};





































#endif