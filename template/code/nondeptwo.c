#define N 200
#define X 10

__kernel
void good_example(__global float* restrict in,
                 __global float* restrict out){

for(int i =0; i < N; i++){


  float temp[X];
  float temp_sum = 0.0

  #pragma unroll
  for(int j =0 ; j < X ; j++){
    temp[j] = in[i*X + j];        // local array <- mem
  }

  #pragma unroll
  for(int j =0 ; j < X ; j++){
    temp_sum += temp[j]; //  register <- local array
  }

  out[i] = temp_sum; // mem <- register
}
