#include "CollisionCounter.hpp"

using namespace sf;

CollisionCounter::CollisionCounter(Font const& font, Vector2f const& pos)
    : text("0", font, 48u), count(0)
{
    text.setPosition(pos);
}

void CollisionCounter::draw(RenderWindow& target) const
{
    target.draw(text);
}
