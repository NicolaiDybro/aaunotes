


# Session 1 - Introduction: Compilers and Programming Languages


## What is a Compiler?
A **compiler** is a program that:
1. Reads and analyzes source code.
2. Translates the source code into **machine code** or another executable form.
3. Produces an executable file that can be run later.

### Advantages:
- **Faster execution**, since the program is already translated.
- **Optimization opportunities**, as the compiler can improve the code.

### Disadvantages:
- **Longer development process**, since the entire program must be compiled before testing.

Examples of compiled languages: **C, C++, Rust, Go**.

## What is an Interpreter?
An **interpreter** is a program that:
4. Reads and analyzes source code.
5. Executes the program directly without generating an executable file.

### Advantages:
- **Faster development process**, since code can be tested immediately.
- **More flexible debugging**, as the program can be executed line by line.

### Disadvantages:
- **Slower execution**, since the code is analyzed each time it runs.
- **Platform-dependent**, unless implemented in a cross-platform runtime.

Examples of interpreted languages: **Python, JavaScript, Ruby**.

## Front End of a Compiler / Interpreter
The **front end** is responsible for transforming a **character string** (program text) into an **abstract syntax tree (AST)**.

6. **Lexical Analysis (Tokenization)**
   - Splits the program into **tokens** (syntactic units).
   - Example: `int x = 5;` → [`int`, `x`, `=`, `5`, `;`]

7. **Syntax Analysis (Parsing)**
   - Checks if the sequence of tokens matches the **grammar** of the language.
   - If valid, produces an **AST**.
   - Eksempelvis ved et for loop, så er der et syntaks træ der kigger på parenteser

8. **Type Checking**
   - Ensures that variables and operations have valid types.
   - Example: `int x = "hello";` would fail.

## Back End of a Compiler
The **back end** of a compiler takes the AST and translates it into an executable form:

9. **AST Optimization**
   - Eliminates redundant instructions.
   - Restructures code for better performance.

10. **Intermediate Representation (IR) Generation**
   - Many compilers use an intermediate step between AST and machine code.
   - Example: **LLVM IR**.

11. **Code Generation**
   - Converts IR into **machine code** or **bytecode**, depending on the target system.

## Back End of an Interpreter
Instead of generating machine code, an interpreter directly executes the AST:

12. **AST Traversal**
   - The interpreter walks through the AST and evaluates nodes.

13. **Bytecode (Optional)**
   - Some interpreters (e.g., Python) convert the AST into **bytecode** (e.g., `.pyc` files), which speeds up execution.

## Choosing Between an Interpreter and a Compiler
- **Compiler:** Best when **execution speed** and **optimization** matter.
- **Interpreter:** Best for **flexibility** and **rapid testing**.

## Abstract Syntax and Language Specification
To specify the **syntax** of a programming language, we use:

- **Syntactic categories** (e.g., expressions, commands).
- **Metavariables** (e.g., `e` for an expression).
- **Formation rules** (e.g., `e ::= n | x | e1 + e2 | e1 * e2`).
- **Abstract syntax trees (ASTs)** to represent program structure.

## Concrete vs. Abstract Syntax
- **Concrete syntax**: The program as **text** (as written by a developer).
- **Abstract syntax**: The **tree structure** representing the program.

A **parser** converts concrete syntax into abstract syntax.

## Turing Completeness
A programming language is **Turing-complete** if it can simulate a **Turing machine**, meaning it can express any algorithm.

Examples of **Turing-complete** languages:
- Imperative languages (**C, Java**).
- Functional languages (**Haskell, Lisp**).
- Logic languages (**Prolog**).

## Functional vs. Imperative Programming
- **Imperative languages** follow the **von Neumann architecture** (memory and CPU instructions).
- **Functional languages** are based on **λ-calculus** and avoid side effects.

### Example of a functional program in Haskell:
```haskell
gcd a 0 = a
gcd a b = gcd b (mod a b)
```



## Transpiler

### Fordele:
- Hvis kildekoden er meget nyt, som så oversætter til et mere populært sprog
- Portabilitet - Kan bruges på forskellige systemer relativt nemt

### Ulemper:
- Ikke så effektivt som, hvis man bare lavede en compiler

## Opgaver:


Nævn så mange imperativeprogrammeringssprog som du kan! Hvordan ved du at de er imperative?

- Java
- C
- C++
- Python
- Lua
- Swift
- Rust
- COBOL
- ALGOL
- BASIC
- COMAL

De er imperative, da de følger en række instruktioner der ændre hvordan programmet opfører sig.  Kommandoer x = e


På hvilke måder minder Algo 60 om C?
Algo 60 og C har et par af de samme kontrolstrukturer som if-else, while, for
Begge har en imperativ tilgang.
Begge har også blokstruktur i form af {} og begin..end 