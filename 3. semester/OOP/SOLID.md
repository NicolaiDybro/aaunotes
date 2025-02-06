### Single-Responsibility Principle
>A class should have one and only one reason to change, meaning that a class should have only one job.

E.g. the class Areacalculator which also have a method that formats the output is bad, because the entire class would need to be overwritten if other formats should be supported or the output changes. Better to have Areacalculator and AreacalculatorOutputter. Before Areacalculators responsibility where to calculate area as well as output.
### Open-closen Principle
>Objects or entities should be open for extension but closed for modification.

E.g. Geometry object classes could implement a interface which add the area method, then Areacalculator could call that method. Now new Geometry classes can be added without modifying Areacalculator.

### Liskov Substitution Princible
>Let q(x) be a property provable about objects of x of type T. Then q(y) should be provable for objects y of type S where S is a subtype of T.

### Interface segregation Princible
> A client should never be forced to implement an interface that it doesn’t use, or clients shouldn’t be forced to depend on methods they do not use.

Split interfaces up
### Dependency Inversion Princible
>Entities must depend on abstractions, not on concretions. It states that the high-level module must not depend on the low-level module, but they should depend on abstractions.

In a class which connects to MySQL database, it's better to connect to a class with implements the connect interface, such that which database is being used isn't relevant.