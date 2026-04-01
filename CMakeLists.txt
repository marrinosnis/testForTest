add_library(CustomPrint SHARED)


option(PRINT "just print a message when building" OFF)


if(PRINT)
   message("The customPrint lib was built")
endif()


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
