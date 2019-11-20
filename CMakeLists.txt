cmake_minimum_required(VERSION 2.8.12)
project(demo-ci-conan)

include(${CMAKE_CURRENT_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)

set(SOURCES src/libH.cpp)
file(GLOB HEADERS include/libH/*)

add_library(libH ${SOURCES} ${HEADERS})
set_target_properties(libH PROPERTIES CXX_STANDARD 17)
target_link_libraries(libH PRIVATE CONAN_PKG::libA CONAN_PKG::libE)

target_include_directories(
    libH PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

install(TARGETS libH
        RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}/bin
        LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
        ARCHIVE DESTINATION ${CMAKE_INSTALL_PREFIX}/lib)
install(FILES ${HEADERS}
        DESTINATION ${CMAKE_INSTALL_PREFIX}/include/libH
        PERMISSIONS OWNER_WRITE OWNER_READ GROUP_READ WORLD_READ)
