workspace "CarSeller"
    configurations { "Debug", "Release" }
    platforms { "x64" }  -- Targeting x64 platform

project "CarSeller"
    kind "ConsoleApp"
    language "C++"
    targetdir ("bin/%{cfg.buildcfg}-%{cfg.platform}")

    files { 
        "src/**.h", 
        "src/**.cpp", 
        "include/**.h", 
        "include/**.hpp" 
    }

    includedirs { "include", os.getenv("BOOST_ROOT") }
    libdirs { os.getenv("BOOST_ROOT") .. "/stage/lib" }

    pchheader "include/pch.h"
    pchsource "src/pch.cpp"

    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On"
        buildoptions { "-std=c++17" }  

    filter "configurations:Release"
        defines { "NDEBUG" }
        optimize "On"
        buildoptions { "-std=c++17" } 
    filter "platforms:x64"
        architecture "x86_64"
        links {
            "boost_log_setup-mgw13-mt-d-x64-1_85",  
            "boost_log-mgw13-mt-d-x64-1_85"
        }

    defines { "BOOST_LOG_DYN_LINK" }

filter "files:src/**.cpp"
