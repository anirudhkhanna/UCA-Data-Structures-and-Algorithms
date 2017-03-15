package stack;

import stack.Stack;

public class StackClient {
	
	public static void main(String[] args) {
		Stack<Integer> s = new Stack<Integer>();
		
		System.out.println("\nPUSHING: ");
		
		s.push(1);	System.out.println(s);
		s.push(2);	System.out.println(s);
		s.push(3);	System.out.println(s);
		s.push(4);	System.out.println(s);
		s.push(5);	System.out.println(s);
		s.push(6);	System.out.println(s);
		
		System.out.println("\nPOPPING: ");
		
		s.pop();	System.out.println(s);
		s.pop();	System.out.println(s);
		s.pop();	System.out.println(s);
		s.pop();	System.out.println(s);
		s.pop();	System.out.println(s);
		s.pop();	System.out.println(s);
	}
}