__kernel
void example(){
  ...

  int shift_reg[SIZE]; // SIZE is a compile time constant

  while(not_finished){

    #pragma unroll   // <- must specify this
    for(int j =0 ; j < SIZE-1 ; j++){
      shift_reg[i] = shift_reg[i+1];
    }
    shif_reg[SIZE-1] = read_channel_intel(in);

    //do something

  }//end while

  ...
}
