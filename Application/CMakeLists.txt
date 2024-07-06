cmake_minimum_required(VERSION 3.10)

add_executable(Application src/Entry.cpp)

target_include_directories( Application PUBLIC
	src
	../Framework/src
	../Libraries
)

target_compile_features(Application PRIVATE cxx_std_17)

target_link_libraries(Application Atom)