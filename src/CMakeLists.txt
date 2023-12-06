# (c) 2020 Copyright, Real-Time Innovations, Inc. All rights reserved.
# No duplications, whole or partial, manual or electronic, may be made
# without express written permission.  Any such copies, or revisions thereof,
# must display this notice unaltered.
# This code contains trade secrets of Real-Time Innovations, Inc.
cmake_minimum_required(VERSION 3.11)
project(command-response-xml-application)

# Find RTI Connext dependencies
set(CMAKE_MODULE_PATH
    ${CMAKE_MODULE_PATH}
    "$ENV{NDDSHOME}/resource/cmake"
)

#set(COMPILE_FLAGS_STD_C11 "-std=c++11")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${COMPILE_FLAGS_STD_C11}")

set(LINKER_FLAGS "-v")
Set(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${LINKER_FLAGS}")

find_package(
    RTIConnextDDS "7.2.0"
    REQUIRED
    COMPONENTS
		core
)

set(TRACKER_CPP_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/tracker.cxx"
)

# Main application
add_executable(Tracker
    ${TRACKER_CPP_SOURCES}
)

target_link_libraries(Tracker
	RTIConnextDDS::cpp_api
)



