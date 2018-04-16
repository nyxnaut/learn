cmake_minimum_required(VERSION 3.9)
project(learnC)
set(CMAKE_C_STANDARD 11)
set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

# find_package(Threads)
find_package(GSL)
find_package(Readline)

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

add_executable(stddev_bugged stddev_bugged.c)
target_link_libraries(stddev_bugged
	m
)

add_executable(dynamic dynamic.c)
target_link_libraries(dynamic
	${CMAKE_DL_LIBS}
	${Readline_LIBRARY}
)
