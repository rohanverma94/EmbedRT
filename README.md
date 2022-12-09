## EmbedRT

EmbedRT is a shorthand for Embedded Reactive Tensor, a math processing compiler for x86_64 , Nvidia GPUs and ARM based targets. ASIC & FPGA support is also in pipeline. 


### EmbedRT has three components

- Utils - A set of highly deterministic high precision timing utilities.
- Tensor Library - High level algebra and computation library backed by JIT and GPU acceleration.
- Device Library - This supports cross-target compilation for ARM targets.

### Requirements ###

*  LLVM 12.0 (Build scripts included in project)
*  Linux 64 bit, preferable CentOS 7 or Fedora 34+ or Rocky Linux
*  AMD64 ABI. Can be found [here](https://software.intel.com/sites/default/files/article/402129/mpx-linux64-abi.pdf).
*  C++ 17/20 enabled compiler (>= g++ 11).
*  LLVM requires CMake 3.18 to build
*  For more info look at [LLVM DOCS](https://llvm.org/docs/GettingStarted.html).


### How to get started? ###

* Setup & Install LLVM 12.0.
* Also setup clang , compiler-rt , dragonegg, libcxx, libcxxabi, libunwind, lld, lldb,openmp & polly.
* LLVM Tutorial for making languages, which can be found [here](https://llvm.org/docs/tutorial/)