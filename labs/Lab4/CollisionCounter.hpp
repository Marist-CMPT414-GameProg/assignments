#ifndef HPP_HUD
#define HPP_HUD

#include <SFML/Graphics.hpp>

class CollisionCounter {
public:
    CollisionCounter(sf::Font const& font, sf::Vector2f const& pos);
    void draw(sf::RenderWindow& target) const;
private:
    sf::Text text;
    int count;
};

#endif HPP_HUD
