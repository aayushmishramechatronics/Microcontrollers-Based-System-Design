; example-6 : an assembly language code to perform logical operations in ARM Cortex M4F core and mention the flag updates.
    AREA main, CODE, READONLY
    EXPORT __main ; make main visible to linker
    ENTRY
__main
    MOV R1, #0x01
    MOV R2, #0x01 
    ANDS R1, R2
    BICS R1, R2
    EORS R1, R2
    ORNS R1, R2
    ORRS R1, R2
Here B Here
ENDP
    ALIGN
    AREA allocations, DATA, READWRITE
END
