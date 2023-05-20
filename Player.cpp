#include "Player.h"

Player::Player()
{

}

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
    sprite.setOrigin(25, 75);
    position = sf::Vector2f(x, y);
    sprite.setPosition(position);

    sprite.rotate(rot * 90);



    rotation = rot;

}

sf::Vector2f Player::getPosition()
{
    return sprite.getPosition();
}

int& Player::getRotation()
{
    return rotation;
}

sf::Sprite Player::getSprite()
{
    return sprite;
}

sf::Vector2i Player::getRows() const
{
    if(rotation == 2) // Not horizontal
    {
        return sf::Vector2i((position.y - 25) / 50, (position.y - 25) / 50 + 1);
    }
    else if(rotation == 0)
    {
        return sf::Vector2i((position.y - 25) / 50 - 1, (position.y - 25) / 50);
    }
    return sf::Vector2i((position.y - 25) / 50, (position.y - 25) / 50);
}

sf::Vector2i Player::getColumns() const
{
    if(rotation == 1)
    {
        return sf::Vector2i((position.x - 25) / 50, (position.x - 25) / 50 + 1);
    }
    else if(rotation == 3)
    {
        return sf::Vector2i((position.x - 25) / 50 - 1, (position.x - 25) / 50);
    }
    return sf::Vector2i((position.x - 25) / 50, (position.x - 25) / 50);
}

int Player::getRow() const
{
    return static_cast<int>((position.y - 25) / 50.f);
}

int Player::getColumn() const
{
    return static_cast<int>((position.x - 25) / 50.f);
}


bool Player::isHorizontal()
{
    return rotation % 2 != 0;
}








void Player::setPosition(const sf::Vector2f pos)
{
    position = pos;
    sprite.setPosition(pos);
}

void Player::setRotation(const int rot)
{
    rotation = rot;
    sprite.setRotation(rot * 90);
}


