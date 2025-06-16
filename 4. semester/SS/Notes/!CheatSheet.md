
# Context Free
En **PDA (Pushdown Automaton)** er en maskine, der:

- Læser input én symbol ad gangen
- Har en **stack**, som den kan **pushe** og **poppe** symboler på
- Bruger stacken til at holde styr på "hukommelse", fx balancerede symboler

**PDA** kan bruges til at undersøge om noget er context free. Kan du lave en **PDA** så er den context free.

## Eksempel:
$$L=\{a^n b^n | n\ge 0\}$$
I det er eksempel er der det samme antal a'er og b'er.

- For hver a du læser så pusher du A på stacken
- For hver b du læser så popper du A fra stacken
- Hvis du ender med en helt tom stack og hele input er læst, accepter sproget


Et andet eksempel kunne være:
$$L=\{a^n b^n c^n | n\ge 0\}$$


Her er problemet vi har to ting der skal tælles nu?
Først skal der holdes styr på, at der er lige mange a og b, som i det første eksempel.
Så skal der også holdes styr på der er lige man b og c, så det er anden tæller.

Vi har kun 1 stack, så derfor er den **IKKE** PDA, og derfor ikke Context Free.

# Pumping Lemma

Pumping Lemma siger at:

> All string in the language can be repeated *"pumped"* if they are at least as long as a certain length, the pumping length *p*

## Eksempel (på engelsk)


We got the following language:

$$L=\{(ab)^n a^m|n,m\ge0,n>m\}$$

Goal is to prove that L is not regular.

Using the Pumping Lemma for **regular** languages, which states:

>For every regular language, there exists a constant p (the pumping length) such that every string w $\in$ L with $|w| \ge p$ can be split into three parts, $w=xyz$, satisfying:
>
>1. $|xy| \ge p$
>2. $y \ne \epsilon$
>3. For all $i \le 0, xy^iz \in L$

### Step 1

We assume L is regular, and let p be the pumping length given by the lemma


### Step 2

Pick a specific string:
$$w=(ab)^{p+1}a^p$$
Why is this a **smart choice?**
- It belongs to L, since:
	- It has n = p + 1 repetitions of "ab"
	- It has m = p a's
	- And n > m, as required

### Step 3

The demon splits $w = xyz$ such that:
- $|xy| \le p$: This means x and y are within the first p characters of w
- $y \ne \epsilon$ So some part of the string is being pumped

### Step 4

We now want to show that L is not regular. For any decomposition of w into xyz as above, we show that for $i=0, xy^i z \notin L$. By the condition given by the demon$|xy| \le p$, we know that y occurs in the first half of $(ab)^{p+1}$, and that z then must contain at least an occurrence of b. 

#### Case 1
Case 1 is that y has an occurrences of ab. Then it means that in $xy^0z$, ab is consecutively repeated at most p-times. This giving us that: $xy^iz \notin L$. 

#### Case 2
Case 2 is that y has no occurrences of ab. Then, as y is nonempty and occurs in $(ab)^{p+1}$, only three cases are possible that $y=ba, y=a, y=b$. For each of these cases $xy^0z \notin (ab)^*a^*$, thus is not in the required format to belong in L. 





Så altså, handler det om at enten ved at tilføje noget eller fjerner y, ved at i=2 eller i=0 f.eks. så kan vi bevise den ikke længere er i den korrekte format. 