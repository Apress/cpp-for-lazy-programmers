To install SSDL for Unix or macOS, run make in this directory.

It currently makes one version of the library:  shared (.so).

To run an SSDL in Unix or macOS, you need this in the library path. In the sample code, ./runx and ./runm use a script that knows to find it. You could also put it in a folder where the operating system can find it:  maybe the project folder. Better yet, wherever libSDL2.so[.*] may be (possibly under /usr/lib), or export LD_LIBRARY_PATH=<where you put it> for Unix and export DYLD_LIBRARY_PATH=<where you put it> for macOS; and then just run the executable, often a.out.

The makefile creates a tester program shared-test; you can run it with the script runx, to verify that make worked (that is, that the library built and the program runs). Run it thus: ./runx (for Unix) or ./runm (for macOS)

If you opt to instead use static (make libssdl.a), you don't need export LD_LIBRARY_PATH or export DYLD_LIBRARY_PATH.  Test it by running ./static-test.


