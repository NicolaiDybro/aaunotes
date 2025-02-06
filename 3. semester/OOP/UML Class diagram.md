### Class
![[Pasted image 20241229105248.png]]
 - Visibility notation: 
	- `+` for public (visible to all classes)
	- `-` for private (visible only within the class)
	- `#` for protected (visible to subclasses)
	- `~` for package or default visibility (visible to classes in the same package)

### Relations
![[Pasted image 20241229105732.png]]
#### Association
bi-directional relationship (e.g. book belongs to library and library has book)
#### Directed Association
Like association, but only one class is associated with another, can be used for dependencies to show a directional tree.
#### Aggregation
Relationship where one class is made up of another class. Where the other class can still exist without the aggregating class. Diamond is associated with the whole class. (e.g. company /diamond /arrow employee, here employees can still exist without a company)
#### Composition
Like a aggregation but more strong. The other class can't exist without the other. (e.g. contact book which has contact pages. if the contact book is destroyed the contact pages are too)
#### Generalization (In-heritance)
![[Pasted image 20241229111043.png]]
#### Realization (Interface implementation) ![[Pasted image 20241229111145.png]]
#### Dependency
Not as strong relation as assosiation, but still a relation
![[Pasted image 20241229111522.png]]
#### Usage dependency
Does not own or create new instances, just uses
![[Pasted image 20241229111644.png]]

