; example - 5 : an assembly language code to perform shift and rotate in ARM Cortex M4F core.   
    AREA main, CODE, READONLY
    EXPORT __main ; make main visible to linker
    ENTRY
__main
    MOV R1, #0x4
    MOV R2, #0x5A5A
    LSR R2, R1
    ASR R2, R1
    LSL R2, R1
    ROR R2, R1
    RRX R2, R1
Here B Here
    ENDP
    ALIGN
    AREA allocations, DATA, READWRITE
END
