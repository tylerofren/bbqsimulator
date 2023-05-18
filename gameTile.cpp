#include "gameTile.h"

GameTile::GameTile()
{

}

GameTile::GameTile(const std::string& textureName, float x, float y)
{
    if(!texture.loadFromFile(textureName))
    {   
        errorFile.open("errors.txt");
        errorFile << "failed to load image" << endl;
        errorFile.close();
    }
    position = sf::Vector2f(x, y);
    texture.setSmooth(true);
    sprite.setTexture(texture);
    sprite.setPosition(position);
    sprite.setTextureRect(sf::IntRect(0, 0, 50, 50));
}

sf::Sprite& GameTile::getSprite()
{
    return sprite;
}



