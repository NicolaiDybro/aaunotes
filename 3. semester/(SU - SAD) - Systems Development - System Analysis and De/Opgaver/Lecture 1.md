
1. OOA&D, section 1.9, exercise 1.

What is the difference between objects and classes?

Object er en instance af en class.
Class er en form for blueprint. Lad os sige at frugt er class, så vil banan og æble være objekter.

1. OOA&D, section 1.9, exercise 4.

Why should systems developers understand the context of the systems they are designing?

For at sikre sig, at det de bliver udviklet rent faktisk har nytte til den bruger som skal bruge det.

1. OOA&D, section 1.9, exercise 5, give examples.

How can you distinguish between a system’s problem domain and application domain? Can they partly overlap?

En god start er at finde selve problemet der skal løses, hvilket er problem domain. Herunder kan du undersøge alt der kontrolleres, styres eller lignede. Dette er application domain.

De kan godt overlappe. Eksempelvis hvis man tager udgangspunkt i opgaven fra i dag med både, så kan problem domain være at båden er en del af "problemet". Det er en enhed eller en ting der er en del af problemet.

I application domain ser vi også båd. Da båd bliver en class der skal styres af systemet. 

1. OOA&D, section 2.10, exercise 2.

What is a system definition and how is it used?

Det er en beskrivelse af et computer system, som er beskrevet med sprog. Programmer skal både udvikles med kode, men også socialt da det skal beskrives. 
Det kan være med til at skabe overblik og muligheder, som gør det nemt at sammenligne. Den skal være præcis og kort. 

Man kan sagtens lave flere forskellige af samme system, som gør det nemt at sammeligne. 


1. OOA&D, section 2.10, exercise 9.

What are the elements in the FACTOR criterion for system definition?

FACTOR criterion kan enten bruges som en form for checkliste til en system defintion:

- Functionality: The system functions that support the application-do main tasks. 
- Application domain: Those parts of an organization that administrate, monitor, or control a problem domain. 
- Conditions: The conditions under which the system will be developed and used. 
- Technology: Both the technology used to develop the system and the technology on which the system will run. 
- Objects: The main objects in the problem domain. 
- Responsibility: The system’s overall responsibility in relation to its con text.


1. Aalborg Taxi want a new system for administering and monitoring their taxis, drivers, customers and taxi rides. Describe in text the problem domain and application domain of such a system.


Vi skal først kigge på selve problemet, og hvilke komponenter der er i problem domain.

Taxaer er mængden af de forskellige køretøjer. Problemer med placeringer og måske tilgængelighed.
Chauffører
Kunder, behov
Taxature
Der er også være forskellige problemer med ruter og tildeling af de taxaer der er givet.


Application domain er så hvordan dette system imødekommer de behov der er lavet i problemområcdet.

Der kan være noget taxastyring, Class = Taxa
Der kan være chaufførstyring
Kundestyring
Rutestyring
Og måske noget rapport genering.

Alt i alt så deles det op i selve problemet og så hvordan det skal styres ved application domain.
Her ser vi blandt andet chauffører og taxa går igen.

1. Are the taxis, drivers, customers and taxi rides in the application domain, the problem domain or both? Why?  

Det har jeg lidt allerede snakket om.

Men taxis, drivers and customers kan være i begge dele. Da de alle skal styres. Taxature kan også gå under begge to. 


1. Make a system definition for the Taxi System. The system definition must comply with the FACTOR-criterion.

Aalborg Taxi Managment System

1. Feasibility



3. Make a radically different system definition for the Taxi System. The system definition must comply with the FACTOR-criterion. Compare with the first one; what are the differences.  
    
10. Download and install the tool Visual Paradigm for UML Community Edition from www.visual-paradigm.com.

12. Start Visual Paradigm for UML (VP-UML). Create a Class Diagram that reproduces Figure 1.3 in the OOA&D book. Experiment with the tool.  
    Hint: "1..*" is found under Multiplicity.