add_library(CustomPrint)

target_sources(CustomPrint
	PRIVATE
		${CMAKE_CURRENT_SOURCE_DIR}/src/CustomPrint.cpp

	PUBLIC
		FILE_SET myHeaders
		TYPE HEADERS
		BASE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/src
		FILES
			CustomPrint.h
)
