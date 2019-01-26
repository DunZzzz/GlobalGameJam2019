#
# CMakeLists.txt
# Copyright (C) 2018 emilien <emilien@emilien-pc>
#
# Distributed under terms of the MIT license.
#

CMAKE_MINIMUM_REQUIRED(VERSION 3.10)

PROJECT(client CXX)
SET(GRAPH_LIB "graphical")

SET(CMAKE_CXX_STANDARD 14)

set(CMAKE_EXPORT_COMPILE_COMMANDS OFF)

SET(CMAKE_CXX_FLAGS "-O1")
SET(CMAKE_CXX_FLAGS_RELEASE "-O2 -march=native")
SET(CMAKE_CXX_FLAGS_DEBUG "-O0 -W -Wall -Wextra -pedantic -ggdb3")

if (CMAKE_BUILD_TYPE MATCHES DEBUG)
	message("--- Launching in debug mode")
elseif(CMAKE_BUILD_TYPE MATCHES RELEASE)
	message("--- Launching in release mode")
else ()
	message("--- Launching in normal mode")
endif ()

# OXYGINE LIBRARY

cmake_minimum_required (VERSION 2.6)
project (GamePart1)

add_subdirectory(lib/oxygine-framework oxygine-framework)
add_definitions(${OXYGINE_DEFINITIONS})

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OXYGINE_CXX_FLAGS}")

link_directories(${OXYGINE_LIBRARY_DIRS})

if (WIN32)
	set_target_properties(GamePart1 PROPERTIES WIN32_EXECUTABLE TRUE)
endif(WIN32)

if (EMSCRIPTEN)
	SET(CMAKE_EXECUTABLE_SUFFIX ".html")	
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -s NO_EXIT_RUNTIME=1 -s WASM=0 -s WARN_ON_UNDEFINED_SYMBOLS=1 --memory-init-file 0 -s TOTAL_MEMORY=50331648 -s FORCE_FILESYSTEM=1")
	em_link_pre_js(GamePart1  ${OXYGINE_JS_LIBRARIES}  ${CMAKE_CURRENT_SOURCE_DIR}/data.js)
endif(EMSCRIPTEN)

# UTIL LIBRARY

SET(LIB_UTIL "util")

FILE(GLOB SRCS_UTIL
	${CMAKE_SOURCE_DIR}/Util/Src/Exception.cpp
	${CMAKE_SOURCE_DIR}/Util/Src/Parameter.cpp
	${CMAKE_SOURCE_DIR}/Util/Src/TermColor.cpp
	)

ADD_LIBRARY(${LIB_UTIL} STATIC ${SRCS_UTIL})

TARGET_INCLUDE_DIRECTORIES(${LIB_UTIL} PUBLIC
	${CMAKE_SOURCE_DIR}/Util/Include/
	)

# END -- UTIL LIBRARY

# GLOBAL GAME JAM

SET(GLOBAL_GAME_JAM "globalGameJam")

FILE(GLOB SRCS_GLOBAL_GAME_JAM
	${CMAKE_SOURCE_DIR}/GGJ/Src/Main.cpp
	${CMAKE_SOURCE_DIR}/GGJ/Src/Game.cpp
	${CMAKE_SOURCE_DIR}/GGJ/Src/MapCreator.cpp
	${CMAKE_SOURCE_DIR}/GGJ/Src/Tiles.cpp
	${CMAKE_SOURCE_DIR}/GGJ/Src/House.cpp
	)

ADD_EXECUTABLE(${GLOBAL_GAME_JAM} ${SRCS_GLOBAL_GAME_JAM})

TARGET_INCLUDE_DIRECTORIES(${GLOBAL_GAME_JAM} PUBLIC
	${CMAKE_SOURCE_DIR}/GGJ/Include/
	${OXYGINE_INCLUDE_DIRS}
	)

TARGET_LINK_LIBRARIES(
	${GLOBAL_GAME_JAM}
	${OXYGINE_CORE_LIBS}
	${LIB_UTIL}
	)

set_target_properties(${GLOBAL_GAME_JAM} PROPERTIES COMPILE_FLAGS
	"${OXYGINE_CXX_FLAGS} -Wno-unused-parameter -Wno-reorder"
	)

# END -- GLOBAL GAME JAM
