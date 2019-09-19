Copy into this folder the main.cpp you want to test using SSDL without the libraries, and compile as below. The reason is to make debugging SSDL easier.

To run with MinGW, copy Makefile.mingw to Makefile; make; and enter: bash runw, or bash gdbw to debug.
 ***THIS IS NOT FINISHED. MinGW isn't giving me a problem, so I'll defer this for now. ***

To run with Unix, copy Makefile.unix to Makefile; make; and enter: ./runx. Or ./dddx or ./gdbx to debug.

To run with Microsoft Visual studio, open SSDL_Project.sln and go from there.
