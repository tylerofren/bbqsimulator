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


