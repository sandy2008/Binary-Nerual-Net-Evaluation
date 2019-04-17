`for (int j = 0; j < BLOCK_SIZE; ++j) Cvalue += __popc(A[row][j]^B[j][col]);`

- Rewrote
```
static int bdot(const uint8_t* A, const uint8_t* B, const int N)
{
  int i, num_bytes, res;

  num_bytes = CEIL_POS(N/8.0);
  res = 0;
  for (i = 0; i < num_bytes; ++i) {
    res += popcnt8(~(A[i]^B[i]));
  }
  res = res*2 - N;
  return res;
}
```
