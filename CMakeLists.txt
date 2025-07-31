cmake_minimum_required(VERSION 3.14)

project(assignment4)

set(TARGET go)

set(SOURCES 
    ${CMAKE_SOURCE_DIR}/src/Server.cpp
    ${CMAKE_SOURCE_DIR}/src/Packet.cpp
    ${CMAKE_SOURCE_DIR}/src/GenPacket.cpp
    )

add_executable(${TARGET} main.cpp ${SOURCES})

target_include_directories(${TARGET} PUBLIC Inc)