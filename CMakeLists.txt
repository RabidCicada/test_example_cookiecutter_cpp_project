cmake_minimum_required(VERSION 3.9)

# Set a name and a version number for your project:
project(example-cookiecutter-cpp-project VERSION 0.0.1 LANGUAGES CXX)

# Set CMake policies for this project

# We allow <Package>_ROOT (env) variables for locating dependencies
cmake_policy(SET CMP0074 NEW)

# Initialize some default paths
include(GNUInstallDirs)

# Define the minimum C++ standard that is required
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# Compilation options
option(BUILD_PYTHON "Enable building of Python bindings" ON)
option(BUILD_DOCS "Enable building of documentation" ON)

# Find external dependencies
find_package(FAKE_DEPENDENCY)

# compile the library
add_subdirectory(src)


# compile the application
add_subdirectory(app)

# compile the tests
include(CTest)
if(BUILD_TESTING)
  add_subdirectory(ext/Catch2)
  include(./ext/Catch2/contrib/Catch.cmake)
  add_subdirectory(tests)
endif()

if(BUILD_DOCS)
  # Add the documentation
  add_subdirectory(doc)
endif()
if(BUILD_PYTHON)
  # Add Python bindings
  add_subdirectory(ext/pybind11)
  
  # Compile the Pybind11 module
  pybind11_add_module(_examplecookiecuttercppproject python/examplecookiecuttercppproject/_example-cookiecutter-cpp-project.cpp)
  target_link_libraries(_examplecookiecuttercppproject PUBLIC example-cookiecutter-cpp-project)

  # Install the Python module shared library
  install(TARGETS _examplecookiecuttercppproject DESTINATION .)
endif()

# Add an alias target for use if this project is included as a subproject in another project
add_library(example-cookiecutter-cpp-project::example-cookiecutter-cpp-project ALIAS example-cookiecutter-cpp-project)

# Install targets and configuration
install(
  TARGETS example-cookiecutter-cpp-project
  EXPORT example-cookiecutter-cpp-project-targets
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})

install(
  EXPORT example-cookiecutter-cpp-project-targets
  FILE example-cookiecutter-cpp-projectTargets.cmake
  NAMESPACE example-cookiecutter-cpp-project::
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/example-cookiecutter-cpp-project)

include(CMakePackageConfigHelpers)
configure_package_config_file(
  ${CMAKE_CURRENT_LIST_DIR}/example-cookiecutter-cpp-projectConfig.cmake.in
  ${CMAKE_CURRENT_BINARY_DIR}/example-cookiecutter-cpp-projectConfig.cmake
  INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/example-cookiecutter-cpp-project)

install(
  FILES ${CMAKE_CURRENT_BINARY_DIR}/example-cookiecutter-cpp-projectConfig.cmake
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/example-cookiecutter-cpp-project)

export(
  EXPORT example-cookiecutter-cpp-project-targets
  FILE ${CMAKE_CURRENT_BINARY_DIR}/example-cookiecutter-cpp-projectTargets.cmake
  NAMESPACE example-cookiecutter-cpp-project::)

install(
  DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/include/
  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

# This prints a summary of found dependencies
include(FeatureSummary)
feature_summary(WHAT ALL)
