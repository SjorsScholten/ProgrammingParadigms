workspace "ProgrammingParadigms"
    architecture "x64"
    configurations { "Debug", "Release" }

    filter "system:windows"
        systemversion "latest"

    filter "configurations:Debug"
        defines "DEBUG"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        defines "NDEBUG"
        runtime "Release"
        optimize "on"

    filter {}

    outputdir = "%{cfg.buildcfg}-%{cfg.architecture}-%{cfg.system}"
    
    targetdir ("bin/" .. outputdir .. "%{prj.name}")
    objdir ("bin/int/" .. outputdir .. "%{prj.name}")

project "DOD.ParticleEngine"
    language "C++"
    cppdialect "C++17"
    location "%{prj.name}"
    kind "ConsoleApp"

    files {
        "vendor/Glad/src/*.c",

        "%{prj.name}/**/**.hpp",
        "%{prj.name}/**/**.cpp",
        "%{prj.name}/**/**.glsl"
    }
    
    includedirs {
        "vendor/**/include",

        "%{prj.name}/include"
    }

    libdirs "vendor/GLFW/lib"

    links "glfw3"