#ifndef HPP_ASTEROID
#define HPP_ASTEROID

#include <SFML/Graphics.hpp>

class Asteroid {
public:
    Asteroid(sf::Texture const&, sf::Vector2f const & = sf::Vector2f(0, 0));
    void draw(sf::RenderWindow&);
    sf::FloatRect const& getCollider() const;
    void update(sf::Time const&);
    void setPosition(float, float);
    void setTexture(sf::Texture const&);
    void setVelocity(float, float);
    void spawn(sf::Vector2f const&, sf::Vector2f const&);
    void destroy();
private:
    sf::Sprite sprite;
    sf::Vector2f velocity;
};

#endif HPP_ASTEROID