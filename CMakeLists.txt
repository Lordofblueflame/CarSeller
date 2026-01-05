cmake_minimum_required(VERSION 3.20)

project(CarSeller LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(CarSeller
    Source/main.cpp
    Source/Model/Car.cpp
    Source/Model/Owner.cpp
    Source/Infrastructure/EventEmitter.cpp
    Source/Controller/MarketController.cpp
)

target_include_directories(CarSeller PRIVATE
    Include
)
