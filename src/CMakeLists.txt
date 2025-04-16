add_library(libtdb libtdb.cpp)
add_library(tdb::libtdb ALIAS libtdb)

set_target_properties(
	libtdb
	PROPERTIES OUTPUT_NAME tdb
)

target_compile_features(libtdb PUBLIC cxx_std_17)

target_include_directories(
	libtdb
	PRIVATE include
	PUBLIC ${CMAKE_SOURCE_DIR}/include
)
