add_library(CustomPrint)

target_sources(CustomPrint
	PRIVATE
		src/CustomPrint.cpp

	PUBLIC
		FILE_SET myHeaders
		TYPE HEADERS
		BASE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}
		FILES
			src/CustomPrint.h
)
