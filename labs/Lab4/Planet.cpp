#include "Planet.hpp"

using namespace sf;

Planet::Planet(Texture const& texture, Vector2f const& pos)
    : sprite(texture)
{
    sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
    sprite.setPosition(pos);
}

void Planet::draw(RenderWindow& target) const
{
    target.draw(sprite);
}

FloatRect const& Planet::getCollider() const
{
    return sprite.getGlobalBounds();
}
