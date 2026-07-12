cmake_minimum_required(VERSION 4.1.2) # XXX: switch to 4.2 when I update VS

project(Xeyday.Log
    DESCRIPTION "Logging for the Xeyday engine."
    HOMEPAGE_URL "https://github.com/Xeyday/log"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Variables
set(XEYDAY_LOG_DEPENDECIES_DIR "${CMAKE_CURRENT_SOURCE_DIR}/dependencies")

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

add_subdirectory(src)
add_subdirectory(tests)
