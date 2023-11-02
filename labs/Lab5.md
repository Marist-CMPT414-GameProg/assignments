# Lab Activity \#5 -- Handling Collisions

## Goals

Explore how to use modular and OOP design principles to tackle problems like collision resolution.

## Preparation

1. Create a new Project named `Lab4` in your `GameProg1` Visual Studio solution.
2. Configure yoru Project with the usual Properties for building with SFML.
3. Download the `graphics.zip` file from this repository and unzip it into your new Project folder.

## Part 1 - Initial Game Implementation

For this Lab, we will implement an initial version of the program with a keyboard-controlled `Bee` character. Then we will add static `Flower` obstacles. Finally, we will implement basic collision detection and resolution.

### A Texture Holder Singleton

Add to your Project a new header file named "TextureHolder.hpp" and a new source file named "TextureHolder.cpp". Use the code given below as your initial implementation.

__TextureHolder.hpp__
```cpp
#ifndef TEXTURE_HOLDER_H
#define TEXTURE_HOLDER_H

#include <SFML/Graphics.hpp>
#include <map>

class TextureHolder
{
public:
    static sf::Texture& GetTexture(std::string const& filename);

private:
    // Private/deleted constructors and assigment to enforce uniqueness
    TextureHolder();
    TextureHolder(TextureHolder const&) = delete;
    TextureHolder& operator=(TextureHolder const&) = delete;

    std::map<std::string, sf::Texture> m_Textures;

    static TextureHolder* m_s_Instance;
};

#endif
```

__TextureHolder.cpp__
```cpp
#include "TextureHolder.hpp"
#include <assert.h>

using namespace sf;
using namespace std;

TextureHolder* TextureHolder::m_s_Instance = nullptr;

TextureHolder::TextureHolder()
{
    assert(m_s_Instance == nullptr); // This should never happen!
    m_s_Instance = this;
}

sf::Texture& TextureHolder::GetTexture(std::string const& filename)
{
    static TextureHolder holder;

    auto& m = m_s_Instance->m_Textures;

    auto keyValuePair = m.find(filename);

    if (keyValuePair != m.end())
    {
        return keyValuePair->second;
    }
    else
    {
        auto& texture = m[filename];
        texture.loadFromFile(filename);
        return texture;
    }
}
```

### A Game Object Base Class

Add to your Project a new header file named "GameObject.hpp" and a new source file named "GameObject.cpp".

1. For the header file, the code is given below. Copy this into your header file and save.
2. For the implementation file, implement the three non-abstract methods as follows:
    - Constructor - set the texture from the string parameter, set the origin of the encapsulated sprite to be half the width and height of the sprite's bounds, and set the sprite position from the vector parameter
    - `draw` method - draw the sprite on the window
    - `getCollider` method - return the global bounds of the sprite

__GameObject.hpp__
```cpp
#ifndef HPP_GAMEOBJECT
#define HPP_GAMEOBJECT

#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>

struct GameObject
{
    virtual void draw(sf::RenderWindow&) const;
    virtual sf::FloatRect getCollider() const;

    virtual void update(sf::Time const& dt) = 0;

protected:
    GameObject(std::string const&, sf::Vector2f const&);

    sf::Sprite sprite;
};

#endif HPP_GAMEOBJECT
```
__GameObject.cpp__
```cpp
#include "GameObject.hpp"
#include "TextureHolder.hpp"

using namespace sf;

GameObject::GameObject(std::string const& textureFilename, Vector2f const& position)
{
    sprite.setTexture(TextureHolder::GetTexture(textureFilename));
    sprite.setOrigin(0.5f * getCollider().getSize());
    sprite.setPosition(position);
}

void
GameObject::draw(RenderWindow& win) const
{
    win.draw(sprite);
}

FloatRect
GameObject::getCollider() const
{
    return sprite.getGlobalBounds();
}
```

### The Bee Sub-Class

Add to your Project a new header file named "Bee.hpp" and a new source file named "Bee.cpp". Use the code given below as your initial implementation.

__Bee.hpp__
```cpp
#ifndef HPP_BEE
#define HPP_BEE

#include "GameObject.hpp"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <map>

class Bee : public GameObject
{
public:
    Bee(sf::Vector2f const&);

	void handleInput(sf::Event const& event);
	void handleKeyEvent(sf::Event::KeyEvent key, bool isPressed);
	void update(sf::Time const&);

private:
  float speed = 300.0f;
	sf::Vector2f velocity;

	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();
	void stopLeft();
	void stopRight();
	void stopUp();
	void stopDown();
};

#endif HPP_BEE
```

__Bee.cpp__
```cpp
#include "Bee.hpp"
#include "TextureHolder.hpp"

using namespace sf;


Bee::Bee(Vector2f const& position)
    : GameObject("graphics/bee.png", Vector2f(0, 0)), velocity()
{}

void
Bee::update(sf::Time const& dt)
{
    Vector2f prevPosition = sprite.getPosition();
    Vector2f newPosition = prevPosition + dt.asSeconds() * speed * velocity;
    sprite.setPosition(newPosition);
}

void
Bee::handleInput(Event const& event)
{
    if (event.type == Event::KeyPressed) {
        handleKeyEvent(event.key, true);
    }
    else if (event.type == Event::KeyReleased) {
        handleKeyEvent(event.key, false);
    }
}

void
Bee::handleKeyEvent(Event::KeyEvent key, bool isPressed)
{
    switch (key.code) {
    case Keyboard::W:
        isPressed ? moveUp() : stopUp();
        break;
    case Keyboard::S:
        isPressed ? moveDown() : stopDown();
        break;
    case Keyboard::A:
        isPressed ? moveLeft() : stopLeft();
        break;
    case Keyboard::D:
        isPressed ? moveRight() : stopRight();
        break;
    }
}

void Bee::moveLeft()
{
    velocity.x = -1;
}

void Bee::moveRight()
{
    velocity.x = 1;
}

void Bee::moveUp()
{
    velocity.y = -1;
}

void Bee::moveDown()
{
    velocity.y = 1;
}

void Bee::stopLeft()
{
    velocity.x = std::max(0.0f, velocity.x);
}

void Bee::stopRight()
{
    velocity.x = std::min(0.0f, velocity.x);
}

void Bee::stopUp()
{
    velocity.y = std::max(0.0f, velocity.y);
}

void Bee::stopDown()
{
    velocity.y = std::min(0.0f, velocity.y);
}
```

### The Main Function and Game Loop

Add to your Project a new source file named "Main.cpp". Use the code given below as your initial implementation.

__Main.cpp__
```cpp
#include <array>
#include <sstream>
#include <fstream>
#include <iostream>
#include "GameObject.hpp"
#include "Bee.hpp"
#include "TextureHolder.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace sf;

int const MAX_GAME_OBJS = 10;
using GameObjArray = std::array<GameObject*, MAX_GAME_OBJS>;

int main()
{
    // Forward declarations
    void configureWindow(RenderWindow&);
    void populateScene(GameObjArray&);
    void handleInput(RenderWindow&, GameObjArray const&);
    void update(Clock&, GameObjArray const&);
    void render(RenderWindow&, GameObjArray const&);

    GameObjArray gameObjects;
    populateScene(gameObjects);

    RenderWindow window;
    configureWindow(window);

    // The main game loop
    Clock clock;
    while (window.isOpen())
    {
        handleInput(window, gameObjects);
        update(clock, gameObjects);
        render(window, gameObjects);
    }

    return 0;
}

// Handle input for the game loop
void handleInput(RenderWindow& window, GameObjArray const& gameObjects)
{
    Event event;
    while (window.pollEvent(event))
    {
        if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape) {
            window.close();
        }

        dynamic_cast<Bee*>(gameObjects[0])->handleInput(event);
    }
}

// Update the game incrementally by one frame
void update(Clock& clock, GameObjArray const& gameObjects)
{
    Time dt = clock.restart();
    float dtAsSeconds = dt.asSeconds();

    for (auto obj : gameObjects) {
        if (obj) { obj->update(dt); }
    }
}

// Draw the game world
void render(RenderWindow& window, GameObjArray const& gameObjects)
{
    window.clear();

    for (auto obj : gameObjects) {
        if (obj) { obj->draw(window); }
    }

    window.display();
}

// Helper functions

void configureWindow(RenderWindow& window)
{
    Vector2f resolution;
    resolution.x = VideoMode::getDesktopMode().width;
    resolution.y = VideoMode::getDesktopMode().height;

    View mainView(sf::FloatRect(0, 0, 2160, 1440));
    window.create(VideoMode(resolution.x, resolution.y), "Collisions Demo", Style::Fullscreen);
    window.setView(mainView);
}

void populateScene(GameObjArray& gameObjects)
{
    gameObjects[0] = new Bee(Vector2f(0, 0));
    for (int i = 1; i < gameObjects.size(); ++i) {
        gameObjects[i] = nullptr;
    }
}
```

## Part 2 - Initial Game Implementation

Next, we will implement several incremental changes to our program, culminating in a simple but functioning collision system.

1. Add a `Flower` class that also extends the base `GameObject`. Flowers don't handle input nor move at all.
2. Populate your scene with several Flowers, being sure to leave space between them for the Bee to move through.
3. Add to the Bee class a new memebr variable named `prevPosition` and a new method named `cancelMove`. Updating the Bee should always record the current position as the `prevPosition`, and cancelling a move should restore the Bee to that position.
4. Add a new helper function named `checkCollisions` that you will call from with the game loop's `update` function. This function must loop through the list of all game objects, checking each one for collision with the Bee. If there is a collision, then cancel the Bee's movement.
5. Test your program, and debug until it works!

# Deliverables
To receive full credit for this Lab activity:

- You must have a named Git repository under our class GitHub organization.
- That repository must contain a folder for your `Lab5` project.
- Your `Lab5` folder must contain both your source code and the necessary project configuration.
- Your code must compile and run successfully, and the program satisfy the requirements above.
