cmake_minimum_required(VERSION 3.15)

set(CMAKE_EXPORT_COMPILE_COMMANDS true)
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_SOURCE_DIR}/toolchain.cmake)

project(patch_add_icons_to_header_in_nm LANGUAGES C ASM)

set(CMAKE_C_STANDARD 99)
add_compile_options(-Os)

# S75v52
add_executable(S75v52 patch.c patch.S)
define_patch(S75v52 NSG S75 52)

# C81v51
add_executable(C81v51 patch.c patch.S)
define_patch(C81v51 NSG C81 51)

# E71v45
add_executable(E71v45 patch.c patch.S)
define_patch(E71v45 ELKA E71 45)

# EL71v45
add_executable(EL71v45 patch.c patch.S)
define_patch(EL71v45 ELKA EL71 45)

# CX70v56
add_executable(CX70v56 patch.c patch.S)
define_patch(CX70v56 SG CX70 56)

# S65v58
add_executable(S65v58 patch.c patch.S)
define_patch(S65v58 SG S65 58)
