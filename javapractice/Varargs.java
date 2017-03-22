package javapractice;

public class Varargs {

	static void varargsFun(String... args) {
		System.out.print("Varargs :: " + args.length + " arguments passed: ");
		for(String item:args)
			System.out.print(item + " ");
		System.out.println();
	}

	static void arrayFun(String[] args) {
		System.out.print("Array :: " + args.length + " arguments passed: ");
		for(String item:args)
			System.out.print(item + " ");
		System.out.println();
	}
	
//	static void varargsMultiple(int... args0, float...fs args1) { } <-- Error. Only one varargs parameter is allowed.
	
//	static void varargsPositioned(int... args0, int args1) { } <-- Error. Varargs parameter must be the last parameter.
	
	public static void main(String... args) { // Can declare main() with varargs too!
		varargsFun();
		varargsFun("Hi");
		varargsFun("Hi", "Hello");
		String strArr[] = new String[] {"Hi", "Hello"};
		varargsFun(strArr);

		System.out.println();
	//	arrayFun(); <-- Error. Improper call.
	//	arrayFun("Hi"); <-- Error. Improper call.
	//	arrayFun("Hi", "Hello"); <-- Error. Improper call.
		String strArr1[] = new String[] {"Hi", "Hello"};
		arrayFun(strArr1);
	}
}
