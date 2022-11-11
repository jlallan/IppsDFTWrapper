# IppsDFTWrapper

This project is a simple wrapper for the Complex 1-D Discrete Fourier Transform
(DFT) functions of the [Intel Integrated Performance Primitives (IPP)](https://www.intel.com/content/www/us/en/developer/tools/oneapi/ipp.html)
library in C. The goal is to remove the burden of buffer allocation and
management from the user and make the Intel IppsDFT library easier to use.

## Usage
IppsDFTWrapper supports four IPP precisions. Most IppsDFTWrapper functions and
datatypes have a base name and a suffix indicating the datatype precision. The
supported precisions (and suffixes) are:
- Real: `Ipp32f (32f)` and `Ipp64f (64f)`
- Complex: `Ipp32fc (32fc)` and `Ipp64fc (64fc)`

The IppsDFTWrapper process is as follows:
1. Declare a DFTSpec pointer
2. Intialize the DFTSpec with a transform size and division flag.
3. Execute the forward and inverse transforms as many times as needed.
4. Free the DFTSpec pointer.

## Division Flags
Supported division flags include:
- `DIV_FWD_BY_N`
- `DIV_INV_BY_N`
- `DIV_BY_SQRTN`
- `NODIV_BY_ANY`

## Example Usage
For a complex 32-bit float transform of data in `Ipp32fc* pSrc` to `Ipp32fc* pDst`:

```c
/* Complex Float Example in C */
int length = 1024;
int divflag = DIV_BY_SQRTN;
DFTSpec* spec;
dft_init_32fc(&spec, length, divflag);
dft_fwd_32fc(spec, pSrc, pDst); /* can repeat with different buffers */
dft_inv_32fc(spec, pDst, pSrc); /* can repeat with different buffers */
dft_free(spec);
```

For a separate real and imaginary 64-bit float transform of the data in
`Ipp64f* pSrcRe` and `Ipp64f* pSrcIm` to `Ipp64f* pDstRe` and
`Ipp64f* pDstIm`:

```c
/* Separated Double Example in C */
int length = 1024;
int divflag = DIV_INV_BY_N;
DFTSpec* spec;
dft_init_64f(&spec, length, divflag);
dft_fwd_64f(spec, pSrcRe, pSrcIm, pDstRe, pDstIm); /* can repeat with different buffers */
dft_inv_64f(spec, pDstRe, pDstIm, pSrcRe, pSrcIm); /* can repeat with different buffers */
dft_free(spec);
```

## Compiling
This repository includes a simple Makefile suitable for basic needs and
shows how to compile the library for single and double precisions.

Once `autoconf` is set up and working properly, this Makefile will eventually be
replaced to standardize the install process.

## License
MIT License - Copyright (c) 2022 James Allan

See the LICENSE file in this repository for full information.
