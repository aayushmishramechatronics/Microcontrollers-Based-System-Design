; example-3 : assembly language program to perform subtraction between 25 and 35, and store the output in R3 register of MSP432P401R. 
; show the output in debugging window. Syntax: SUB Operand 1 - Operand 2
      AREA main, CODE, READONLY
      EXPORT
      ENTRY main ; make main visible to linker
__main
      MOV R1, #0x40
      MOV R2, #0x20
      SUB R3, R1, R2
      ALIGN
      AREA allocations, DATA, READWRITE
      END
