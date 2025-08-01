/*
 * Copyright 2025 Free Software Foundation, Inc.
 *
 * This file is part of GNU Radio
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 */

#include <pybind11/complex.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

#include <gnuradio/dpd/MP_model_PA.h>
// pydoc.h is automatically generated in the build directory
#include <MP_model_PA_pydoc.h>

void bind_MP_model_PA(py::module& m)
{

    using MP_model_PA    = gr::dpd::MP_model_PA;


    py::class_<MP_model_PA, gr::sync_block, gr::block, gr::basic_block,
        std::shared_ptr<MP_model_PA>>(m, "MP_model_PA")

        .def(py::init([](int Order, int Mem_Depth, std::string Mode, const std::vector<gr_complex>& Coeff) {
                    return MP_model_PA::make(Order, Mem_Depth, Mode, Coeff);
                }),
                py::arg("Order"),
                py::arg("Mem_Depth"),
                py::arg("Mode"),
                py::arg("Coeff")
        );




}








