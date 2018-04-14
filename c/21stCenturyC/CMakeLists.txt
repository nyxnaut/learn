cmake_minimum_required(VERSION 3.9)
project(learnC)
set(CMAKE_C_STANDARD 11)
set(CMAKE_BUILD_TYPE "Debug")


# find_package(Threads)
find_package(GSL)

add_executable(erf erf.c)
if(UNIX)
	target_link_libraries(erf
		m
	)
endif()
add_executable(gsl_erf gsl_erf.c)
target_link_libraries(gsl_erf
	${GSL_CBLAS_LIBRARY}
	${GSL_LIBRARY}	
)
