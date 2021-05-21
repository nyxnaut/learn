cmake_minimum_required(VERSION 3.2)
project(Accelerated_Cpp_Ch_05 LANGUAGES CXX)

# Examples
add_library(c_grade grade.cc)
add_library(split split.cc)

add_executable(categorize_students categorize_students.cc)
add_executable(split_standalone split.cc)

target_link_libraries(c_grade
	PRIVATE Student_info median)

target_link_libraries(categorize_students
	PRIVATE median c_grade Student_info)

target_include_directories(categorize_students PRIVATE ../chapter_04)
target_include_directories(c_grade PRIVATE ../chapter_04)
