# Lab Activity 1 – Hello World in SFML

## Goals
Practice writing and building simple C++ programs that leverage SFML.

## Instructions
For this Lab, we’re going to set up our develpoment environment and create a simple Hello World program that runs in a small graphical window.

### Your GitHub Repository

1. Join our GitHub org.
    1. If you have not done so already, send your GitHub username to your instructor and then check for an invitation email from GitHub.
    2. Accept the invitation to join our `Marist-CMPT414-GameProg` organization.
2. Create your own repository.
    1. Go to our organization's Web page at [https://github.com/Marist-CMPT414-GameProg](https://github.com/Marist-CMPT414-GameProg).
    2. Click the green `New` button to begin creating a new repository.
    3. Name your repository "lastname-work", where the "lastname" part is _your own last name_, not the literal string "lastname".
    4. Add a brief description such as "My lab and project work for Game Design & Programming I".
    5. Make certain that the repository visibility is set to `Private`.
    6. Check the box to `Add a README file`.
    7. Under the _Add .gitignore_ heading, click the drop-down list and find/select `Visual Studio`. (Note: If you are a Mac user with CLion IDE, then choose `CMake` instead.)
    8. Finally, click the green `Create repository` button.

### Visual Studio Solution and Project
If you are a Mac user with CLion IDE, you may skip these instructions. I don't have alternative instructions for you here. Sorry!

1. Launch Visual Studio (_not_ VSCode!).
2. From the Visual Studio splash screen, select `Clone a repository` under the "Get Started" heading.
3. Browse your GitHub repositories to find your newly created `lastname-work` repo, or copy and paste the GitHub clone URL from your repo's Web page. (Note: I've found the simply copying and pasting the URL is faster than letting Visual Studio search for it.)
4. Click the `Clone` button. When the process is complete, Visual Studio will open the newly cloned folder.
5. From the `File` menu, select `New`, then `Project...`, then search for and select `Blank Solution`.
6. Name the solution "GameProg1" and click the `Create` button.
7. Then, from the `File` menu or "Solution Explorer" panel, open your newly created solution.
8. From the `File` menu, select `New`, then `Project...`, then search for and select `Empty Project`. (Note: The description should say "Start from scratch with C++ for Windows...")
9. Name the project "Lab1" and in the "Solution" drop-down you must select `Add to solution` (_not_ "Create new solution").
10. Be sure to save your solution now!

### Get SFML

1. Download an appropriate SFML version from [https://www.sfml-dev.org/download/sfml/2.6.0/](https://www.sfml-dev.org/download/sfml/2.6.0/).
2. Extract the SMFL ZIP archive into your repository directory, but outside of your "GameProg1" solution folder. (Note: You may choose either 32-bit or 64-bit, but this choice will affect the setting you need to configure in Visual Studio.)

### First C++ Program
Now, we're going to write a very short C++ program that displays the message "Hello, World!" in a text console.

1. Be sure that you have your `Lab1` project open in Visual Studio.
2. Next, `Add` and `New file...` to your project. This file must be a "C++ File (.cpp)" and you shold name it `hello.cpp`.
3. Open your new `hello.cpp` file for editing (if it is not already).
4. Type (don't copy and paste you lazy coder!) the following code into your file and save:
    ```cpp
    #ifndef CPP_HELLO
    #define CPP_HELLO
    #include <iostream>
    int main(int argc, char** argv)
    {
        std::cout << "Hello, World!" << std::endl;
        return 0;
    }
    #endif CPP_HELLO
    ```
6. Press F5 or select `Start Debugging` from the `Debug` menu to launch your program.

### First SFML Program
Finally, we will update our program to display the message in a small, graphical window using SFML.

1. Modify your source code manually (no copy and paste!) to use SFML to create a window with a text message:

    ```cpp
    #ifndef CPP_HELLO
    #define CPP_HELLO
    
    #include <iostream>
    #include <SFML/Graphics.hpp>
    
    using namespace std;
    using namespace sf;
    
    int main()
    {
        cout << "Hello, World!" << endl;
    
        RenderWindow window({ 500, 250 }, "Lab 1", Style::Default);
    
        Font font;
        if (!font.loadFromFile("../../SFML-2.6.0/examples/opengl/resources/tuffy.ttf"))
            return 1;
    
        Text text("Hello World!", font, 75);
        text.setPosition(75, 75);
    
        while (true)
        {
            window.clear();
            window.draw(text);
            window.display();
        }
    
        return 0;
    }
    #endif CPP_HELLO
    ```
    2. Configure Visual Studio per your instructors verbal instructions (sorry! not sure what happened to my original instructions for this part of the lab!).
    3. Once again, press F5 or select `Start Debugging` from the `Debug` menu to launch your program.

## Deliverables
To receive full credit for this Lab activity:

- You must have a named Git repository under our class GitHub organization.
- That repository must contain a folder for your Lab1 project.
- Your Lab1 folder must contain both your source code and the necessary project configuration.
- Your code must compile and run successfully, and the program satisfy the requirements above.
  
