cmake_minimum_required(VERSION 3.15)

set(CMAKE_EXPORT_COMPILE_COMMANDS true)
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_SOURCE_DIR}/toolchain.cmake)

project(patch_media_player_modification LANGUAGES C ASM)

set(CMAKE_C_STANDARD 99)
add_compile_options(-Os -DSWILIB_MODERN)

file(GLOB_RECURSE SOURCES "src/*.c", "src/*.S")

# E71v45
add_executable(E71v45 ${SOURCES})
define_patch(E71v45 ELKA E71 45)
