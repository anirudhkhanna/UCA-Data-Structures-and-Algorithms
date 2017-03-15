/* Sample program in Java demonstrating classes, interfaces, polymorphism, generics etc. */

package javapractice.processscheduling;

import java.util.Comparator;

/* BINARY SEARCH TREE CLASS */
class BinarySearchTree<Key extends Comparable, Value> // Key and Value are generic type names. This also has to mention about Key (Priority) extending Comparable here only. At compile time, the generic BST class never knows what type it will receive, and so it never recognizes the members of Priority or Process classes. So, for printing purposes we can override toString() in required class, and for implemented interfaces we mention them here.
{
	class Node
	{
		Key key; // priority-based key
		Value value; // process will be the value associated with the key
		Node left;
		Node right;
		
		Node(Key key, Value value)
		{
			this.key = key;
			this.value = value;
		}
	};
	
	private Node root = null;
	
	/* Insertion with Comparable (uses Comparable interface implemented by Priority class to compare its objects) */
	public void insertWithComparable(Key key, Value value)
	{
		root = insertWithComparable(root, key, value);
	}
	
	private Node insertWithComparable(Node n, Key key, Value value)
	{
		if(n == null)
			return new Node(key, value);

		if(key.compareTo(n.key) == 0)
			n.right = insertWithComparable(n.right, key, value); // key (priority) is same, so just insert in right (here we can't just discard another process having same priority)
		else if(key.compareTo(n.key) < 0)
			n.left = insertWithComparable(n.left, key, value);
		else if(key.compareTo(n.key) > 0)
			n.right = insertWithComparable(n.right, key, value);
		
		return n;
	}

	/* Insertion with Comparator (uses Comparator interface implemented by various comparator classes to compare Priority objects) */
	public void insertWithComparator(Key key, Value value, Comparator cmp)
	{
		root = insertWithComparator(root, key, value, cmp);
	}
	
	private Node insertWithComparator(Node n, Key key, Value value, Comparator cmp)
	{
		if(n == null)
			return new Node(key, value);

		if(cmp.compare(key, n.key) == 0)
			n.right = insertWithComparator(n.right, key, value, cmp); // key (priority) is same, so just insert in right (here we can't just discard another process having same priority)
		else if(cmp.compare(key, n.key) < 0)
			n.left = insertWithComparator(n.left, key, value, cmp);
		else if(cmp.compare(key, n.key) > 0)
			n.right = insertWithComparator(n.right, key, value, cmp);
		
		return n;
	}
	
	/* InOrder Traversal */
	public void inOrder()
	{
		inOrder(root);
	}
	
	private void inOrder(Node n)
	{
		if(n == null) return;
		
		inOrder(n.left);
		System.out.print(n.value + " "); // toString() method has been overridden in the actual class. We can't use getter method here as Value type won't recognize members at compile time and give error.
		inOrder(n.right);
	}
	
	/* Clear the BST */
	public void clear()
	{
		root = null;
	}
};

/* MAIN CLASS */
public class JavaPracticeProcessScheduling
{
	public static void main(String[] args)
	{
		BinarySearchTree bstTemp = new BinarySearchTree();
		BinarySearchTree<Priority, Process> bst = new BinarySearchTree<Priority, Process>();
		
		Process proc1 = new Process(1, "Process1");
		Priority prio1 = new Priority(20, 30);
		Process proc2 = new Process(1, "Process2");
		Priority prio2 = new Priority(10, 40);
		Process proc3 = new Process(1, "Process3");
		Priority prio3 = new Priority(30, 50);
		
		bst.insertWithComparable(prio1, proc1);
		bst.insertWithComparable(prio2, proc2);
		bst.insertWithComparable(prio3, proc3);
		
		System.out.print("\nInOrder: ");
		bst.inOrder();
		System.out.print("\n***\n");

		bst.clear();
		
		Comparator cmp = new ComparatorByMedianTime();
		bst.insertWithComparator(prio1, proc1, cmp);
		bst.insertWithComparator(prio2, proc2, cmp);
		bst.insertWithComparator(prio3, proc3, cmp);

		System.out.print("\nInOrder: ");
		bst.inOrder();
		System.out.print("\n***\n");
	}
};