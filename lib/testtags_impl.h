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

#ifndef INCLUDED_HISTORY_TESTTAGS_IMPL_H
#define INCLUDED_HISTORY_TESTTAGS_IMPL_H

#include <history/testtags.h>

namespace gr {
  namespace history {

    class testtags_impl : public testtags
    {
     private:
         int history_length;

     public:
        testtags_impl(int history_length);
        ~testtags_impl();

        int work(int noutput_items,
           gr_vector_const_void_star &input_items,
           gr_vector_void_star &output_items);
    };

  } // namespace history
} // namespace gr

#endif /* INCLUDED_HISTORY_TESTTAGS_IMPL_H */

