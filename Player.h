#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <fstream>

using namespace std;

#ifndef PLAYER_H
#define PLAYER_H

class Player
{
private:
// Player properties
sf::Sprite sprite;
sf::Texture texture;
sf::Vector2f position;
int rotation;






// Error file
ofstream errorFile;




public:
Player(float, float, int);
Player();

bool isHorizontal();

// Accessors
sf::Vector2f getPosition();
sf::Sprite getSprite();
int& getRotation();



// Only includes player
int getRow() const;
int getColumn() const;
// Includes player and fork
sf::Vector2i getRows() const;
sf::Vector2i getColumns() const;

// Modifiers
void setPosition(const sf::Vector2f);
void setRotation(const int);




};














#endif