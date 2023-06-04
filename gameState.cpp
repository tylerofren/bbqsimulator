#include "gameState.h"

GameState::GameState()
{

}

GameState::~GameState()
{
    
}

GameState::GameState(sf::Vector2f playerPos, sf::Vector2f sausagePos, sf::Vector2f sausage2Pos, int playerRot, vector<cookState> partStates, vector<cookState> partStates2, bool drowned, bool drowned2)
{
    playerPosition = playerPos;
    sausagePosition = sausagePos;
    sausage2Position = sausage2Pos;
    playerRotation = playerRot;
    cookStates = partStates;
    cookStates2 = partStates2;
    sausageDrowned = drowned;
    sausage2Drowned = drowned2;
}

sf::Vector2f GameState::getPlayerPosition()
{
    return playerPosition;
}

sf::Vector2f GameState::getSausagePosition()
{
    return sausagePosition;
}

sf::Vector2f GameState::getSausage2Position()
{
    return sausage2Position;
}

int GameState::getPlayerRotation()
{
    return playerRotation;
}

vector<cookState> GameState::getCookStates()
{
    return cookStates;
}

vector<cookState> GameState::getCookStates2()
{
    return cookStates2;
}

bool GameState::getSausageDrowned()
{
    return sausageDrowned;
}

bool GameState::getSausage2Drowned()
{
    return sausage2Drowned;
}

