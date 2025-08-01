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

#include <gnuradio/dpd/RLS_postdistorter.h>
// pydoc.h is automatically generated in the build directory
#include <RLS_postdistorter_pydoc.h>

void bind_RLS_postdistorter(py::module& m)
{

    using RLS_postdistorter    = gr::dpd::RLS_postdistorter;


    py::class_<RLS_postdistorter, gr::sync_block, gr::block, gr::basic_block,
        std::shared_ptr<RLS_postdistorter>>(m, "RLS_postdistorter")

        .def(py::init([](const std::vector<int>& dpd_params, int iter_limit) {
                    return RLS_postdistorter::make(dpd_params, iter_limit);
                }),
                py::arg("dpd_params"),
                py::arg("iter_limit")
        );







}








