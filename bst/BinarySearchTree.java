package bst;

//import queue.Queue;
import java.util.LinkedList; // for generic queue implementation

public class BinarySearchTree {
	
	private class Node {
		int     key;		// key
//		int     value;		// value corresponding to the key (optional)
		Node    left;		// left child node
		Node    right;		// right child node
		Node    parent;		// parent node
		int     leftsize;	// number of elements in its left sub-tree
		int     rightsize;	// number of elements in its right sub-tree
		
		public Node(int key) {
			this.key = key;
			this.left = this.right = null;
			this.parent = null;
			this.leftsize = 0;
			this.rightsize = 0;
		}
	} // Node class closed
	
	private Node root = null;
	
	
	/* GET NODE HAVING THE GIVEN KEY */
	private Node getNode(Node n, int key) {
		if(n == null)
			return null;
		
		if(n.key == key)
			return n;
		else if(key < n.key)
			return getNode(n.left, key);
		else
			return getNode(n.right, key);
	}
	
	
	/* INSERTION */
	public void insert(int key) {
		root = insert(root, key);
	}
	private Node insert(Node n, int key) {
		if(n == null)
			return new Node(key);

		if(n.key == key)
			; // duplicate found.
		else if(key < n.key) {
			n.leftsize++;
			n.left = insert(n.left, key);
		}
		else {
			n.rightsize++;
			n.right = insert(n.right, key);
		}

		return n;
	}
	
	/* INSERTION WITH PARENT */
	public void insertWithParent(int key) {
			root = insertWithParent(root, null, key);
	}
	private Node insertWithParent(Node n, Node parent, int key) {
		if(n == null) {
			Node newNode = new Node(key);
			newNode.parent = parent;
			return newNode;
		}
		if(n.key == key)
			; // duplicate found.
		else if(key < n.key) {
			n.leftsize++;
			n.left = insertWithParent(n.left, n, key);
		}
		else {
			n.rightsize++;
			n.right = insertWithParent(n.right, n, key);
		}

		return n;
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
	
	/* IN ORDER TRAVERSAL WITH PARENT DISPLAYED */
	public void inOrderTraverseWithParent() {
		System.out.println();
		inOrderTraverseWithParent(root);
	}
	private void inOrderTraverseWithParent(Node n) {
		if(n == null) return;

		inOrderTraverseWithParent(n.left);
		if(n.parent != null) System.out.print(n.key + " (P: " + n.parent.key + ")   ");
		else                 System.out.print(n.key + "(P: null)   ");
		inOrderTraverseWithParent(n.right);
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

	
	/* PRINT LEAVES */
	public void printLeaves() {
		System.out.println();
		printLeaves(root);
	}
	private void printLeaves(Node n) {
		if(n == null) return;
		
		printLeaves(n.left);
		if(n.left == null && n.right == null) {
			System.out.print(n.key + " ");
		}
		printLeaves(n.right);
	}

	
	/* PRINT LEFT BOUNDARY (Top-down, except leaf nodes) */
	public void printLeftBoundary() {
		System.out.println();
		printLeftBoundary(root);
	}
	private void printLeftBoundary(Node n) {
		if(n == null) return;
		
		if (n.left != null) {
			System.out.print(n.key + " "); // to ensure top-down order, print this node before calling for the left sub-tree
			printLeftBoundary(n.left);
		}
		else if(n.right != null) { // n.left was null, so check its right child as boundary element
			System.out.print(n.key + " ");
			printLeftBoundary(n.right);
		}
		// do nothing if it is a leaf node, this way we can omit leaf node from the boundary
	}

	
	/* PRINT RIGHT BOUNDARY (Bottom-up, except leaf nodes) */
	public void printRightBoundary() {
		System.out.println();
		printRightBoundary(root);
	}
	private void printRightBoundary(Node n) {
		if(n == null) return;
		
		if (n.right != null) {
			printRightBoundary(n.right); // to ensure bottom-up order, call for the right sub-tree before printing this node
			System.out.print(n.key + " ");
		}
		else if(n.left != null) { // n.right was null, so check its left child as boundary element
			printRightBoundary(n.left);
			System.out.print(n.key + " ");
		}
		// do nothing if it is a leaf node, this way we can omit leaf node from the boundary
	}


	/* PRINT BOUNDARY (Circumference, anti-clockwise starting from root) */
	public void printBoundary() {
		System.out.println();
		printBoundary(root);
	}
	private void printBoundary(Node n) {
		if(n == null) return;
		
		System.out.print(n.key + " "); // the root element

		printLeftBoundary(n.left); // the left boundary (of the left of root) in top-down order
		
		printLeaves(n.left); // the leaf nodes of the left of root
		printLeaves(n.right); // the leaf nodes of the right of root
		
		printRightBoundary(n.right); // the right boundary (of the right of root) in bottom-up order
	}

	
	/* DEPTH OF A NODE (No. of edges from the node to the tree's root) */
	public int depth(int key) {
		Node n = getNode(root, key);
		if(n != null)
			return depth(n);
		else
			return Integer.MIN_VALUE; // node not found
	}
	private int depth(Node n) {
		if(n.parent == null)
			return 0;
		else
			return 1 + depth(n.parent);
	}

	
	/* HEIGHT OF TREE (Aka. max depth in a tree, i.e. the depth of the deepest leaf node) */
	public int height() {
		return height(root);
	}
	private int height(Node n) {
		if(n == null)
			return -1;
		else {
			int leftHeight = height(n.left); // get height of left sub-tree
			int rightHeight = height(n.right); // get height of right sub-tree

			if(leftHeight > rightHeight) // return 1 + whichever sub-tree's height is greater
				return 1 + leftHeight;
			else
				return 1 + rightHeight;
		}
	}

	
	/* TOP VIEW */
	public void topView() {
		System.out.println();
		topViewLeft(root);
		if(root != null)
			topViewRight(root.right);
	}
	private void topViewLeft(Node n) {
		if(n == null) return;

		topViewLeft(n.left);
		System.out.print(n.key + " ");
	}
	private void topViewRight(Node n) {
		if(n == null) return;

		System.out.print(n.key + " ");
		topViewRight(n.right);
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
	

	/* DELETE MIN */
	public void deleteMin() {
		if(root == null) return;
		root = deleteMin(root);
	}
	private Node deleteMin(Node n) {
		if(n.left == null)
			return n.right;
		else {
			n.leftsize--;
			n.left = deleteMin(n.left);
		}

		return n;
	}


	/* DELETE MAX */
	public void deleteMax() {
		if(root == null) return;
		root = deleteMax(root);
	}
	private Node deleteMax(Node n) {
		if(n.right == null)
			return n.left;
		else {
			n.rightsize--;
			n.right = deleteMax(n.right);
		}
		
		return n;
	}

	
	/* DELETE GIVEN NODE */
	public void delete(int key) {
		root = delete(root, key);
	}
	private Node delete(Node n, int key) {
		if(n == null)
			return null;

		/* If this current node has the key (i.e. node n is to be deleted) */
		if(n.key == key) {
			if(n.left == null) return n.right; // if n has no left child, just replace it with its right child tree/null
			else
			if(n.right == null) return n.left; // if n has no right child, just replace it with its left child tree/null
			
			/*
			 * Node n has both children, left as well as right
			 * 
			 * Find the minimum element in its right sub-tree.
			 * Now the minimum element will never have a left child but may have a right child sub-tree.
			 * Move its right child to its parent's left link (where minimum was originally connected) and remove minimum
			 * Also, minimum's right link shall attach to the actual right side of node n to be deleted
			 * 
			 * Finally, place the minimum element (with its modified child tree structure) in place of n
			 * And make it's left link to the left child of n
			 */
			Node temp = n; // copy actual n in temp
			n = getMinNode(n.right); // now n has min node from the right sub-tree of n
			n.right = deleteMin(temp.right); // delete minimum node in right sub-tree and place its right child (if any) as its (min's) parent's left link instead.
											 // also, return the modified structure of the right sub-tree to left link of min node (stored in n).
			n.left = temp.left; // make the left link of the prepared n to left child of temp (actual node n)
			return n; // return the modified node structure replacing original n
		}
		/* Otherwise search the nodes for the key */
		else if(key < n.key) n.left = delete(n.left, key); // key is in the left sub-tree
		else				 n.right = delete(n.right, key); // key is in the right sub-tree
		
		return n;
	}
	private Node getMinNode(Node n) {
		if(n.left == null)
			return n;
		else
			return getMinNode(n.left);
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

	
	/* PARENT OF A NODE (When parent references were stored) */
	public int parent(int key) {
		if(root.key == key)
			return Integer.MIN_VALUE; // parent of root will be null
		else
			return getNode(root, key).parent.key; // find that node and return its parent's key
	}
	
	/* PARENT OF A NODE WITHOUT USING PARENT REFERENCES (When parent references were not stored) */
	public int parent2(int key) {
		return parent2(root, key); // find that node's parent's key
	}
	private int parent2(Node n, int key) {
		if(n == null)
			return Integer.MIN_VALUE;
		
		boolean foundLeft = false;
		boolean foundRight = false;
		if(n.left != null)
			foundLeft = (n.left.key == key) ? true : false;
		if(n.right != null)
			foundRight = (n.right.key == key) ? true : false;

		if(foundLeft || foundRight)
			return n.key;
		else if(key < n.key)
			return parent2(n.left, key);
		else
			return parent2(n.right, key);
	}

	
	/* SIZE OF LEFT SUB-TREE */
	public int sizeLeft(int key) {
		Node n = getNode(root, key);
		if(n != null)
			return n.leftsize;
		else
			return Integer.MIN_VALUE; // node not found
	}

	
	/* SIZE OF RIGHT SUB-TREE */
	public int sizeRight(int key) {
		Node n = getNode(root, key);
		if(n != null)
			return n.rightsize;
		else
			return Integer.MIN_VALUE; // node not found
	}


	/* KTH SMALLEST ELEMENT */
	public int kthSmallestElement(int k) {
		return kthSmallestElement(root, k);
	}
	private int kthSmallestElement(Node n, int k) {
		if(n == null)
			return Integer.MIN_VALUE;

		if(n.leftsize + 1 == k)
			return n.key;
		else if(k > n.leftsize)
			return kthSmallestElement(n.right, k - (n.leftsize + 1));
		else
			return kthSmallestElement(n.left, k);
	}

	/* KTH SMALLEST ELEMENT ITERATIVE */
	public int kthSmallestElementIterative(int k) {
		return kthSmallestElementIterative(root, k);
	}
	private int kthSmallestElementIterative(Node n, int k) {
		int res = Integer.MIN_VALUE;
		
		if(root == null)
			return res;

		/* A crawling pointer */
		Node pTraverse = root;
		
		/* Go to kth smallest element node */
		while(pTraverse != null) {
			if(pTraverse.leftsize + 1 == k) {
				res = pTraverse.key;
				break;
			}
			else if(k > pTraverse.leftsize) {
				/* There are lesser no. of nodes on the left sub-tree. The kth position element will be in the right sub-tree. */
				k = k - (pTraverse.leftsize + 1);
				pTraverse = pTraverse.right;
			}
			else {
				/* There are greater no. of nodes on the left sub-tree. The kth position element will be in the left sub-tree somewhere. */
				pTraverse = pTraverse.left;
			}
		} // while loop closed
		
		return res;
	}

	
	/* LOWEST COMMON ANCESTOR (LCA) OF TWO NODES (The first common ancestor) */
	public int lowestCommonAncestor(int val1, int val2) {
		if(getNode(root, val1) == null || getNode(root, val2) == null)
			return Integer.MIN_VALUE;

		return lowestCommonAncestor(root, val1, val2);
	}
	private int lowestCommonAncestor(Node n, int val1, int val2) {
		if(n == null)
			return Integer.MIN_VALUE;

		if(val1 < n.key && val2 < n.key)
			return lowestCommonAncestor(n.left, val1, val2);
		else if(val1 > n.key && val2 > n.key)
			return lowestCommonAncestor(n.right, val1, val2);
		else
			return n.key;
	}

	
	/* RANK OF A NODE (Number of elements smaller than itself. When parent references and sub-tree sizes are stored.) */
	public int rank(int key) {
		Node n = getNode(root, key);
		if(n != null)
			return n.leftsize + otherSmallerNodes(n.parent, n); // size of left sub-tree + other smaller nodes if any
		else
			return Integer.MIN_VALUE; // node not found
	}
	private int otherSmallerNodes(Node parentOfn, Node n) {
		if(parentOfn == null) // reach up towards the root, with help of parent references
			return 0;
		
		if(parentOfn.right.key == n.key) // if you reach to a parent from its right sub-tree, add its left sub-tree's size + 1 (itself), because those must be smaller nodes.
			return 1 + parentOfn.leftsize + otherSmallerNodes(parentOfn.parent, parentOfn);
		else
			return otherSmallerNodes(parentOfn.parent, parentOfn); // otherwise just keep moving up
	}

	/* RANK OF A NODE WITHOUT USING PARENT REFERENCES AND STORED SUB-TREE SIZES (When parent references and sub-tree sizes were not stored) */
	public int rank2(int key) {
		if(getNode(root, key) == null)
			return Integer.MIN_VALUE; // node not found
		else
			return rank2(root, key);
	}
	private int rank2(Node n, int key) {
		if(n.key == key) // if key found, then return size of its left sub-tree, because all left elements must be smaller
			return size(n.left);

		if(key > n.key) // if key is greater, find it in the right sub-tree recursively. Also, all the left elements + 1 (the current element) must be smaller than it.
			return 1 + size(n.left) + rank2(n.right, key);
		else
			return rank2(n.left, key); // if key is smaller, find it in the left sub-tree recursively.
	}

	
	/* CHECK IF TREE IS BST */
	public boolean isBST() {
		return isBST(root, Integer.MIN_VALUE, Integer.MAX_VALUE);
	}
	private boolean isBST(Node n, int low, int high) {
		if(n == null)
			return true;
		
		if(n.key <= low || n.key >= high)
			return false;
		else
			return isBST(n.left, low, n.key) && isBST(n.right, n.key, high);
	}

	
	/* CLEAR THE TREE */
	public void clear() {
		root = null; // Java's automatic Garbage Collector will take care of the rest
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