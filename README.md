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

## Controller Mappings

Controller mappings are a listing of the physical buttons on a given joystick or gamepad and the corresponding index or axis. The goal of this project is produce a large listing of button mappings for Windows, Mac and Linux.

Mappings live in the `mappings/` folder and are categorized by platforms. The actual mapping files are JSON and named with the following convention:

    controllerName-driverName-driverMode.json

Both `driverName` and `driverMode` are optional. For example, for the 360 pad on Windows the file is simply called `xbox-360.json` as Microsoft provides and official driver on Windows with minimal configuration (it's as plug-and-play as it gets). However, to use a Dual Shock 3 you must use a third party driver which has a ton of configuration options. In this case the file name calls those out to differentiate it from other potential configurations for a Dual Shock 3.

As I only have a few different types of controllers I would love to have others contribute mappings for different pads (Logitech pads, Wiimotes, etc.) so SFML developers can have a comprehensive list of gamepad button mappings.

If you have a mapping to contribute send it to me at <a href="mailto:hello@seanmonahan.org?subject=SFML Gamepad Mapping">hello@seanmonahan.org</a>. Please stick to the naming convention described above as well as the format used in the JSON files themselves.

## Issues and Feedback

If you run into any issues please open a ticket [here](https://github.com/NoobsArePeople2/SFMLGamepadTest/issues).
You can email me with feedback at <a href="mailto:hello@seanmonahan.org?subject=SFMLGamepadTest">hello@seanmonahan.org</a>

## License

SFMLGamepadTest is licensed under the MIT license.