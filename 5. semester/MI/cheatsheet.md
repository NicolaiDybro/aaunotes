
# Extra Exercises

## Neural Network

### Question 1
ReLU activation function: $ReLU(x)=max(0,x)$

What is the value of the pink ball for observation 1, before applying the activation function?:
$0.7\cdot8.3+1.6\cdot12.1=25.17$

What is the value of the pink ball for observation 1, after applying the activation function?: 
$ReLU(25.17)=max(0,25.17)=25.17$


What is the value of the orange ball for observation 1, before applying the activation function?:
$2.4\cdot8.3+(-1.6)\cdot12.1=0.56$

What is the value of the orange ball for observation 1, after applying the activation function?: 
$ReLU(25.17)=max(0,0.56)=0.56$



What is the value of _Rating_ for observation 1?:
$0.6\cdot25.17+0.56\cdot4.8=\underline{\underline{17.79}}$

What is the value of _Rating_ for observation 2?:
$0.7\cdot5.7+1.6\cdot4.5=11.19$
$2.4\cdot5.7+(-1.6)\cdot4.5=6.48$

$0.6 \cdot 11.19 + 6.48 \cdot 4.8 = \underline{\underline{37.818}}$

### Question 2

Sigmoid activation function: 
$$
\text{Sigmoid}(x) = \frac{1}{1 + e^{-x}}
$$
The learning rate is set to 0.3


SSE (Sum of Squared Errors):
$$
\text{SSE} = (y - o)^2
$$

Where y is the truth and o is the output
| | Observation ID | Enjoyment | Length | Rating | $\hat{y}$ |
| -------------: | --------: | -----: | -----: | --------: |
|              1 |       5.8 |    9.2 |   0.54 |      0.88 |
|                |           |        |        |           |
|                |           |        |        |           |

Calculate the SSE error value:
$
$(0.54 - 0.88)^2=0.1156$$


Calculate the SSE error value:$$(0.54 - 0.88)^2=0.1156$$

Calculate the error term for the _Rating_ node:
$$
\delta_{\text{Rating}} = o_b(1 - o_b)\,(y - o_b) 
$$

$\delta_{\text{Rating}} = 0.88(1 - 0.88)\,(0.54 - 0.88)\approx-0.0359$



The output of the pink node is 0.9999.  
What is the value of the updated weight from the pink node to the _Rating_ node?


$$
w_{ab}^{\text{new}} := w_{ab}^{\text{current}} + \left[ \alpha \cdot \delta_b \cdot x_{ab} \right]
$$
wherein:

$$
w_{ab}^{\text{new}} := 0.6 + \left[ 0.3 \cdot (-0.0359) \cdot 0.9999 \right] \approx 0.5892
$$

The output of the orange node is 0.31.  
What is the value of the updated weight from the orange node to the _Rating_ node?

$$w_{ab}^{\text{new}} := 4.8 + \left[ 0.3 \cdot (-0.0359) \cdot 0.31 \right] \approx 4.7967 $$

Calculate the error term for the pink node (hidden layer):
we use
$$o_b \left( 1 - o_b \right) \sum_c w_{bc}\,\delta_c$$
wherein: 
$$0.9999(1-0.9999) \cdot ( 0.6 \cdot (-0.0359))\approx 0$$


What is the value of the updated weight from the _Enjoyment_ node to the pink node?
$$
w_{ab}^{\text{new}} := w_{ab}^{\text{current}} + \left[ \alpha \cdot \delta_b \cdot x_{ab} \right]
$$

$$0.7 + [0.3\cdot0\cdot5.8]=0.7$$
What is the value of the updated weight from the _Length_ node to the pink node?:
$$1.6 + [0.3\cdot0\cdot9.2]=1.6$$


Calculate the error term for the orange node (hidden layer):
we use
$$o_b \left( 1 - o_b \right) \sum_c w_{bc}\,\delta_c$$
wherein: 
$$0.31(1-0.31) \cdot ( 4.8 \cdot (-0.0359))\approx -0.0369$$



What is the value of the updated weight from the _Enjoyment_ node to the orange node?
$$
w_{ab}^{\text{new}} := w_{ab}^{\text{current}} + \left[ \alpha \cdot \delta_b \cdot x_{ab} \right]
$$

$$(2.4) + [0.3\cdot(-0.0369)\cdot5.8]\approx2.3357$$
What is the value of the updated weight from the _Length_ node to the orange node?:
$$(-1.6) + [0.3\cdot(-0.0369)\cdot9.2]\approx-1.7018$$






## Planning under uncertainty, markov decision processes

### Question 1

the following rules are part of a _Reward Function_: 

- Getting the solutions: +5  
- Getting caught by the teacher: -10  
- Moving elsewhere: -0.3


The student is hesitant when moving, so there is a 30% chance he won't move, a 20% chance he will take a wrong turn and move to the right, and a _50_% chance he will move in the desired direction. The discounting factor is 0.6.

After one iteration of value iteration, what is the value inside (1 decimal):
$$max = moveoption_{n0} + ... + moveoption_{n}$$
$$moveoption = chance of desision + value of desesion$$
$$V = rewardfunction + discounting factor \cdot max$$
- (3;2):


$$
max = 0.5\cdot6+0.2\cdot(-12)+0.3\cdot(-12)=-3
$$

$$
V_1(3;2)=-10+0.6\cdot (-3)= \underline{\underline{-11.8}}
$$

- (1;3): 

$$
max = 0.5\cdot6+0.2\cdot3+0.3\cdot(-2)=3
$$

$$
V_1(1;3) = -0.3+0.6\cdot 3= \underline{\underline{1.5}}
$$


- (3;3):

$$
max = 0.5\cdot6+0.2\cdot6+0.3\cdot6=6
$$

$$
V_1(3;3) = 5+0.6\cdot 6= \underline{\underline{8.6}}
$$

Now, after 2 iterations of value iteration, what is the value inside (3 decimals):

- (2;3):
$$
V_1(2;3)=-0.3 + 0.6 \cdot (0.5\cdot6+0.2\cdot6+0.3\cdot3)=2.76
$$

$$
max = 0.5\cdot8.6+0.2\cdot 8.6+0.3\cdot 2.76=6.848
$$

$$
V_2(2;3) = -0.3+0.6\cdot 6.848=\underline{\underline{3.809}}
$$

- (3;2)

$$
max = 0.5\cdot8.6+0.2\cdot(-11.8)+0.3\cdot(-11.8)=-1.6
$$

$$
V_2(3;2) = -10+0.6\cdot (-1.6)=\underline{\underline{-10.96}}
$$


- (2;2)


$$
V_1(1;2)=-0.3 + 0.6 \cdot (0.5\cdot3+0.2\cdot(-4)+0.3\cdot6)=1.2
$$


$$
V_1(2;2)=-0.3 + 0.6 \cdot (0.5\cdot6+0.2\cdot(-12)+0.3\cdot(-4))=-0.66
$$



$$
max = 0.5\cdot2.76+0.2\cdot(-11.8)+0.3\cdot(-0.66)= -1.178
$$

$$
-0.3+0.6\cdot (-1.178)=\underline{\underline{-1.007}}
$$



## Constraint Satisfaction Problems


### Question 1
(a, d), (d,a), (b,e), (e,b), (c, a), (a,c), (b, d), (d,b)

a != 1, 2
b != 6
c != 1
d != 1, 2
e != 4,5,6



## Bayesian Networks

### Question 1

Your goal is to calculate P(D,C,B,A). First, which of the following variable orderings are consistent with the bayesian network above?

$$
X_1=A, X_2=B,X_3=C,X_4=D
$$

$$
X_1=A, X_2=C,X_3=D,X_4=B
$$

$$
X_1=A, X_2=C,X_3=B,X_4=D
$$


Now Select which probabilities you need to calculate together using the given the ordering X1=A,X2=C,X3=D,X4=B:
$$
(P(B|A,C,D) \cdot P(D|C,A) \cdot P(C|A) \cdot P(A))
$$


Now calculate(three decimal):
$$
P(D,C,B,A)=0.2 \cdot 0.46 \cdot 0.3 \cdot 0.6=0.017
$$
$$P(D, ¬ C, B,  A)==0.2 \cdot 0.54 \cdot 0.7 \cdot 0.6=0.045$$



3%

27%

7%

63%

Yes

## Supervised Learning and Decision Trees

### Question 1

We assume a **linear regression model** of the form

$$
\hat y=w_0+w_1 x_1+w_2 x_2​
$$

with  
$$
w_0=1, w_1=2, w_w=-1
$$

$\hat y$ of the first row: $1+2 \cdot 3 + (-1) \cdot 2 = 5$

$\hat y$ of the second row: $1+2 \cdot 1 + (-1) \cdot 4 =-1$

$\hat y$ of the third row: $1+2 \cdot 2 + (-1) \cdot 0 =5$

$\hat y$ of the fourth row: $1+2 \cdot 1 + (-1) \cdot 1 =2$

$\hat y$ of the fith row: $1+2 \cdot 0 + (-1) \cdot 4 =-3$


Mean Squared Error for the model:

$$
MSE=(y-\hat y)^2
$$

| Row | Error (y − ŷ) | Squared error |
|-----|---------------|---------------|
| 1   | -1            | 1             |
| 2   | 3             | 9             |
| 3   | -4            | 16            |
| 4   | 1             | 1             |
| 5   | 2             | 4             |


$$
\mathrm{MSE} = \frac{1 + 9 + 16 + 1 + 4}{5}=6.2
$$


### Question 2

*The Entropy Formula*
The formula for the Entropy of the target variable $S$ is:
$$Entropy(S) = \sum_{i=1}^{c} -p_i \log_2 p_i$$

$$Ent(Fun) = -p_{yes} \log_2(p_{yes}) - p_{no} \log_2(p_{no})$$

- **Yes:** 3 examples (Rows 1, 3, 5)
- **No:** 2 examples (Rows 2, 4)

- $p_{yes} = \frac{3}{5} = 0.6$
- $p_{no} = \frac{2}{5} = 0.4$

$$Ent(Fun) = -3/5 \cdot \log_2 3/5 - 2/5 \cdot \log_2 2/5$$


Looking at the dataset, the attribute **#Stoplights** has two unique values:

1. **$< 10$** (Rows 1 and 5)
2. **$\geq 10$** (Rows 2, 3, and 4)

Therefore, the entropies you must calculate are:

- **$Ent(Fun \mid \#stoplights < 10)$**
- **$Ent(Fun \mid \#stoplights \geq 10)$**

Now you should calculate the expected entropy for the attribute "#stoplights". (HINT: See slide 36.)

| ** #Stoplights** | **Target: Fun**              | **Total** |
| ---------------- | ---------------------------- | --------- |
| **$< 10$**       | [yes, yes] (Rows 1, 5)       | 2         |
| **$\geq 10$**    | [no, yes, no] (Rows 2, 3, 4) | 3         |

For $< 10$:
Both examples are "yes." Therefore the entropy is just 0

$$Ent(Fun \mid \#stoplights < 10) = 0$$
For $\geq 10$:
There is 1 "yes" and 2 "no"s out of 3 total. 

$$Ent(Fun \mid \#stoplights \geq 10) = - \frac{1}{3} \log_2 \frac{1}{3} - \frac{2}{3} \log_2 \frac{2}{3}\approx0.9183$$


The **Expected Entropy** is the weighted average of these values based on the number of examples in each subset (2/5 and 3/5):
$$ExpectedEntropy(Fun \mid \#stoplights) = \frac{2}{5} \times Ent(Fun \mid \#stoplights < 10) + \frac{3}{5} \times Ent(Fun \mid \#stoplights \geq 10)$$

$$ExpectedEntropy(Fun \mid \#stoplights) = \left(\frac{2}{5} \times 0\right) + \left(\frac{3}{5} \times 0.9183\right)$$

$$ExpectedEntropy(Fun \mid \#stoplights) \approx \mathbf{0.551}$$


Now you can calculate the information gain of #stoplights as the entropy of the target variable "Fun" minus the ExpectedEntropy(Fun | #stoplights).

$$IG(S, A) = Entropy(S) - ExpectedEntropy(S \mid A)$$

$$Ent(Fun) = - \frac{3}{5} \log_2 \frac{3}{5} - \frac{2}{5} \log_2 \frac{2}{5} \approx 0.971$$

$$ExpectedEntropy(Fun \mid \#stoplights) \approx 0.551$$

$$IG(\#stoplights) = 0.971 - 0.551$$

$$IG(\#stoplights) = \mathbf{0.420}$$

Calculate the information gain of the other attributes and choose the one with the highest information gain.

Here you can check if they are check pure. Time you can see that noon is no and evening is yes. This is the only one that has *two* pure groups. 



# Mini Exams

## Mini-Exam on Lectures 2 and 3

### Question 6


Compute the probability of the atomic event P (¬t, s, ¬m, f, ¬d).
Note, we use s as a shorthand for S=True, and ¬m as a shorthand for M=False, and so on.
Include 4 decimal digits (0.xxxx), truncating the rest.

$$
P (¬t, s, ¬m, f, ¬d)=(1-0.001)\cdot0.002\cdot(1-0.05)\cdot0.7\cdot(1-0.01)\approx 0.0013
$$


### Question 10

$$P(\neg t, \neg m, \neg d, f) = \sum_{S \in \{s, \neg s\}} P(\neg t) \cdot P(\neg m) \cdot P(S | \neg t) \cdot P(\neg d | \neg m) \cdot P(f | \neg m, S)$$



## Mini Exam for Lectures 04-08

### Question 2+3
$$P(\neg t, \neg m, \neg d, f) = \sum_{S \in \{s, \neg s\}} P(\neg t) \cdot P(\neg m) \cdot P(S | \neg t) \cdot P(\neg d | \neg m) \cdot P(f | \neg m, S)$$

Scenarie 1 ($S$ er sand): $0,999 \cdot 0,95 \cdot 0,002 \cdot 0,99 \cdot 0,7 = 0,0013153827$

Scenarie 2 ($S$ er falsk): $0,999 \cdot 0,95 \cdot 0,998 \cdot 0,99 \cdot 0,08 = 0,0750123792$

Sum: $0,0013153827 + 0,0750123792 = 0,0763277619$

### Question 4
After the investigation, Sherlock discovers that there were footprints in the house, the testament was not changed, and the diamonds were not stolen. What is the probability that moriarty is the mastermind behind the crime?  
  
Indicate for each variable whether it is query, evidence, or hidden variable.
Query = Question, what do we want to find out
Evidence = 
### Question 5
Non-colliders block when observed; colliders block when unobserved.

### Question 9 
We use the formula $(Input \cdot Weight) + Bias = Value_{before}$ and then apply **ReLU**, which stands for **Rectified Linear Unit** and is defined as $f(x) = \max(0, x)$.

Value (before activation function) A:
$$
(3 \cdot 2) + (1 \cdot -3) - 1 = 6 - 3 - 1 = \mathbf{2}
$$


### Question 12
Accuracy

Accuracy measures the proportion of total predictions (both positive and negative) that were correct.

- **Formula:** $\frac{TP + TN}{TP + TN + FP + FN}$
    
- **Calculation:** $\frac{1000 + 100}{1310} = \frac{1100}{1310} \approx \mathbf{0.840}$ (or **84.0%**)
    

Recall (Sensitivity)

Recall measures how well the model finds all the actual positive cases. It answers: "Out of all the people who were actually positive, how many did we catch?"

- **Formula:** $\frac{TP}{TP + FN}$
    
- **Calculation:** $\frac{1000}{1000 + 200} = \frac{1000}{1200} \approx \mathbf{0.833}$ (or **83.3%**)
    

Precision

Precision measures how reliable the model is when it predicts "Positive." It answers: "Out of all the times we guessed positive, how often were we right?"

- **Formula:** $\frac{TP}{TP + FP}$
    
- **Calculation:** $\frac{1000}{1000 + 10} = \frac{1000}{1010} \approx \mathbf{0.990}$ (or **99.0%**)

### Question 13

Precision measures the accuracy of positive predictions.

$$Precision = \frac{TP}{TP + FP} = \frac{377}{377 + 233} = \frac{377}{610} \approx 0.618$$


Recall measures the ability of the model to find all the positive units.

$$Recall = \frac{TP}{TP + FN} = \frac{377}{377 + 43} = \frac{377}{420} \approx 0.898$$


Accuracy measures the fraction of predictions our model got right.

$$Accuracy = \frac{TP + TN}{TP + TN + FP + FN} = \frac{377 + 865}{377 + 865 + 233 + 43} = \frac{1242}{1518} \approx 0.818$$


Specificity measures the ability of the model to find all the negative units.

$$Specificity = \frac{TN}{TN + FP} = \frac{865}{865 + 233} = \frac{865}{1098} \approx 0.788$$

### Question 15
To compute the **Sum of Absolute Error (SAE)** for each neural network, we use the formula:

SAE=∑∣Target−Output∣

Compute the **sum of absolute error** for each neural network

Sum of absolute error for Neural Network A:
- **ex1:** $|5 - 10| = 5$
    
- **ex2:** $|6 - 6| = 0$
    
- **ex3:** $|0 - 0| = 0$
    
- **ex4:** $|1 - 1| = 0$
    

**Sum of absolute error for Neural Network A:** $5 + 0 + 0 + 0 = 5$


Sum of absolute error for Neural Network B:
- **ex1:** $|5 - 7| = 2$
    
- **ex2:** $|6 - 4| = 2$
    
- **ex3:** $|0 - 2| = 2$
    
- **ex4:** $|1 - 0| = 1$
    

**Sum of absolute error for Neural Network B:** $2 + 2 + 2 + 1 = 7$


To compute the **Sum of Squared Error (SSE)** for each neural network, we use the formula:

SSE=∑(Target−Output)2

Calculation for Neural Network A

- **ex1:** (5−10)2=(−5)2=25
    
- **ex2:** (6−6)2=(0)2=0
    
- **ex3:** (0−0)2=(0)2=0
    
- **ex4:** (1−1)2=(0)2=0
    

**Sum of squared error for Neural Network A:** 25+0+0+0=25

---

Calculation for Neural Network B

- **ex1:** (5−7)2=(−2)2=4
    
- **ex2:** (6−4)2=(2)2=4
    
- **ex3:** (0−2)2=(−2)2=4
    
- **ex4:** (1−0)2=(1)2=1
    

**Sum of squared error for Neural Network B:** 4+4+4+1=13


### Question 18
TRY TO DRAW AT LOOK WHICH ONE IS CLOSE
What is the (8,8) cluster updated to after the first iteration of k-means? (2 decimals):

Manhatten Distance:
$$d = |x_1 - x_2| + |y_1 - y_2|$$

We got the following points:
- $P_1: (2, 4)$
- $P_2: (2, 8)$
- $P_3: (4, 6)$
- $P_4: (10, 2)$
- $P_5: (12, 4)$
- $P_6: (12, 8)$
- $P_7: (16, 6)$

If you look at the (8,8) you can see that 4 out of the 7 points are closest to (8,8), therefore:

What is the (8,8) cluster updated to after the first iteration of k-means? (2 decimals):
**Cluster 1** $\{P_1, P_2, P_3, P_6\}$: $(\frac{2+2+4+12}{4}, \frac{4+8+6+8}{4}) = (\frac{20}{4}, \frac{26}{4}) = \mathbf{(5.00, 6.50)}$

What is the (14,2) cluster updated to after the first iteration of k-means? (2 decimals):
**Cluster 2** $\{P_4, P_6, P_7\}$: $(\frac{10+12+16}{3}, \frac{2+4+6}{3}) = (\frac{38}{3}, \frac{12}{3}) = \mathbf{(12.67, 4.00)}$


What is the (8,8) cluster updated to after the second iteration of k-means? (2 decimals):
**Cluster 1** (update from $5.00, 6.50$) $\{P_1, P_2, P_3\}$: $(\frac{2+2+4}{3}, \frac{4+8+6}{3}) = (\frac{8}{3}, \frac{18}{3}) = \mathbf{(2.67, 6.00)}$

What is the (14,2) cluster updated to after the second iteration of k-means? (2 decimals):
**Cluster 2** (update from $12.67, 4.00$) $\{P_4, P_5, P_6, P_7\}$: $(\frac{10+12+12+16}{4}, \frac{2+4+8+6}{4}) = (\frac{50}{4}, \frac{20}{4}) = \mathbf{(12.50, 5.00)}$




### Question 19

$$P(C, V_1, V_2) = P(C) \cdot P(V_1 | C) \cdot P(V_2 | C)$$


Calculation for $P(C | V_1=t, V_2=t)$

- **Numerator for $C=1$:** $0.3 \times 0.2 \times 0.45 = 0.027$
- **Numerator for $C=2$:** $0.7 \times 0.8 \times 0.55 = 0.308$
- **Total Sum:** $0.027 + 0.308 = 0.335$
- $P(C=1 | t, t) = 0.027 / 0.335 \approx \mathbf{0.08}$
- $P(C=2 | t, t) = 0.308 / 0.335 \approx \mathbf{0.92}$

Calculation for $P(C | V_1=t, V_2=f)$

- **Numerator for $C=1$:** $0.3 \times 0.2 \times 0.88 = 0.0528$
- **Numerator for $C=2$:** $0.7 \times 0.8 \times 0.12 = 0.0672$
- **Total Sum:** $0.0528 + 0.0672 = 0.12$
- $P(C=1 | t, f) = 0.0528 / 0.12 = \mathbf{0.44}$
- $P(C=2 | t, f) = 0.0672 / 0.12 = \mathbf{0.56}$

Calculation for $P(C | V_1=f, V_2=t)$

- **Numerator for $C=1$:** $0.3 \times 0.7 \times 0.45 = 0.0945$
- **Numerator for $C=2$:** $0.7 \times 0.3 \times 0.55 = 0.1155$
- **Total Sum:** $0.0945 + 0.1155 = 0.21$
- $P(C=1 | f, t) = 0.0945 / 0.21 = \mathbf{0.45}$
- $P(C=2 | f, t) = 0.1155 / 0.21 = \mathbf{0.55}$

Calculation for $P(C | V_1=f, V_2=f)$

- **Numerator for $C=1$:** $0.3 \times 0.7 \times 0.88 = 0.1848$
- **Numerator for $C=2$:** $0.7 \times 0.3 \times 0.12 = 0.0252$
- **Total Sum:** $0.1848 + 0.0252 = 0.21$
- $P(C=1 | f, f) = 0.1848 / 0.21 = \mathbf{0.88}$
- $P(C=2 | f, f) = 0.0252 / 0.21 = \mathbf{0.12}$


- For $C=1$:
$$\frac{0.08 (tt) + 0.44 (tf) + 0.45 (ft) + 0.88 (ff)}{4} = \frac{1.85}{4} = \mathbf{0.46}$$

- For $C=2$:
$$\frac{0.92 (tt) + 0.56 (tf) + 0.55 (ft) + 0.12 (ff)}{4} = \frac{2.15}{4} = \mathbf{0.54}$$

P1(V1|C):
**For $C=1$:**

- $P(V_1=t | C=1) = \frac{P(C=1|t,t) + P(C=1|t,f)}{\sum P(C=1)} = \frac{0.08 + 0.44}{1.85} = \frac{0.52}{1.85} \approx \mathbf{0.28}$
- $P(V_1=f | C=1) = 1 - 0.28 = \mathbf{0.72}$

**For $C=2$:**

- $P(V_1=t | C=2) = \frac{P(C=2|t,t) + P(C=2|t,f)}{\sum P(C=2)} = \frac{0.92 + 0.56}{2.15} = \frac{1.48}{2.15} \approx \mathbf{0.69}$
- $P(V_1=f | C=2) = 1 - 0.69 = \mathbf{0.31}$

P1(V2|C):
**For $C=1$:**

- $P(V_2=t | C=1) = \frac{P(C=1|t,t) + P(C=1|f,t)}{\sum P(C=1)} = \frac{0.08 + 0.45}{1.85} = \frac{0.53}{1.85} \approx \mathbf{0.29}$
- $P(V_2=f | C=1) = 1 - 0.29 = \mathbf{0.71}$

**For $C=2$:**

- $P(V_2=t | C=2) = \frac{P(C=2|t,t) + P(C=2|f,t)}{\sum P(C=2)} = \frac{0.92 + 0.55}{2.15} = \frac{1.47}{2.15} \approx \mathbf{0.68}$
- $P(V_2=f | C=2) = 1 - 0.68 = \mathbf{0.32}$

## Mini Exam for Lectures 09-13

### Question 2

What is the **largest** value we can set for A and B for the heuristic to be **admissible.** If the heuristic is not admissible regardless of the value of A or B, enter -1 in both.

To find the maximum allowed value for **A** and **B**, we must identify the minimum number of moves required to solve the puzzle from this specific configuration. Which means:
A = 3
B = 13

What is the **lowest** value we can set for A and B for the heuristic to be **admissible**: If the heuristic is not admissible regardless of the value of A or B, enter -1 in both.
A heuristic is admissible if it never overestimates the cost to reach the goal.

So they are both 0


A heuristic is consistent if, for every node $n$ and every successor $n'$ of $n$ generated by any action $a$:

$$h(n) \leq c(n, a, n') + h(n')$$

**$I \to A$ (cost 2):** Since $h(I) = 4$, $h(A)$ must be at least **2** to satisfy $4 \leq 2 + h(A)$.
**$A \to E$ (cost 1):** Since $h(E) = 1$, $h(A)$ must be at most **2** to satisfy $h(A) \leq 1 + 1$.


**$I \to B$ (cost 1):** Since $h(I) = 4$, $h(B)$ must be at least **3** to satisfy $4 \leq 1 + h(B)$.

**$B \to D$ (cost 3):** Since $h(D) = 3$, $h(B)$ must be at most **6** to satisfy $h(B) \leq 3 + 3$. **BUT** because there is a different direction it needs to be evaluated as well:
**$B \to C$ (cost 3):** Since $h(C) = 2$, $h(B)$ must be at most **5** to satisfy $h(B) \leq 3 + 3$.