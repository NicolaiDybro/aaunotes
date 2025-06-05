


- Historie, assembly og objektkode (brug af `gcc`, `as`, `gdb`, `objdump`).
    - Instruktionssæt arkitektur.
    - Dataenheder: Words (Q=Quad word (8 bytes), L=Long word (4 bytes), W=Word (2 bytes), B=Byte (1 byte)).
    - Registrer: Generelle formålsregistre (f.eks. `rax`, `rbx`, `rcx`, `rdx`, `rsi`, `rdi`, `rbp`, `rsp`, `r8-r15`).
    - Adressering: `Immediate` (konstante værdier), `Registrer` (værdier i registre), `Mem` (værdier i hukommelsen via forskellige adresseringsformer).
    - Aritmetiske og logiske operationer.
- **x86 Assembler: Kontrol- ogdatastrukturer:**
    - Sammenligninger og betingelsesflag (CF, ZF, SF, OF, AF, PF).
    - Selektion (`if-then-else`, betinget tildeling).
    - Iteration (`while`, `do-while`, `for`).
    - Datastrukturer: Layout af arrays (1D og 2D), indeksering, structs, alignment.


**Kalder/kaldte gemte registre:**

- **Caller-saved registres (Caller-gemt):** Registre, hvis værdier skal gemmes af _kalderen_ (den funktion, der kalder en anden funktion), hvis kalderen har brug for dem efter kaldet. Eksempler: `rdi`, `rsi`, `rdx`, `rcx`, `r8`, `r9`, `rax`.
- **Callee-saved registres (Kaldte-gemt):** Registre, hvis værdier _skal_ bevares af den _kaldte_ funktion. Hvis den kaldte funktion modificerer disse registre, skal den gemme deres oprindelige værdier på stakken ved start og gendanne dem før retur. Eksempler: `rbx`, `rbp`, `r12`, `r13`, `r14`, `r15`.

## Bufferoverflow

- Bufferoverflow opstår, når data overskriver nærliggende hukommelse.
    
- Kan føre til:
    
    - Kodeeksekvering.
        
    - Ændring af returadresser.
        
    - Uautoriseret adgang til data.
        
- Eksempler:
    
    - **Stack Overflow**: Overskrivning af return pointer.
        
    - **Heap Overflow**: Manipulation af heap metadata.
        
    - **Format string attacks**: Brug af usikre printf-funktioner.
___
## Forebyggelse af buffer overflow

- **Bounds checking**: Sørg for at begrænse bufferstørrelse.
    
- **Canaries**: Tilføj specielle værdier på stacken til at opdage overskrivninger.
    
- **Address Space Layout Randomization (ASLR)**: Gør det sværere at forudsige adresser.
    
- **Data Execution Prevention (DEP)**: Blokerer eksekvering af kode i data-sektioner.


___
