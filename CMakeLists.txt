cmake_minimum_required(VERSION 3.10)

project( Atom VERSION 0.0.1)

set(FullOutputDir "${CMAKE_SOURCE_DIR}/Build/${CMAKE_SYSTEM_NAME}/${CMAKE_BUILD_TYPE}")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${FullOutputDir}/sLibs")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${FullOutputDir}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${FullOutputDir}")

add_subdirectory(Atom)

add_subdirectory(Application)

add_subdirectory(Libraries)

if( CMAKE_CXX_COMPILER_ID MATCHES "MSVC" )
	# Startup Project
	set_property( DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT Application )
endif()
