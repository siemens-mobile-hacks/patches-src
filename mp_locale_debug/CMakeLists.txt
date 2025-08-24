cmake_minimum_required(VERSION 3.15)

set(CMAKE_EXPORT_COMPILE_COMMANDS true)
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_SOURCE_DIR}/toolchain.cmake)

project(patch_mp_locale_debug LANGUAGES C ASM)

set(CMAKE_C_STANDARD 11)
add_compile_options(-Os)

# E71_45
add_executable(E71_45 patch.c patch.S)
define_patch(E71_45 ELKA E71 45)
