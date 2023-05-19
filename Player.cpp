#include "Player.h"

Player::Player(float x, float y, int rot)
{
    if(!texture.loadFromFile("assets/player.png"))
    {
        errorFile.open("errors.txt");
        errorFile << "Failed to load player image" << endl;
        errorFile.close();
    }
    texture.setSmooth(true);

    sprite.setTexture(texture);
    position = sf::Vector2f(x, y);
    sprite.setPosition(position);
    rotation = rot;

}

sf::Vector2f& Player::getPosition()
{
    return position;
}

int& Player::getRotation()
{
    return rotation;
}

sf::Sprite Player::getSprite()
{
    return sprite;
}

void Player::setPosition(const sf::Vector2f pos)
{
    sprite.setPosition(pos);
}

void Player::setRotation(const int rot)
{
    rotation = rot;
}


