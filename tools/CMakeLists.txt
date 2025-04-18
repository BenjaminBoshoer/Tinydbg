add_executable(tdb tdb.cpp)
target_link_libraries(tdb PRIVATE tdb::libtdb PkgConfig::libedit)

include(GNUInstallDirs)
install(
	TARGETS tdb
	RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
