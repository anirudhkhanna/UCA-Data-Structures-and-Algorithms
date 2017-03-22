package javapractice.visibilityandinheritance.package1;

class Derived extends A {
	public Derived() {
		def = 10;
	//	pri = 20; <-- Error. Not inherited.
		pro = 30;
		pub = 40;
		System.out.println("Object created.");
	}
	
	public static void main(String[] args) {
		Derived d = new Derived();
	}
}