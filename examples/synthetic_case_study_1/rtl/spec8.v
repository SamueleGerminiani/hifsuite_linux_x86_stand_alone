/* Generated by Yosys 0.47+204 (git sha1 b66897e9b, clang++ 18.1.8 -fPIC -O3) */

module spec8(clock, a_9_0, a_9_1, c_9_0, c_9_1);
  wire _00_;
  wire _01_;
  wire _02_;
  wire _03_;
  wire _04_;
  wire _05_;
  wire _06_;
  wire _07_;
  wire _08_;
  wire _09_;
  wire _10_;
  wire _11_;
  wire _12_;
  wire _13_;
  wire _14_;
  wire _15_;
  wire _16_;
  wire _17_;
  wire _18_;
  wire _19_;
  wire _20_;
  wire _21_;
  wire _22_;
  wire _23_;
  wire _24_;
  wire _25_;
  wire _26_;
  wire _27_;
  wire _28_;
  wire _29_;
  wire _30_;
  wire _31_;
  wire _32_;
  wire _33_;
  wire _34_;
  wire _35_;
  wire _36_;
  reg _37_ = 1'h0;
  input a_9_0;
  wire a_9_0;
  input a_9_1;
  wire a_9_1;
  output c_9_0;
  reg c_9_0 = 1'h0;
  output c_9_1;
  wire c_9_1;
  input clock;
  wire clock;
  assign _00_ = _35_ & _36_;
  assign _02_ = a_9_0 & a_9_1;
  assign _03_ = _02_ & _36_;
  assign _05_ = _13_ & a_9_1;
  assign _06_ = _05_ & _36_;
  assign _08_ = _30_ & c_9_0;
  assign _09_ = _02_ & _08_;
  assign _11_ = _05_ & _08_;
  assign _14_ = _35_ & _08_;
  assign _16_ = _37_ & c_9_0;
  assign _17_ = a_9_0 & _16_;
  assign _19_ = _01_ & _07_;
  assign _20_ = _34_ & _19_;
  assign _21_ = _15_ & _18_;
  assign _22_ = _12_ & _21_;
  assign _23_ = _20_ & _22_;
  assign _26_ = _04_ & _07_;
  assign _27_ = _10_ & _12_;
  assign _28_ = _26_ & _27_;
  assign _32_ = _30_ & _31_;
  assign _33_ = a_9_0 & _32_;
  assign _35_ = a_9_0 & _25_;
  assign _36_ = _37_ & _31_;
  always @(posedge clock)
    _37_ <= _24_;
  always @(posedge clock)
    c_9_0 <= _29_;
  assign _13_ = ~a_9_0;
  assign _01_ = ~_00_;
  assign _04_ = ~_03_;
  assign _07_ = ~_06_;
  assign _10_ = ~_09_;
  assign _12_ = ~_11_;
  assign _25_ = ~a_9_1;
  assign _15_ = ~_14_;
  assign _18_ = ~_17_;
  assign _24_ = ~_23_;
  assign _30_ = ~_37_;
  assign _29_ = ~_28_;
  assign _31_ = ~c_9_0;
  assign _34_ = ~_33_;
  assign c_9_1 = c_9_0;
endmodule
