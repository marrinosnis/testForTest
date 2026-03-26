add_library(CustomPrint)

target_sources(CustomPrint
	PUBLIC
		TYPE HEADERS
		BASE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}
		FILES
			CustomPrint.h
	PRIVATE
		${CMAKE_CURRENT_SOURCE_DIR}/CustomPrint.cpp
)
