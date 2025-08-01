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

#include <gnuradio/dpd/gain_phase_calibrate.h>
// pydoc.h is automatically generated in the build directory
#include <gain_phase_calibrate_pydoc.h>

void bind_gain_phase_calibrate(py::module& m)
{

    using gain_phase_calibrate    = gr::dpd::gain_phase_calibrate;


    py::class_<gain_phase_calibrate, gr::block, gr::basic_block,
        std::shared_ptr<gain_phase_calibrate>>(m, "gain_phase_calibrate")
        .def(py::init([]() {
                    return gain_phase_calibrate::make();
                })
        )
  
        ;

}




