workspace "OpenGLBoilerPlate"
    configurations { "Debug", "Release" }
    startproject "OpenGLBoilerPlate"

    flags { "MultiProcessorCompile" }

    filter "configurations:Debug"
        defines { "DEBUG", "DEBUG_SHADER" }
        symbols "On"

    filter "configurations:Release"
        defines { "RELEASE" }
        optimize "Speed"
        flags { "LinkTimeOptimization" }

project "OpenGLBoilerPlate"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
	architecture "x86_64"

    targetdir "bin/%{cfg.buildcfg}"
    objdir "obj/%{cfg.buildcfg}"

    includedirs { "include/", "libs/glad/include/", "libs/glfw/include/", "libs/glm/", "libs/imgui/", "libs/imgui/examples", "libs/imgui/backends" }
    
    files { "src/*.cpp" }

    links { "GLFW", "GLM", "GLAD", "ImGui" }

    filter "system:linux"
        links { "dl", "pthread" }

        defines { "_X11" }

    filter "system:windows"
        defines { "_WINDOWS" }

include "libs/glfw.lua"
include "libs/glad.lua"
include "libs/glm.lua"
include "libs/imgui.lua"