cmake_minimum_required(VERSION 3.10)

project(stringlist LANGUAGES C)

add_executable(stringlist src/main.c
                          src/list.c
                          src/list.h
                          src/details.c
                          src/details.h
                          src/types.h)

# Set a default build type if none was specified
set(default_build_type "Debug")    
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    message("Message: Setting build type to '${default_build_type}' as none was specified.")
    set(CMAKE_BUILD_TYPE "${default_build_type}" CACHE STRING "Choose the type of build." FORCE)
endif()

if (CMAKE_C_COMPILER_ID STREQUAL "GNU")
    target_compile_options(stringlist PRIVATE $<$<CONFIG:RELEASE>:-O2>)
    target_compile_options(stringlist PRIVATE $<$<CONFIG:DEBUG>:-Wall;-Wextra;-Wpedantic>)
endif()

set_target_properties(stringlist PROPERTIES C_STANDARD 11
                                            C_STANDARD_REQUIRED on)