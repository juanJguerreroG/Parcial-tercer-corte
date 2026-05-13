cmake_minimum_required(VERSION 3.10)

project(MiProyecto)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML 3 REQUIRED COMPONENTS Graphics Window System)

add_executable(Juego 
        src/main.cpp 
        src/funciones.cpp
        )

target_include_directories(Juego PRIVATE include)

target_link_libraries(Juego PRIVATE
    SFML::Graphics
    SFML::Window
    SFML::System
)