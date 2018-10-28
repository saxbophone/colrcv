# colrcv

C Library for converting Colours between different Colour Models

This is a simple library written in ISO C99 for simple needs. Disclosure: **I am not a colorimetrist**

I wrote this library a while ago for use in another project of mine. I'm aware that there are libraries already out there that can achieve what this one does, but all those I found were far more complex than what I really needed for my simple needs (converting colours from a handful of different colour models into RGB, for use in computer graphics).

The source used as a reference for the calculations implemented by this library is [https://www.easyrgb.com/en/math.php](https://www.easyrgb.com/en/math.php) —this site really is rather good!

Right now, the following colour models are supported:

- HSL
- HSV
- LAB¹
- RGB
- XYZ¹

> **¹** _The XYZ and LAB colour models require a given reference standard illuminant before either of these models can be converted to or from any other model besides these two. Currently, **colrcv** always uses the D65 illuminant to achieve this, but there are plans in the future to support choosing a different illuminant when making these conversions._

Conversion between any two of these colour models is all supported by the library.

## Licensing

Colrcv is licensed under the **Mozilla Public License Version 2.0** (`MPL-2.0`).

This is a permissive software license which puts copyleft protections only on the original source files of the project themselves, but does not extend this copyleft to other sources which use the library. In other words, the library may be used and integrated into other projects regardless of whether they are open-source or commercial, but any modifications to the library itself must be made available under the same or an equivalent license (see license for further details on the nuances of this).

A full verbatim of this license may be found in the [LICENSE](LICENSE) file in this repository. If for some reason you have not received this file, you can view a copy of the license at [https://www.mozilla.org/MPL/2.0/](https://www.mozilla.org/MPL/2.0/).

## Building

Colrcv can be built without installing for test purposes and for general usage, however if you plan on writing programs that use it I recommend you install it so it will be in your system's standard library and header include locations.

### Dependencies

There are no library dependencies whatsoever beyond the C99 standard library!

#### Build Tools

- A compiler that can compile ISO C99 or C11 code (mingw gcc can compile it on Windows)
- [Cmake](https://cmake.org/) - v3.0 or newer

### Recommended Library Build

> An **out of source build** is recommended, as CMake clutters the directory it is executed in with many files which are awkward to remove.

Invoke CMake within the `build` directory of this repository, with these arguments to make CMake build the library in release mode (with full optimisation) and as a shared library:

```sh
cmake -DCMAKE_BUILD_TYPE=Release -DBUILD_SHARED_LIBS=ON ..
make
```

The above builds in C99 mode by default. The standard to use can be controlled by the `COLRCV_C_STANDARD` CMake variable or by the `COLRCV_C_STANDARD` environment variable.

You can build in C11 mode if you want with either of the following:

```sh
# using CMake variable
cmake -DCMAKE_BUILD_TYPE=Release -DBUILD_SHARED_LIBS=ON -DCOLRCV_C_STANDARD=11 ..
```

```sh
# using environment variable
COLRCV_C_STANDARD=11 cmake -DCMAKE_BUILD_TYPE=Release -DBUILD_SHARED_LIBS=ON ..
```

CMake will generate a build script / project for most IDEs and toolchains (including simple Makefiles). After that, use your toolchain of choice to compile the library as you normally would.
