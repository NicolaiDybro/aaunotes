
- Noter vedr. big vs littl
- bolsk algebra i slides
- 

# Programmerings sproget C

## Introduction
C is a general-purpose, procedural programming language developed by Dennis Ritchie in the early 1970s at Bell Labs. It is one of the most influential languages, forming the foundation for many modern languages like C++, Java, and Python. C is widely used for system programming, embedded systems, and high-performance applications due to its efficiency and control over system resources.

## Strengths of C
- **Efficiency & Performance** – C is a compiled language with low-level memory access, making it highly efficient for system-level programming.
- **Portability** – Code written in C can be compiled on various platforms with minimal modifications.
- **Flexibility & Control** – Provides fine-grained control over memory and hardware, making it suitable for embedded systems and OS development.
- **Foundation for Other Languages** – Many modern languages derive syntax and concepts from C.
- **Rich Standard Library** – Comes with a powerful standard library that includes functions for input/output, string handling, and memory management.

## Weaknesses of C
- **Manual Memory Management** – No built-in garbage collection, requiring developers to handle memory allocation and deallocation, leading to potential memory leaks.
- **Lack of High-Level Abstractions** – C lacks built-in object-oriented programming (OOP) or high-level data structures, making large projects harder to manage.
- **Error-Prone** – No strict type checking, buffer overflows, and pointer-related bugs can lead to crashes and security vulnerabilities.
- **Limited Standard Library** – Compared to modern languages, C has a smaller standard library, requiring external libraries for many features.




# Memory model

## Simple machine-model
- Processor (CPU - Central Processing Unit)
	- Completes machine instructions
- Memory
	- RAM (Primary memory, or working memory)
	- Stores instructions for the running programs
	- Stores the Data for the running programs
		- Variables, temps, objects and more
	- processor works non-stop with memory
		- Reading instructions
		- Reading and writing variables

## Byte-based Memory-model
- Think about this memory as a large byte-array
	- Index called as address
	- Every element can hold 1 byte
- Example:
	- One ASCII character is stored in 1 byte
		- "Hej med jer!"
		- 72,101,106, 32,109,101,100,32, 106, 101, 114, 33, 0
		  - In this memory the ASCII value for "H" in the address 00000004 and the rest of the string will be stored in the next values, this means that "!" will be stored under the address 00000017
		  - If we assume the memory is $2^{32}$ bytes
			  - What is the first address
				  - the first address will always be $0_{10}$ or in hex $0x00000000$
			  - What is the largest (in both decimal and hex)
				  - the largest address is the number of bytes
				$$
									\text{Decimal: } 2^{32} - 1 
				$$$$
				\text{Hex: } 0xFFFFFFFF
				$$

 
### Word

- A gathering of bits, which the computer can work with as a natural unit
	- typeless value
	- Datatype is dependent on the interpretation of the word: (signed/unsigned) integer, float, instruction, pointer,...
	- length: typically 8, 16, 32, 64 bits (exponent of 2)
- Arkitectures Word size
	- Largest amount of bits the machine normally can handle inside of one operation
		- Size of the word that can be written or read in memory
			- Max number of bits in a register
			- Largest integer
			- Largest address
- Earlier: 32 bits (4 byte) words
	- address's limited to 4GB: too low for modern data intensive applications
- Current: 64 bits (8 bytes) words
	- number of potential addresses $=2^{64} ≈1.8 * 10^{19}$ bytes
	- Currently some of these bits have been shaved off because $2^{64}$ is an abnormally large number. Therefore only the 48 bits with least weight are used.
		- $48\text{-bit}$ addresses: $256 \text{ Terabytes}$ 
	- $64\text{-bit}$ machines are also compatible with lower bit applications


## Byte Order

**Big End-ian:** 

Heighest weighted byte first; The least weighted byte has the highest address

**Little End-ian:** 

Lowest weighted byte first; The least weighted byte has the lowest address

| Hex | Decimal | Binary |
| --- | ------- | ------ |
| 0   | 0       | 0000   |
| 1   | 1       | 0001   |
| 2   | 2       | 0010   |
| 3   | 3       | 0011   |
| 4   | 4       | 0100   |
| 5   | 5       | 0101   |
| 6   | 6       | 0110   |
| 7   | 7       | 0111   |
| 8   | 8       | 1000   |
| 9   | 9       | 1001   |
| A   | 10      | 1010   |
| B   | 11      | 1011   |
| C   | 12      | 1100   |
| D   | 13      | 1101   |
| E   | 14      | 1110   |
| F   | 15      | 1111   |
## Decimal Numbers
- Base 10
	- String of characters 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
	-  123 in base 10 = $123_{10} = 1*10^2 + 2*10^1 + 3*10^0$   
	-  Most meaningful character: Heighest weight (leftmost)
	-  Least meaningful character: Lowest weight (rightmost)

# Binary numbers
- Base 2
	- String of 0, 1
	- $101_{2} = 1*2^2 + 0*2^1 + 1*2^0$  
	- Most meaningful bit: Heighest weight (leftmost)
	- Least meaningful bit: Lowest weight (rightmost)

# Hexa-decimal Numbers
- Base 16
	- String of characters '0' to '9' and 'A' to 'F' 
	- $1AF_{16} = 1 * 16^2 + A * 16^1 + F*16^0 = 1 * 16^2 + 10 * 16^1 + 15*16^0 = 431_{10}$ 
- C-notation: Hex number prefixes with "0x"
	- $FA1D37_{16}$ is written as: $0xFA1D37B$ or $0xfa1d37b$
- Conversion to binary is EASY
	- exchange each hex number with its binary value (4 bits)
	- $2BA → 0010 \ 1011 \ 1010$ 
- Conversion from binary is EASY
	- Group the bit string in groups of 4 from the right to the left
	- $1010111010 → 10 \ 1011 \ 1010 → 2BA$


# Binary Representation

- Base 10:
	- Natural
- Base 2:
	- Even more natural and reliable
- Base 16:
	- Compact, easily convertible to/from binary

In base 2 the bit string can become quite large, and it can therefore be preferred to use base 16 instead when dealing with 32 bit or 64 bit as an example

# Notation for Byte values

- Byte = 8 bits
- Binary: $00000000_2$ to $11111111_2$ 
- Decimal: $0_{10}$ to $255_{10}$ 
- Hexa-decimal: $00_{16}$ to $FF_{16}$ 
# Assignments


## Talsystemer

**Q:** Hvor mange forskellige værdier kan repræssenteres ved en byte?

**A:** 256


**Q:** Hvor mange forskellige værdier kan repræssenteres af et ord, som er 2 bytes (w=16 bits) langt?

**A:** 65536

___ 

**Q:** Binær til decimal: Hvilken decimal-værdi har det binære tal 01110110?

**A:** 
	Højre mod venstre: 
	$0*2^0 + 1*2^1 + 1*2^2 + 0*2^3 +1*2^4 +1*2^5 + 2^6 +0*2^7$
	$= 0+2+4+0+16+32+64+0 = 118$



___

**Q:** Hex til decimal: Hvilken decimal (10-tals system) værdi har hexadecimal tallet 0xA5B7?

**A:**
	$7*16^0 + 11*16^1 + 5*16^2 + 10*16^3 = 7+ 176 + 1280 +  40960 = 42423$

___
**Q:** Binær til hex: Hvilken hexa-decimal-værdi har det binære tal 01110110? 0x...

**A:**
	Opdel i grupper af 4 cifre fra højre mod venstre, og konverter hver gruppe til hex
	$0110 = 6$
	$0111 =7$

___
**Q:** Binær til hex: Hvilken hexa-decimal-værdi har det binære tal  110110? 0x...

**A:** 
	Opdel i grupper af 4 cifre fra højre mod venstre, og konverter hver gruppe til hex
	$0110 = 6$  
	$11 =3$

___
**Q:** Angiv tallet  0xA5B7 på binær form (2-tals system).

**A:** 
	Højre mod venstre
	$7=0111$
	$B= 1011$
	$5= 0101$
	$A= 1010$

___
**Q:** Angiv tallet 0x9FF som et 16-bit binært ord.

**A:** Tilføj 0'ere foran så den består af 16 bits: 0000 1001 1111 1111

___ 
Lad a=0x28.

**Q:** Hvilken hexadecimal værdi har a-0x8?  (angiv svar uden 0x prefix)

**A:** 20


**Q:** Hvilken hexadecimal værdi har a+0x8?  (angiv svar uden 0x prefix)

**A:** 30


**Q:** Hvilken hexadecimal værdi har a+0xf? (angiv svar uden 0x prefix)

**A:** 37


## After lecture

### Practice problem 2.1 
Perform the following number conversions:

A.
**Q:**  0x25B9D2 to binary

**A:** 
	0010 0101 1011 1001 1101

B.
**Q:**  binary 1010 1110 0100 1001 to hexidecimal

**A:** 
	0xAE49

C. 
**Q:** 0xA8B3D to binary

**A:**  
	1010 1000 1011 0011 1101

D.
**Q:** binary 11 0010 0010 1101 1001 0110

**A:** 
	322D96

### Practice Problem 2.3
**Q:** in the following table convert the values in **bold** into the other two notations

**A:** See table:
	
| Decimal | Binary        | Hexadecimal |
| ------- | ------------- | ----------- |
| **0**   | **0000 0000** | **0x00**    |
| **158** | *1001 1110*   | *0x9E*      |
| **76**  | *0100 1100*   | *0x4C*      |
| **145** | *1001 0001*   | *0x91*      |
| *174*   | **1010 1110** | *0xAE*      |
| *60*    | **0011 1100** | *0x3C*      |
| *241*   | **1111 0001** | *0xF1*      |


### Practice Problem 2.7


**Q**: What would be printed as a result of the following call to *show_bytes*?

 ``` c
const char *m = "mnopqr";
show_bytes((byte_pointer) m, strlen(m));

```

_Note that letters ‘__a__’ through ‘__z__’ have ASCII codes_ _0x61_ _through_ 0x7A.

A:
	0x6D6E6F707172


### Practice Problem 2.10


**Q: **_As an application of the property that_ _a ^ a =_ _0 for any bit vector_ a, consider the following program:

```C
_void inplace_swap(int *x, int *y) {_

*y = *x ^ *y; /* Step 1 */_

*x = *x ^ *y; /* Step 2 */_

*y = *x ^ *y; /* Step 3 */_

}

```


**A:**

|         | x       | y             |
| ------- | ------- | ------------- |
| Step 1  | a       | a^b           |
| Step 2  | a^(a^b) | a^b           |
| Step 3  | a^(a^b) | (a^b)^a^(a^b) |
| Shorten | b       | a             |

### Practice Problem 2.12

Write C expressions, in terms of variable x, for the following values. Your code should work for any word size w ≥ 8. For reference, we show the result of evaluating the expressions for x = 0x87654321, with w = 32.

**Q:** The least significant byte of x, with all other bits set to 0. 0x00000021

A:

``` C

unsigned int x = 0x87654321;
printf("%.8x", x& 0xFF);

```

**Q:** All but the least significant byte of x complemented, with the least significant byte left unchanged. 0x789ABC21