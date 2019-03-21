## XNOR-Count
The calculations in the BNN become bit operations, a 32-bit multiplication loses 200 units, and a bit operation loses 1 unit.

## Optimization
- For bit operations, the SIMD parallelization instructions in the SWAR can be used for acceleration. The 32 binarized variables are stored in a 32-bit register, resulting in a 32x acceleration.

- In the process of neural network propagation, you can use SWAR technology to calculate 32 Connections using 3 instructions, as follows, so the original 32 time units now (accumulation, popcount, xnor) = 1 + 4 + 1 = 6 units Can be done, up to 5.3 times.
