cmake_minimum_required(VERSION 3.22)

set(APP_NAME testing)

file(GLOB SRC_FILES
        "${CMAKE_SOURCE_DIR}/FirstNRepeatingStream.h"
        "*.cpp"
        )

add_executable(${APP_NAME} ${SRC_FILES})
include_directories(${CONAN_INCLUDE_DIRS_GTEST})

target_include_directories(${APP_NAME}
    PRIVATE
        ${CMAKE_SOURCE_DIR}
)

set_target_properties(${APP_NAME} PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
        LINK_LIBRARIES pthread
        COMPILE_OPTIONS "-std=c++17;-O2;-Wall;-Wextra;-Wpedantic;-fsanitize=thread"
        LINK_OPTIONS "-fsanitize=thread"
        )

target_link_libraries(${APP_NAME}
        ${CONAN_LIBS_GTEST}
)


set_target_properties(${APP_NAME} PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
        )

add_test(NAME ${APP_NAME} COMMAND $<TARGET_FILE:${APP_NAME}>)