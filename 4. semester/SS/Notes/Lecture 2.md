
# Strings and Languages

- An alphabet is a finite nonempty set
    - Examples: Σ1 = {0,1}, Σ2 = {a,b,c,...,x,y,z}, ...
- The members of an alphabet are called symbols
- A string (or word) over an alphabet is a finite sequence of symbols
    - Examples: 0, 001, 0011, ... are all strings over Σ1; word, alphabet, aaabbb, are strings over Σ2;
    - Non-examples: 0+1, a~b, are not strings over Σ1 or Σ2
- The empty string, written ε, is the string with no symbols
- A language over the alphabet Σ is a set of strings over Σ. We denote by Σ* the language of all strings over Σ.

# Substrings

Let w be a string over the alphabet Σ

- A string z is a substring of w if z appears consecutively within w;
    - Examples: Let w = abracadabra. ε, abra, cada, abracadabra, ... are substrings of w
- A string x is a prefix of w if x appears at the beginning of w;
    - Examples: ε, abra, abracada, abracadabra are prefixes of w
- A string y is a suffix of w if y appears at the end of w;
    - Examples: ε, abra, cadabra, ..., abracadabra are suffixes of w

# String Concatenation

- Given strings w and w' over the same alphabet, the concatenation of w and w', written ww', is the string obtained by appending w' to the end of w. w^k = ww...w (k times)
    - Examples: For w = ab and w' = cd, ww' = abcd, w'w = cdab, w^3 = ababab, ...
- Note that...
    - The empty string is the identity element: ∀w. (wε = w = εw);
    - If x is a prefix of w, then w = xw' for some w';
    - If y is a suffix of w, then w = w'y for some w';
    - If z is a substring of w, then w = w'zw'' for some w', w'';

# Last definitions ...

- The length of a word w, written |w|, is the number of symbols it contains.
    - Examples: |abc| = 3, |abracadabra| = 11, |ε| = 0.
- The reverse of w, written w^R, is the string obtained by writing w in the opposite order.
    - Examples: (abc)^R = cba, (abracadabra)^R = arbadacarba, ε^R = ε, (abba)^R = abba, (eve)^R = eve. (palindromes)
- If the alphabet Σ is ordered, then the set of strings over Σ can be ordered lexicographically: w ≤ w' ⇔ (w is a prefix of w' or ∃a ≤ b ∈ Σ. ua is a prefix of w, ub is a prefix of w')

# A simple Model of Computation

- It's an abstract prototype of digital computers used to develop a mathematical theory of computations.
- "workers in the field, [...] have felt more and more that the notion of Turing machine is too general to serve as an accurate model of actual computers. It is well known that even for simple calculations it is impossible to give an a priori upper bound on the amount of tape a Turing machine will need for any given computation. It is precisely this features that renders Turing's concept unrealistic" - Rabin, M. and Scott, D. Finite automata and their decision problems. IBM Journal of Research and Development, vol. 3 (1959), pp. 114 - 125.

# Finite automata are models for computers with an extremely limited amount of memory

- Example: Controller for automatic door
    - Two sensors (on front pad; on rear pad), hence 4 input possibilities: BOTH, only FRONT, only REAR, NEITHER
    - States: OPEN, CLOSED

# Finite Automaton

## Definition

A finite automaton is a 5-tuple (Q, Σ, δ, q0, F), where

- Q is a finite set of states,
- Σ is a finite set called alphabet,
- δ: Q × Σ → Q is the transition function (exactly one next state for each input symbol in each state),
- q0 ∈ Q is the start state (or initial state) (there must always be a starting state),
- F ⊆ Q is the set of accept states (or final states) (there can be 0 accept states, or several). It is possible that the start state is also an accept state (q0 ∈ F).

# Example of Finite Automaton

## State diagram

- input-labelled transition
- pointy arrow to indicate start state
- double circle to indicate accept states
- Example: M1
    - Q = {q1, q2, q3}
    - Σ = {0,1}
    - q0 = q1
    - δ: Q × Σ → Q (tabular definition)
    - F = {q2}
    - δ(q1,0) = q1, δ(q1,1) = q2
    - δ(q2,0) = q3, δ(q2,1) = q2
    - δ(q3,0) = q2, δ(q3,1) = q2
- Observe how the automaton processes the strings
    - 1101 (accept)
    - 001100 (reject)
    - 11010 (accept)

# When an automaton processes a string of symbols over its alphabet, it outputs:

- accept (when it finishes in an accept state)
- reject (otherwise) Note that this automaton accepts any string ending in 1.

# Formal definition of Computation

Let M = (Q, Σ, δ, q0, F) be an FA and w = a1a2…an be a string where each ai ∈ Σ. Then, M accepts w if there exists a sequence r0, r1, …, rn of states in Q satisfying the following 3 conditions:

1. r0 = q0
2. δ(ri, ai+1) = ri+1 for i ∈ {0,…, n-1}
3. rn ∈ F

- Definition:
    - The language of M, denoted by L(M), is {w ∣ M accepts w};
    - We say that M recognises a language A, when A = L(M)
- Definition: r0, r1, …, rn is the computation sequence for w in M.

# Examples of Finite Automata

- Example 1: M2
    - L(M2) = {w ∣ w ends in 1}
- Example 2: M3
    - L(M3) = {w ∣ w ends in 0} ∪ {ε}
- Example 3: M4
    - L(M4) = ∅
- Example 4: M5
    - L(M5) = {w ∣ w starts and ends with the same symbol} = {xwx ∣ x ∈ Σ and w ∈ Σ*} ∪ {a, b}

# Regular Languages

- A language is regular is some finite automaton recognizes it.
- Definition: The language End1 = {w ∣ w ends in 1} is regular, as it is recognized by M2, in symbols, L(M2) = End1.

# Designing Finite Automata

- The question of regularity for a language is equivalent to designing a finite automaton recognizing the given language.
- The best way to design an automaton is to put yourself in the place of the machine and try to processes an input string.
    - Step 1: determine the states (they represent what you should remember about the input string read so far)
    - Step 2: determine the transitions (they represent the actions the machine takes when a new symbol is processed)
    - Step 3: determine start and accept states (they are the states where the machine start and completed its task)
- A common sense design recipe

# Automata design (Example)

- Task: Design an automaton that recognise the language Odd = {w ∈ {0,1}* ∣ w has odd number of occurrences of 1}
    - We just need to remember whether the number of inputs equal to 1 processed so far is either odd or even.
    - By reading 1 we switch state; by reading 0 we stay where we are.
    - Start and accept states are clear.