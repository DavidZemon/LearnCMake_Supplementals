cmake_minimum_required(VERSION 3.7)
project(LearnCMake_Supplementals)

set(CMAKE_CXX_STANDARD 11)

foreach (lib_type SHARED STATIC)
    add_library(reverse_${lib_type} ${lib_type} src/reverse.cpp)
    set_target_properties(reverse_${lib_type} PROPERTIES OUTPUT_NAME "reverse")
    target_include_directories(reverse_${lib_type} PUBLIC
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>)
    install(TARGETS reverse_${lib_type} EXPORT reverse
        DESTINATION lib)
endforeach ()

install(DIRECTORY "${PROJECT_SOURCE_DIR}/include"
    DESTINATION .
    FILES_MATCHING PATTERN "*.h")
install(EXPORT reverse
    DESTINATION .)

set(CPACK_INSTALL_CMAKE_PROJECTS
    "${PROJECT_BINARY_DIR}"
    reverse
    ALL
    /)
set(CPACK_PACKAGE_FILE_NAME reverse)
set(CPACK_GENERATOR TGZ ZIP)
include(CPack)
