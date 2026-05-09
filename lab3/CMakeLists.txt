cmake_minimum_required(VERSION 4.1)

project("lab3" CXX)

add_library(lab3_utils STATIC)

target_sources(lab3_utils
    PUBLIC
    FILE_SET CXX_MODULES FILES lab3_utils.cppm
)

target_compile_features(lab3_utils PUBLIC cxx_std_23)

add_executable(lab3 main.cpp)

target_link_libraries(lab3_utils PRIVATE common_mod)
target_link_libraries(lab3 PRIVATE common_mod lab3_utils)