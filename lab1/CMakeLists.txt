cmake_minimum_required(VERSION 4.1)

project("lab1" CXX)

add_executable(lab1)

target_compile_features(common_mod PUBLIC cxx_std_23)

target_sources(lab1 PRIVATE main.cpp)

target_link_libraries(lab1 PRIVATE common_mod)
