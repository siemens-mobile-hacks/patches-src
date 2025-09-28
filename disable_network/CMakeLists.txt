cmake_minimum_required(VERSION 3.15)

set(CMAKE_EXPORT_COMPILE_COMMANDS true)
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_SOURCE_DIR}/toolchain.cmake)

project(patch_disable_network LANGUAGES C ASM)

set(CMAKE_C_STANDARD 11)
add_compile_options(-Os)

# S65v58
add_executable(S65v58 patch.c patch.S)
define_patch(S65v58 SG S65 58)

# СX70v56
add_executable(CX70v56 patch.c patch.S)
define_patch(CX70v56 SG CX70 56)

# СF75v23
add_executable(CF75v23 patch.c patch.S)
define_patch(CF75v23 SG CF75 23)
