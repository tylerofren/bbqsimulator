#include "Sausage.h"

Sausage::Sausage()
{

}


Sausage::Sausage(float x, float y, bool hor)
{
    if(!texture.loadFromFile("assets/sausage.png"))
    {
        errorFile.open("errors.txt");
        errorFile << "Failed to load sausage image" << endl;
        errorFile.close();
    }
    texture.setSmooth(true);
    sprite.setTexture(texture);
    sprite.setOrigin(25, 75);
    position = sf::Vector2f(x, y);
    sprite.setPosition(position);
    
    if(hor)
    {
        sprite.rotate(90);
    }
    horizontal = hor;

}

// ------ Accessors ---------

sf::Sprite Sausage::getSprite()
{
    return sprite;
}

sf::Vector2f Sausage::getPosition()
{
    return sprite.getPosition();
}

bool Sausage::isHorizontal()
{
    return horizontal;
}

// ------ Modifiers ------

void Sausage::setPosition(const sf::Vector2f pos)
{
    position = pos;
    sprite.setPosition(pos);    
}

void Sausage::setHorizontal(bool hor)
{
    if(hor)
    {
        sprite.rotate(90);
    }
    horizontal = true;
}