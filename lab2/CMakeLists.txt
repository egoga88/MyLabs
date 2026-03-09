cmake_minimum_required(VERSION 4.1)

project("lab2" CXX)

add_executable(lab2)



target_sources(lab2 PRIVATE main.cpp)

target_link_libraries(lab2 PRIVATE common_mod)
