## Kontrol og Arrays

### Højniveau kontrol-strukturer i assembler:

- If-then-else
    
- While loops
    
- Hvordan maskinen håndterer betingelser (if a < b)
    
- Repræsentation af sammensatte datatyper (1D og 2D arrays, structs)
    

## x86-64 Assembler - Introduktion

- Adressering:
    
    - Immediate, registre, hukommelse (mem)
        
- Instruktionssæt arkitektur
    
- Registre:
    
    - Words (Q, L, W, B)
        
    - RAX, RBX, RCX, RDX osv.
        
- Aritmetiske og logiske operationer
    

## Kontrol- og datastrukturer

- Sammenligning & betingelsesflag:
    
    - CF (Carry Flag, unsigned)
        
    - SF (Sign Flag, signed)
        
    - ZF (Zero Flag)
        
    - OF (Overflow Flag, signed)
        
- Selektion:
    
    - If-then-else
        
    - Betinget tildeling
        
- Iteration:
    
    - While, Do-While, For loops
        
- Datastrukturer:
    
    - 1D & 2D arrays, structs, alignment
        

## Procedurekald i x86

- Stack operationer (Push/Pop)
    
- Kald og retur (Call/Ret)
    
- Parameteroverførsel
    
- Stack-frame & lokale variable
    
- Rekursion
    
- Buffer-overløb & sikkerhedsforanstaltninger (canaries, ASLR, NX stack)
    

## Betingelser i Assembler

### Implicit tildeling af condition codes:

- Aritmetiske operationer sætter betingelsesflag
    
- Eksempel: `addq Src, Dest`
    
    - CF = 1 ved mente fra mest betydende bit
        
    - ZF = 1 hvis resultatet er 0
        
    - SF = 1 hvis resultatet er negativt
        
    - OF = 1 ved signed overflow
        

### Explicit tildeling af condition codes:

- `cmpq Src2, Src1` (beregner a - b uden at ændre destination)
    
- `test` instruktion (bruger AND)
    

### Aflæsning af condition codes:

- `sete` (Equal/Zero)
    
- `setg` (Greater, signed)
    
- `seta` (Above, unsigned)
    
- `setl` (Less, signed)
    
- `setb` (Below, unsigned)
    

## Kontrolstrukturer i Assembler

### Ubetingede hop (jmp):

- Direkte: `jmp label`
    
- Indirekte: `jmp *%rax`
    

### Betingede hop (jX):

- `je` (ZF = 1, Equal/Zero)
    
- `jg` (Signed greater)
    
- `jl` (Signed less)
    
- `ja` (Unsigned above)
    
- `jb` (Unsigned below)
    

### If-else i Assembler:

```
cmpq %rsi, %rdi
jle .L4
movq %rdi, %rax
subq %rsi, %rax
ret
.L4:
movq %rsi, %rax
subq %rdi, %rax
ret
```

### Do-While Loop:

```
movl $0, %eax  # result = 0
.L2:
movq %rdi, %rdx
andl $1, %edx
addq %rdx, %rax
shrq %rdi
jne .L2
ret
```

## Arrays i x86-64

### 1D Arrays:

- Allokering:
    
    - `int val[5]` tildeler sammenhængende hukommelse
        
- Indeksering:
    
    - `movl (%rdi,%rsi,4), %eax` (hent `val[digit]`)
        

### 2D Arrays (Row-Major Layout):

- Adresseberegning:
    
    - `A + i * (C * K) + j * K`
        

Eksempel:

```
leaq (%rdi,%rdi,4), %rax  # 5*index
addl %rax, %rsi  # 5*index+dig
movl pgh(,%rsi,4), %eax
```

## Optimale adgangsmønstre

- Pointerbaseret iteration optimerer loop-performance
    

```
movl (%rdi), %edx
imull (%rcx), %edx
addl %edx, %eax
addq $4, %rdi
addq $64, %rcx
cmpq %rsi, %rcx
jne .L3
```

## Strukturer (Structs) i x86-64

- Medlemmer placeres i samme rækkefølge som erklæring
    
- Alignment (padding) anvendes for effektiv adgang
    

Eksempel:

```
leaq (%rdi,%rsi,4), %rax  # r->a[idx]
ret
```

## Optimering af plads

- Omlistning af struct-medlemmer reducerer padding
    

```
struct S5 {
    int i;
    char c;
    char d;
};
```

Giver 8MB i stedet for 12MB (33% besparelse ved 1 mio. elementer)