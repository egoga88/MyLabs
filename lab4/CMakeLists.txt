cmake_minimum_required(VERSION 4.1)

project("lab4" CXX)
add_library(lab4_utils STATIC)
target_sources(lab4_utils
    PUBLIC
    FILE_SET CXX_MODULES FILES lab4_utils.cppm
)

target_compile_features(lab4_utils PUBLIC cxx_std_23)


add_executable(lab4 main.cpp)

target_link_libraries(lab4 PRIVATE common_mod)
target_link_libraries(lab4 PRIVATE common_mod lab4_utils)