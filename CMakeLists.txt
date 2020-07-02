cmake_minimum_required(VERSION 3.13 FATAL_ERROR)

project(static-link-test)
set(CMAKE_CXX_STANDARD 17)

add_library(plugin STATIC plugin.cpp plugin.h)

add_library(core STATIC core.cpp core.h)

add_executable(main main.cpp)

if (WIN32)
  target_link_libraries(main PUBLIC core plugin)
  target_link_options(main PUBLIC "/WHOLEARCHIVE:core" "/WHOLEARCHIVE:plugin")
else ()
  target_link_libraries(main PUBLIC
    -Wl,--whole-archive
    core
    plugin
    -Wl,--no-whole-archive)
endif ()
