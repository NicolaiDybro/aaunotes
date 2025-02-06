# Functions

What happens when an object reaches their final state?
- The object can no longer perform or suffer events.
- The state of the object can still be read by a function.
- Example: a bank account object must still exist after we have closed it, so we can read it, e.g. for customer or tax

Iteration in statechart diagram

+: 0 or 1 times
\* 0 or 1 or many times

Item-descriptor pattern:
both classes contain objects
in a library system, the 'book' is the book in the electronic system, 'copy' is a physical copy of the book (there can be many copies of one book)