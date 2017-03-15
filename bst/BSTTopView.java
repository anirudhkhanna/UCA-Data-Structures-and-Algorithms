package bst;

import java.util.HashSet;
import java.util.Set;
import java.util.LinkedList;

public class BSTTopView {
	private class Node {
		int     key;        // key
		Node    left;       // left child node
		Node    right;      // right child node
		
		public Node(int key) {
			this.key = key;
		}
	} // Node class closed

	Node root = null;
	
	
	/* INSERTION */
	void insert(int key) {
		root = insert(root, key);
	}
	
	private Node insert(Node n, int key) {
		if(n == null) {
			Node newNode = new Node(key);
			return newNode;
		}
		else if(key < n.key)	n.left = insert(n.left, key);
		else	n.right = insert(n.right, key);
		return n;
	}


	/* INORDER (JUST FOR CHECKING THINGS) */
	void inOrderTraverse(Node n) {
		if(n == null) return;
		inOrderTraverse(n.left);
		System.out.print(n.key+" ");
		inOrderTraverse(n.right);
	}
	
	
	/* WNODE CLASS TO STORE NODE AS WELL AS ITS WIDTH (CAN BE USED WHEN WE DON'T HAVE ACCESS TO NODE CLASS, SHOWS HAS-A RELATIONSHIP) */
	private class wNode {
		Node n;
		int width;
		
		public wNode(Node n, int width) {
			this.n = n;
			this.width = width;
		}
	}
	
	
	/* TOP VIEW TO SHOW TOP ELEMENTS OF EACH WIDTH WITH LEVEL ORDER TRAVERSAL */
	/* DONE BY SETTING RELATIVE WIDTH (HORIZONTAL POSITION) OF EVERY ELEMENT
	 * Root : 0
	 * Left children of root: -1 for each unit left
	 * Right children of root: +1 for each unit right
	 */
	public void topView() {
		Set<Integer> set = new HashSet<Integer>();
		QueueClass<wNode> q = new QueueClass<wNode>();
		
		int w = 0; // initial width
		q.insert(new wNode(root, w)); // insert root initially
		
		while(q.hasItems()) {
			wNode t = q.delete();
			w = t.width;
			if(!set.contains(w)) {
				System.out.print(t.n.key + " ");
				set.add(w);
			}
			
			if(t.n.left != null) q.insert(new wNode(t.n.left, w-1));
			if(t.n.right != null) q.insert(new wNode(t.n.right, w+1));
		}
	}
	
	
	/* MAIN FUNCTION */
	public static void main(String args[]) {
		
//            __12__
//           /      \
//          10      15
//         / \      / \
//        5   11   13  20
//         \
//          9
//         /
//        8
//       /
//      7
		
		// First Tricky Tree
		BSTTopView tree = new BSTTopView();

		tree.insert(12);	tree.insert(10);
		tree.insert(5);		tree.insert(9);
		tree.insert(8);		tree.insert(7);
		tree.insert(11);	tree.insert(15);
		tree.insert(13);	tree.insert(20);
		
		System.out.println("\n\nTREE 1 TOP VIEW: ");
		tree.topView();
		
//          7
//        /   \
//      2       8
//        \
//          4
//            \
//              5
//               \
//                 6

		// Second Tricky Tree
		BSTTopView tree2 = new BSTTopView();

		tree2.insert(7);	tree2.insert(2);
		tree2.insert(4);	tree2.insert(5);
		tree2.insert(6);	tree2.insert(8);

		System.out.println("\n\nTREE 2 TOP VIEW: ");
		tree2.topView();

		// Third Tree
		BSTTopView tree3 = new BSTTopView();

		tree3.insert(7);//                        7
		tree3.insert(1);//                       /  \
		tree3.insert(0);//                      /    \
		tree3.insert(3);//                     1      9
		tree3.insert(2);//                    / \    / \
		tree3.insert(5);//                   0   3  8  10
		tree3.insert(4);//                      / \
		tree3.insert(6);//                     2   5
		tree3.insert(9);//                        / \
		tree3.insert(8);//                       4   6
		tree3.insert(10);//
		
		System.out.println("\n\nTREE 3 TOP VIEW: ");
		tree3.topView();
	}
}


/* GENERIC QUEUE IMPLEMENTATION WITH LINKED LIST */
class QueueClass<T> {
	private LinkedList<T> list = new LinkedList<T>();
	
	public void insert(T item) { list.addLast(item); }
	public T delete()          { return list.poll(); }
	public boolean hasItems()  { return !list.isEmpty(); }
	public int size()          { return list.size(); }
}