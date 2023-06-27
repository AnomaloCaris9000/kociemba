file(GLOB SRCS "*.cpp")
file(GLOB INCS "inc/*.hpp")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/inc)

add_executable(${PROJECT_NAME} ${SRCS} ${INCS})