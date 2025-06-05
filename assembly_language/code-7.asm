; example-7 : an assembly language code to perform arithmetic operations in ARM Cortex M4F core and mention the flag updates.
    AREA main, CODE, READONLY
    EXPORT __main ; make main visible to linker
    ENTRY
__main
    MOV R1, #0x01
    MOV R2, #0x01
    ADDS R1, R2
    ADCS R1, R2
    SUBS R1, R2
    SBCS R1, R2
    RSBS R1, R2
    ADDW R1, R2, #0xFFF
    SUBW R1, R2, #0xFFF
Here B Here
    ALIGN
    AREA allocations, DATA, READWRITE
END
