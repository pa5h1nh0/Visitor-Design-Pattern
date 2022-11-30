cmake_minimum_required(VERSION 3.10)

include(cmake/prelude.cmake)

project(
    visitor_pattern
    VERSION 0.1.0
    DESCRIPTION "Test: visitor pattern"
    LANGUAGES CXX
)

include(cmake/project-is-top-level.cmake)
include(cmake/variables.cmake)

# ---- Declare library ----

add_library(
    area OBJECT
    source/algos/area.cpp
)

add_library(
    perimeter OBJECT
    source/algos/perimeter.cpp
)

add_library(
    circle OBJECT
    source/shapes/circle.cpp
)

add_library(
    rectangle OBJECT
    source/shapes/rectangle.cpp
)

add_library(
    square OBJECT
    source/shapes/square.cpp
)

target_include_directories(
    area ${warning_guard}
    PUBLIC
    "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/source>"
    "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/source/algos>"
)

target_include_directories(
    perimeter ${warning_guard}
    PUBLIC
    "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/source>"
    "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/source/algos>"
)

target_include_directories(
    circle ${warning_guard}
    PUBLIC
    "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/source>"
    "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/source/shapes>"
)

target_include_directories(
    rectangle ${warning_guard}
    PUBLIC
    "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/source>"
    "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/source/shapes>"
)

target_include_directories(
    square ${warning_guard}
    PUBLIC
    "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/source>"
    "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/source/shapes>"
)

target_compile_features(area PUBLIC cxx_std_20)
target_compile_features(perimeter PUBLIC cxx_std_20)
target_compile_features(circle PUBLIC cxx_std_20)
target_compile_features(rectangle PUBLIC cxx_std_20)
target_compile_features(square PUBLIC cxx_std_20)

# ---- Declare executable ----

add_executable(visitor_pattern_exe source/main.cpp)
add_executable(visitor_pattern::exe ALIAS visitor_pattern_exe)

set_property(TARGET visitor_pattern_exe PROPERTY OUTPUT_NAME visitor_pattern)

target_compile_features(visitor_pattern_exe PRIVATE cxx_std_20)

target_link_libraries(visitor_pattern_exe PRIVATE
  area
  perimeter
  circle
  rectangle
  square
)

# ---- Install rules ----

if(NOT CMAKE_SKIP_INSTALL_RULES)
  include(cmake/install-rules.cmake)
endif()

# ---- Developer mode ----

if(NOT visitor_pattern_DEVELOPER_MODE)
  return()
elseif(NOT PROJECT_IS_TOP_LEVEL)
  message(
      AUTHOR_WARNING
      "Developer mode is intended for developers of visitor_pattern"
  )
endif()

include(cmake/dev-mode.cmake)
