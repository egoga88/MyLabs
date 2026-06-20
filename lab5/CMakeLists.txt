cmake_minimum_required(VERSION 4.1)

project("lab5" CXX)


add_executable(lab5 main.cpp)
add_library(lab5_utils)
target_sources(lab5_utils
    PUBLIC
    FILE_SET CXX_MODULES FILES lab5_utils.cppm
)

target_compile_features(lab5_utils PRIVATE cxx_std_23)


target_link_libraries(lab5 PRIVATE common_mod lab5_utils)