cmake_minimum_required(VERSION 3.13)
set(CMAKE_CXX_COMPILER /usr/bin/g++)
project(Membot)

add_executable(${PROJECT_NAME})
add_subdirectory(src)

set_property(TARGET Membot PROPERTY CXX_STANDARD 17)

target_compile_options(Membot PRIVATE -Wall -Wextra)

find_package(wxWidgets REQUIRED gl core base)

include(${wxWidgets_USE_FILE})
target_link_libraries(
    Membot
        ${wxWidgets_LIBRARIES}
        ${wxWidgets_LIBRARY_DIRS}
)