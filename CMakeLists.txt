add_library(CustomPrint)

target_sources(CustomPrint
	PRIVATE
		src/CustomPrint.cpp

	PUBLIC
		FILE_SET myHeaders
		TYPE HEADERS
		BASE_DIRS src
		FILES
			CustomPrint.h
)
