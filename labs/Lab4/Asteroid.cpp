#include "Asteroid.hpp"
#include <iostream>

using namespace sf;

Asteroid::Asteroid(Texture const& texture, Vector2f const& pos)
    : sprite(texture), velocity(0, 0)
{
    sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
    sprite.setPosition(pos);
}

void Asteroid::destroy()
{
    sprite.setPosition(std::numeric_limits<float>::infinity(), std::numeric_limits<float>::infinity());
}

void Asteroid::draw(RenderWindow& target)
{
    target.draw(sprite);
}

FloatRect const& Asteroid::getCollider() const
{
    return sprite.getGlobalBounds();
}

void Asteroid::update(sf::Time const& dt)
{
    sprite.setPosition(sprite.getPosition() + dt.asSeconds() * velocity);
}

void Asteroid::setPosition(float x, float y)
{
    sprite.setPosition(x, y);
}

void Asteroid::setTexture(Texture const& texture)
{
    sprite.setTexture(texture);
}

void Asteroid::setVelocity(float dx, float dy)
{
    velocity.x = dx;
    velocity.y = dy;
    std::cerr << dx << " " << dy << std::endl;
}

void Asteroid::spawn(Vector2f const& from, Vector2f const& to)
{
    sprite.setPosition(from);
    velocity = (to - from) * (std::rand() / (0.5f * RAND_MAX));
    std::cerr <<"(" << sprite.getPosition().x << " " << sprite.getPosition().y << ")\n";
}
