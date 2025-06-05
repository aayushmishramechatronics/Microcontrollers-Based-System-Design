; example-8 : an assembly language code to perform Multiplication and Division in ARM Cortex M4F.
    AREA main, CODE, READONLY
    EXPORT __main ; make main visible to linker
    ENTRY
__main
    MOV R1, #0x0FF
    MOV R2, #0x0FF
    MUL R3, R1, R2
    MLA R4, R3, R1, R2
    MLS R5, R3, R1, R2
    UMULL R1, R2, R3, R4
    UMLAL R1, R2, R3, R4
    SMULL R1, R2, R3, R4
    SMLAL R1, R2, R3, R4
    SDIV R3, R1, R2
    UDIV R1, R2, R3
Here B Here
ENDP
    ALIGN
    AREA allocations, DATA, READWRITE
END
