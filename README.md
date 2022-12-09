## EmbedRT

EmbedRT is a shorthand for Embedded Reactive Tensor, a math processing compiler for x86_64 & ARM based targets. ASIC & FPGA support is also in pipeline. 


### EmbedRT has three components

- Utils - A set of highly deterministic high precision timing utilities.
- Tensor Library - High level algebra and computation library.
- Device Library - This supports cross-target compilation for ARM targets.


### Documentation

For extra precision timers - 

rdtsc() returns the number of "nominal" processor cycles since the system booted in a 64-bit unsigned integer. For all recent Intel processors, this counter increments at a fixed rate, independent of the actual core clock speed or the energy-saving mode.

rdtscp() 
is the same as rdtsc except that it is partially ordered -- it will not execute until all prior instructions in program order have executed. 

full_rdtscp() 
returns the number of "nominal" processor cycles in a 64-bit unsigned integer and also modifies its two integer arguments to show the processor socket and processor core that were in use when the call was made.  (Note: the various cores in a chip usually have very similar values for the TSC, but they are allowed to vary by processor.  This function guarantees that you know exactly which processor the TSC reading came from.)

get_core_number() 
uses the RDTSCP instruction, but returns only the core number in an integer variable.

get_socket_number() 
uses the RDTSCP instruction, but returns only the socket number in an integer variable.

rdpmc_instructions() 
uses a "fixed-function" performance counter to return the count of retired instructions on the current core in the low-order 48 bits of an unsigned 64-bit integer.

rdpmc_actual_cycles() 
uses a "fixed-function" performance counter to return the count of actual CPU core cycles executed by the current core.  Core cycles are not accumulated while the processor is in the "HALT" state, which is used when the operating system has no task(s) to run on a processor core.

rdpmc_reference_cycles() 
uses a "fixed-function" performance counter to return the count of "reference" (or "nominal") CPU core cycles executed by the current core.  This counts at the same rate as the TSC, but does not count when the core is in the "HALT" state.  If a timed section of code shows a larger change in TSC than in  rdpmc_reference_cycles, the processor probably spent some time in a HALT state.

rdpmc() 
reads the programmable core performance counter number specified in the input argument. No error or bounds checking is performed.

 get_TSC_frequency() 
 parses the Brand Identification string from the CPUID instruction to get the "nominal" frequency of the processor, which is also the invariant TSC frequency, and returned as a float value in Hz. This can then be used to convert TSC cycles to seconds.

