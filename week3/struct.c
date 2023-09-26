struct data {
  int x;
  int y;
};

// [] [] [] [] [] [] [] []
// x  .. .. .. y  .. .. ..

// .data
// data: .space 8

// x is at offset 0
// y is at offset 4
// lw  $t0, data+0 // $t0 = data.x
// lw  $t1, data+4 // $t1 = data.y



struct data2 {
  int x; // offset 0
  int y; // offset 4
  char z; // offset 8
  // 3 bytes of empty space in an array
};

// size 9

struct data arr[2];
// [] [] [] [] [] [] [] [] []
// x1 .. .. .. y1 .. .. .. x2 ...

struct data2 arr2[2];
// 9 not aligned to 4!
// [] [] [] [] [] [] [] [] [] []
// x1 .. .. .. y1 .. .. .. z1 ..

struct data3 {
  int x; // offset 0
  char z; // offset 4
  // 3 bytes of padding
  int y; // offset 8
};

// size 12
