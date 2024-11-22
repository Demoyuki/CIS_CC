// Code your design here
module LabExerciseTwo(a, b, c, G, H, I );
  input a, b, c;
  output G, H, I;
  
  assign G = a;					//G = x
  assign H = ~a & b | a & ~b;	//H = x’y + xy’
  assign I = ~b & c | b & ~c;	//I = y’z + yz’
  
endmodule