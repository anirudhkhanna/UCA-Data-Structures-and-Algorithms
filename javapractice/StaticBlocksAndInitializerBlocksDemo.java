package javapractice;

class Grandparent {

	// Static init block
	static {
		System.out.println("Static block - Grandparent\n");
	}

	// Instance init block
	{
		System.out.println("Initializer block - Grandparent\n");
	}

	// Constructor
	public Grandparent() {
		System.out.println("Constructor - Grandparent\n");
	}
}

class Parent extends Grandparent {

	// Static init block
	static {
		System.out.println("Static block - Parent\n");
	}

	// Instance init block
	{
		System.out.println("Initializer block - Parent\n");
	}

	// Constructor
	public Parent() {
		System.out.println("Constructor - Parent\n");
	}
}

class Child extends Parent {

	// Static init block
	static {
		System.out.println("Static block - Child\n");
	}

	// Instance init block
	{
		System.out.println("Initializer block - Child\n");
	}

	// Constructor
	public Child() {
		System.out.println("Constructor - Child\n");
	}
}

class StaticBlocksAndInitializerBlocksDemo {
	public static void main(String args[]) {
		new Child();
	}
}
