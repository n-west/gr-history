#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
# Copyright 2017 <+YOU OR YOUR COMPANY+>.
#
# This is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 3, or (at your option)
# any later version.
#
# This software is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this software; see the file COPYING.  If not, write to
# the Free Software Foundation, Inc., 51 Franklin Street,
# Boston, MA 02110-1301, USA.
#

from gnuradio import gr, gr_unittest
from gnuradio import blocks
import history_swig as history

class qa_testtags (gr_unittest.TestCase):

    def setUp (self):
        self.tb = gr.top_block ()

    def tearDown (self):
        self.tb = None

    def test_001_t (self):
        src_data = range(64)
        tags = gr.tags_vector_t()
        tag1 = gr.tag_utils.python_to_tag({
            'offset': 0, 'key': gr.pmt.intern("test"), 'value': gr.pmt.intern("first")})
        tag2 = gr.tag_utils.python_to_tag({
            'offset': 8, 'key': gr.pmt.intern("test"), 'value': gr.pmt.intern("eight")})
        tags.append(tag1)
        tags.append(tag2)
        src = blocks.vector_source_f(src_data, False, 1, tags)
        but = history.testtags(5)
        dst = blocks.vector_sink_f()
        tag_dst = blocks.tag_debug(gr.sizeof_float, "fksdhfj")
        self.tb.connect(src, but, dst)
        self.tb.connect(but, tag_dst)
        self.tb.run ()
        # check data
        print "current tags:"
        received_tags = gr.pmt.to_python(tag_dst.current_tags())
        for rx_tag in received_tags:
            print rx_tag
        print "data:"
        print dst.data()


if __name__ == '__main__':
    gr_unittest.run(qa_testtags, "qa_testtags.xml")
