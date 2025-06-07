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
    


### Instruktions tabel

| Instruction | Meaning                      | Description / Use-case                                                   |
|-------------|-------------------------------|---------------------------------------------------------------------------|
| mov         | Move                          | Copies data from source to destination                                   |
| leaq        | Load Effective Address        | Computes a memory address and stores it in a register (no dereference)   |
| add         | Add                           | Adds source to destination                                               |
| sub         | Subtract                      | Subtracts source from destination                                        |
| imul        | Integer Multiply              | Multiplies operands (signed)                                             |
| idiv        | Integer Divide                | Divides `rdx:rax` by operand, quotient in `rax`, remainder in `rdx`      |
| xor         | Exclusive OR                  | Often used to zero a register (`xor %rax, %rax`)                         |
| cmp         | Compare                       | Subtracts operands and sets flags (but doesn't store result)             |
| test        | Bitwise AND + flag update     | Like `cmp`, but performs `AND`                                           |
| jmp         | Jump                          | Unconditional jump                                                       |
| je/jne      | Jump if equal / not equal     | Conditional jump based on comparison                                     |
| call        | Call function                 | Pushes return address, jumps to function                                 |
| ret         | Return                        | Pops return address into `%rip`, returns to caller                       |
| push        | Push to stack                 | Decreases `%rsp`, stores value                                           |
| pop         | Pop from stack                | Loads value from `%rsp`, then increases `%rsp`                           |

### register tabel

| Register  | Traditional Name  | Role / Typical Use                                         |
| --------- | ----------------- | ---------------------------------------------------------- |
| %rax      | Accumulator       | Return values from functions; general arithmetic           |
| %rbx      | Base              | General purpose; preserved across function calls           |
| %rcx      | Counter           | Used in loops and certain instructions                     |
| %rdx      | Data              | Function argument #2; also used in multiplication/division |
| %rsi      | Source Index      | Function argument #2 (Linux); string/memory source         |
| %rdi      | Destination Index | Function argument #1 (Linux); string/memory destination    |
| %rsp      | Stack Pointer     | Points to the top of the stack                             |
| %rbp      | Base Pointer      | Used to reference function local variables                 |
| %rip      | Instruction Ptr   | Holds address of next instruction                          |
| %r8–%r9   |                   | Function arguments #5–#6 (Linux calling convention)        |
| %r10–%r11 |                   | Scratch registers (not preserved across calls)             |
| %r12–%r15 |                   | General purpose; preserved across calls                    |
|           |                   |                                                            |
#### Caller eller callee register

| Register | Funktion        | Bevares af | Brug                                       |     |
| -------- | --------------- | ---------- | ------------------------------------------ | --- |
| %rax     | Returnværdi     | Caller     | Return value, midlertidige beregninger     |     |
| %rbx     | General purpose | Callee     | Skal gendannes af callee                   |     |
| %rcx     | 4. parameter    | Caller     | Bruges også til loops og system calls      |     |
| %rdx     | 3. parameter    | Caller     | Funktionens tredje argument                |     |
| %rsi     | 2. parameter    | Caller     | Funktionens andet argument                 |     |
| %rdi     | 1. parameter    | Caller     | Funktionens første argument                |     |
| %r8      | 5. parameter    | Caller     | Funktionens femte argument                 |     |
| %r9      | 6. parameter    | Caller     | Funktionens sjette argument                |     |
| %r10     | Midlertidig     | Caller     | Bruges til system calls og intern brug     |     |
| %r11     | Midlertidig     | Caller     | Bruges til system calls og intern brug     |     |
| %r12     | General purpose | Callee     | Skal gendannes af callee                   |     |
| %r13     | General purpose | Callee     | Skal gendannes af callee                   |     |
| %r14     | General purpose | Callee     | Skal gendannes af callee                   |     |
| %r15     | General purpose | Callee     | Skal gendannes af callee                   |     |
| %rbp     | Frame pointer   | Callee     | Bruges ofte til stack-frame (kan udelades) |     |
| %rsp     | Stack pointer   | Callee     | Skal altid bevares korrekt (automatisk)    |     |### Størrelses suffixer

| Suffix | Navn (traditionel) | Bitstørrelse | Antal bytes | Bruges til registre        | Eksempelinstruktion | Tilhørende typer |
| ------ | ------------------ | ------------ | ----------- | -------------------------- | ------------------- | ---------------- |
| b      | Byte               | 8 bits       | 1 byte      | `%al`, `%bl`, `%cl`, `%dl` | `movb $1, %al`      | char             |
| w      | Word               | 16 bits      | 2 bytes     | `%ax`, `%bx`, `%cx`, `%dx` | `movw $1, %ax`      | short            |
| l      | Long               | 32 bits      | 4 bytes     | `%eax`, `%ebx`, `%ecx`     | `movl $1, %eax`     | int              |
| q      | Quadword           | 64 bits      | 8 bytes     | `%rax`, `%rbx`, `%rcx`     | `movq $1, %rax`     | long             |

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