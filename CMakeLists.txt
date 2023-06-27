cmake_minimum_required(VERSION 3.0.0)

# project name
project(kociemba)
set(SRCDIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(INCDIR ${SRCDIR}/inc)

add_compile_options(-I ${INCDIR})

add_subdirectory(${SRCDIR})
add_subdirectory(${INCDIR})