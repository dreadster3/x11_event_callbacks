cmake_minimum_required(VERSION 3.23)

set(VCPKG_ROOT "/opt/vcpkg" CACHE STRING "Vcpkg root directory")
set(CMAKE_TOOLCHAIN_FILE "${VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake" CACHE STRING "Vcpkg toolchain file")

project(x11_event_callbacks)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(X11 REQUIRED)

file(GLOB CPPFILES src/*.cpp)
file(GLOB HPPFILES src/*.hpp)

set(SOURCE_FILES ${CPPFILES} ${HPPFILES})

add_executable(x11_event_callbacks ${SOURCE_FILES})
target_link_libraries(x11_event_callbacks X11)

