## EmbedRT

EmbedRT is a shorthand for Embedded Reactive Tensor, a math processing compiler for x86_64, RISC-V and ARM64 based targets. 

This project is actively back into the development. Keep a watch here. 

### EmbedRT has three components

- Utils - A set of highly deterministic high precision timing utilities.
- Tensor Library - High level algebra and computation library backed by JIT.
- Device Library - This supports cross-target compilation for ARM targets.

### Requirements ###

*  LLVM 20.0 (Build scripts included in project)
*  Linux 64 bit, based on debian and fedora.
*  AMD64 ABI. Can be found [here](https://software.intel.com/sites/default/files/article/402129/mpx-linux64-abi.pdf).
*  C++ 20 enabled compiler (>= clang 14).
*  LLVM requires CMake 3.18 to build
*  For more info look at [LLVM DOCS](https://llvm.org/docs/GettingStarted.html).

For CUDA setup, check nvidia docs. This might not work with nouveau drivers.
