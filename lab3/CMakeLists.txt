cmake_minimum_required(VERSION 4.1)

project("lab3" CXX)

add_executable(lab3)



target_sources(lab3 PRIVATE main.cpp)

target_link_libraries(lab3 PRIVATE common_mod)
