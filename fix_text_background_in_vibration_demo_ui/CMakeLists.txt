cmake_minimum_required(VERSION 3.15)

set(CMAKE_EXPORT_COMPILE_COMMANDS true)
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_SOURCE_DIR}/toolchain.cmake)

project(patch_fix_text_background_in_vibration_demo_ui LANGUAGES C ASM)

set(CMAKE_C_STANDARD 11)
add_compile_options(-Os)

# S75_52
add_executable(S75v52 patch.c patch.S)
define_patch(S75v52 NSG S75 52)
