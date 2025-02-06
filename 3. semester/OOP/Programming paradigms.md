![[Pasted image 20241229135415.png]]
### Imperative Programming
A paradigm where the programmer explicitly specifies the sequence of operations the computer must perform to achieve a desired outcome. Focus on step by step instructions to achieve outcome.
#### Procedural programming
Use functions to improve code reuse and abstractions
### Declarative programming
Focus on logic instead of control flows
#### Functional programming
Functions are treated as types, and can be passed as parameters or returned. In javascript array.map uses function programming, because the programmer can just focus on the login without thinking about the step by step instructions. Example:
```javascript
const numbers = [1, 2, 3, 4, 5];
const sum = numbers.reduce((acc, num) => acc + num, 0);  // Calculate sum
console.log(sum);

```
