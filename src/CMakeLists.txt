file(GLOB SRCS "*.cpp")
file(GLOB INCS "inc/*.hpp")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/inc)

add_executable(${PROJECT_NAME} ${SRCS} ${INCS})

target_link_libraries(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/lib/libsfml-audio.dylib)
target_link_libraries(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/lib/libsfml-graphics.dylib)
target_link_libraries(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/lib/libsfml-system.dylib)
target_link_libraries(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/lib/libsfml-window.dylib)

include_directories(${CMAKE_SOURCE_DIR}/include)

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD_REQUIRED ON)