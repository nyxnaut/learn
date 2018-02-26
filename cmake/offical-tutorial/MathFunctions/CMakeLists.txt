include_directories (${CMAKE_CURRENT_BINARY_DIR})

add_executable (MakeTable MakeTable.cpp)
add_custom_command (
	OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/Table.h
	COMMAND MakeTable ${CMAKE_CURRENT_BINARY_DIR}/Table.h
	DEPENEDS MakeTable
)

add_library (MathFunctions mysqrt.cpp ${CMAKE_CURRENT_BINARY_DIR}/Table.h)

install (TARGETS MathFunctions DESTINATION bin)
install (FILES MathFunctions.h DESTINATION include)
