project	"DataStructures"
	location "DataStructures"
	kind "Utility"
	language "C++"
	cppdialect "C++17"
	systemversion "latest"
	
	includedirs {
		"%{prj.name}/include"
	}

	filter "configurations:Debug"
		defines { "DEBUG" }
		symbols "On"

	filter "configurations:Release"
		defines { "RELEASE" }
		optimize "On"
