package pq;

// Max Priority Queue implemented as a max heap
public class PriorityQueue {
	
	private int arr[];	// array representation of the PQ (index of left & right child: 2i and 2i+1, when indexing starts from 1) (index of left & right child: 2i+1 and 2i+2, when indexing starts from 0)
	private int size;	// maximum size
	private int pos;	// current end-position
	
	/* PQ CONSTRUCTOR */
	public PriorityQueue(int size) {
		this.size = size + 1; // one extra because we will start indexing from 1
		this.arr = new int[this.size];
		this.pos = 0;
	}
	
	/* INSERTION */
	public void insert(int n) {
		if(pos >= size) return;
		
		arr[++pos] = n;
		swimUp(pos);
	}
	
	private void swimUp(int i) {
		if(i <= 1) return;
		
		// if current element is greater than its parent
		if(arr[i] > arr[i/2]) {
			swap(i, i/2);
			swimUp(i/2);
		}
	}
	
	/* DELETE AND POP MAX ELEMENT */
	public int deleteMax() {
		if(pos < 1) return Integer.MIN_VALUE;
		
		int temp = arr[1]; // current max element will be at first position
		swap(1, pos);
		pos--;
		sinkDown(1);
		
		return temp;
	}
	
	private void sinkDown(int i) {
		int max = i, left = (2 * i), right = (2 * i + 1);
		
		if(left <= pos && arr[left] > arr[max]) // if left child is larger than root
			max = left;
		if(right <= pos && arr[right] > arr[max]) // if right child is larger than the largest so far
			max = right;
		
		// if largest is not root anymore, then we must sink it
		if(max != i) {
			swap(i, max);
			sinkDown(max); // recursively call sink-down for the affected sub-tree
		}
	}
	
	/* DISPLAY CURRENT PQ ELEMENTS */
	public void display() {
		for(int i = 1; i <= pos; i++)
			System.out.print(arr[i] + " ");
	}
	
	/* CLEAR THE PQ */
	public void clear() {
		pos = 0;
	}
	
	
	/* HEAP SORT A GIVEN ARRAY */
	/* 
	 * (HERE, LIST INDEXING STARTS FROM 0)
	 * (LIM: 0 TO N-1)
	 * (LEFT: 2I+1, RIGHT: 2I+2)
	 * 
	 */
	public void heapSort(int list[]) {
		int n = list.length;
		
		// build a max-heap (max-PQ) by rearranging the array (from half of the array to its beginning, not taking leaf nodes unnecessarily)
		for(int i = n/2 - 1; i >= 0; i--) // here indexing is from 0
			heapify(list, n, i);
		
		// one by one extract an element from the heapified array
		for(int i = n - 1; i >= 0; i--) {
			swap(list, 0, i); // Move current root (0th (maximum) element) to the end (current ith position)
			heapify(list, i, 0); // call heapify on the reduced heap
		}
	}
	
	/* HEAPIFY AN ARRAY (SINK-DOWN FUNCTIONALITY, CALLS ITSELF TO BUILD HEAP IN TOP-DOWN MANNER) */
	private void heapify(int list[], int listSize, int i) {
		int max = i, left = (2 * i + 1), right = (2 * i + 2);
		
		if(left < listSize && list[left] > list[max]) // if left child is larger than root
			max = left;
		if(right < listSize && list[right] > list[max]) // if right child is larger than the largest so far
			max = right;
		
		// if largest is not root anymore, then we must sink it
		if(max != i) {
			swap(list, i, max);
			heapify(list, listSize, max); // recursively heapify the affected sub-tree
		}
	}
	
	private void swap(int list[], int i, int j) {
		int t = list[i];
		list[i] = list[j];
		list[j] = t;
	}
	
	private void swap(int i, int j) {
		int t = arr[i];
		arr[i] = arr[j];
		arr[j] = t;
	}
}