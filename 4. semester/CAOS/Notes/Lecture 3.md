
* Skriv noter vedr. lidt notation omkring register og hukommelse
* Skriv noter vedr. fuldstædnige adresseudtryk


# Assembler programmering i x86-64

## Hvad er en ISA?

- ISA (Instruction Set Architecture) er den del af processorens design, som man skal forstå for at kunne læse/skrive assembler og maskinkode.
- Det er et slags "API" for processoren.
- X86-64 er en 64-bit ISA, der er udviklet af Intel.

## Hukommelse

- Hukommelsen er et stort array af bytes, der kan indeholde både data og instruktioner.
- Hver byte har en unik adresse.
- X86-64 er "little endian", hvilket betyder, at de mindst betydende bytes er gemt først i hukommelsen.

## Registre

- Processoren har et lille antal interne lagerpladser, der kaldes registre.
- Registre er meget hurtigere at tilgå end hukommelsen.
- X86-64 har 16 almene registre, der hver er 64 bits brede.
- Der er også en række specialiserede registre, f.eks. stakpointeren (%rsp) og instruktionspointeren (%rip).

![[x64_cheatsheet.pdf]]

## Instruktioner

- En instruktion er en kommando, der fortæller processoren, hvad den skal gøre.
- Instruktioner består typisk af en opcode (operation) og en eller flere operander.
- Operander kan være registre, hukommelsesadresser eller konstanter.
- X86-64 har et stort og komplekst sæt af instruktioner.

## Adressering

- Adressering er den måde, hvorpå man angiver, hvor data skal læses fra eller skrives til.
- X86-64 har en række forskellige adresseringsmåder, der giver mulighed for at adressere data på mange forskellige måder.
- Nogle af de mest almindelige adresseringsmåder er:
    - Register: Data er i et register.
    - Immediate: Data er en konstant.
    - Direct: Data er i en bestemt hukommelsesadresse.
    - Indirect: Data er i en hukommelsesadresse, der er gemt i et register.

## Datatyper

- X86-64 understøtter en række forskellige datatyper, herunder:
    - Heltal: 1, 2, 4 eller 8 bytes.
    - Flydende tal: 4, 8 eller 10 bytes.
    - Pointers: 8 bytes.

## Aritmetik

- X86-64 har en række instruktioner til at udføre aritmetiske operationer, herunder:
    - Addition: `add`
    - Subtraktion: `sub`
    - Multiplikation: `mul`
    - Division: `div`
    - Skift: `shl`, `shr`

## Logik

- X86-64 har også en række instruktioner til at udføre logiske operationer, herunder:
    - And: `and`
    - Or: `or`
    - Xor: `xor`
    - Not: `not`

## Kontrolstruktur

- X86-64 har instruktioner til at ændre rækkefølgen af instruktioner, herunder:
    - Hop: `jmp`
    - Betinget hop: `je`, `jne`, `jg`, `jl`, osv.
    - Kald: `call`
    - Retur: `ret`

## Procedurer

- Procedurer er en måde at opdele et program i mindre, genanvendelige enheder.
- X86-64 bruger stakken til at overføre parametre til og fra procedurer.

## Assembler sprog

- Assembler sprog er et lav-niveau sprog, der er meget tæt på maskinkode.
- Assembler sprog er specifikt for hver ISA.
- Det er svært at programmere i assembler, men det giver mulighed for at optimere sin kode.

## Værktøjer

- Der findes en række værktøjer, der kan bruges til at udvikle assembler programmer, herunder:
    - Assembler: `as`
    - Linker: `ld`
    - Debugger: `gdb`
    - Disassembler: `objdump`


## Eksempel

```
movq $5, %rax # Flyt 5 ind i register %rax
addq $3, %rax # Adder 3 til register %rax
```