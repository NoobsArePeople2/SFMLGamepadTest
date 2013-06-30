-- See "paths.lua.sample" for instructions on creating the file.
dofile ("paths.lua")

LINKS = {}
if os.is("macosx") then

    KIND       = "WindowedApp"
    LINKS      = { "sfml-graphics.framework", "sfml-window.framework", "sfml-system.framework", "CoreFoundation.framework" }
    PLATFORMS  = { "x32" }
    BUILD_OPTS = "-std=c++11 -stdlib=libc++"
    LINK_OPTS  = "-stdlib=libc++"
    DEFINES    = ""

elseif os.is("windows") then

    KIND       = "ConsoleApp"
    LINKS      = { "sfml-graphics-s-d", "sfml-window-s-d", "sfml-system-s-d" }
    PLATFORMS  = {}
    BUILD_OPTS = ""
    LINK_OPTS  = ""
    DEFINES    = "SFML_STATIC"

end

solution "SFML Gamepad Test"
  configurations { "Debug", "Release" }

  project "SFML Gamepad Test"
    kind(KIND)
    language "C++"
    files { "**.h", "**.cpp", "**.hpp", "**.c", "**.ttf" }
    links(LINKS)
    libdirs(PATH_TO_SFML_LIB)
    includedirs(PATH_TO_SFML_INC)
    buildoptions(BUILD_OPTS)
    linkoptions(LINK_OPTS)
    defines(DEFINES)
    platforms(PLATFORMS)

    configuration "Debug"

    configuration "Release"
