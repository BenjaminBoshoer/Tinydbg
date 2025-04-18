find_package(Catch2 REQUIRED)

add_executable(tests tests.cpp)
target_link_libraries(tests PRIVATE tdb::libtdb Catch2::Catch2WithMain)
