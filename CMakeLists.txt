cmake_minimum_required(VERSION 3.7)
project(reverse)

option(BUILD_SHARED_LIBS "Build dynamic libraries when on, static otherwise" ON)
set(CMAKE_CXX_STANDARD 11)

add_library(reverse src/reverse.cpp)
set_target_properties(reverse PROPERTIES OUTPUT_NAME "reverse")
target_include_directories(reverse PUBLIC
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>)
install(TARGETS reverse EXPORT ${PROJECT_NAME}Config
    DESTINATION lib)

install(DIRECTORY "${PROJECT_SOURCE_DIR}/include"
    DESTINATION .
    FILES_MATCHING PATTERN "*.h")
install(EXPORT ${PROJECT_NAME}Config
    DESTINATION "lib/cmake/${PROJECT_NAME}")

set(CPACK_INSTALL_CMAKE_PROJECTS
    "${PROJECT_BINARY_DIR}"
    reverse
    ALL
    /)
set(CPACK_PACKAGE_FILE_NAME reverse)
set(CPACK_GENERATOR TGZ ZIP)
include(CPack)
