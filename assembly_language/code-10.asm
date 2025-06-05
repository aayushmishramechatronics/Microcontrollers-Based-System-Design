; example-10: an assembly language program to perform the addition of the number A5 ten times.
    AREA SATURATION, CODE, READONLY
    EXPORT __main
    ENTRY
__main
    MOV R0, #10
    MOV R1, #0
    MOV R2, #0xA5
  loop ADD R1, R2
    SUBS R0, #1;
    BNE Here
END
