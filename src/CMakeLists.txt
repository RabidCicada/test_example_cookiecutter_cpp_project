add_library(example-cookiecutter-cpp-project example-cookiecutter-cpp-project.cpp)
target_include_directories(example-cookiecutter-cpp-project PUBLIC
  $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include/>
  $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)
