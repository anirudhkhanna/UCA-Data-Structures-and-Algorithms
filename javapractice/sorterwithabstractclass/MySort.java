/* Demonstrating abstract classes, inheritance etc. */

package javapractice.sorterwithabstractclass;

/* Abstract sorter class */
abstract class Sorter {
	void swap(int arr[], int x, int y) {
		int temp = arr[x];
		arr[x] = arr[y];
		arr[y] = temp;
	}

	void print(int arr[]) {
		for(int i = 0; i < arr.length; i++)
			System.out.print(arr[i] + " ");
	}

	abstract void sort(int arr[]);
}

/* Bubble sorter class inheriting the abstract sorter class as its base */
class BubbleSorter extends Sorter {
	// print function inherited and overridden from sorter class
	@Override
	void print(int arr[]) {
		System.out.print("From BubbleSorter: arr[] = ");
		super.print(arr); // calling the actual print function by using "super"
	}

	// defining the inherited abstract function sort from sorter class
	@Override
	void sort(int arr[]) {
		int i, j;

		for(i = 0; i < arr.length - 1; i++)
			for(j = 0; j < arr.length - i - 1; j++)
				if(arr[j] > arr[j + 1])
					swap(arr, j, j + 1); // use of swap function from sorter class
	}
}

/* Selection sorter class inheriting the abstract sorter class as its base */
class SelectionSorter extends Sorter {
	// print function inherited and overridden from sorter class
	@Override
	void print(int arr[]) {
		System.out.print("From SelectionSorter: arr[] = ");
		super.print(arr); // calling the actual print function by using "super"
	}

	// defining the inherited abstract function sort from sorter class
	@Override
	void sort(int arr[]) {
		int i, j, min;

		for(i = 0; i < arr.length - 1; i++) {
			min = i;
			for(j = i; j < arr.length; j++) {
				if(arr[j] < arr[min])
					min = j;
			}
			swap(arr, i, min); // use of swap function from sorter class
		}
	}
}

/* Main class */
public class MySort {
	public static void main(String args[]) {
		BubbleSorter bubbleSorter = new BubbleSorter();
		Sorter selectionSorter = new SelectionSorter(); // Can declare like this too. Shows IS-A relationship. But the object will not contain the extra, non-inherited members of the child class, is any.

		int arr[] = new int[] {7, 5, 3, -5, 3, 0, 1, -2};
		System.out.println("\nOriginal array: ");
		bubbleSorter.print(arr);

		bubbleSorter.sort(arr);

		System.out.println("\n\nSorted array: ");
		bubbleSorter.print(arr);

		arr = new int[] {7, 5, 3, -5, 3, 0, 1, -2};
		System.out.println("\n\n\nOriginal array: ");
		selectionSorter.print(arr);

		selectionSorter.sort(arr);

		System.out.println("\n\nSorted array: ");
		selectionSorter.print(arr);
	}
}
