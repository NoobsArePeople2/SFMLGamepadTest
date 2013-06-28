PATH_TO_SFML_LIB = { "E:/Dev/libs/SFML-sean-build/lib" }
PATH_TO_SFML_INC = { "E:/Dev/libs/SFML-sean/include" }

solution "SFML Gamepad Test"
  configurations { "Debug", "Release" }

  project "SFML Gamepad Test"
    kind "ConsoleApp"
    language "C++"
    files { "**.h", "**.cpp", "**.hpp", "**.c", "**.ttf" }
    links { "sfml-graphics-s-d", "sfml-window-s-d", "sfml-system-s-d" }
    libdirs(PATH_TO_SFML_LIB)
    includedirs(PATH_TO_SFML_INC)
    defines "SFML_STATIC"

    configuration "Debug"

    configuration "Release"
