When something happens in the problem domain, the model must be updated to accurately represent the problem domain (e.g. new student -> student information gets added to the model)

## System definition

Concise description of the system expressed in natural language (FACTOR - Functionality, Application Domain, Conditions, Technology, Objects, Responsibility)

Make multiple system definitions, let the user choose which system definition they want.

## Problem domain analysis

Result should be a class diagram and a behavioral pattern for each class.

The behavioral pattern describes the behavior for each class, describing what they do over time and what we have to monitor with the system.

### Key Concepts

- Problem domain analysis: the part of a context that is administrated, monitored, or controlled by a system.
- Model: provides an updated overview of the problem domain.

## Classes
### Results
An event table which shows major classes and events in the problem domain

Classify objects and events in the problem domain

Events: 
- Atomic
- Common to several objects
- Unique name

## Activities
- Find candidates for classes and events.
	- Brainstorming, be open for all ideas
	- Use existing descriptions
	- Collaborate with/interview users
- Naming: 
	- Must be simple and readable
	- Originate in the problem domain
- For classes
	- look at nouns
	- eliminate nouns that reflect administration objectst or devices
	- describe a single instance
- For events
	- look at verbs
	- eliminate verbs related to the way users carry out their job, that is part of the application domain
- General evaluation criteria, criteria for classes, criteria for events