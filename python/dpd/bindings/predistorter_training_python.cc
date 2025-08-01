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

#include <gnuradio/dpd/predistorter_training.h>
// pydoc.h is automatically generated in the build directory
#include <predistorter_training_pydoc.h>

void bind_predistorter_training(py::module& m)
{

    using predistorter_training    = gr::dpd::predistorter_training;


    py::class_<predistorter_training, gr::sync_block, gr::block, gr::basic_block,
        std::shared_ptr<predistorter_training>>(m, "predistorter_training")

        .def(py::init([](const std::vector<int>& dpd_params, std::string mode, const std::vector<gr_complex>& taps) {
                    return predistorter_training::make(dpd_params, mode, taps);
                }),
                py::arg("dpd_params"),
                py::arg("mode"),
                py::arg("taps")
        )

        



        ;




}








