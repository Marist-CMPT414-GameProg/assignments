#include <array>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Planet.hpp"
#include "Asteroid.hpp"
#include "CollisionCounter.hpp"

using namespace sf;

template <size_t N>
void resetAsteroids(std::array<Asteroid, N>&, Vector2f const&, bool = false);

int main()
{
    VideoMode vm(1024, 1024);
    RenderWindow window(vm, "Lab #2");
    View view(sf::FloatRect(0, 0, 1024, 1024));
    window.setView(view);

    Clock clock;
    float timeElapsed = 0;

    Vector2f center(512, 512);
    float radius = 360;
    float angle = 0;

    Font font;
    if (!font.loadFromFile("../../SFML-2.6.0/examples/opengl/resources/tuffy.ttf")) {
        std::cerr << "Failed to load font file!" << std::endl;
        return 1;
    }

    bool acceptInput = true;

    Texture textureBackground;
    textureBackground.loadFromFile("graphics/space.png");
    Sprite spriteBackground;
    spriteBackground.setTexture(textureBackground);
    spriteBackground.setOrigin(0, 0);
    spriteBackground.setPosition(0, 0);
    spriteBackground.setScale(2, 2);

    Texture texturePlanet;
    texturePlanet.loadFromFile("graphics/planet.png");
    Planet planet(texturePlanet, center);

    CollisionCounter hudCounter(font, Vector2f(24, 24));

    const int MAX_ASTEROIDS = 5;
    Texture textureAsteroid;
    textureAsteroid.loadFromFile("graphics/moon.png");
    std::array<Asteroid,MAX_ASTEROIDS> asteroids = {
        Asteroid(textureAsteroid),
        Asteroid(textureAsteroid),
        Asteroid(textureAsteroid),
        Asteroid(textureAsteroid),
        Asteroid(textureAsteroid)
    };
    resetAsteroids(asteroids, center);

    while (window.isOpen())
    {
        Time dt = clock.restart();
        timeElapsed += dt.asSeconds();
        std::srand(std::time(0));

        /**** HANDLE INPUT ****/

        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type) {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::KeyReleased:
                acceptInput = true;
                break;
            case sf::Event::KeyPressed:
                switch (event.key.code) {
                case Keyboard::Escape:
                    window.close();
                    break;
                case Keyboard::Space:
                    if (acceptInput)
                    {
                        acceptInput = false;
                        resetAsteroids(asteroids, center, true);
                    }
                    break;
                default:
                    break;
                }
                break;
            default:
                break;
            }
        }

        /**** UPDATE ****/

        for (int i = 0; i < MAX_ASTEROIDS; i++)
        {
            asteroids[i].update(dt);
            if (asteroids[i].getCollider().contains(center)) {
                std::cerr << "Hit by asteroid " << i << "!\n";
                //planet.hit(); // TODO uncomment after this method is implemented
                asteroids[i].destroy();
            }
        }

        /**** RENDER ****/

        window.clear();
        window.draw(spriteBackground);
        planet.draw(window);
        for (int i = 0; i < MAX_ASTEROIDS; i++)
        {
            asteroids[i].draw(window);
        }
        hudCounter.draw(window);
        window.display();
    }

    return 0;
}

template <size_t N>
void resetAsteroids(std::array<Asteroid,N>& asteroids, Vector2f const& center, bool inMotion)
{
    std::cerr << "Resetting!" << asteroids.size() << std::endl;
    const int RADIUS = 512;
    for (int i = 0; i < asteroids.size(); i++)
    {
        float angle = 2 * std::acos(-1) * i / asteroids.size();
        float dx = std::cos(angle) * RADIUS;
        float dy = std::sin(angle) * RADIUS;
        Vector2f pos(center.x + dx, center.y + dy);
        asteroids[i].spawn(pos, inMotion ? center : pos);
    }
}