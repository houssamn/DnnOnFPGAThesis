#define N 200
#define X 10

__kernel
void bad_example(__global float* restrict in,
                 __global float* restrict out){

for(int i =0; i < N; i++){
  #pragma unroll
  for(int j =0 ; j < X ; j++){
    out[i] += in[i*X + j]; // memory dependency
  }
}
