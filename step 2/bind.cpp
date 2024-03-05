#include <pybind11/pybind11.h>

#include "matrix.h"

namespace py = pybind11;

PYBIND11_MODULE(toy_matrix, m) {
    py::class_<Matrix>(m, "Matrix")
        .def(py::init<size_t, size_t>())
        .def("Set", &Matrix::Set)
        .def("Get", &Matrix::Get)
        .def("Rows", &Matrix::Rows)
        .def("Cols", &Matrix::Cols)
        .def("FillRandom", &Matrix::FillRandom)
        .def("Print", &Matrix::Print)
        .def("PrintSummary", &Matrix::PrintSummary)
        // .def("Dot", py::overload_cast<const Matrix&>(&Matrix::Dot, py::const_))
        .def_static("Dot", py::overload_cast<const Matrix&, const Matrix&, Matrix&>(&Matrix::Dot));
}
