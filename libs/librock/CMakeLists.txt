CMAKE_MINIMUM_REQUIRED(VERSION 2.4)
IF(COMMAND CMAKE_POLICY)
	CMAKE_POLICY(SET CMP0003 OLD)
ENDIF(COMMAND CMAKE_POLICY)

PROJECT(librock)

SET(LIBROCK_SRC
hard/time/gmtime.c
librock/target/types.c
)

INCLUDE_DIRECTORIES(.)
ADD_LIBRARY(librock ${LIBROCK_SRC})

IF("${CMAKE_SYSTEM_PROCESSOR}" STREQUAL "x86_64" AND CMAKE_COMPILER_IS_GNUCC)
	SET_TARGET_PROPERTIES(librock PROPERTIES COMPILE_FLAGS "-fPIC ${COMPILE_FLAGS} -fPIC")
ENDIF("${CMAKE_SYSTEM_PROCESSOR}" STREQUAL "x86_64" AND CMAKE_COMPILER_IS_GNUCC)
