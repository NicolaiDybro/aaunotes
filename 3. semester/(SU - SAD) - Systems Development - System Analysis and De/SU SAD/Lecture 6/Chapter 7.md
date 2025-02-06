Focuses on what the system can do to assist actors in their work.
- WHAT is the system going to do?

Function: A facility for making a model useful for actors.
- A function is a requirement, an abstract property of the system. They are realized through operations.
- Activated, executed, provides a result.
- Can change a model component's state or create a reaction in the application or the problem domains. 

### Finding functions
- Partly the problem domain description (classes, events), party the application domain description (use cases)
	- Classes: Read and update functions typically
	- Events: Requirements for update functions
	- Use cases: all types of functions

## Update Functions
- Activated by a problem domain event and result in a change in the model's state.
- Usually receives data from something or someone, such as when someone registers or logs into a system or inputs information.

Questions for each event:
- How is the event observed and how is it registered (i.e. user input, registered as data in the system, etc)? In which use cases does this happen?
- How should the use cases be supported by update functions?
- Which objects, attributes, and object structures are affected by the event, and what requirements does this impose on the update functions?

General:
- There should be an update an function for each event, since if an event is included, it must be important for the model

## Signal functions
- Activated by a change in the model's state and result in a reaction in the context, such as a display to the actors in the application domain.
- Example is something that sends an alert when a critical state is reached.
- Example: task overdue, customer overdrawing, etc.

Questions about critical states:
- What are the critical states for the model?
- What is the significance of these critical states? What are the consequences when they occur?
- How does a signal function register that the model has entered a critical state?
- What signals does each critical state give rise to? How reliable and strong do the signals have to be?

General:
- Users help identify signal functions, by providing critical states

## Read functions
- Activated by a need for information in an actor's work task, results in the system displaying relevant parts of the model.
- Example is a function that retrieves information to be shown to an actor, such as information about the users in the system or whatever.

Questions about information needs
- Given the work of the actors, what do the actors need to know about the state of the model? What read functions does this give rise to?
- Given the model, which objects and structures will the actors need information about? What read functions does this give rise to?

General:
- There should be a read function per class or something similar, as it's usually necessary to be able to read the values of objects in the model.

## Compute
- Activated by a need for information in an actor's work task and consist of a computation involving information provided by the actor or the model.
- Result is a display of the computation result.
- An example would be the autolocate batch function from our semester project.

Questions about needs for computation:
- Which computations (not necessarily based on the model) do the actors need to have carried out?
- Does the computational basis come from the actors, the mode, or both?
- Which computations form complete wholes in the use cases?

General:
- Related to more complex information needs that cannot be immediately met by reading the model.
- Must be identified from the use cases
- Delimit individual compute functions: A computation sequence that cannot be interrupted by the actor should be supported by one function.
	- If it consists of several alternative parts, consider using more than one function.
		- Avoid cluttering the list of functions.
- If the thing we wish to compute exists as an attribute, we do not need a compute, but can make do with a read function.
	- If it does not exist as an attribute, we need a compute function.

## Multiple types
- Functions can sometimes be multiple types
	- Most commonly read and compute

## Complex functions
- Specify briefly
- Either pseudo code or functional partitioning

## Evaluate functions
- Required functionality must be consistent with the list of functions
- Ask user
- Review questions
- Compare with the system definition and the model
	- If the model contains objects, structures or events that are never used by any of the functions, either the model contains too much or some functions are missing.