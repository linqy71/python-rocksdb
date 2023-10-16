#include <pybind11/pybind11.h>
#include "pyrocksdb.hpp"

namespace py = pybind11;

void init_checkpoint(py::module &m) {
  py::class_<py_Checkpoint>(m, "Checkpoint")
    .def(py::init<>())
    .def("Create", (Status (py_Checkpoint::*)(py_DB& db) ) &py_Checkpoint::Create)
    .def("CreateCheckpoint", (Status (py_Checkpoint::*)(const std::string& checkpoint_dir, uint64_t log_size_for_flush)) &py_Checkpoint::CreateCheckpoint, py::arg("checkpoint_dir"), py::arg("log_size_for_flush")=0);
}

