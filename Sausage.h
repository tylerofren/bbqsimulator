#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <fstream>

using namespace std;

#ifndef SAUSAGE_H
#define SAUSAGE_H

/*
    Represents the cook state of each sausage part.
*/  
enum cookState
{
    Raw,
    Cooked,
    Overcooked
};

/*
    Sausage
*/
class Sausage
{
private:
    // ----- Sausage Properties -----
    sf::Sprite sprite;
    sf::Vector2f position;
    bool horizontal;
    bool isFacingUp;
    bool cookedOnCurrentGrill;
    /*
        Part states: (top = right)
        0 - Facing down, top
        1 - Facing down, bottom
        2 - Facing up, top
        3 - Facing up, bottom
    */
    vector<cookState> partStates; 
    bool drowned;

    // ----- Sounds -----
    // Sizzle
    sf::Sound sizzle;
    sf::SoundBuffer buffer;
    // Plop
    sf::Sound plop;
    sf::SoundBuffer plopBuffer;

    // ----- Textures -----
    /*
        0 - uncooked
        1 - top cooked, bottom raw
        2 - top raw, bottom cooked
        3 - top cooked, bottom cooked
        4 - top overcooked, bottom raw
        5 - top overcooked, bottom cooked
        6 - top overcooked, bottom overcooked
        7 - top raw, bottom overcooked
        8 - top cooked, bottom overcooked
    */
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

    // ----- Initialization -----
    void loadSizzle();
    void loadPlop();
    void loadTextures();

    // Debug
    ofstream errorFile;
public:
    // ----- Constructors -----
    Sausage();
    Sausage(float, float, bool);

    // ----- Accessors -----
    sf::Sprite getSprite();
    sf::Vector2f getPosition();
    sf::Vector2i getRows() const; // Returns both indexes of the sausage row position, in ascending order
    sf::Vector2i getColumns() const; // Returns both indexes of the sausage col position, in ascending order
    vector<cookState> getCookStates();
    bool getDrowned();
    bool getIsFacingUp();
    bool getIsCookedOnCurrentGrill();
    cookState getCookState(int);
    bool isHorizontal();

    // ----- Modifiers -----
    void setPosition(const sf::Vector2f);
    void setHorizontal(bool);
    void setCookedOnCurrentGrill(bool);
    void setCookStates(vector<cookState>);
    void drownSausage(bool);

    // ----- Void Functions -----
    void cook(int);
    void reset();
    void updateTexture();
    void flip();
};

#endif