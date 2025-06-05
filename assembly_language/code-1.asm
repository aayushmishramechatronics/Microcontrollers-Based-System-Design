;example-1 : to familiarize Keil uVision Software with MSP432P401R
    AREA main, CODE, READONLY
    EXPORT __main ;make main visible to linker
    ENTRY
__main
    MOV R0, #0
    MOV R1, #4
    MOV R2, #6
    ADD R3, R2, R1
    ALIGN
    AREA allocations, DATA, READWRITE
    END
