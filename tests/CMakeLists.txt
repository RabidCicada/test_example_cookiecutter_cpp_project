add_executable(tests tests.cpp example-cookiecutter-cpp-project_t.cpp)
target_link_libraries(tests PUBLIC example-cookiecutter-cpp-project Catch2::Catch2)

# allow user to run tests with `make test` or `ctest`
catch_discover_tests(tests)
