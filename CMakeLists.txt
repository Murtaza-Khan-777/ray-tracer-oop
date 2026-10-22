cmake_minimum_required(VERSION 3.16)
project(ray_tracer_oop LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(SFML COMPONENTS graphics window system QUIET)
find_package(TGUI QUIET)

file(GLOB_RECURSE RAY_TRACER_SOURCES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
)

add_executable(ray_tracer_oop ${RAY_TRACER_SOURCES})
target_include_directories(ray_tracer_oop PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include")

if(SFML_FOUND)
    target_link_libraries(ray_tracer_oop PRIVATE SFML::Graphics SFML::Window SFML::System)
endif()

if(TGUI_FOUND)
    target_link_libraries(ray_tracer_oop PRIVATE TGUI::TGUI)
endif()
