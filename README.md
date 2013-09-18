# SFMLGamepadTest

A simple testbed application for working with gamepads in SFML.

## Dependencies

- [SFML 2.0](http://sfml-dev.org/download/sfml/2.0/)
- [premake4](http://industriousone.com/premake)

## Building the Project

Building the project is super simple but does require a bit of setup. Fortunately setup breaks down into a few steps:

1. Install all the dependencies.
2. Clone this repo.
3. Using the command line (Terminal on Mac, Powershell, or cmd.exe if you must, on Windows) `cd` into the root of the cloned repo (the folder with `main.cpp`, `paths.lua.sample`, etc. in it).
4. Open `paths.lua.sample` in your favorite text editor and save a new file based on it called `paths.lua`. `paths.lua` is used to point premake to the install locations of the SFML headers and libs. It is ignored by git.
5. In your copy of `paths.lua`,
    1. Replace "E:/absolute/path/to/SFML/headers" with the absolute path to the installed SFML headers (SFML's .hpp files) on your system.
    2. Replace "E:/absolute/path/to/SFML/libs" with the absolute path to the installed SFML libs (SFML's .a, .lib or .frameworks depending on your OS) on your system.
    3. Save `paths.lua`.
6. Use premake to generate a project for your favorite IDE.

Here are some examples of using premake to generate projects:

    # Generate a CodeBlocks project
    $ premake4 codeblocks

    # Generate an XCode 4 project
    $ premake4 xcode4

    # Generate a Visual Studio 2010 project
    $ premake4 vs2010

Once you have the project generated open it in your IDE and build away.

## Issues and Feedback

If you run into any issues please open a ticket [here](https://github.com/NoobsArePeople2/SFMLGamepadTest/issues).
You can email me with feedback at <a href="mailto:hello@seanmonahan.org?subject=SFMLGamepadTest">hello@seanmonahan.org</a>

## License

SFMLGamepadTest is licensed under the MIT license.