-- See "paths.lua.sample" for instructions on creating the file.
dofile ( "paths.lua" )

LINKS = {}
if os.is("macosx") then

    KIND       = "WindowedApp"
    LINKS      = { "sfml-graphics.framework", "sfml-window.framework", "sfml-system.framework", "CoreFoundation.framework" }
    -- LINKS      = { "sfml-graphics-d", "sfml-window-d", "sfml-system-d", "CoreFoundation.framework" }
    PLATFORMS  = { "x32" }
    BUILD_OPTS = "-std=c++11 -stdlib=libc++"
    LINK_OPTS  = "-stdlib=libc++"
    DEFINES    = ""
    POST_BUILD_CMDS = { "scripts/copy-res-mac.sh" }

elseif os.is("windows") then

    KIND       = "ConsoleApp"
    LINKS      = { "sfml-graphics-s-d", "sfml-window-s-d", "sfml-system-s-d" }
    PLATFORMS  = {}
    BUILD_OPTS = ""
    LINK_OPTS  = ""
    DEFINES    = "SFML_STATIC"
    POST_BUILD_CMDS = {}

end

solution "SFML_Gamepad_Test"
  configurations { "Debug", "Release" }

  project "SFML_Gamepad_Test"
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
    postbuildcommands(POST_BUILD_CMDS)


    configuration "Debug"

    configuration "Release"
