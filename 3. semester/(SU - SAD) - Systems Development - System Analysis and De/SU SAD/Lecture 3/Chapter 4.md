## Structure

### Class structures
- Generalization: A general class (the super class) describes properties common to a group of specialized classes (the subclasses).
- Cluster: A collection of related classes.
### Object Structures:
- Aggregation: A superior object consists of a number of objects (parts).
- Association: A meaningful relation between a number of objects.

How to identify relations between classes and objects:
- What are the specific relations between objects in the problem domain?
- What is the conceptual relation between two or more classes in our problem-domain model?

Abstract classes, which have no objects, should be written in italic. An example would be *Role*, if it has *User* and *Administrator* as subclasses, the role itself would never have any objects.

General things when making a class diagram:
- Generalization arrows should point upwards.
- Specialized classes inherit the properties and behavior of the general class.
- Multiple inheritance is allowed in OOAD, can sometimes improve the model.
- When doing aggregation, the whole should be placed above the parts.

Should I create a state chart diagram describing the behavior of a specialized class?

An object should only capture properties relevant to the problem domain.

Types of connections:
- Generalization: is-a relationship (super/subclass relationship)
	- Doesn't have multiplicity as it's a is-a relationship, that means a car is exactly one vehicle and a vehicle can be exactly one car
- Aggregation: has-a or owns-a relation (whole/part relationship), usually between different (conceptual) levels.
	- One class "owns" the other
	- The child can exist independently of the parent.
	- Can have multiplicity
- Association: Relation, usually a loose relation, on the same level.
	- Usage: for example, it makes no sense to say that a person is contains objects from the car class as its parts. Instead, a person is associated with a car. This is also because the person who owns a car is not a defining property of the car, nor the reverse.
	- Associations can be named, since it's not always clear which properties a given association structure represents. Between a car and person it might be "ownership". In most cases, if we need to name an association we could instead introduce a class which contains the properties for us.
	- Can have multiplicity
- Composition: like aggregation, but the child cannot exist independently of the parent.
	- Rack and shelf - can't have a shelf without it being on a rack, a shelf therefore cannot exist independently and a composition should be used.
	- Can have multiplicity


### Cluster Structure
Collection of classes that helps us achieve and provide a problem domain overview. Helps break down the model into smaller modules.
- Usually named after a central class, such as "car
- Classes within a cluster usually connected by generalization or aggregation
- Clusters are usually related through association

## Find candidates for structure
Study abstract, static relations between classes and study concrete dynamic relations between objects.

### Identify generalizations
Relation between two or more classes
- Find generalizations (Take every pair of selected classes and determine whether one of the two is a generalization of the other)
	- If so, the generalization class events must be a subset of the specialization class events.
- Determine if relevant generalization classes exist for pairs of selected classes. (customer and suppliers -> generalization: business partners)
- Attempt to define a relevant generalization or specialization.

### Identify aggregations
Relation between two or more objects.
- Examine each pair of classes to see if the objects of one class might be a decomposition of the objects of the other class.
- Determine if its relevant to aggregate the objects from each pair of classes into objects from a newly create whole-class.
- Determine if we can decompose existing classes into relevant classes not yet part of the model.

Typical applications of aggregation structures:
- Whole-Part: the whole is the sum of the parts, if we add or remove, we change the fundamentality of the whole.
- Container-Content: the whole is a container for the parts (rack and shelves), if we add or remove we do not change the fundamentality of the whole.
- Union-Member: The whole is an organized union of members, we do not change the fundamentality of the whole, however there is a lower limit on the number of members as the union cannot function without members.

The whole is considered to be superior to its parts, therefore the whole should be placed above its parts.

- Questions to determine whether aggregation or association should be used (if atleast 2 yes, consider association):
		- Can the objects exist independently of each other?
		- Are the objects equally ranked?
		- Can the connection from an object from the one class change to other objects from the other class?
### Identify associations
Relation between two or more objects.
- Look at remaining class pairs and see if they can be meaningfully related.
- Use association whenever we must administrate, monitor, control relations between objects that are not otherwise related in the model.
### Identify clusters
- Increases clarity. 
- Generalization and aggregation represent a close relationship between classes  and the objects, while association is a looser relation, it is therefore natural to base clusters on the generalization and aggregation relationships. 
- A class cannot be in two clusters at the same time, if you think it should be in two at the same time, its preferable to create a new cluster.

## Patterns:

### Role pattern
Example
- Role abstract superclass, with concrete classes Employee and Customer. 
- Each person then has-a (aggregation) role. This means a person aggregates zero or more role objects, where each role object is a specialization of the role class.
Let's a person change roles over time. 

Simplified pattern: Person aggregates Employee Role and Customer Role objects directly, used when the roles have nothing in common.
Another: Customer and Employee are specializations of an employee. 

### Relation pattern
- Party 1 aggregates a number of relation objects, and each relation object have a relation to party 2. 
- The relation is owned by party 
- They can have many relations, but each must be represented by exactly one relation object.

Variants:
- Both parties aggregate the relation object, both own the relation
- Both parties connected to the relation object through an association. Loose relation.

### Hierarchy pattern
Objects that are organized into a hierarchy

Example:
- A semester has between 0 and many classes
- A class has between 0 and many students

Variants:
- Objects at one level can belong to several objects on the level above.

### Item Descriptor Pattern
Provides a distinction between items and their descriptions
Example:
- A book has many copies, but a copy is a copy of exactly one book.
- Format: A descriptor aggregates an item, with the descriptor defining properties shared by all the related objects from the "Item" class.

## Evaluate structures
- Structures must be used correctly (correct relationships) - makes no sense to say that an engine is a car, or that a shelf is a rack. Use linguistic expressions to test whether it makes sense.
	- Use aggregation structures to capture fundamental, definitive relations and association structures to capture fluid relations (typically extending across the diagram).
	- Questions to determine whether aggregation or association should be used (if atleast 2 yes, consider association):
		- Can the objects exist independently of each other?
		- Are the objects equally ranked?
		- Can the connection from an object from the one class change to other objects from the other class?
- Structures must be conceptually true (avoid introducing classes or relationships that do not have a basis in the real world)
	- Names, concepts, structural relations reflect the users' understanding
- Structures must be simple
	- No more classes and relations than necessary
	- No need to decompose or generalize classes if it doesn't provide any value.

Hair Salon example pages 392-394