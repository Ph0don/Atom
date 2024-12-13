cmake_minimum_required(VERSION 3.10)

add_library(Atom src/Application.h
		 src/Application.cpp
		 src/Window.h
		 src/Window.cpp
		 src/Win32Window.h
		 src/Win32Window.cpp
		 src/GraphicsContext.h
		 src/GraphicsContext.cpp
		 src/D3D12Context.h
		 src/D3D12Context.cpp)

if(WIN32)
target_compile_definitions(Atom PRIVATE AT_PLATFORM_WINDOWS)

endif()

if(LINUX)
target_compile_definitions(Atom PRIVATE AT_PLATFORM_WINDOWS)
endif()

target_include_directories( Atom PUBLIC
	src
	../Libraries
)

target_compile_features(Atom PRIVATE cxx_std_17)

target_link_libraries(Atom PUBLIC glfw)
