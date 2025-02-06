# Function Component
- Behavior in an object-oriented system is described as operations on the system's classes
	- Can be activated through relevant class objects
	- Must implement all functions in terms of operations
- Purpose of the function component is to give the user interface and other system components access to the model
	- Function component: A part of a system that implements functional requirements.
- Functions describe externally observable behavior that relates directly and meaningfully to the users' work.
	- Designed and implemented using operations in the system's classes
	- Operation: A process property specified in a class and activated through the class' object.
		- (Procedure) activated by a message, carries out data processing, returns to the caller with or without a message
- Implement functions using operations on classes
	- Which operations are necessary to implement a given function?
	- Base the design on function types.
	- Design functions, not program them. Do not come too close to programming.
		- Only specify complex operations

## How to:
- Describe all functions by one or more operations, which are more or less abstract (they use the technical platform)
- Explore patterns to help implement functions as operations
- Specify complex operations

### Common to all types of functions
- How should the function be implemented as operations in different classes?
- How is the main operation activated and what input data does it use?
- Which objects and connections are involved in performing the operations, and how are they identified?
- What is the feedback from the main operation?

### Update
- How can you determine if the update is legal?
Update functions are directly linked to events in the problem-domain. When a relevant problem-domain event occurs, it should leave a trace in the model through an update function. The function should:
- Receive input data (through devices, through a user) that describes the event 
- Output data is the model update or returned to the caller
- Identify relevant objects and attributes by looking at the triggering events.
- Update operations must reflect behavioral patterns, as they determine legal event traces
- If two operations are very similar, they can possibly be implemented as just one operation (withdraw/deposit for example)
### Read
- Which attributes and connections should be read, and how are these found?
Read requirements must be implemented by a read function or, alternatively, a compute function. A read function should:
- Receive input data describing the desired reading (typically attributes used to identify objects to be read)
- Read the actual data in the model
- Return the data to the caller
- Read operations:
	- Decide what the results are from each operation
### Compute
- Which algorithms should be carried out?
Usually involves a reading of the model. Is often combined with an update function if it needs to update the model as well. Compute function:
- Input: data and attributes necessary for the computation. (objects, attributes, connections in the model that should be read)
- Result: the result of the computation
### Signal
- Which rules apply to the signaling?
Describe certain states and relations between objects that trigger a signal. 
- Input: not necessarily
	- Sometimes there might be some threshold values or limits that trigger the signal
	- Continually reads the model
- Output: message to a user or a control impulse to a device in the problem-domain.
- Decide threshold values, or rules
	- Objects, attributes and connections that should be evaluated
- Should be either active or passive
	- Active: operation that is permanently active (running) and regularly evaluates its rules
	- Passive: evaluates the rules whenever some event(s) happen
	- If the rules are simple, and the they can only happen when a specific event happens, a passive is good 
		- Otherwise active might be better

## Patterns
Several design options can help realize functions as a set of operations.
### Model class placement
- Places operations in a model component class
	- The operations belong logically with the other elements
- Useful when an operation accesses only a single object or simple aggregate structure
	- Place operations for updating a private event in the class that the event is attached to
	- Same with operations for updating basic attributes (they also deal with only one object)
- Can also use this pattern even if several objects are involved, if the responsibility for the operation can clearly be placed on one of the model classes

### Function class placement
- Useful when responsibility for the operation cannot be clearly tied to a specific class in the model
- Should generally define one or more function-component classes as containing operations that realize functions (function managers)
	- Typically do not contain significant attributes

### Strategy pattern
- Let's you change the strategy dynamically
- Let's you add new strategies without changing the existing system

### Active function
- An operation that is permanently active

## Complex operations
- Only specify complex operations
- Reading attributes:
	- Instead of defining read operations for a person's name and address, just include them as attributes.
- Only designate operations for generating and destroying objects in special situations.
- Can also assume that an object structure implicitly defines operations for searching the set of connections that the structure represents

### Sequence diagram
- When a function is implemented by several operations distributed over several objects, you might have to ensure such interactions work
- Can do this with a sequence diagram

### State chart diagram
- Use to object state chart diagram to specify the relationship between an object's states and the state changes in the form of operation calls
	- Transitions reflect calls to operations in the corresponding class

#### System total behavior
- Can also use a statechart diagram to describe the system's total behavior
	- In relation to general states and their relations to problem-domain events