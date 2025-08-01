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

#include <gnuradio/dpd/LMS_postdistorter.h>
// pydoc.h is automatically generated in the build directory
#include <LMS_postdistorter_pydoc.h>

void bind_LMS_postdistorter(py::module& m)
{

    using LMS_postdistorter    = gr::dpd::LMS_postdistorter;


    py::class_<LMS_postdistorter, gr::sync_block, gr::block, gr::basic_block,
        std::shared_ptr<LMS_postdistorter>>(m, "LMS_postdistorter")

        .def(py::init([](const std::vector<int>& dpd_params, int iter_limit, std::string method, gr_complexd learning_rate) {
                    return LMS_postdistorter::make(dpd_params, iter_limit, method, learning_rate);
                }),
                py::arg("dpd_params"),
                py::arg("iter_limit"),
                py::arg("method"),
                py::arg("learning_rate")

        );

}








