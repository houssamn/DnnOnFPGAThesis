#pragma ii 1
for(int b = 0 ; b < batch_size ; b++){//loop batch size
 for(int i =0 ; i < IMAGE_HEIGHT ; i++){ //img height
  for(int j = 0 ; j < IMAGE_WIDTH ; j++ ){ //img width
   for(int chout = 0 ; chout < CH_OUT ; chout++){ //output channels
   float val[WIDTH*HEIGHT*CH_IN];  //local storage of intermediate results
    for(int k = -PAD_H; k <= PAD_H ; k++ ){ //kernel height
     #pragma unroll
     for(int l = -PAD_W ; l <= PAD_W ; l++){ //kernel width
     #pragma unroll
      for(int z = 0 ; z < CH_IN  ; z++ ){ //input channels
       //Check if out of bounds
       if(i+k>=0 && i+k<IMAGE_HEIGHT && j+l>=0 && j+l<IMAGE_WIDTH){
        val[z][k+PAD_H][l+PAD_W] =
        coeff[chout][k+PAD_H][l+PAD_W][z]*input[b][i+k][j+l][z];
       }else{
        val[z][k+PAD_H][l+PAD_W] = 0.0;
       }
      }
     }
    }
    float final_val = 0.0;

    #pragma unroll
    for(int i =0; i < CH_IN*WIDTH*HEIGHT ; i++){
    //Aggregate partial sums <- reduction
     final_val += val[i];
    }

    final_val += bias_buff[chout];
    //Write Output
    output[b][i][j][chout] = relu(final_val);
    }//end chout loop

    }
  }
}
