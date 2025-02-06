![[OOP24L6.pdf]]

### Syntax
![[OOP24L6.pdf#page=10]]
![[OOP24L6.pdf#page=11]]

### Exception types
![[OOP24L6.pdf#page=15]]
- Checked exceptions
	- Subclasses of Exception
	- Must be declared by method that throws
- Unchecked exceoptions
	- Subclasses of RuntimeException
	- Don't have to be declared by method that throws
- Errors
	- Used for assertions
	- Used for application breaking events
	- Usually bad practice to catch Errors
	-  E.g. Out of memory

### Assertion
![[OOP24L6.pdf#page=37]]
- Instance of AssertionError which is subclass of Error
- Must be enabled on execution
- Assertions can't be handled