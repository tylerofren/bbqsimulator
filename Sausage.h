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

bool topRightIsCooked;
bool topLeftIsCooked;
bool botRightIsCooked;
bool botLeftIsCooked;

int cookState;

// Error file
ofstream errorFile;






public:
Sausage();
Sausage(float, float, bool);


// Accessors
sf::Sprite getSprite();
sf::Vector2f getPosition();
bool isHorizontal();

// Modifiers
void setPosition(const sf::Vector2f);
void setHorizontal(bool);









};





































#endif