;example-2 : an assembly language program to perform addition between 25 and 35 and store the output in R3 register of MSP432P401R. 
;Show the output in Debugging window.Syntax: ADD Operand 1 + Operand 2
    AREA main, CODE, READONLY
    EXPORT
    ENTRY main ; make main visible to linker
__main
    MOV R1, #0x25
    MOV R2, #0x34
    ADD R3, R2, R1
    ALIGN
    AREA allocations, DATA, READ WRITE
    END
  
