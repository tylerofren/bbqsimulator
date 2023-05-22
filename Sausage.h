#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>

using namespace std;

#ifndef SAUSAGE_H
#define SAUSAGE_H

enum cookState
{
    Raw,
    Cooked,
    Overcooked
};

class Sausage
{
private:
// Sausage properties
sf::Sprite sprite;

sf::Vector2f position;
bool horizontal;

// Error file
ofstream errorFile;

/*

bool topRightIsCooked;
bool topLeftIsCooked;
bool botRightIsCooked;
bool botLeftIsCooked;

int cookState;
*/

vector<cookState> partStates;
bool isFacingUp;
bool cookedOnCurrentGrill;



void loadTextures();
sf::Texture texture;
sf::Texture texture1;
sf::Texture texture2;
sf::Texture texture3;
sf::Texture texture4;
sf::Texture texture5;
sf::Texture texture6;
sf::Texture texture7;
sf::Texture texture8;








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

void setCookedOnCurrentGrill(bool);




// // Cooking
void cook(int);
void reset();

cookState getCookState(int);
void updateTexture();

bool getIsFacingUp();
bool getIsCookedOnCurrentGrill();

void flip();













};





































#endif