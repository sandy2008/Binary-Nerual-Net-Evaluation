`for (int j = 0; j < BLOCK_SIZE; ++j) Cvalue += __popc(A[row][j]^B[j][col]);`

- Rewrote
```
#define CEIL_POS(X) ((X-(int)(X)) > 0 ? (int)(X+1) : (int)(X))

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

- Benchmark
```
	auto test_gemm = [&]() {
		cudaMemset(fC, 0, N * N * sizeof(int));
		dim3 blockDim(16, 16);
		dim3 gridDim(N / 16 + 1, N / 16 + 1);
		auto start = chrono::high_resolution_clock::now();
		gemm<<<gridDim, blockDim>>>(fA, fB, fC, N, N, N);
		cudaDeviceSynchronize();
		auto end = chrono::high_resolution_clock::now();
		chrono::duration<double> diff = end - start;
		cout << "GEMM kernel time: " << diff.count() << " s\n";

		float* result = (float*)malloc(N * N * sizeof(float));
		cudaMemcpy(result, fC, N * N * sizeof(float), cudaMemcpyDeviceToHost);
		return result;
	};
	float* result_gemm = test_gemm();
  ```
  
  - Brnchmark
  ```
  	auto test_cublas = [&]() {
		cudaMemset(fC, 0, N * N * sizeof(int));
		cublasHandle_t handle;
		cublasCreate(&handle);

		auto start = chrono::high_resolution_clock::now();
		float alpha = 1.0, beta = 0.0;
		// cublas use column-major
		cublasSgemm(handle, CUBLAS_OP_N, CUBLAS_OP_N, N, N, N, &alpha, fB, N, fA, N, &beta, fC, N);
		cudaDeviceSynchronize();
		auto end = chrono::high_resolution_clock::now();
		chrono::duration<double> diff = end - start;
		cout << "cublas time: " << diff.count() << " s\n";

		float* result = (float*)malloc(N * N * sizeof(float));
		cudaMemcpy(result, fC, N * N * sizeof(float), cudaMemcpyDeviceToHost);
		return result;
	};
	float* result_cublas = test_cublas();
  ```
