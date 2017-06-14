import heap.MaxHeap;

public class MaxHeapClient {
	
	public static void main(String[] args) {
		MaxHeap heap = new MaxHeap(5);
		
		heap.insert(5);
		heap.insert(3);
		heap.insert(1);
		heap.insert(100);
		heap.insert(19);
		
		System.out.print("Heap: ");
		heap.display();
		System.out.print("\ndeleteMax();");
		heap.deleteMax();
		System.out.print("\nHeap: ");
		heap.display();
		System.out.print("\ndeleteMax();");
		heap.deleteMax();
		System.out.print("\nHeap: ");
		heap.display();
		
		System.out.print("\n\nclear(); ");
		heap.clear();
		
		heap.insert(40);
		heap.insert(20);
		heap.insert(10);
		heap.insert(30);
		heap.insert(50);
		System.out.print("\n\nNew heap created. ");
		System.out.print("\nHeap: ");
		heap.display();
		
		System.out.print("\n------------------------\n\n");
		System.out.print("Functionality of Heap Sort: \n");
		
		int list[] = new int[5];
		for(int i = 0; i < list.length; i++)
			list[i] = (int)(Math.random() * 100);
		
		System.out.print("\nList: ");
		for(int i = 0; i < list.length; i++)
			System.out.print(list[i] + " ");
		
		System.out.print("\nheapSort(list);");
		heap.heapSort(list);
		
		System.out.print("\nList: ");
		for(int i = 0; i < list.length; i++)
			System.out.print(list[i] + " ");
	}
}