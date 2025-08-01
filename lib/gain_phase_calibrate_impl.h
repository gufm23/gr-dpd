/* -*- c++ -*- */
/*
 * Copyright 2020 Alekh Gupta
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_DPD_GAIN_PHASE_CALIBRATE_IMPL_H
#define INCLUDED_DPD_GAIN_PHASE_CALIBRATE_IMPL_H

#include <gnuradio/dpd/gain_phase_calibrate.h>

namespace gr {
namespace dpd {

class gain_phase_calibrate_impl : public gain_phase_calibrate
{
private:
    gr_complex cfactor, previous_cfactor, current_cfactor;
    int ninput_items, item;
    bool d_reference_acquired, reference_acquired;
    gr_complex d_sample, sample;


public:
    gain_phase_calibrate_impl();
    ~gain_phase_calibrate_impl();

    // Decides closeness to zero or null
    bool almost_equals_zero(double a, int num_digits);
    // Where all the action really happens
    int general_work(int noutput_items,
                     gr_vector_int& ninput_items,
                     gr_vector_const_void_star& input_items,
                     gr_vector_void_star& output_items);
};

} // namespace dpd
} // namespace gr

#endif /* INCLUDED_DPD_GAIN_PHASE_CALIBRATE_IMPL_H */
