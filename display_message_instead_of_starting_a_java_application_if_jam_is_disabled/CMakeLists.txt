cmake_minimum_required(VERSION 3.15)

set(CMAKE_EXPORT_COMPILE_COMMANDS true)
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_SOURCE_DIR}/toolchain.cmake)

project(patch_display_message_instead_of_starting_a_java_application_if_jam_is_disabled LANGUAGES C ASM)

set(CMAKE_C_STANDARD 99)
add_compile_options(-Os)

# S65v58
add_executable(S65v58 patch.c patch.S)
define_patch(S65v58 SG S65 58)

# CX70v56
add_executable(CX70v56 patch.c patch.S)
define_patch(CX70v56 SG CX70 56)
