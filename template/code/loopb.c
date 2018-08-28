int x = 0, y = 0;
while (y != m) {
  compute (x,y);
  x++;
  if (x == n) {
    x = 0;
    y ++;
  }//end if
}//end while
