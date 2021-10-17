workspace "Banana"

	architecture "x64"
	
	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architechture}"

project "Banana"
	location "Banana"
	kind "Sharedlib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "on"
		systemversion "10.0.19041.0"

		defines
		{
			"BN_PlATFORM_WINDOWS",
			"BN_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "BN_DEBUG"
		symbols "On"

	filter "configurations:Realease"
		defines "BN_REALEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "BN_DIST"
		optimize "On"


project "Sandbox"
		location "Sandbox"
		kind "ConsoleApp"
		language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include",
		"Banana/src"
	}

	links
	{
		"Banana"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "on"
		systemversion "10.0.19041.0"


		defines
		{
			"BN_PlATFORM_WINDOWS"
		}


	filter "configurations:Debug"
		defines "BN_DEBUG"
		symbols "On"

	filter "configurations:Realease"
		defines "BN_REALEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "BN_DIST"
		optimize "On"

		