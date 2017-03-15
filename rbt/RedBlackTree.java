package rbt;

import java.util.LinkedList; // for generic queue implementation

public class RedBlackTree {
	
	private static final boolean RED = true;
	private static final boolean BLACK = false;
	
	private class Node {
		int     key;		// key
	//	int     value;		// value of the key (optional to use)
		boolean color;		// color of the parent edge. true implies RED and false implies BLACK
		Node    left;		// left child node
		Node    right;		// right child node
		
		public Node(int key, boolean color) {	// node constructor
			this.key = key;
			this.color = color;
			this.left = this.right = null;
		}
	} // Node class closed
	
	private Node root = null;
	
	
	/* INSERTION */
	public void insert(int key) {
		root = insert(root, key, RED);
	}
	
	private Node insert(Node n, int key, boolean color) {
		if(n == null)
			return new Node(key, color);
		
		if(n.key == key)
			; // duplicate found
		else if(key < n.key)
			n.left = insert(n.left, key, color);
		else
			n.right = insert(n.right, key, color);
		
		// balancing the tree after node is inserted (cases according to left-leaning Red Black Tree)
		if(isRed(n.right) && !isRed(n.left)) // if a red link is on the right side but not on the left side, we rotate it to the left
			n = rotateLeft(n);
		if(isRed(n.left) && isRed(n.left.left)) // if 2 consecutive red links (i.e. 3 nodes) are there on the left side so that it is conceptually a 4-node (a 4-branched node with 3 values), we rotate it to the right to pop-up the middle node
			n = rotateRight(n);
		if(isRed(n.left) && isRed(n.right)) // if both left and right child links are red (the element was popped-up from a 4-node), we flip the link colors (child links to black and parent link to red)
			flipColors(n);
		
		return n;
	}
	
	/* CHECK IF COLOR OF THE LINK OF A NODE IS RED (The link to its parent) */
	private boolean isRed(Node n) {
		if(n == null) return false;
		return n.color == RED;
	}
	
	/* ROTATE TO LEFT */
	private Node rotateLeft(Node n) {
		Node t = n.right;
		n.right = t.left;
		t.left = n;
		
		t.color = n.color;
		n.color = RED;
		
		return t;
	}
	
	/* ROTATE TO RIGHT */
	private Node rotateRight(Node n) {
		Node t = n.left;
		n.left = t.right;
		t.right = n;
		
		t.color = n.color;
		n.color = RED;
		
		return t;
	}
	
	/* FLIP COLORS OF EDGES ASSOCIATED WITH A NODE (Two RED child links to BLACK and BLACK parent link (if any) to RED) */
	private void flipColors(Node n) {
		n.left.color = n.right.color = BLACK;
		n.color = RED;
	}
	
	
	/* IN ORDER TRAVERSAL */
	public void inOrderTraverse() {
		System.out.println();
		inOrderTraverse(root);
	}
	
	private void inOrderTraverse(Node n) {
		if(n == null) return;
		
		inOrderTraverse(n.left);
		System.out.print(n.key + " ");
		inOrderTraverse(n.right);
	}
	
	
	/* PRE ORDER TRAVERSAL */
	public void preOrderTraverse() {
		System.out.println();
		preOrderTraverse(root);
	}
	
	private void preOrderTraverse(Node n) {
		System.out.print(n.key + " ");
		if (n.left != null)  preOrderTraverse(n.left);
		if (n.right != null) preOrderTraverse(n.right);
	}
	
	
	/* POST ORDER TRAVERSAL */
	public void postOrderTraverse() {
		System.out.println();
		postOrderTraverse(root);
	}
	
	private void postOrderTraverse(Node n) {
		if(n == null) return;
		
		postOrderTraverse(n.left);
		postOrderTraverse(n.right);
		System.out.print(n.key + " ");
	}
	
	
	/* LEVEL ORDER TRAVERSAL */
	public void levelOrderTraverse() {
		System.out.println();
		levelOrderTraverse(root);
	}
	
	private void levelOrderTraverse(Node root) {
		if(root == null) return;
		
		Queue<Node> q = new Queue<Node>();
		
		q.insert(root);
		while(q.hasItems()) {
			Node n = q.delete();
			System.out.print(n.key + " ");
			
			if(n.left != null)  q.insert(n.left);
			if(n.right != null) q.insert(n.right);
		}
	}
	
	
	/* HEIGHT OF TREE (Aka. max depth in a tree, i.e. the depth of the deepest leaf node) */
	public int height() {
		return height(root);
	}
	
	private int height(Node n) {
		if(n == null)
			return -1;
		else
			return 1 + Math.max(height(n.left), height(n.right));
	}
	
	
	/* FIND MIN */
	public int min() {
		if(root == null) return Integer.MIN_VALUE;
		return min(root);
	}
	
	private int min(Node n) {
		if(n.left == null)
			return n.key;
		else
			return min(n.left);
	}
	
	
	/* FIND MAX */
	public int max() {
		if(root == null) return Integer.MAX_VALUE;
		return max(root);
	}
	
	private int max(Node n) {
		if(n.right == null)
			return n.key;
		else
			return max(n.right);
	}
	
	
	/* SIZE OF TREE (No. of elements) */
	public int size() {
		if(root == null) return Integer.MIN_VALUE;
		return size(root);
	}
	
	private int size(Node n) {
		if(n == null)
			return 0;
		
		return size(n.left) + 1 + size(n.right);
	}
	
	
	/* CLEAR THE TREE */
	public void clear() {
		root = null;
	}
}


/* GENERIC QUEUE IMPLEMENTATION WITH LINKED LIST */
class Queue<T> {
	private LinkedList<T> list = new LinkedList<T>();
	
	public void insert(T item) {
		list.addLast(item);
	}
	public T delete() {
		return list.poll();
	}
	public boolean hasItems() {
		return !list.isEmpty();
	}
	public int size() {
		return list.size();
	}
}