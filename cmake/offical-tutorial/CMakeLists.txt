cmake_minimum_required (VERSION 2.6)
project (Tutorial)

#Version numbering:
set (Tutorial_VERSION_MAJOR 1)
set (Tutorial_VERSION_MINOR 0)

include (CheckFunctionExists)
check_function_exists (log HAVE_LOG)
check_function_exists (exp HAVE_EXP)

# configure a header file to pass some of the CMake settings to source code:
configure_file (
	"${PROJECT_SOURCE_DIR}/TutorialConfig.h.in"
	"${PROJECT_BINARY_DIR}/TutorialConfig.h"
)

# add the binary tree to the search path for include files
# (needed to find TutorialConfig.h)
include_directories ("${PROJECT_BINARY_DIR}")

# we can optionally include libaries:
option (USE_MYMATH "Use tutorial provided math implementation" ON)

if (USE_MYMATH)
	include_directories ("${PROJECT_SOURCE_DIR}/MathFunctions")
	add_subdirectory (MathFunctions)
	set (EXTRA_LIBS ${EXTRA_LIBS} MathFunctions)
endif ()

# add the executable
add_executable (Tutorial tutorial.cpp)
target_link_libraries (Tutorial ${EXTRA_LIBS})

install (TARGETS Tutorial DESTINATION bin)
install (FILES "${PROJECT_BINARY_DIR}/TutorialConfig.h" DESTINATION include)

# enable testing
enable_testing ()

# does the application run
add_test (TutorialRuns Tutorial 25)

# does it sqrt of 25
add_test (TutorialComp25 Tutorial 25)
set_tests_properties (TutorialComp25
  PROPERTIES PASS_REGULAR_EXPRESSION "25 is 5"
)

# does it handle small numbers
add_test (TutorialSmall Tutorial 0.0001)
set_tests_properties (TutorialSmall
  PROPERTIES PASS_REGULAR_EXPRESSION "0.0001 is 0.01"
)

# does the usage message work?
add_test (TutorialUsage Tutorial)
set_tests_properties (TutorialUsage
  PROPERTIES
  PASS_REGULAR_EXPRESSION "Usage:.*number"
)

#define a macro to simplify adding tests
macro (do_test arg result)
  add_test (TutorialComp${arg} Tutorial ${arg})
  set_tests_properties (TutorialComp${arg}
    PROPERTIES PASS_REGULAR_EXPRESSION ${result}
    )
endmacro ()

# do a bunch of result based tests
do_test (4 "4 is 2")
do_test (9 "9 is 3")
do_test (5 "5 is 2.236")
do_test (7 "7 is 2.645")
do_test (25 "25 is 5")
do_test (0.0001 "0.0001 is 0.01")
