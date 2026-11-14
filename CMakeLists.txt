cmake_minimum_required(VERSION 3.20)
project(SuperMarioBrosXYZ)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(SuperMarioBrosXYZ
        main.cpp
        Colors.cpp
        Sprite.cpp
        Entity.cpp
        Player.cpp
        Goomba.cpp
        Block.cpp
        World.cpp
        Camera.cpp
        Game.cpp
)
