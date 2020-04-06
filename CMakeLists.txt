cmake_minimum_required(VERSION 3.15)
project(saper)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(saper
        Array2D.h
        main.cpp
        MinesweeperBoard.cpp
        MinesweeperBoard.h
        MSBoardTextView.cpp
        MSBoardTextView.h
        MsTextController.cpp
        MsTextController.h MSSFMLView.cpp MSSFMLView.h)
# Detect and add SFML
set(SFML_PATH "C:/cpp/SFML-2.5.1" ${CMAKE_MODULE_PATH})
set(SFML_DIR ${SFML_PATH}/lib/cmake/SFML)
find_package(SFML 2 REQUIRED graphics window system)

if(SFML_FOUND)
    target_link_libraries(saper sfml-graphics sfml-window sfml-audio)
    include_directories(${SFML_PATH}/include/SFML/)
endif()