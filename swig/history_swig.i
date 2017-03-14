/* -*- c++ -*- */

#define HISTORY_API

%include "gnuradio.i"			// the common stuff

//load generated python docstrings
%include "history_swig_doc.i"

%{
#include "history/testtags.h"
%}


%include "history/testtags.h"
GR_SWIG_BLOCK_MAGIC2(history, testtags);
