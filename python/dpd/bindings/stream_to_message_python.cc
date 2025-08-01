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

#include <gnuradio/dpd/stream_to_message.h>
// pydoc.h is automatically generated in the build directory
#include <stream_to_message_pydoc.h>

void bind_stream_to_message(py::module& m)
{

    using stream_to_message    = gr::dpd::stream_to_message;


    py::class_<stream_to_message, gr::sync_block, gr::block, gr::basic_block,
        std::shared_ptr<stream_to_message>>(m, "stream_to_message")

        .def(py::init([]() {
                    return stream_to_message::make();
                })
        );





}








