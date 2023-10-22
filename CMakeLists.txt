cmake_minimum_required(VERSION 3.23)

project(x11_event_callbacks)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(X11 REQUIRED)

file(GLOB CPPFILES src/*.cpp)
file(GLOB HPPFILES src/*.hpp)

set(SOURCE_FILES ${CPPFILES} ${HPPFILES})

add_executable(x11_event_callbacks ${SOURCE_FILES})
target_link_libraries(x11_event_callbacks X11)

install(TARGETS x11_event_callbacks DESTINATION ${CMAKE_INSTALL_BINDIR})
