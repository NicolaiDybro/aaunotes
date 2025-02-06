# Part V
- Starting point for component design is the architectural specifications and the system requirements.
	- Stay true to the component architecture
		- This means do not make a component perform tasks that are not part of its responsibilities, for example
	- If you can't stay true to the component architecture, revise it, for example if the technical limitations dictates it

# Model component
- Purpose is to deliver current and historical data to functions, interfaces (ultimately to users and other systems)
	- Stored information is related to the problem domain
	- Main task is to represent the events using the mechanisms available in object-oriented programming languages.\
- Result is a revised class diagram, with new attributes classes and structures, these represent the events.
	- Operations describe system dynamics, attributes and object structures describe static aspects
- Every time an event is to be registered, the system should check if it's legal according to the object's state (function design)
- Choose the simplest representation of events
	- Information that will never be requested should not be stored (unless future dictates it will be requested)

## How to make the model component

### Private events
Events that only involve one class
- only occur in sequence and selection (+): represent as class attributes (take the attributes from the event and put the into the class (date, name, etc))
- occur in iterations (\*): represent as a new class, attach them to the class which has the event using AGGREGATION (for each iteration, the system will generate a new object from the class). Take the attributes from the event (date, name, etc) and put them into the class

### Common events
Events that involve two or more classes
- Represent the event in relation to one of the objects, possibly add structural connections to give the other objects access to the relevant attributes
	- Depends on architecture, simplest way is recommended

How to:
- If it is involved in different ways with different classes (+ for one class, \* for another class), represent it in relation to the class that offers the simplest representation
- If it is involved in the same way with all classes, weight possible representations against each other.
	- Simplest representation is often the one where the least extra associations need to be added (example figure 12.9 page 245, it's more simple to add Deposit and Withdraw to Account than to Customer, as if it's added to Customer we need to add an association between Account and Deposit/Withdraw)

### Simplification

####  Generalization
- If two classes have the same attributes, they can generally be turned into one class, and if it's necessary to be able to distinguish between types, add an attribute which specifies type
	- Could also add actual generalization, e.g. make *Transaction* and then Deposit and Withdraw?
	- If the operations differ greatly, it might not be a good idea to generalize
If we have this:
![[Pasted image 20250107194923.png]]
Instead of doing this:
![[Pasted image 20250107194939.png]]
Could also do something like this?:
![[Pasted image 20250107194910.png]]

#### Association
- When adding structures, classes, consider old structures to see if they've become unnecessary and can be removed (2020-01 exercise 4.2 removing association between A and B since we have a relation through e3 and e5)