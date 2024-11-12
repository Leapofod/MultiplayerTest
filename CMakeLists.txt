cmake_minimum_required(VERSION 3.12)
project(multiplayer-test)

# Generate compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
if (PROJECT_IS_TOP_LEVEL AND UNIX)
    execute_process(COMMAND ${CMAKE_COMMAND} -E create_symlink
                        ${CMAKE_BINARY_DIR}/compile_commands.json
                        ${CMAKE_CURRENT_SOURCE_DIR}/compile_commands.json
    )
endif()

# Find and populate raylib
set(RAYLIB_VER 5.0)
find_package(raylib ${RAYLIB_VER} QUIET)
if (NOT raylib_FOUND)
    include(FetchContent)
    FetchContent_Declare(
        raylib
        DOWNLOAD_EXTRACT_TIMESTAMP OFF
        URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VER}.tar.gz
    )
    FetchContent_GetProperties(raylib)
    if (NOT raylib_POPULATED)
        set(FETCHCONTENT_QUIET NO)
        FetchContent_Populate(raylib)
        set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
        add_subdirectory(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})
    endif()
endif()


# Executable
add_executable(${PROJECT_NAME})
add_subdirectory(src)

set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${PROJECT_NAME}
    OUTPUT_NAME "Random Multiplayer")

# Copy resources folder to output
add_custom_command(
    TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/resources-out $<TARGET_FILE_DIR:${PROJECT_NAME}>/resources
)

target_include_directories(${PROJECT_NAME}
                PRIVATE src/include
                PRIVATE src/external)

# Include raylib
target_link_libraries(${PROJECT_NAME} raylib)

# Checks if OSX and links appropriate frameworks (Only required on MacOS)
if (APPLE)
    target_link_libraries(${PROJECT_NAME} "-framework IOKit")
    target_link_libraries(${PROJECT_NAME} "-framework Cocoa")
    target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
endif()
