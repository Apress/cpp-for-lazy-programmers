To install SSDL for MinGW, run make in this directory.

It currently makes the static version of the library.  If you want shared, you can move the resulting libssdl.dll to a path where the OS can find it, possibly C:\MinGW\msys\1.0\bin or your project folder. 

To run an SSDL or SDL program with MinGW, you need the .dll files for SDL2, SDL2_image, SDL2_mixer, and SDL2_ttf, and all .dll files they depend on. In the sample code, bash runw calls a script that knows where these are. You could also put them in a folder where the operating system can find them:  maybe C:\MinGW\msys\1.0\bin, or the project folder, and then just run the executable, often a.out.

static-test tests the library; you can run it to verify that make worked (that is, that the library built and the program runs). Run it thus: bash runw
