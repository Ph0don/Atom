cmake_minimum_required(VERSION 3.10)

add_subdirectory(glfw)
target_include_directories(Atom PRIVATE glfw/include)


file(GLOB imguiSrc CONFIGURE_DEPENDS "imgui/*.h" "imgui/*.cpp")

add_library(imgui "${imguiSrc}")

if(WIN32)
target_sources(imgui PRIVATE imgui/backends/imgui_impl_win32.cpp
			    imgui/backends/imgui_impl_dx12.cpp)
endif()

# target_sources(imgui PRIVATE imgui/backends/imgui_impl_glfw.cpp
#			    imgui/backends/imgui_impl_vulkan.cpp)
target_include_directories(imgui PUBLIC imgui glfw/include)