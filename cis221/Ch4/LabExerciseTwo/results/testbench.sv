// Code your testbench here
// or browse Examples
module LabExerciseTwo_tb;
  reg a, b, c;
  wire G, H, I;
  
  LabExerciseTwo l2(.a(a),.b(b),.c(c),.G(G),.H(H),.I(I));
  initial begin
    $dumpfile("dump.vcd");
    $dumpvars(1);
    a=0; b=0; c=0;
    #1 
    //$display("a:%b,b:%b,c:%b ->  G:%b,H:%b,I:%b ",a,b,c,G,H,I);
    if (G == 0 & H== 0 & I== 0) $display("%b%b%b passed", a,b,c); else $error("%b%b%b failed", a,b,c);
   
    a=0; b=0; c=1;
    #1 
    //$display("a:%b,b:%b,c:%b ->  G:%b,H:%b,I:%b ",a,b,c,G,H,I);
    if (G == 0 & H== 0 & I== 1) $display("%b%b%b passed", a,b,c); else $error("%b%b%b failed", a,b,c);
    
    a=0; b=1; c=0;
    #1 
    //$display("a:%b,b:%b,c:%b ->  G:%b,H:%b,I:%b ",a,b,c,G,H,I);
    if (G == 0 & H== 1 & I== 1) $display("%b%b%b passed", a,b,c); else $error("%b%b%b failed", a,b,c);
   
    a=0; b=1; c=1;
    #1 
    //$display("a:%b,b:%b,c:%b ->  G:%b,H:%b,I:%b ",a,b,c,G,H,I);
    if (G == 0 & H== 1 & I== 0) $display("%b%b%b passed", a,b,c); else $error("%b%b%b failed", a,b,c);
    
    a=1; b=0; c=0;
    #1
    //$display("a:%b,b:%b,c:%b ->  G:%b,H:%b,I:%b ",a,b,c,G,H,I);
    if (G == 1 & H== 1 & I== 0) $display("%b%b%b passed", a,b,c); else $error("%b%b%b failed", a,b,c);
    
    a=1; b=0; c=1;
    #1
    //$display("a:%b,b:%b,c:%b ->  G:%b,H:%b,I:%b ",a,b,c,G,H,I);
    if (G == 1 & H== 1 & I== 1) $display("%b%b%b passed", a,b,c); else $error("%b%b%b failed", a,b,c);
    
    a=1; b=1; c=0;
    #1
    //$display("a:%b,b:%b,c:%b ->  G:%b,H:%b,I:%b ",a,b,c,G,H,I);
    if (G == 1 & H== 0 & I== 1) $display("%b%b%b passed", a,b,c); else $error("%b%b%b failed", a,b,c);
        
    a=1; b=1; c=1;
    #1
    //$display("a:%b,b:%b,c:%b ->  G:%b,H:%b,I:%b ",a,b,c,G,H,I);
    if (G == 1 & H== 0 & I== 0) $display("%b%b%b passed", a,b,c); else $error("%b%b%b failed", a,b,c);
    
  end

endmodule