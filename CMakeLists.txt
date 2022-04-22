cmake_minimum_required(VERSION 3.22)
project(test1)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXE_LINKER_FLAGS "-static -static-libgcc")
set(SFML_STATIC_LIBRARIES TRUE)
add_executable(test1 main.cpp hero.h consts.h map.h view.h random.h entity.h enemy.h)


set(SFML_DIR "C:\\Users\\Honor MagicBook Pro\\CLionProjects\\lib\\sfml\\GCC 7.3.0 MinGW (SEH) - 64-bit\\SFML-2.5.1\\lib\\cmake\\SFML")
target_link_libraries(test1 sfml-graphics sfml-audio)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_FILE}/cmake_modules")
find_package(SFML 2.5.1 COMPONENTS graphics audio REQUIRED)