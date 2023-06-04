#include <SFML/Graphics.hpp>
#include "Player.cpp"
#include "Sausage.cpp"

#ifndef GAMESTATE_H
#define GAMESTATE_H

/*
    Creates a GameState that saves sprite positions and rotations, as well as Sausage cook states.
*/

class GameState
{
private:
sf::Vector2f playerPosition;
sf::Vector2f sausagePosition;
sf::Vector2f sausage2Position;
int playerRotation;
vector<cookState> cookStates;
vector<cookState> cookStates2;
bool sausageDrowned;
bool sausage2Drowned;



public:
GameState();
~GameState();
GameState(sf::Vector2f, sf::Vector2f, sf::Vector2f, int, vector<cookState>, vector<cookState>, bool, bool);

// Accessors
sf::Vector2f getPlayerPosition();
sf::Vector2f getSausagePosition();
sf::Vector2f getSausage2Position();
int getPlayerRotation();
vector<cookState> getCookStates();
vector<cookState> getCookStates2();
bool getSausageDrowned();
bool getSausage2Drowned();




};

















#endif