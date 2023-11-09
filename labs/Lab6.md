# Lab Activity \#5 -- Handling Collisions

## Goals

Explore how to apply the _State_ design pattern for controlling a simple AI entity.

## Preparation

1. Download the `StateMachine.zip` file from this repository, unzip it into your `GameProg1` solution directory.
2. Open your `GameProg1` solution, go to "Add existing Project..." and then find and select the State Machine VC++ project file.
3. Update your Project cofniguration with the usual Properties for building with SFML, if necessary.
4. Build the program and run it to verify that the program compiles and does not crash.

## Instructions

In this Lab, the `Player` controls a _Hand_ sprite that can be used to activate one of three `Trigger`s, and the `Bee` is now a computer-controlled entity that responds to those triggers.

Your job is to implement a simple state machine for the `Bee` can switch among three distinct behaviors:

- __Idle__ - entering the idle state stops the bee's movement and while in the idle state the bee remains still.
- __Orbit__ - in the orbit state, the Bee simply flies in a circlular path around its focal point (i.e., the center of the `Flower`)
- __Wander__ - in the wander state, the Bee flies around randomly, but ideally never strays too far from its focal point

The `Bee` should respond to the `Trigger`s as follows:

- The _Red_ trigger makes the Bee enter the idle state.
- The _Green_ trigger makes the Bee enter the orbit state.
- The _Blue_ trigger makes the Bee enter the wander state.

_Advice:_ Make one state at a time, and be sure to test your program frequently.

## Optional Followup Work

For more practice with the _State_ pattern, you can try creating an entirely new kind of game object and implement a different state machine for that object.

# Deliverables
To receive full credit for this Lab activity:

- You must have a named Git repository under our class GitHub organization.
- That repository must contain a folder for your `Lab6` project.
- Your `Lab6` folder must contain both your source code and the necessary project configuration.
- Your code must compile and run successfully, and the program satisfy the requirements above.
