#include "gameTile.h"

GameTile::GameTile(std::string textureName, float x, float y)
{
    if(!texture.loadFromFile(textureName))
    {
        cout << "failed to load image" << endl;
    }
    texture.setSmooth(true);
    sprite.setTexture(texture);
    // Only takes 50x50 part of the image
    sprite.setTextureRect(sf::IntRect(0, 0, 50, 50)); 
    sprite.setPosition(sf::Vector2(x, y));
}


sf::Sprite GameTile::getSprite()
{
    return sprite;
}


