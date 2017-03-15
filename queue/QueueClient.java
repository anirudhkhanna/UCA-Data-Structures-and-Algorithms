package queue;

import queue.Queue;

public class QueueClient {
	public static void main(String[] args) {
		Queue<Integer> q = new Queue<Integer>();
		q.insert(10);
		q.insert(20);
		q.insert(30);
		q.insert(40);
		
		System.out.println("Size: " + q.size());
		System.out.println("Elements: ");
		System.out.println(q.delete());
		System.out.println(q.delete());
		System.out.println(q.delete());
		System.out.println(q.delete());
	}
}
