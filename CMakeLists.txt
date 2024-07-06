cmake_minimum_required(VERSION 3.10)

project( Atom VERSION 0.0.1)

add_subdirectory(Atom)

add_subdirectory(Application)

add_subdirectory(Libraries)

if( CMAKE_CXX_COMPILER_ID MATCHES "MSVC" )
	# Startup Project
	set_property( DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT Application )
endif()