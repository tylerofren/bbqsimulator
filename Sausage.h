#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
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

// Cooking sounds
sf::Sound sizzle;
sf::SoundBuffer buffer;


void loadSizzle();

// Plop sound
sf::Sound plop;
sf::SoundBuffer plopBuffer;

void loadPlop();




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

sf::Texture blankTexture;


bool drowned;





public:
Sausage();
Sausage(float, float, bool);


// Accessors
sf::Sprite getSprite();
sf::Vector2f getPosition();
sf::Vector2i getRows() const;
sf::Vector2i getColumns() const;
vector<cookState> getCookStates();
bool isHorizontal();

bool getDrowned();




// Modifiers
void setPosition(const sf::Vector2f);
void setHorizontal(bool);

void setCookedOnCurrentGrill(bool);

void setCookStates(vector<cookState>);

void drownSausage(bool);




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