# Lab Activity \#2 -- Spiraling out of Control

## Goals
Practice writing creating and manipulating sprites C++ with SFML.

## Instructions
For this Lab, we're going to create a simple app in which several Sprites moves in a regular pattern and the user can change their direction via a keyboard control.

1. __Lab Project__. In Visual Studio, "Add" a "New Project..." named `Lab2` to your existing Solution. (In CLion or other IDE, the steps are different but analogous.) _Important: Be sure to choose "Empty Project (C++)"_.
2. __Project Properties__. Configure your project to find SFML in the same way that we did in class and for Lab 1. This includes...
    - _Debugging_ > _Environment_ => `PATH=../../SFML-2.6.0/bin;$(PATH)`
    - _C/C++_ > _General_ > _Additional Include Directories_ => `../../SFML-2.6.0/include`
    - _Linker_ > _General_ > _Additional Library Directories_ => `../../SFML-2.6.0/lib`
    - _Linker_ > _Input_ > _Additional Dependencies_ => `sfml-window-d.lib;sfml-graphics-d.lib;sfml-system-d.lib;$(CoreLibraryDependencies);%(AdditionalDependencies)`
3. __Download Assets__. Download the three images located in the `resources` folder of this repo and place them in a new `graphics` subfolder of your local `Lab2` project.
3. __Version 1__. Write a short C++ program that uses the SFML library to display a static foreground sprite (`sunflower.png`) on top of a background sprite (`grass.png`) in a 500x500 window. Be sure to use the `sfml::View` class to make a View that matches the size of the background, in this case 1024x1024. Also check for user input so that you can quit the program if the user presses the Escape key. Test your program and then commit your changes!
4. __Version 2__. Add another foreground sprite (`bee.png`), but this time you will animate the sprite. Move the bee clockwise in a circle, indefinitely. The user should still be able to quit the program by pressing the Esc key. Again, test your program and then commit your changes!
5. __Version 3__. Define an `enum` class to represent the `Direction` of movement (clockwise or counter-clockwise). Then, make it possible for the user to switch the direction of movement of all the Sprites by pressing the Spacebar key. Feel free to add any other bells and whistles you like, as long as the above requirements are present. As always, test your program and then commit your changes!

_Tips_: You'll need a `main` function, and from SFML you will also need the classes `VideoMode`, `View`, `RenderWindow`, `Sprite`, and possibly others. You will also need to rely on some basic trigonometric functions like `sin` and `cos` to compute the position of the bee each frame!

# Deliverables
To receive full credit for this Lab activity:

- You must have a named Git repository under our class GitHub organization.
- That repository must contain a folder for your `Lab2` project.
- Your `Lab2` folder must contain both your source code and the necessary project configuration.
- Your code must compile and run successfully, and the program satisfy the requirements above.
- You must have a least three separate commits!