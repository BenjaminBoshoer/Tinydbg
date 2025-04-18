cmake_minimum_required(VERSION 3.19)

project("Tinydbg" LANGUAGES CXX)

include(CTest)

find_package(PkgConfig REQUIRED)
pkg_check_modules(libedit REQUIRED IMPORTED_TARGET libedit)

add_subdirectory("src")
add_subdirectory("tools")

if(BUILD_TESTING)
	find_package(Catch2 CONFIG REQUIRED)
	add_subdirectory("test")
endif()
