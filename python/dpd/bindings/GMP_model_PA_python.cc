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

#include <gnuradio/dpd/GMP_model_PA.h>
// pydoc.h is automatically generated in the build directory
#include <GMP_model_PA_pydoc.h>

void bind_GMP_model_PA(py::module& m)
{

    using GMP_model_PA    = gr::dpd::GMP_model_PA;


    py::class_<GMP_model_PA, gr::sync_block, gr::block, gr::basic_block,
        std::shared_ptr<GMP_model_PA>>(m, "GMP_model_PA")

        .def(py::init([](int model_param1, int model_param2, int model_param3, int model_param4, int model_param5, std::string mode, const std::vector<gr_complex>& coeff1, const std::vector<gr_complex>& coeff2)
                {
                    return GMP_model_PA::make(model_param1, model_param2, model_param3, model_param4, model_param5, mode, coeff1, coeff2);
                }),
                py::arg("model_param1"),
                py::arg("model_param2"),
                py::arg("model_param3"),
                py::arg("model_param4"),
                py::arg("model_param5"),
                py::arg("mode"),
                py::arg("coeff1"),
                py::arg("coeff2")
        );




}








