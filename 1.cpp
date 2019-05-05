#include <stdio.h>
#include <stdint.h>
#include <time.h>

#define CEIL_POS(X) ((X-(int)(X)) > 0 ? (int)(X+1) : (int)(X))


static int popcnt8(const uint8_t v) {
  uint8_t c;
  c = v - ((v >> 1) & 0x55);
  c = ((c >> 2) & 0x33) + (c & 0x33);
  return ((c >> 4) + c) & 0x0F;
}

static int popcnt16(const uint16_t v) {
  uint16_t c;
  c = v - ((v >> 1) & 0x5555);
  c = ((c >> 2) & 0x3333) + (c & 0x3333);
  return ((c >> 4) + c) & 0x000F;
}

static int popcnt32(const uint32_t v) {
  uint16_t c;
  c = v - ((v >> 1) & 0x55555555);
  c = ((c >> 2) & 0x33333333) + (c & 0x33333333);
  return ((c >> 4) + c) & 0x0000000F;
}

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

static int bdot16(const uint16_t* A, const uint16_t* B, const int N)
{
  int i, num_bytes, res;

  num_bytes = CEIL_POS(N/16.0);
  res = 0;
  for (i = 0; i < num_bytes; ++i) {
    res += popcnt16(~(A[i]^B[i]));
  }
  res = res*2 - N;
  return res;
}


static char* test_bdot_1()
{
  uint8_t A_in[3] = {1,175,248};
  uint8_t B_in[3] = {108,178,223};
  int actual = 1;
  int N = 21;
  int comp;
  char output_msg[] = "\nTEST: bdot_1\nOutput Mismatch: \nComputed=%d, Actual=%d\n";

  /* 21 len vector input */
  comp = bdot(A_in, B_in, N);
  // printf(output_msg, comp, actual);
}

static char* test_bdot_2()
{
  uint8_t A_in[13] = {255,255,255,255,255,255,255,255,255,255,255,255,240};
  uint8_t B_in[13] = {255,255,255,255,255,255,255,255,255,255,255,255,255};
  int actual = 100;
  int N = 100;
  int comp;
  char output_msg[] = "\nTEST: bdot_2\nOutput Mismatch: \nComputed=%d, Actual=%d\n";

  /* 100 len vector input (all 1s) */
  comp = bdot(A_in, B_in, N);
  // printf(output_msg, comp, actual);
}

static char* test_bdot_3()
{
  uint8_t A_in[13] = {0,0,0,0,0,0,0,0,0,0,0,0,0};
  uint8_t B_in[13] = {255,255,255,255,255,255,255,255,255,255,255,255,255};
  int actual = -100;
  int N = 100;
  int comp;
  // char output_msg[] = "\nTEST: bdot_3\nOutput Mismatch: \nComputed=%d, Actual=%d\n";

  /* 100 len vector input (A -1s, B 1s) */
  comp = bdot(A_in, B_in, N);
  // printf(output_msg, comp, actual);
}

static char* test_bdot16_3()
{
  uint16_t A_in[7] = {0,0,0,0,0,0,0};
  uint16_t B_in[7] = {65535,65535,65535,65535,65535,65535,255};
  int actual = -100;
  int N = 100;
  int comp;
  // char output_msg[] = "\nTEST: bdot_16_3\nOutput Mismatch: \nComputed=%d, Actual=%d\n";

  /* 21 len vector input */
  comp = bdot16(A_in, B_in, N);
  // printf(output_msg, comp, actual);
}

int main( int argc, const char* argv[] )
{
  clock_t tStart = clock();

  for (int i = 0; i <= 10000000; i++){
  test_bdot_3();
  }
  printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
  
  clock_t tStart2 = clock();
  for (int i = 0; i <= 10000000; i++){
  test_bdot16_3();
  }
  printf("Time taken: %.2fs\n", (double)(clock() - tStart2)/CLOCKS_PER_SEC);
}