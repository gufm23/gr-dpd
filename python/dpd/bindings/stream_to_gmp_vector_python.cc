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

#include <gnuradio/dpd/stream_to_gmp_vector.h>
// pydoc.h is automatically generated in the build directory
#include <stream_to_gmp_vector_pydoc.h>

void bind_stream_to_gmp_vector(py::module& m)
{

    using stream_to_gmp_vector    = gr::dpd::stream_to_gmp_vector;


    py::class_<stream_to_gmp_vector, gr::sync_block, gr::block, gr::basic_block,
        std::shared_ptr<stream_to_gmp_vector>>(m, "stream_to_gmp_vector")

        .def(py::init([](const std::vector<int>& dpd_params) {
                    return stream_to_gmp_vector::make(dpd_params);
                }),
                py::arg("dpd_params")
        );




}








