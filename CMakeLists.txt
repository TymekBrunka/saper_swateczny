cmake_minimum_required(VERSION 3.23)
project(reaktory LANGUAGES C CXX)
set (CMAKE_CXX_STANDARD 20)

find_package(glfw3 REQUIRED) #glfw3 is name OF THE FILE, NOT TARGET

find_package(glm REQUIRED) #refuses to work normaly with find_package()

add_subdirectory(src/rendering)
include_directories(src/GamingClasses)

add_executable(main
  src/main.cpp
  src/GamingClasses/Camera.cpp
  src/GamingClasses/SpriteInstancing.cpp
)

target_link_libraries(main PUBLIC rr glm::glm-header-only)
