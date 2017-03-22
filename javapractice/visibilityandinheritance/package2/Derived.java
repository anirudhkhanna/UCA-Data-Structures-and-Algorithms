package javapractice.visibilityandinheritance.package2;

import javapractice.visibilityandinheritance.package1.A;

class Derived extends A {
	public Derived() {
	//	def = 10; <-- Error. Not inherited.
	//	pri = 20; <-- Error. Not inherited.
		pro = 30;
		pub = 40;
		System.out.println("Object created.");
	}
	
	public static void main(String[] args) {
		Derived d = new Derived();
	}
}