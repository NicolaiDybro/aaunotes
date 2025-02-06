## Behavior
A systems fundamental purpose is to register, store, and produce information about problem-domain events. Limitations on event order, i.e. some events have to happen before others.

- Objects in the systems model are not intended to behave like problem-domain objects.
- With minimal delay, an object in the systems model should change state in response to problem-domain events that involve its corresponding object.
### Behavioral Patterns and attributes
- An objects behavior is defined by an event trace that exhibits a certain ordering of events over time.
- Event trace: a sequence of events involving a specific object
- Behavioral pattern: a description of possible event traces for all objects in a class

General:
- Common events describe interaction between classes
- Should ensure that problem-domain model includes classes with sequence, selection and iteration patterns.
	- Non structured: a collection of intermediate events in a combination of selection and iteration, all events can occur an arbitrary number of times in an arbitrary order. Usually people in the PD or classes at the top.
	- Structured: Overall sequence that includes all major events between birth and death. Some selection and iteration can be within the sequence. Usually physical objects or documents.
	- Should have atleast one class with a structured behavioral pattern.
- Update event table with the events that you figure out happen only once (+) and an arbitrary number of times (\*) as the simple event table only includes a checkmark
	- Must be consistent with the state chart diagrams.
- Behavior must be consistent with structure.

A behavioral pattern orders events in time:
- Sequence: Events in a set occur one by one. +
- Selection: Exactly one out of a set of events occurs. |
- Iteration: An event occurs zero or more times. \*
- For example: (account opened + (amount deposited | amount withdrawn)* + account closed)
	- This allows multiple event traces, (amount deposited | amount withdrawn) can happen an arbitrary amount of times

How to create state chart diagrams:
- create the event traces for an object, example: account opened - amount deposited - amount withdrawn - amount deposited - account closed
- Create behavioral pattern from the event trace
	- (Describe events common to two or more objects)
	- Add attributes, which are descriptive properties of a class or an event (add these to events in this activity)
	- Can also generate candidates for new classes and structures if it's necessary
- In each class, the first event describes the event that creates or leads to the birth of the object, whereas the last event is the event that makes the object die or disappear.
- Typically transitions correspond to events, but it's also possible to have a transition that occurs when a condition becomes true.
	- Here, the condition would be enclosed in brackets \[]
- Limitations can be imposed by other behavioral patterns, for example with the Customer and Account classes (fig 5.11), a customer cannot close an account they do not have. 
	- This is not allowed as the behavioral pattern for an account states that it must be opened before it can be closed.

Create behavioral patterns:
- Which events cause the creation problem-domain object?
- Which events cause the disappearance of a problem domain object?
- With an event trace, we can ask these questions:
	- Is the overall form structured or unstructured?
	- Which events occur together in a sequence?
	- Are there any alternative events? (for example, amount withdrawn and amount deposited are alternative events, this helps identify selection, but in this example they can be done more than once, therefore actually iteration)
	- Can a given event occur more than once?
- Transitions should be events (conditions?)
- States should be something that is happening (pregerminating, growing, open, etc)
- Behavioral pattern should be as simple as possible
- Still precise to describe all legal and illegal event traces

Overall state:
- Useful when many states can transition to the same state, for example in a phone call, a person can hang up at any time.

### Inheritance of behavioral patterns
- The behavioral pattern of a super class is inherited by all of its specializations.
	- Subclasses will typically expand the behavior by adding subpatterns with events that are unique to that class.
	- Subclasses inherits all superclass events and their ordering in time
	- The allowed event trace for a subclass must be within the general class, and they are often proper subsets of their general classes event trace.
		- Subclasses pose additional restrictions on the legal event trace. 

#### Multiple inheritance
- Does not introduce problems, events have unique names
- Subclasses with multiple parents, inherits the events from all parents.
- If we have *Account* which is the superclass to Loan, Checking and Basic Account, and Service Account is a subclass of Loan and Checking Account, a conflict can arise if both Loan and Checking Account impose limitations on *Account* behavior
	- In this case, we cannot define service account as something that is both a checking account and a loan, unless we change one of the superclass behavioral patterns.
- If the same event is inherited from multiple superclasses, the subclass behavioral pattern must adhere to the limitations imposed by all relevant superclasses.

## Patterns

### Stepwise Relation Pattern
- Used when certain problem-domain objects are related to the elements of a hierarchy in a stepwise or sequential manner.
	- Example: students are first assigned to a semester, then to a class, then to a group within the class, in this case it uses sequence.
- In its general form, the stepwise relation pattern has a structure like the hierarchy pattern and a class like "student" or "member" which models the objects assigned to elements in the hierarchy (student is assigned to semester, class, group, etc)
- It will have a behavioral pattern for each class that forms a level in the hierarchy
- It will have a behavioral pattern for the student or member class, which defines the order in which a student is assigned to elements on different levels of the hierarchy.

### Stepwise Role Pattern
- Focuses on the horizontal dimension in a class diagram rather than the vertical dimension.
- Describes how the behavior of a whole changes as parts become active.
- Example: Sale consists of offer, order, delivery. Offer leads to order, order leads to delivery. These all happen in sequence in sale's behavioral pattern.
- More complicated version: When roles are active in parallel rather than existing in a sequential order. (education and career, for example)
	- In this case we could introduce career and education as separate role classes, each with their own behavioral pattern.
	- Then the dependencies between the two patterns can be described using common events.

### Composite Pattern
- Offers a way to describe the creation and destruction of a hierarchy using a detailed structure that is unknown at model-development time.
- With a *Part*, Simple Part and Composite Part, where each Composite Part has one or more *Part* in them, this can be used to model their behavior.
- The top level behavior requires some behavior from the level beneath it, which in turn requires behavior from the level beneath it, and so on.
	- Recursive description
- Opposite: We start at the top and end up at the bottom with all the simple parts

## Consider Structures

### Aggregration and association
- Aggregation and association between objects should be consistent with common events between the same objects.
	- If we find that two or more objects have common events, consider adding an aggregation or association structure between them.
	- If two objects are associated through association or aggregation, they should have atleast one common event, and vice versa.

### Generalization
- An event that is included in the behavioral pattern for two different classes does not necessarily mean a common event, it could also mean that one class is a subclass of the other.
	- Distinguish between common and inherited events.
	- Use events to determine if one is a subclass of the other (its events must then be a subset of the other class' events).
- If two classes have many events with the same name, consider whether they are different specializations of a third class.
	- However, if the objects of the two PD classes are involved in the same events, these events become common events.

## Consider Classes
- Sometimes the power of expression through state chart diagrams is too weak for something, such as a customer closing and opening multiple accounts.
- In this case, it can be beneficial to create a new class, Account, which can also have a behavioral pattern.

## Describe Attributes
- Describes an event or a class
- Not always necessary if we only want to know whether a specific event has occurred or not, but we typically want to store more information about the event.
- Three different kinds:
	- Attributes tied to an event, such as a date when the customer opens an account
	- General information that does not relate to a single event but to the object as a whole (name, address, length, width, etc)
		- This does not comply with the general advice that attributes should be event-related.
		- Some classes have several attributes whose present value is all you need to know, then it might cause confusion to define events that model changes for these attribute values.
	- Attributes that can be derived from other attributes, e.g. balance, 
		- Be cautious with expressing functional requirements as attributes
- Attributes should be atomic in relation to their use.
	- A customers name can be divided into first name and last name, but this is usually unnecessary.
- Questions to specify class attributes:
	- What are the general characteristics of the class?
	- How is the class described in the problem domain?
	- What basic data must be captured about objects from this class?
	- What results from an event trace must be captured?
- Questions to specify event attributes examples:
	- What time did the event occur?
	- Which amount did it concern?