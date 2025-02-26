
NFA vs DFA:
![[Pasted image 20250226200233.png]]

![[Pasted image 20250226202302.png]]

In a DFA we must have all the a,b. Like if you can have a transition you MUST have it as seen in this example.



# Building a lexer
- We define a NFA for each class tokens
- Then we create an NFA that forms the union of the NFAs
- Construct a small DFA using subset construction
- 



1. Hvad er starttilstanden i den DFA, du kan bygge fra NFA’en i figur 1 ved hjælp af delmængdekon struktionen? Figur 1: En nondeterministisk endelig automat 

{1,2}

1. Find alle transitioner fra starttilstanden for DFA’en, du kan bygge fra NFA’en i figur 1 ved hjælp af delmængdekonstruktionen. Hvis du vil, kan du selvfølgelig bygge hele DFA’en.

{1,2} a-> {1}
{1,2} b-> {1}
