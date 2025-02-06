### Application Domain Analysis:
- How will the target system be used?
- Define requirements for the systems functions and interfaces
## Usage
System must fit the application domain.

### Use cases
A pattern for interaction between the system and actors in the application domain.
- A way of using the system.

#### Identify use-cases:
- How will the system be used?
- Examine application domain tasks


#### Describe use-cases
- Using statechart diagrams or or text specifications.
- In each description/diagram, identify actors and interactions (do not write how the interactions are performed)
	- Objects relevant to the use case
	- Functions relevant to the use case
#### Patterns

##### Procedural pattern
- Sequence
- Ensures business rules are observed
	- For example, enter code before using credit card

##### Material pattern
- Few general states
- Good for things like documents or something where any tool may be used in any order
- Good when there are few rules as to when tools can be used

#### Evaluate use-cases
- Review descriptions to find mistakes and inconsistencies
	- Each use-case should be simple and constitute a coherent whole
	- Descriptions should provide understandings and overview
	- use cases should be described in enough detail to enable identification of functions and interface elements
- Test use-cases to see if they work in practice
### Actors
An abstraction of users or other systems that interact with the target system.

#### Identify actors
- Who will use the system?
- Determine the the division of labor (roles, for example)
	- If several roles appear the same, consider making them into one actor
- Can use the work tasks in the application domain

#### Describe actors
Actor specification consists of 3 things:
- Goal: Describe as precisely as possible the actors role in relation to the target system (A person who owns an account, the account owner's basic need is to make payments with their plastic card)
- Characteristics describe important aspects of actors' use of the system (if the actor is another system, the characteristics could include the technical interface).
- Examples: Concrete examples of the different types of actors within this actor specification 

### Use case table
- Represented as either a use case table or use-case diagram through UML.