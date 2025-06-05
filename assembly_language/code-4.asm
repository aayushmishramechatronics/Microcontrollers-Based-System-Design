; example-4 : an Assembly language code to perform data movement in ARM Cortex M4F core
      AREA main, CODE, READONLY
      EXPORT __main ; make main visible to linker
      ENTRY
__main
      MOV R1, #0x40
      MOV R2, #0x20
      MOVT R3, #0xFFFFFFFF
      MOVW R4, #0xFFFFFFFF
      MVN R5, #0x0FF, #2
  Here B Here
      ENDP
      ALIGN
      AREA allocations, DATA, READWRITE
  END
