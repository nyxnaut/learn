cmake_minimum_required(VERSION 3.9)
project(learnOpenGL)
set (CMAKE_CXX_STANDARD 11)

# sure I'm  missing the C in CMake but meh. it compiled. i'm tired.
# tomorrow's me can play with it

find_package(glfw3 REQUIRED)
find_package(OpenGL)
find_package(X11)
#find_package(Threads)

add_library(glad STATIC ${CMAKE_CURRENT_SOURCE_DIR}/lib/glad/glad.c)
target_include_directories(glad PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}/include/
)

add_executable(glfw-test glfw-test/test.cpp)
target_link_libraries(glfw-test
	glfw3
	${OPENGL_LIBRARIES}
	${X11_LIBRARIES}
	${CMAKE_DL_LIBS}
	${CMAKE_THREAD_LIBS_INIT}
)
add_executable(glad-test glad-test/test.cpp)
target_link_libraries(glad-test
	glfw3
	glad
	${OPENGL_LIBRARIES}
	${X11_LIBRARIES}
	${CMAKE_DL_LIBS}
	#${CMAKE_THREAD_LIBS_INIT}
)
