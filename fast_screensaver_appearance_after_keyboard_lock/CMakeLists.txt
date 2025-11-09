cmake_minimum_required(VERSION 3.15)

set(CMAKE_EXPORT_COMPILE_COMMANDS true)
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_SOURCE_DIR}/toolchain.cmake)

project(patch_fast_screensaver_appearance_after_keyboard_lock LANGUAGES C ASM)

set(CMAKE_C_STANDARD 99)
add_compile_options(-Os)

# E71v45
add_executable(E71v45 patch.c patch.S)
define_patch(E71v45 ELKA E71 45)

# CX70v56
add_executable(CX70v56 patch.c patch.S)
define_patch(CX70v56 SG CX70 56)

# S65v58
add_executable(S65v58 patch.c patch.S)
define_patch(S65v58 SG S65 58)

# C72v22
add_executable(C72v22 patch.c patch.S)
define_patch(C72v22 SG C72 22)
