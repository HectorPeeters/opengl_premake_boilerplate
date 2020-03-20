workspace "OpenGLBoilerPlate"
    configurations { "Debug", "Release" }

    flags { "MultiProcessorCompile" }

    filter "configurations:Debug"
        defines { "DEBUG", "DEBUG_SHADER" }
        symbols "On"

    filter "configurations:Release"
        defines { "RELEASE" }
        optimize "Speed"
        flags { "LinkTimeOptimization" }

include "libs/glfw.lua"
include "libs/glad.lua"
include "libs/glm.lua"

project "OpenGLBoilerPlate"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
	architecture "x86_64"

    targetdir "bin/%{cfg.buildcfg}"
    objdir "obj/%{cfg.buildcfg}"

    includedirs { "include/", "libs/glad/include/" }
    
    files { "src/main.cpp" }

    links { "GLFW", "GLM", "GLAD" }

    filter "system:linux"
        links { "dl", "pthread" }

        defines { "_X11" }

    filter "system:windows"
        defines { "_WINDOWS" }
