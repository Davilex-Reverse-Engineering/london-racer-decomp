cmake_minimum_required(VERSION 3.20)
project(SPEL)

include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/reccmp.cmake")

add_executable(SPEL WIN32
    main_SPEL.cpp
    main_SPEL.hpp
)
reccmp_add_target(SPEL ID SPEL)
set_property(TARGET SPEL PROPERTY OUTPUT_NAME "spel")
set_property(TARGET SPEL PROPERTY PREFIX "")
set_property(TARGET SPEL PROPERTY SUFFIX ".exe")

reccmp_configure()
