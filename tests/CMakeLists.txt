find_package(Qt6 COMPONENTS Test REQUIRED)
# add test executable
add_executable(tests_qduration test_qduration.cpp)
target_link_libraries(tests_qduration PRIVATE QtDuration Qt6::Test)  # or correct QtTest target

add_test(NAME QDurationTests COMMAND tests_qduration)