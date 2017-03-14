/* -*- c++ -*- */
/*
 * Copyright 2017 <+YOU OR YOUR COMPANY+>.
 *
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gnuradio/io_signature.h>
#include "testtags_impl.h"

namespace gr {
  namespace history {

    testtags::sptr
    testtags::make(int history_length)
    {
      return gnuradio::get_initial_sptr
        (new testtags_impl(history_length));
    }

    /*
     * The private constructor
     */
    testtags_impl::testtags_impl(int history_length)
      : gr::sync_block("testtags",
              gr::io_signature::make(1, 1, sizeof(float)),
              gr::io_signature::make(1, 1, sizeof(float))),
      history_length(history_length)
    {
        set_history(history_length);
    }

    /*
     * Our virtual destructor.
     */
    testtags_impl::~testtags_impl()
    {
    }

    int
    testtags_impl::work(int noutput_items,
        gr_vector_const_void_star &input_items,
        gr_vector_void_star &output_items)
    {
      const float *in = (const float *) input_items[0];
      float *out = (float *) output_items[0];

      memcpy(out, in+history_length, sizeof(float) * noutput_items);

      // Tell runtime system how many output items we produced.
      return noutput_items;
    }

  } /* namespace history */
} /* namespace gr */

