set(SOURCE_DIR Source/)

set(LFSR_SOURCE LFSR/${SOURCE_DIR})

set(SOURCES
    ${LFSR_SOURCE}/LFSR.cpp
    ${LFSR_SOURCE}/LFSR8.cpp
    ${LFSR_SOURCE}/LFSR4.cpp
    Main.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})