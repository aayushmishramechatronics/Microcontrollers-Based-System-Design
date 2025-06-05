; example-9 : an assembly language program to perform data in accessed memory locations.
    AREA main, CODE, READONLY
    EXPORT __main
    ENTRY
__main
    LDR R1, =0x20000000 ;R1=0x20000000
    LDR R2, =0x64156415
    STR R2, [R1] ;Store R2 to location 0x20000000
    ADD R1, R1, #1 ;R1 = R1 + 1 = 0x20000001
    STR R2, [R1] ;Store R2 to location 0x20000001
    ADD R1, R1, #1 ;R1 = R1 + 1 = 0x20000002
    STR R2, [R1] ;Store R2 to location 0x20000002
    ADD R1, R1, #1 ;R1 = R1 + 1 = 0x20000003
    STR R2, [R1] ;Store R2 to location 0x20000003
END
