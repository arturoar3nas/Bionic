cmake_minimum_required(VERSION 2.8)

file(GLOB SRC
    "*.h"
    "*.cpp"
)

project(Bionic)
add_executable(${PROJECT_NAME} ${SRC})
