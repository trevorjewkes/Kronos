# Sample project using wxWidgets and Boost with Catch.h for testing

This runs under Ubuntu after I installed wxWidgets and Boost libraries on my machine.

## To build

```
cd bin/
cmake ..
make
```

This will produce two executables. One is the actual application, `run`, and the other is the test executable.

## Info on the libraries

I downloaded Boost and wxWidgets and compiled from source and then installed as per the instructions on the website. Some modifications to CMakeLists.txt might need to be made to cross compile on Windows Visual Studios.

- [Catch](https://github.com/philsquared/Catch) for testing
- [Clang-format](http://clang.llvm.org/docs/ClangFormat.html) should be used to comform to the [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html)
- [cpplint.py](https://github.com/google/styleguide/tree/gh-pages/cpplint) is included to further help with style
- [Install Boost](www.boost.org)
- [Install wxWidgets](https://www.wxwidgets.org/downloads/)
