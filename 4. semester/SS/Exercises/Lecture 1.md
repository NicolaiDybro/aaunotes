![[Pasted image 20250224175611.png]]


1. aaabba, aaaab, aabb, bbabba, bbaab, bbbb, bbbabba, bbbaab, bbbbb
2. aa,bb, bbb, abba, aab, bb
3. bb
4. abba, aab, bb, abbaaab, aabbb ...


![[Pasted image 20250224180601.png]]


1. 
a) q1 -> q2 -> q3 -> q3 -> q3 -> q3
b) q1 -> q2 ->  q3 -> q3 -> q3 -> q3 -> q3
c) q1 -> q2 -> q3 -> q3
d) q1

2. 
in m1: none
in m2: d
in m3:  d

3.  
$$L(M_1)=\{ b^na|n\ge0 \}$$
$$L(M_2)=\{ b|n\ge0 \}$$
$$L(M_3)=\{ b^n a^m|m\in\{0,1\}|n\ge0 \}$$

![[Pasted image 20250224182541.png]]


```mermaid
stateDiagram-v2

    [*] --> q0

    state q0 (q0)
    state q1 (q1) #green
    state q2 (q2)
    state r1 (r1) #green
    state r2 (r2)

    q0 --> q1: a
    q0 --> r1: b

    q1 --> q1: a
    q1 --> q2: b

    q2 --> q1: a
    q2 --> q2: b

    r1 --> r2: a
    r1 --> r1: b

    r2 --> r2: a
    r2 --> r1: b

```


$$L(M_4)=\{xwx|x\inΣ|w\inΣ^*\}\cup\{a,b\}$$
r1 and q1 should be green

![[Pasted image 20250224182643.png]]
1. 
```mermaid
stateDiagram-v2
    [*] --> q1
    state q1 (q1)
    state q2 (q2) 
    state q3 (q3) #green
    state q4
    q1 --> q2: 1
    q2 --> q4: 22
    q2 --> q3: 1
    q3 --> q4: 22
    q4 --> q4: 1,22
    q3 --> q3: 1,22
```
2. 

```mermaid
stateDiagram-v2
    [*] --> q1
    state q1 (q1)
    q1 --> q1: 1,2,3
```
3. 
```mermaid
stateDiagram-v2
    [*] --> q1
    state q1 (q1)
    q1 --> q2: 1,2,3
```
4. 
```mermaid
stateDiagram-v2
    [*] --> q1
    state q1 (q1)
    q1 --> q2: go
    q2 --> q2: go, stop
	q2 --> q1: stop
```