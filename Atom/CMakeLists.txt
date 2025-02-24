cmake_minimum_required(VERSION 3.10)

add_library(Atom)

target_sources(Atom PRIVATE
		 src/Application.cpp
		 src/Window.cpp
		 src/GraphicsContext.cpp)

if(WIN32)
target_compile_definitions(Atom PRIVATE AT_PLATFORM_WINDOWS)
target_include_directories(Atom PRIVATE src/Platform/Windows)
target_sources(Atom PRIVATE
		 src/Platform/Windows/Win32Window.cpp
         src/Platform/Windows/D3D12Context.cpp)
endif()

if(LINUX)
target_compile_definitions(Atom PRIVATE AT_PLATFORM_LINUX)
target_include_directories(Atom PRIVATE src/Platform/Linux)
target_sources(Atom PRIVATE src/Platform/Linux/GLFWWindow.cpp)
endif()

target_include_directories( Atom PUBLIC
	src
	../Libraries
)

target_compile_features(Atom PRIVATE cxx_std_17)

target_link_libraries(Atom PUBLIC glfw)
