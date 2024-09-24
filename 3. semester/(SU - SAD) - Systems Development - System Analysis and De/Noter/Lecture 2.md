
# Problem domain analysis

## Results
The results of the problem domain analysis is a class diagram and behavioural pattern for each class
![[Pasted image 20240909103421.png]]

## Key concepts

## Activities


# The Classes activity

## Results

An event table
Intermediate product
The event table shows major classes and events in the problem domain.

So for each major class we have a list of all the events, and how the effect each other. 

We classify major objects and events in the problem domain

## Key concepts

- Object
	- An entity with a identity, state and behaviour 
- Class
	- A collection of objects sharing information
- Event
	- An instantaneous incident involving one or more objects
	- Events must be:
		- Atomic (Meaning that you can not track to another event.. and another.. and another)
		- Common to several objects
		- Unique name

## Activities
![[Pasted image 20240909110703.png]]

How do I do this?
1. Make a list of all relevant classes/events
2. Start to consider many sources (users, descriptions of the system, problem domain)
3. Name the classes and events
	1. For classes look and nouns
		- Must be a single instance (object)
	2. For events look and verbs
		- Must be a single event

## Exercise:
Suggest classes and events for modelling a hair salon with emphasis on work planning and administration of appointments
### Classes
- Customer
- Appointment
- Treatment
- Work schedule
- Employee

### Events
- Appointment booked
- Work schedule created
- Work schedule edited
- 





# Challenges in this activity
