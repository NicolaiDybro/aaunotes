### Part 1: Basic Definitions

- **Lexical analysis** is the process of breaking down a program's source code into a stream of tokens, which are the basic building blocks of the language.
- **Formal languages** are sets of strings, where a string is a finite sequence of symbols.
- **Regular expressions** are a notation for describing patterns in strings.
- **Nondeterministic finite automata (NFAs)** are a type of machine that can be used to recognize regular languages.

### Part 2: Strings and Languages

- **Alphabet:** A finite set of symbols.
- **String:** A finite sequence of characters from an alphabet.
- **Empty string:** A string with no characters, denoted by ε.
- **Language:** A set of strings over an alphabet.

**Examples:**

- The set of all strings over the alphabet {a, b} is {ε, a, b, aa, ab, ba, bb, ...}.
- The language of all strings that start with a is {a, aa, ab, aaa, aab, aba, abb, ...}.
- The language of all strings that contain at least one a and at least one b is {ab, ba, aab, aba, abb, baa, bab, bba, ...}.

### Part 3: Regular Expressions

- **Regular operators:**
    - **Union:** `|` (e.g., `a|b` matches either `a` or `b`)
    - **Concatenation:** (e.g., `ab` matches `ab`)
    - **Star:** `*` (e.g., `a*` matches zero or more `a`s)
- **Regular expression:** A string that describes a pattern in strings, using regular operators and basic expressions:
    - `ε` matches the empty string
    - `a` matches the character `a`
    - `R1|R2` matches any string that matches `R1` or `R2`
    - `R1R2` matches any string that is the concatenation of a string that matches `R1` and a string that matches `R2`
    - `R*` matches any string that is the concatenation of zero or more strings that match `R`

**Examples:**

- The regular expression `a(b|c)*` matches any string that starts with `a` and is followed by zero or more `b`s or `c`s.
- The regular expression `(a|b)*a` matches any string that ends in `a`.

### Part 4: Nondeterministic Finite Automata (NFAs)

- **NFA:** A machine with a finite set of states, transitions between states labeled with a character or ε, an initial state, and a set of final states.
- **Acceptance:** An NFA accepts a string if there is a path from the initial state to a final state such that the concatenation of the labels on the path is equal to the string.
- **Nondeterminism:** An NFA can have multiple transitions from a state with the same label, or transitions labeled with ε.

**Example:**

The following NFA accepts the language of all strings that end in `a`.

```
┌───┐     a     ┌───┐     a     ┌───┐
│ q0 │───>│ q1 │───>│ q2 │───>│ q3 │
└───┘     b     └───┘     b     └───┘
      <───<───<───
```

### Part 5: From Regular Expression to NFA

There is an algorithm for converting any regular expression to an equivalent NFA. The algorithm has a case for each form of regular expression:

- **Basic expressions:**
    - `a` becomes `───a───>`
    - `ε` becomes `───ε───>`
- **Composite expressions:**
    - `R1R2` becomes the concatenation of the NFAs for `R1` and `R2`
    - `R1|R2` becomes the union of the NFAs for `R1` and `R2`
    - `R*` becomes the Kleene star of the NFA for `R`

| Concept | Description | Purpose | Details/Examples |
|---|---|---|---|
| Lexical analysis | Nedbrydning af kildekode til tokens | Første skridt i kompileringsprocessen | Eksempel: `x = y + 10;` bliver til `ID(x)`, `ASSIGN`, `ID(y)`, `PLUS`, `INT(10)`, `SEMICOLON` |
| Formal language | Sæt af strenge over et alfabet | Definerer gyldig programsyntaks | Kan beskrives med formelle grammatikker eller automater. |
| Regular expression (regex) | Mønsterbeskrivelse af strenge | Angiver token-struktur | Operatorer: `\|`, `.`, `*`, `ε`. Eksempel: `(a\|b)*c` matcher strenge, der ender på 'c' og består af 'a' og 'b'. |
| NFA (Nondeterministic Finite Automaton) | Teoretisk maskine til mønstergenkendelse | Grundlag for leksikalske analysatorer | Tilstande, overgange (med symboler eller `ε`), starttilstand, accepttilstand(e). |
| Token | Grundlæggende byggeblok i et sprog (fx keyword, identifier) | Repræsenterer en meningsfuld enhed i koden | Eksempler: `if`, `while`, `x`, `+`, `123`, `"hello"`. Tokens er output fra den leksikalske analyse. |
| Alphabet (Σ) | Endeligt sæt af symboler (tegn) | Definerer tilladte tegn i sproget | Eksempel: `Σ = {a, b, c, ..., z, 0, 1, ..., 9}` |
| String (w) | Endelig sekvens af tegn fra et alfabet | Repræsenterer kodeelementer | Eksempel: `"variabelNavn"`, `"123"`, `"+"`. Den tomme streng er `ε`. |
| Empty string (ε) | Streng uden tegn | Kan bruges i mønstergenkendelse | Nyttig i regex og NFA-overgange. |
| Language (L) | Sæt af strenge over et alfabet | Definerer gyldige kodsekvenser | Eksempel: Sproget af alle gyldige C-programmer. |
| Regular operators | `\|`, `.`, `*` | Bruges til at bygge komplekse regex |  |
| NFA states | Start-, accept- og mellemtilstande | Repræsenterer trin i mønstergenkendelse | NFA'en starter i starttilstanden og bevæger sig mellem tilstande baseret på input. Accepttilstand indikerer match. |
| NFA transitions | Forbindelser mellem tilstande (med symboler fra `Σ` eller `ε`) | Angiver tegnmatch eller `ε`-bevægelser | Overgange definerer, hvordan NFA'en bevæger sig mellem tilstande. `ε`-overgange sker uden input. |
| NFA acceptance | Nå en accepttilstand efter at have læst hele inputstrengen | Vis, at input matcher mønsteret (regex) | Hvis NFA'en kan nå en accepttilstand efter at have læst hele strengen, er strengen "accepteret". |



# Opgaver

### 1. Find et regulært udtryk, der beskriver sproget af alle binære tal, der ikke begynder eller slutter med 0. 

Skal altid starte med 1

Og skal altid slutte med 1
Derfor er svaret:
$1(0|1)*1$


![[Pasted image 20250219175830.png]]

### 2. Byg en NFA, der genkender det sprog, der er beskrevet af det regulære udtryk 01∗.


![[Pasted image 20250219175704.png]]