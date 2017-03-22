package javapractice;

/* Abstract class */
abstract class MyAbstractClass {
	int x;
	int y = 10;
	static int z = 20;
	
	void foo() { System.out.println("Method: foo()"); }
	abstract void bar();
//	void baz(); <-- Error, must include "abstract" keyword, or otherwise define the function
	public void bax() { System.out.println("Method: bax()"); }
}

/* Interface */
interface MyInterface {
//	int x; <-- Error, as instance variables are final in interfaces
	int y = 10;
	static int z = 20;
	
//	void foo() { System.out.println("Method: foo()"); } <-- Error, as function definition is not allowed in interfaces
	void bar();
	abstract void baz();
//	private void bax(); <-- Error, interface methods are public and abstract only
}

interface MyAnotherInterface {
	int y = 10;
	
	void bar();
	abstract void baz();
	void bax(); // Defined automatically in MyClass as it inherits this defined function from MyAbstractClass
}

/* Class */
class MyClass extends MyAbstractClass implements MyInterface, MyAnotherInterface {
	public void bar() { System.out.println("Abstract Method: bar()"); } // Must be public, as interface methods are public and we can not downcast
	public void baz() { System.out.println("Abstract Method: baz()"); } // Must be public, as interface methods are public and we can not downcast
}

/* Demonstrator class */
public class AbstractClassesAndInterfaces {
	public static void main(String[] args) {
		MyAbstractClass mac;
	//	mac = new MyAbstractClass(); <-- Error, can not directly instantiate
		mac = new MyAbstractClass() {
			void bar() { System.out.println("Abstract Method: bar()"); }
		};
		
		MyInterface mi;
	//	mi = new MyInterface(); <-- Error, can not directly instantiate
		mi = new MyInterface() {
			public void bar() { System.out.println("Abstract Method: bar()"); }
			public void baz() { System.out.println("Abstract Method: baz()"); }
		};
		
		MyClass mc;
		mc = new MyClass();
		mc.foo();
		mc.bar();
		mc.baz();
		mc.bax();
	//	System.out.println(mc.y + " " + MyClass.z); <-- Error, when multiple variables of same name are inherited, it is ambiguous to refer to them
	}
}
