#ifndef HPP_PLANET
#define HPP_PLANET

#include <SFML/Graphics.hpp>

class Planet {
public:
    Planet(sf::Texture const&, sf::Vector2f const&);
    void draw(sf::RenderWindow&) const;
    sf::FloatRect const& getCollider() const;
    //void hit(); // TODO uncomment and implement this method
private:
    sf::Sprite sprite;
};

#endif HPP_PLANET