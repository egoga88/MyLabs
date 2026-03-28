cmake_minimum_required(VERSION 4.1)

project("lab2" CXX)



add_library(lab2_utils STATIC)

target_sources(lab2_utils
    PUBLIC
    FILE_SET CXX_MODULES FILES lab2_utils.cppm
)

target_compile_features(lab2_utils PUBLIC cxx_std_23)

add_executable(lab2 main.cpp)

target_link_libraries(lab2_utils PRIVATE common_mod)
target_link_libraries(lab2 PRIVATE common_mod lab2_utils)

