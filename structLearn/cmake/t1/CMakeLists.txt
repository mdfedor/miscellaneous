cmake_minimum_required(VERSION 3.25.1)

project(FFFF)

add_executable(${PROJECT_NAME} main.cpp)

install(TARGETS ${PROJECT_NAME} DESTINATION bin)