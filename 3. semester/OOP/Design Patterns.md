### Creational Patterns
- Factory
	- *Simple Factory*: Abstracts object creation with a factory class (9. Design Patterns: slide 22)
	- *Factory Method*: Abstract factory class than can be inherited from to create factories (9. Design Patterns: slide 25)
	- *Abstract Factory*: Encapsulates similar factories bound by common theme. Subclass factories can have multiple methods (9. Design Patterns: slide 27)
- *Builder*: Build complex objects one method at a time. Can be exapended with Director to call methods of a builder in a specific order. (10. Design Patterns 2)
- *Singleton*: There only ever exists one instance of a class (11. Design Patterns 3: slide 24)

### Structural Patterns
- *Decorator*: A wrapper of an object, which implements the same interface as the object. The wrapper can have extended functionality, while the same interface is still used. (10. Design Patterns 2: slide 11)
- Adapter
	- *Object adapter*: Wraps a object, but with anoth interface, such that that object can be used as something else. (10. Design Patterns 2: slide 16)
	- *Class adapter*: New subclass of object, but extends the desired interface which the object should be adapted to (10. Design Patterns 2: slide 17)
- *Composite*: A tree like structure, like calling get size of a folder which calls get size of all its files and folders. Both file and folder is implemented using the same interface. (10. Design Patterns 2: slide 20)

### Behavioral Patterns
- *Template Method*: Superclass is a template that subclasses can overwrite. Abstract methods must be implemented, other methods can be overwritten. Usefull for algorithms with slightly different implementations. (10. Design Patterns 2: slide 24)
- *Observer*: Objects can subscribe to another object to have its method called when something happens in the other object. The other objects uses a subscriber interface, that every object that what to subscribe can call. (11. Design Patterns 3: slide 3)
- *Command*: Requests represented as objects, usually from a Command interface. Another object deals with running the commands. Supports undoable commands. (11. Design Patterns 3: slide 7)
- *Strategy*: An object, which uses another object from a Strategy interface, to provide implementation. (11. Design Patterns 3: slide 12)
- *Visitor*: Minimize modification. A object needs to add a acceptVisitor method, and then new functionality can be added in the form of new visitor classes, without modifying an object. (11. Design Patterns 3: slide 15)