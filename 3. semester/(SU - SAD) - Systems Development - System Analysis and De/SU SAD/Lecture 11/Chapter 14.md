- Cohesion: how well the things (attributes, operations) inside a class fit together
	- *A measure of how well a class or component is tied together.*
	- High cohesion is best, so that all things are related inside a class
	- Several factors points to high cohesion:
		- Operations constitute a functional whole
		- Attributes and object structures describe objects with well-defined states
		- Operations use each other
	- High component cohesion:
		- Component classes are conceptually related
		- Structural relations among classes are primarily generalizations and aggregations
		- Key operations can be carried out within the component
	- Names of classes and components are an important factor for cohesion
- Coupling (negative property): how much multiple classes are connected (a measure of how closely two classes or components are connected), expresses that change in one class or component necessitates change in another class or component
	- Low coupling is best, so that classes can be exchanged without changing a lot of the system
	- Outside coupling: a class or component refers directly to the public properties of another class or component
		- okay to use
	- Inside coupling: an operation refers directly to other, private properties in the same class
	- Coupling from below: a specialized class refers directly to private properties in the superclass
	- Sideways coupling a class refers directly to private properties in another class
- Realization of flexibility and comprehensibility criteria can be realized through evaluating coupling and cohesion
- Split a cohesive class: Resulting classes will be tightly coupled
- Integrate two classes with low coupling: incohesive class


## Connecting components
- Design connections so that classes and components maintain cohesion, ensure that coupling is low
- Result is a class diagram with connections instead of dependencies
- Three forms of connections:
	- Aggregating another component's classes
	- Specializing another component's public class
	- Calling public operations in another component's objects
		- Preferred as it makes it easy to achieve high cohesiveness and low coupling

### Class aggregation
- Aggregate another component's public class
	- Example: Account has many objects (instances) and they are all aggregated into an object of the "Account Management" class

### Class specialization
- Use a public class from another component to define a new class by specialization.
	- Typically the super class is above the subclass, but in a layered architecture the serving class is below the served class.
- Useful when we use classes provided by other classes
	- Do not have to tamper with the provided class, can add properties by specializing
	- Coupling is low subclasses only use public operations

### Operation call
- Realize dependency between two components by having an operation in one component's object call an operation in another component's object
	- Recommended to stereotype the dependency with \<\<call>>
	- If there are multiple operations on each, look at the specifications of the calling operations to see the full semantics

## Patterns

### Observer pattern
- Good when several objects depend on one object's change of state
- Useful for maintaining a strictly layered component architecture

## Evaluate connections