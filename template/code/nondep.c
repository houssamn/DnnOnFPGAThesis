#define N 200
#define X 10

__kernel
void good_example(__global float* restrict in,
                 __global float* restrict out){

for(int i =0; i < N; i++){
  float temp=0.0;

  #pragma unroll
  for(int j =0 ; j < X ; j++){
    temp += in[i*X + j];        //  register <- mem
  }

  out[i] = temp; // mem <- register
}
