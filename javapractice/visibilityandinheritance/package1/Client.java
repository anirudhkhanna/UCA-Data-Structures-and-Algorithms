package javapractice.visibilityandinheritance.package1;

class Client {
	public static void main(String[] args) {
		A a = new A();
		System.out.println(a.def);
	//	System.out.println(a.pri); <-- Error. Not visible.
		System.out.println(a.pro);
		System.out.println(a.pub);
	}
}