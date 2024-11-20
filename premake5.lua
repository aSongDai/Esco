workspace "Esco"
    architecture "x64"

    configurations{
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Esco"
    location "Esco"
    kind "SharedLib"
    language "C++"
    
    -- 目标文件位置
    targetdir  ("bin/" .. outputdir .. "/%{prj.name}")
    objdir  ("bin-int/" .. outputdir .. "/%{prj.name}")

    files{
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs {
        "%{prj.name}/vendor/spdlog/include",
        "%{prj.name}/src"
    }

    -- 宏
    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines {
            "ESCO_PLATFORM_WINDOWS",
            "ESCO_BUILD_DLL",
            "FMT_"
        }
        
        postbuildcommands 
        {
            ("COPY %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }

    filter "configurations:Debug"
        defines {
            "ESCO_DEBUG"
        }
        symbols "On"
        buildoptions "/MTd"

    filter "configurations:Release"
        defines{
            "ESCO_RELEASE"
        }
        optimize "On"
    filter "configurations:Dist"
        defines{
            "ESCO_DIST"
        }
        optimize "On"

    filter {"system:windows", "configurations:Release"}
        buildoptions "/MT"


project "Sandbox"
    location "Sandbox"
    language "C++"
    kind "ConsoleApp"

    targetdir ("bin/" .. outputdir .. "%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "%{prj.name}")

    files {
        "%{prj.name}/src/**.cpp",
        "%{prj.name}/src/**.h"
    }
    includedirs {
        "Esco/vendor/spdlog/include",
        "Esco/src"
    }
    links {
        "Esco"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines {
            "ESCO_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines {
            "ESCO_DEBUG"
        }
        symbols "On"
    filter "configurations:Release"
        defines {
            "ESCO_RELEASE"
        }
        optimize "On"
    filter "configurations:Dist"
        defines{
            "ESCO_DIST"
        }
        optimize "On"
    filter {"system:windows", "configurations:Release"}
        buildoptions "/MT"
