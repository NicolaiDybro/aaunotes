# Mathematical Preliminaries & Notation

## Sets

* **Definition:** A set is a group of objects (e.g., numbers, symbols, other sets).
* **Elements:** The objects in a set are called elements or members.
* **Notation:**
    * Listing elements: `{7, 21, 57}`, `{x, y, z, ...}`
    * Rule of membership: `{n | n = 2m for some m ∈ ℕ}`
* **Key Sets:**
    * Empty set: `∅ = {}`
    * Natural numbers: `ℕ = {0, 1, 2, 3, ...}`
    * Integers: `ℤ = {..., -2, -1, 0, 1, 2, ...}`
    * Rationals: `ℚ = {n/m | n, m ∈ ℤ and m ≠ 0}`
* **Basic Definitions:**
    * Subset: `A ⊆ B` (every member of A is a member of B)
    * Proper subset: `A ⊂ B` (A ⊆ B and A ≠ B)
    * Union: `A ∪ B` (smallest set containing all elements of A and B)
    * Intersection: `A ∩ B` (biggest set containing elements common to A and B)
    * Set difference: `A \ B` (elements of A that are not in B)
    * Cartesian product: `A × B = {(a, b) | a ∈ A and b ∈ B}`
    * Power set: `P(A)` or `2^A` (set of all subsets of A)

## Sequences and Tuples

* **Sequence:** An ordered list of elements.
* **Tuple:** A finite sequence.
* **Notation:** `(a1, a2, ..., an)`
* **Cartesian Product (tuples):** `A × B = {(a, b) | a ∈ A, b ∈ B}`

## Relations

* **Definition:** A relation between sets A and B is a subset of `A × B`.
* **Notation:** `R ⊆ A × B`
* **Types:**
    * Binary relation: A relation between two sets.
    * n-ary relation: A relation among n sets.
* **Properties of Binary Relations:**
    * Reflexive: `∀a ∈ A, (a, a) ∈ R`
    * Symmetric: `∀a, b ∈ A, (a, b) ∈ R ⇒ (b, a) ∈ R`
    * Transitive: `∀a, b, c ∈ A, (a, b) ∈ R and (b, c) ∈ R ⇒ (a, c) ∈ R`
    * Equivalence relation: reflexive, symmetric, and transitive.
    * Partial order: reflexive, anti-symmetric and transitive.
    * Total order: Partial order where every pair of elements are comparable.

![[Pasted image 20250220073612.png]]

## Functions

* **Definition:** A function `f: A → B` is a relation where each element of A is associated with exactly one element of B.
* **Domain:** A
* **Codomain:** B
* **Range:** `{f(a) | a ∈ A}`
* **Types:**
    * Total function: Defined for all elements in A.
    * Partial function: Defined for some elements in A.
    * Injective (one-to-one): `∀a1, a2 ∈ A, f(a1) = f(a2) ⇒ a1 = a2`
    * Surjective (onto): `∀b ∈ B, ∃a ∈ A, f(a) = b`
    * Bijective: Injective and surjective.

## Boolean Logic and Logical Notation

* **Logical Operators:**
    * AND: `∧`
    * OR: `∨`
    * NOT: `¬`
    * Implication: `⇒`
    * Equivalence: `⇔`
* **Quantifiers:**
    * Universal: `∀` (for all)
    * Existential: `∃` (there exists)

![[Pasted image 20250220080040.png]]

## Types of Proofs

* **Proof by Construction:** Showing existence by creating an example.
* **Proof by Contradiction:** Assume the opposite and derive a contradiction.
* **Proof by Induction:**
    * Base case: Prove for the smallest element(s).
    * Inductive step: Assume true for n, prove true for n+1.
* **Well-founded induction:**
    * Base case: proves P(x) for all minimal elements of X.
    * Inductive step: proves that, for each i ∈ X , if P(j) is true for all j ⊏ i, then so is P(i).

## Well-Founded Sets and Induction.

* **Well-founded set:** A set with a relation ⊏ such that there are no infinite descending chains.
* **Examples:**
    * Natural numbers with `<`.
    * Lexicographic order on `ℕ × ℕ`.
    * Algebraic expressions with "subexpression" relation.

## Well-founded induction Example.

* Proof that a binary tree T of height h(T) has at most 2<sup>h(T)</sup> leaves.
* Use well-founded induction on the set of binary trees, ordered by "is a proper subtree of".
* Base case: Empty tree.
* Inductive step: Assume true for subtrees, prove true for the tree.