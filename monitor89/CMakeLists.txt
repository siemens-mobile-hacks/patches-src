cmake_minimum_required(VERSION 3.15)

set(CMAKE_EXPORT_COMPILE_COMMANDS true)
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_SOURCE_DIR}/toolchain.cmake)

project(patch_monitor89 LANGUAGES C ASM)

set(CMAKE_C_STANDARD 11)
add_compile_options(-Os)

# C72_22
add_executable(C72_22 patch.c patch.S)
define_patch(C72_22 SG C72 22)

# CX70_56
add_executable(CX70_56 patch.c patch.S)
define_patch(CX70_56 SG CX70 56)

# S65_58
add_executable(S65_58 patch.c patch.S)
define_patch(S65_58 SG S65 58)
target_compile_definitions(S65_58 PUBLIC -DHAS_BT)

# CF75_23
add_executable(CF75_23 patch.c patch.S)
define_patch(CF75_23 SG CF75 23)
