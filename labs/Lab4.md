# Lab Activity \#4 -- Applying the Observer Pattern

## Goals

Practice applying the _Observer_ design pattern ina practical C++ SFML example.

## Preparation

1. First, download the `Lab4` starter code from my `johnson-work` repository.
2. Place the entire `Lab4` folder into your `GameProg1` Visual Studio solution folder alongside your other projects.
3. Then, _Add_ the _Existing Project..._ to your solution.

## Instructions

For this Lab, you are refactoring existing code in order to apply a design pattern that is not already used in the code.

1. __Base Classes__. First, define a `Subject` class, an `Event` struct, and an `Observer` interface.
    - Note: You may follow the example we studied in the my _Patterns_ project, but with a two changes: the `Subject::notify` method must take in an `Event` object, and the `Observer::onNotify` method must be _pure virtual_.
2. __Extend Subject__. The `Planet` class will act as the subject in this pattern, and thus must extend the base `Subject` class.
    - You must implement the `hit` method so that it creates an appropriate `Event` instance and then calls `notify`.
3. __Extend Observer__. The `CollisionCounter` class will act as the observer in this pattern, and thus must extend the base `Observer` class.
    - You must implement the `onNotify` method so that it updates the collision count and displays the correct text.
4. __Connect the Two__. In the `main` function, be sure to add the `CollisioCounter` observer to the `Planet` subject before the game loop starts.
5. __Test It__. Re-build and run your program to ensure that it works correctly. Press the spacebar to launch the asteroids and watch the counter increase with each hit.

# Deliverables
To receive full credit for this Lab activity:

- You must have a named Git repository under our class GitHub organization.
- That repository must contain a folder for your `Lab4` project.
- Your `Lab4` folder must contain both your source code and the necessary project configuration.
- Your code must compile and run successfully, and the program satisfy the requirements above.
