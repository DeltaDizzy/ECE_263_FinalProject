cmake_minimum_required(VERSION 3.10)
project(SemesterProject VERSION 0.1.0 LANGUAGES C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)
set(CMAKE_BUILD_TYPE Debug)

set(SRC_DIR src/main)

add_executable(SemesterProject ${SRC_DIR}/proj_main.c ${SRC_DIR}/prj2.c)

target_compile_options(SemesterProject PRIVATE -WX)

target_link_libraries(SemesterProject ${CMAKE_SOURCE_DIR}/mailPrjLibrary.lib)

# required for includes
target_include_directories(SemesterProject PRIVATE src/include)
