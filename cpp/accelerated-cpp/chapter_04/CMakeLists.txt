cmake_minimum_required(VERSION 3.2)
project(Accelerated_Cpp_Ch_04 LANGUAGES CXX)

add_library(median median.cc)
add_library(Student_info Student_info.cc)
add_library(grade grade.cc)

add_executable(function_compute_grades function_compute_grades.cc)
add_executable(grade_many_students grade_many_students.cc)
add_executable(grade_split_files grade_split_files.cc)

add_executable(calculate_squares-4-2 calculate_squares-4-2.cc)

target_link_libraries(grade
	PRIVATE Student_info median)

target_link_libraries(grade_split_files
	PRIVATE median grade Student_info)
