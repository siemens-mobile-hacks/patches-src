cmake_minimum_required(VERSION 3.15)

set(CMAKE_EXPORT_COMPILE_COMMANDS true)
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_SOURCE_DIR}/toolchain.cmake)

project(patch_speed_up_menu_scrolling LANGUAGES C ASM)

set(CMAKE_C_STANDARD 11)
add_compile_options(-Os)

# E71v45
add_executable(E71v45 patch.c patch.S)
define_patch(E71v45 ELKA E71 45)

# S75v52
add_executable(S75v52 patch.c patch.S)
define_patch(S75v52 NSG S75 52)
