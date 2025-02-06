### Instance methods
![[Pasted image 20241229162301.png]]
#### Cannot be overridden
- getClass()
- notify()
- notifyAll()
- wait()
#### Can be overwritten
- toString()
- equals()
	- Default: Uses ==
	- Requirements 
		- Reflexive, symmetric and transitive.
		- Return false given null
		- Consistent with hashCode
		- Must also override hashCode to comply with its requirements
- hashCode()
	- Default: Memory address as int
	- Requirements
		- internal consistency: the value of hashCode() may only change if a property that is in equals() changes
		- equals consistency: objects that are equal to each other must return the same hashCode
		- collisions: unequal objects may have the same hashCode
#### Protected (Must be overwritten if used)
- clone()
	- Must implement Cloneable
	- Default: Shallow copy
- finalize(): Depricated
