package javapractice.visibilityandinheritance.package2;

import javapractice.visibilityandinheritance.package1.A;

class Client {
	public static void main(String[] args) {
		A a = new A();
	//	System.out.println(a.def); <-- Error. Not visible.
	//	System.out.println(a.pri); <-- Error. Not visible.
	//	System.out.println(a.pro); <-- Error. Not visible.
		System.out.println(a.pub);
	}
}