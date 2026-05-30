cmake_minimum_required(VERSION 4.1)

project("lab3" CXX)

add_library(lab3_utils STATIC)

target_sources(lab3_utils
    PUBLIC
    FILE_SET CXX_MODULES FILES lab3_utils.cppm
)

add_library(classes STATIC)

target_sources(classes
    PUBLIC
    FILE_SET CXX_MODULES FILES classes.cppm
)

target_compile_features(classes PUBLIC cxx_std_23)

target_compile_features(lab3_utils PUBLIC cxx_std_23)

add_executable(lab3 main.cpp)

target_link_libraries(lab3_utils PRIVATE classes common_mod)
target_link_libraries(lab3 PRIVATE common_mod lab3_utils classes)