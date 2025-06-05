

# Instruktioner (Subset):

- `halt`: Stopper processoren.
- `nop`: No operation (gør ingenting).
- `rrmovq rA, rB`: Register-til-register flytning.
- `irmovq V, rB`: Immediat værdi til register.
- `rmmovq rA, D(rB)`: Register til hukommelse.
- `mrmovq D(rB), rA`: Hukommelse til register.
- `OPq rA, rB`: Aritmetiske/logiske operationer (f.eks. `addq`, `subq`, `andq`, `xorq`).
- `jmp Dest`: Ubetinget jump.
- `jXX Dest`: Betinget jump (f.eks. `je`, `jne`, `jl`, `jle`, `jg`, `jge`).
- `call Dest`: Procedurekald (lægger returadresse på stakken, hopper til Dest).
- `ret`: Returnerer fra procedure (fjerner returadresse fra stakken og hopper dertil).
- `pushq rA`: Lægger registerværdi på stakken.
- `popq rA`: Fjerner værdi fra stakken og lægger i register.

# Programmeringssynligt Tilstand
- **PC (Program Counter):** Adressen på den næste instruktion der skal udføres.
- **CC (Condition Codes):** Betingelsesflag (ZF, SF, OF) der angiver resultatet af seneste ALU-operation. Bruges til betingede jumps.
- **Stat Registre (F-status):** Angiver programmets status:
    - `AOK`: Normal drift.
    - `HLT`: Processor stoppet af `halt` instruktion.
    - `ADR`: Ugyldig adresse (f.eks. forsøg på at tilgå ikke-eksisterende hukommelse).
    - `INS`: Ugyldig instruktion (f.eks. ukendt opkode).
- **Reg (Registrefil):** 15 individuelle registre, hver 64-bit bred. Inkluderer `%rsp` (stakpointer).
- **Mem (Hukommelse):** Stor array af bytes. Virtuelt adresseret.


# SEQ Eksekvering Eksempel
- **Detaljeret gennemgang af et simpelt program:**
    ```
    irmovq $0x100,%rbx # %rbx <-- 0x100
    irmovq $0x200,%rdx # %rdx <-- 0x200
    addq %rdx,%rbx     # %rbx <-- %rbx + %rdx = 0x300
    je dest            # jump hvis ZF=1, men ZF=0, så fortsæt
    rmmovq %rbx,0(%rdx) # M[0x200] <-- %rbx = 0x300
    ```
- **Fokus på `addq` og `je`:**
    - `addq` opdaterer betingelsesflag (her `ZF` til 0, da resultatet 0x300 ikke er nul).
    - `je` kontrollerer `ZF`. Da `ZF` er 0, tages hoppet ikke, og PC opdateres sekventielt til den næste instruktion.