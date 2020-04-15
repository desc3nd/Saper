cmake_minimum_required(VERSION 3.1)
project(saper)
set(CMAKE_CXX_STANDARD 14)
    add_compile_options(-Wall -Wextra)
add_custom_target(arial.ttf)
add_executable(saper
        Array2D.h
        main.cpp
        MinesweeperBoard.cpp
        MinesweeperBoard.h
        MSBoardTextView.cpp
        MSBoardTextView.h
        MsTextController.cpp
        MsTextController.h
        MSSFMLView.cpp
        MSSFMLView.h MSSFLMController.cpp MSSFLMController.h)
# Detect and add SFML
if (UNIX)
    set ( CMAKE_MODULES_PATH "/usr/share/SFML/cmake/Modules" ${CMAKE_MODULE_PATH})
endif(UNIX)

if (WIN32)
# //   set( SFML_STATIC_LIBRARIES TRUE )
    set ( SFML_DIR "C:/cpp/SFML-2.5.1/lib/cmake/SFML")
endif(WIN32)
find_package(SFML 2 REQUIRED graphics window system)
target_link_libraries(saper sfml-graphics sfml-audio)