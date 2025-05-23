cmake_minimum_required(VERSION 3.15)

set(CMAKE_EXPORT_COMPILE_COMMANDS true)
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_SOURCE_DIR}/toolchain.cmake)

project(patch_set_dir_of_theme_resources LANGUAGES C ASM)

set(CMAKE_C_STANDARD 99)
add_compile_options(-Os)

# E71v45
add_executable(E71v45 patch.c patch.S)
define_patch(E71v45 ELKA E71 45)

# EL71v45
add_executable(EL71v45 patch.c patch.S)
define_patch(EL71v45 ELKA EL71 45)

# S68v52
add_executable(S68v52 patch.c patch.S)
define_patch(S68v52 NSG S68 52)
target_compile_definitions(S68v52 PUBLIC -DTHUMB_VARIANT)

# S75v52
add_executable(S75v52 patch.c patch.S)
define_patch(S75v52 NSG S75 52)
target_compile_definitions(S75v52 PUBLIC -DTHUMB_VARIANT)

# C81v51
add_executable(C81v51 patch.c patch.S)
define_patch(C81v51 NSG C81 51)
target_compile_definitions(C81v51 PUBLIC -DTHUMB_VARIANT)
