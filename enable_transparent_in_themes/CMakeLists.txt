cmake_minimum_required(VERSION 3.15)

set(CMAKE_EXPORT_COMPILE_COMMANDS true)
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_SOURCE_DIR}/toolchain.cmake)

project(patch_enable_transparent_in_themes LANGUAGES C ASM)

set(CMAKE_C_STANDARD 99)
add_compile_options(-Os)

# E71v45
add_executable(E71v45 patch.c patch.S)
define_patch(E71v45 ELKA E71 45)

# EL71v45
add_executable(EL71v45 patch.c patch.S)
define_patch(EL71v45 ELKA EL71 45)
