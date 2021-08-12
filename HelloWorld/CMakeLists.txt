cmake_minimum_required(VERSION 3.10.2)

# Specify your project's name
project(Main)

# Specify at least C++11, better C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable strict handling of warnings
add_definitions("-Wall -Wextra")


# Specify your app's executable name, and list of source files used to create it.
add_executable(Main
    src/Main.cpp
    # ... any other source files
)