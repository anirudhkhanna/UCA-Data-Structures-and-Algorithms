package stack;

public class Stack<T> {
	
	private T arr[];
	private int top;
	
	public Stack() {
		arr = (T[]) new Object[2];
		top = -1;
	}
	
	private void resizeArr(int capacity) {
		T[] temp = (T[]) new Object[capacity];
		System.arraycopy(arr, 0, temp, 0, (top + 1));
		arr = temp;
		System.out.println("  (Resized to " + capacity + ")");
	}
	
	public void push(T data) {
		if((top + 1) == arr.length)	// if the array is filled up to full length, expand it to double the length
			resizeArr(arr.length * 2);
		
		arr[++top] = data;
	}
	
	public T pop() {
		if(top < 0)
			return null;
		
		if((top + 1) == (arr.length / 4))	// if the array is filled up to only one-fourth, shrink it to half the length
			resizeArr(arr.length / 2);

		return arr[top--];
	}
	
	public T peek() {
		if(top < 0)
			return null;
		return arr[top];
	}
	
	@Override
	public String toString() {
	//	return java.util.Arrays.toString(arr);
		
		if(top < 0)
			return "[]";
		
		String res = "[";
		for(int i = 0; i < top; i++)
			res += arr[i] + ", ";
		res += arr[top] + "]";
		
		return res;
	}
}