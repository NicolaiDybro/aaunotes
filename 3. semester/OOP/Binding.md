### Early binding
The binding which can be resolved at compile time by the compiler is known as static or early binding. Binding of all the static, private and final methods is done at compile-time. Example:
```java
public class NewClass {
	public static class superclass {
		static void print()
		{
			System.out.println("print in superclass.");
		}
	}
	public static class subclass extends superclass {
		static void print()
		{
			System.out.println("print in subclass.");
		}
	}

	public static void main(String[] args)
	{
		superclass A = new superclass();
		superclass B = new subclass();
		A.print();
		B.print();
	}
}
/* OUTPUT
print in superclass.
print in superclass.
*/
```

### Late binding
In the late binding or dynamic binding, the compiler doesn’t decide the method to be called. Overriding is a perfect example of dynamic binding. In overriding both parent and child classes have the same method.
```java
public class NewClass {
	public static class superclass {
		void print()
		{
			System.out.println("print in superclass.");
		}
	}

	public static class subclass extends superclass {
		@Override
		void print()
		{
			System.out.println("print in subclass.");
		}
	}

	public static void main(String[] args)
	{
		superclass A = new superclass();
		superclass B = new subclass();
		A.print();
		B.print();
	}
}

/* OUTPUT
print in superclass.
print in subclass.
*/
```

