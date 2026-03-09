cmake_minimum_required(VERSION 3.16)
project(kelp)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(kelp
    src/main.cpp
    src/lexer.cpp
    src/token.cpp
)