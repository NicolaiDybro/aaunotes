## Problem Domain Analisys
- What information should the system deal with?
- PDA provides language for expressing requirements to the system.

When inquiring about the PD do not worry about existing systems. Describe the phenomena that they administrate, monitor and control.

## Classes
- Object: An entity with identity, state, and behavior.
- Class: A description of a collection of objects sharing structure, behavioral pattern, and attributes.
- Event: An instantaneous incident involving one or more objects.

Classify objects in the problem domain, characterize them through their events.

### Which objects and events should we include in the model and which should be left out?
Study the problem domain. Abstract problem-domain phenomena by seeing them as objects and events. Looking at the problem domain we see objects and events.

#### Object
Customer, clerk, contract, order, item, shelf, etc. Can also be less tangible such as organization, resource. Must be able to identify the object as an individual entity.

#### Classes
Objects grouped together create classes, all objects in a class share common attributes, structure, behavioral patterns.

How to identify classes:
- Write down all potentially relevant classes, without evaluating them in detail. Use own perception of problem domain, descriptions, etc, system definition, rich pictures, etc. Can also examine similar computerized systems.
- Nouns or noun phrases, and general types

Use class names that:
- Are simple and readable.
- Originate in the problem domain.
- Indicate a single instance.

#### Events
Numerous verbs relate to the way users carry out their jobs; these do not belong in the problem domain, but rather in the application domain. 

How to identify events:
- Look at an activity's start and end points, as well as intermediate events.
- Doesn't necessarily have to be explicitly written in the description. For example, with S-Food assignment, it just says that customers can compose meals not that they can cancel them, but it's valid to include an 'Order cancelled' event in this instance, since it would be very intuitive that customers could cancel orders, etc. So can be anything that would make sense from start to end in the activity.
- Verbs and general types

Use event names that:
- Are simple and readable.
- Originate in the problem domain.
- Indicate a single instance.

Use the same tense for all events, (personally prefer past tense, since the event is supposed to represent something that has happened.)

### Evaluation criteria for classes and events
- Class or event should be included in the problem domain if and only if system functions use information about it.
- Is the class or event within the system definition?
- Is the class or event relevant for the problem-domain model?

Typical mistakes is to include the user or the system itself in the candidate class list (unless user has a functionality such as login to restrict data access).
Events should only include the things that happen in the problem domain, not within the computerized system.

#### Criteria for classes
- Can you identify objects from the class? (such as through a reference, number, name, etc,)
- Does the class contain unique information?
- Does the class encompass multiple objects?
- Does the class have a suitable and manageable number of events?

If the information contained in a class can be derived from other classes, you are modeling functionality, the class should be rejected.
A class with very few events might be too simple or irrelevant, and might not be necessary to include therefore. A class with too many events might be too complex and should maybe be divided up into smaller classes.

Descriptions of classes should be its responsibilities.

Few, clear responsibilities = high cohesion, many responsibilities = low cohesion, it should possibly be split up into smaller classes.

#### Criteria for events
- Is the event instantaneous?
- Is the event atomic?
- Can the event be identified when it happens?

Atomic meaning?

### Event table
A table with events in the outer leftmost column, and the classes in the top most row.

How to identify relations between classes and events?
- Which events is this class involved in?
- Which classes are involved in this event?

Event table can be used to evaluate classes and events.

Pages 385-392 hair salon example