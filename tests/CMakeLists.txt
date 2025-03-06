find_package(Catch2 REQUIRED)

# These tests can use the Catch2-provided main
add_executable(tests StoreTests.cpp)
target_link_libraries(tests PRIVATE ${PROJECT_NAME})
target_include_directories(tests PRIVATE ${CMAKE_SOURCE_DIR}/src)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)

include(CTest)
include(Catch)
catch_discover_tests(tests)