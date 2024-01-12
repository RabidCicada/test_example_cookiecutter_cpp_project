#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "example-cookiecutter-cpp-project/example-cookiecutter-cpp-project.hpp"

namespace py = pybind11;

namespace examplecookiecuttercppproject {

PYBIND11_MODULE(_examplecookiecuttercppproject, m)
{
  m.doc() = "Python Bindings for example_cookiecutter_cpp_project";
  m.def("add_one", &add_one, "Increments an integer value");
}

} // namespace examplecookiecuttercppproject
