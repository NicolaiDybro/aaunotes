![[OOP24L4.pdf]]
### General
- All classes are subclasses of the object class
- Instances of a subclass can be type casted to the ancestors of that class
- Use final modifier for class, to make it uninheritable for security, correctness and performance
#### Todo
- What's binding?
- Go through examples in code
- In example can shape be called to get area
- Research object class
- Can everything be defined like "Object o = new Circle()"
- Research generic types

### Terminology
![[OOP24L4.pdf#page=10]]
![[OOP24L4.pdf#page=14]]

### Subclass access
![[OOP24L4.pdf#page=11]]

### Binding
![[OOP24L4.pdf#page=22]]

### Method overriding vs overloading
- Overriding, same signature like defining your own .toString
	- Requirements: same name, arguments. Same or more relax access level. No final methods.
	- Can optionaly be acompanies by the "@Override" annotation. It makes it easier to understand and makes the compiler check for correct override, which could be usefull if names where misspelled
	- Called hiding for static methods
- Overloading, different signature for enableing different arguments and return types
	- Uses the most specific overload when multiple can be called

### Abstract
![[OOP24L4.pdf#page=41]]
- A class must override all abstract methods of it's superclass