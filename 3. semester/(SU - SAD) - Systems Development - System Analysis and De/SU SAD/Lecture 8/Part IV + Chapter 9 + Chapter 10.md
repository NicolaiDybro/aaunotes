## Part IV
- Component architecture
	- decomposes the system into identifiable, mutually related components
- Process architecture
	- focuses on objects, structures the systems processes
- Define and prioritize criteria
- Bridge criteria and technical platform
- Evaluate designs early

# Criteria
Criterion: A preferred property of an architecture.
- Good design balances several criteria.
- Good design should be usable, flexible, and comprehensible.

### Usability
- Look at the whole of the design.
- Look at the extent to which the design satisfies the users' needs.
	- Analysis, problem-domain, functionality and interaction requirements.
- Look at the extent to which the design fits with the technical platform.
	- Uses devices, processors, software components, etc, without bottlenecks
	- A good design exploits the resources appropriately
- To what extent should user needs and requirements be met at the expense of adaptability to the technical platform?

### Flexibility
- Minimize the consequences of changes (modularity, achieved by encapsulation)
- For example, minimize the consequence that it has that a part of the system is exchanged for something corresponding (seen from the outside, has the same properties), but still different (new internal behavior)
- Lego bricks example

### Comprehensibility
- Fundamental tool for achieving comprehensibility is abstraction
	- Classification, generalization, modularization (primary abstraction mechanisms in OOD)
	- Corresponds to concepts class, generalization, structure, and component
- Reuse of patterns add comprehensibility
	- Even reuse of programming language patterns.
	- Patterns tied to the system's architecture:
		- basic division in model, function and interface components
		- layered architecture, client-server, etc.
- Can also be increased by grouping responsibilities.
	- describing and implementing similar system parts into a single component or class

## Conditions
### Technical
- Existing hardware, basic software, and systems.
- Reuse of patterns and existing components.
- Use of purchased standard components.

Newest technology carries more uncertainties in some cases, and can thereby increase the risk of failure.

### Organizational
- Contractual arrangements.
- Plans for continued development.
- Division of work between developers.

### Human
- Design competence.
- Experience with similar systems.
- Experience with technical platform.

# Components
Structural system view that separates system concerns.

## System components
- Component architecture: A system structure composed of interconnected components.
	- Should be comprehensible and flexible
	- Separate concerns to reduce complexity.
		- also increase comprehensibility and flexibility generally
- Component: A collection of program parts that constitutes a whole and has well-defined responsibilities.
	- Most of the program parts will be classes

Generally:
- A user interface component
	- Should generally be in the top of a layered architecture, since most changes occur in the application domain (not pd), thereby few components depend on the user interface.
- A functions component
- A model component
	- Should generally be in the bottom as it's rarely subject to big changes, and therefore it's okay for a lot of other components to depend on it.
- Reuse existing components

## Architectural patterns
Dependency:
- Implies that a change in one component (pointed at) may affect the other component (pointed from)

### Layered architecture pattern
- Hierarchical thinking
- Each layer is a component
- The upwards interface describes the operations it makes available to the layers above
- The downwards interface describes which operations the component can access in the layer below
- Typically a layer uses the layer below
- Can supplement with a horizontal decomposition into subcomponents (parts)
	- A part has no essential interaction with other parts in the same layer.
- Allows you to modify or exchange the parts independently of one another.

#### Variations
- Closed: a given layer can only use operations from the layer immediately adjacent (above or below)
- Open: can use operations from any layer above or below it
- Strict: can only use operations from the layers below
- Relaxed: can use operations in layers above and below

Gives us the following:
- Closed strict: Can only access operations in the layer directly below it
	- Simple dependencies between components, for any layer only the layer above it can use its operations
	- If we want to change the interface, we need only to change the layer in question and the one above it.
	- Problem: A layer at a higher level will often need operations from layers at a lower level.
		- Must construct operations that merely transmit calls to the lower level.
	- Best if there are many layers so that we do not have to change that much if we wish to change one layer.
- Closed relaxed: Can access operations in the layers directly above or below it
- Open strict: Can access operations from all the layers below
	- Not same problems as a closed strict, but difficult to change the interface for a layer at a low level, since it can lead to changes in all layers above the one in question.
- Open relaxed: Can access operations from all the layers below or above
	- If this is exaggerated the layered idea can disappear.

### Generic architecture pattern
- Let's you elaborate basic systems that include interface, function and model components.
- Model is the lowest layer
- Above model the function component, on top the interface components
- Can be a good idea to incorporate components that serve as well-defined interfaces to certain parts of the technical platform
	- Technical component, with (examples) database, network software, etc

### Client server architecture pattern
- Server and several clients
- Server has a collection of operations that it makes available to the clients.
	- The server doesn't have to know of the clients, but the clients have to know of the server and its operations.
- Network thinking
- Always consider using this when facing geographical distribution

Different forms figure 10.9 page 202

## Define subsystems
- Decompose a system into subsystems: distributing the total model, functionality and interface among several smaller systems.
- System interface and user interface has the responsibility of providing access to functions.
- Probably not a good idea to let the function component communicate with other subsystems, this could jeopardize the component's responsibility.

### Identify components
- Usually start with the layered architecture pattern using interface, function and model components.
	- Extend with various decompositions
	- Can decompose the model component into parts if there are clear demarcations (if there are clear boundaries between different things in the model component)
	- Should be careful when it comes to model component decomposition
		- If some objects are unrelated in a system with high complexity, you might want to separate them into different components (could have an information component with the plant, tray, user classes and a inventory component with the batch, shelf, tray, etc)

#### Function
- Main responsibility is to provide the model's functionality.
- Can decompose if it is incohesive or complex functionality needs.
- In architecture with layered functionality, the layer immediately above the model component uses the model and provides more advanced functionality to the next layer.

#### Interface
- Main responsibility is to handle interaction between the actors and the functionality.
- Typically user interface component and system interface component

### Using existing components
- The system will likely interface with legacy systems
- Certain standard components must be used
- External suppliers can supply advanced class libraries.

### Extending the technical platform
- Libraries and systems as extensions of the underlying technical platform (java, sql, etc.)

### Specify complex components
- Need to specify the responsibility, dependency and the relationship to the context of complex components