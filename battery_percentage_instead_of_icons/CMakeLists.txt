cmake_minimum_required(VERSION 3.15)

set(CMAKE_EXPORT_COMPILE_COMMANDS true)
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_SOURCE_DIR}/toolchain.cmake)

project(patch_battery_percentage_instead_of_icons LANGUAGES C ASM)

set(CMAKE_C_STANDARD 11)
add_compile_options(-Os)

# E71_45
add_executable(E71v45 patch.c patch.S)
define_patch(E71v45 ELKA E71 45)

# S65v58
add_executable(S65v58 patch.c patch.S)
define_patch(S65v58 SG S65 58)

# C72v22
add_executable(C72v22 patch.c patch.S)
define_patch(C72v22 SG C72 22)

# CX70v56
add_executable(CX70v56 patch.c patch.S)
define_patch(CX70v56 SG CX70 56)

# CF75v23
add_executable(CF75v23 patch.c patch.S)
define_patch(CF75v23 SG CF75 23)
target_compile_definitions(CF75v23 PUBLIC -DSECONDARY_DISPLAY)
