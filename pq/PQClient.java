package pq;

import pq.PriorityQueue;

public class PQClient {
	
	public static void main(String[] args) {
		PriorityQueue pq = new PriorityQueue(5);
		
		pq.insert(5);
		pq.insert(3);
		pq.insert(1);
		pq.insert(100);
		pq.insert(19);
		
		System.out.print("PQ: ");
		pq.display();
		System.out.print("\ndeleteMax();");
		pq.deleteMax();
		System.out.print("\nPQ: ");
		pq.display();
		System.out.print("\ndeleteMax();");
		pq.deleteMax();
		System.out.print("\nPQ: ");
		pq.display();
		
		System.out.print("\n\nclear(); ");
		pq.clear();
		
		pq.insert(40);
		pq.insert(20);
		pq.insert(10);
		pq.insert(30);
		pq.insert(50);
		System.out.print("\n\nNew PQ created. ");
		System.out.print("\nPQ: ");
		pq.display();
		
		System.out.print("\n------------------------\n\n");
		System.out.print("Functionality of Heap Sort in PQ: \n");
		
		int list[] = new int[5];
		for(int i = 0; i < list.length; i++)
			list[i] = (int)(Math.random() * 100);
		
		System.out.print("\nList: ");
		for(int i = 0; i < list.length; i++)
			System.out.print(list[i] + " ");
		
		System.out.print("\nheapSort(list);");
		pq.heapSort(list);
		
		System.out.print("\nList: ");
		for(int i = 0; i < list.length; i++)
			System.out.print(list[i] + " ");
	}
}