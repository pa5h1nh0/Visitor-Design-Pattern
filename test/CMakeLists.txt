# Parent project does not export its library target, so this CML implicitly
# depends on being added from it, i.e. the testing is done only from the build
# tree and is not feasible from an install location

project(visitor_patternTests LANGUAGES CXX)

# ---- Tests ----

add_executable(visitor_pattern_test source/visitor_pattern_test.cpp)

target_include_directories(
    visitor_pattern_test ${warning_guard}
    PUBLIC
    "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/source>"
)

target_compile_options(visitor_pattern_test PRIVATE
    -Wno-conversion
    -Wno-sign-conversion
)

target_compile_features(visitor_pattern_test PRIVATE cxx_std_20)
target_link_libraries(visitor_pattern_test PRIVATE
    area
    perimeter
    circle
    rectangle
    square
)

add_test(NAME visitor_pattern_test COMMAND visitor_pattern_test)

# ---- End-of-file commands ----

add_folders(Test)
