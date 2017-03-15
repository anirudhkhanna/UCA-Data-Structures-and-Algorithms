package bst;

public class BSTBottomView {

	private class Node {
		int     key;        // key
		int     width;      // width of the key (horizontal displacement wrt. root, in - if left of root, in + if right of root)
		int     level;      // level (depth)
		Node    left;       // left child node
		Node    right;      // right child node
		Node    parent;     // parent node

		public Node(int key) {
			this.key = key;
		}
	} // Node class closed

	Node root = null;
	int maxWidth = 0, minWidth = 0;
	Node bottomNode;


	/* INSERTION, WITH PARENT ALSO STORED */
	void insert(int key) {
		root = insertWithParent(root, null, key);
	}
	
	private Node insertWithParent(Node n, Node parent, int key) {
		if(n == null) {
			Node newNode = new Node(key);
			newNode.parent = parent;
			return newNode;
		}
		else if(key < n.key)	n.left = insertWithParent(n.left, n, key);
		else	n.right = insertWithParent(n.right, n, key);
		return n;
	}


	/* INORDER (JUST FOR CHECKING THINGS) */
	void inOrderTraverse(Node n) {
		if(n == null) return;
		inOrderTraverse(n.left);
		System.out.print(n.key+" ");
		inOrderTraverse(n.right);
	}

	
	/* SET RELATIVE WIDTH (HORIZONTAL POSITION) OF EVERY ELEMENT
	 * Root : 0
	 * Left children of root: -1 for each unit left
	 * Right children of root: +1 for each unit right
	 */
	public void setWidth(Node n) {
		if(n == null)	return;
		setWidth(n.left);
		n.width = widthOfElem(n);
		setWidth(n.right);
	}

	int widthOfElem(Node n) {
		if(n.parent == null)	return 0;
		
		if(n.parent.right != null && n.key == n.parent.right.key) // it is a right child
			return 1 + widthOfElem(n.parent);
		
		else // it is a left child
			return -1 + widthOfElem(n.parent);
	}


	/* SET MAX AND MIN WIDTH (in instance variables maxWidth and minWidth) */
	public void setMaxAndMinWidth(Node n) {
		if(n == null)	return;

		setMaxAndMinWidth(n.left);
		if(n.width > maxWidth) maxWidth = n.width;
		if(n.width < minWidth) minWidth = n.width;
		setMaxAndMinWidth(n.right);
	}

	
	/* SET LEVEL (VERTICAL DEPTH) OF EVERY ELEMENT WRT. ROOT */
	public void setLevel(Node n) {
		if(n == null)	return;
		setLevel(n.left);
		n.level = level(n);
		setLevel(n.right);
	}

	private int level(Node n) {
		if(n.parent == null)	return 0;
		else	return 1 + level(n.parent);
	}
	
	
	/* GET ELEMENT OF GIVEN WIDTH THAT HAS LOWERMOST LEVEL (FOR BOTTOM VIEW) */
	public void bottomLevel(int width) {
		bottomNode = new Node(0);
		bottomNode.width = width;
		bottomNode.level = Integer.MIN_VALUE;
		bottomLevel(root, width);
	}

	public void bottomLevel(Node n, int width) {
		if(n == null)	return;

		bottomLevel(n.left, width);
		if(n.width == width && n.level > bottomNode.level)
			bottomNode = n;
		bottomLevel(n.right, width);
	}

	
	/* MAIN FUNCTION */
	public static void main(String args[]) {
		
//            __12__
//           /      \
//          10       15
//         / \      / \
//        5   11   13  20
//         \
//          9
//         /
//        8
//       /
//      7
		
		// First Tricky Tree
		BSTBottomView tree = new BSTBottomView();

		tree.insert(12);	tree.insert(10);
		tree.insert(5);		tree.insert(9);
		tree.insert(8);		tree.insert(7);
		tree.insert(11);	tree.insert(15);
		tree.insert(13);	tree.insert(20);
		
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
		BSTBottomView tree2 = new BSTBottomView();

		tree2.insert(7);	tree2.insert(2);
		tree2.insert(4);	tree2.insert(5);
		tree2.insert(6);	tree2.insert(8);
		
		// Some pre-solution adjustments for setting the width and level of each element:
		tree.setWidth(tree.root);
		tree.setLevel(tree.root);
		tree.setMaxAndMinWidth(tree.root);
		
		tree2.setWidth(tree2.root);
		tree2.setLevel(tree2.root);
		tree2.setMaxAndMinWidth(tree2.root);
		
		// Show solution for both the trees:
		System.out.println("\n\nTREE 1 BOTTOM VIEW: ");
		for(int i = tree.minWidth; i<= tree.maxWidth; i++) {
			tree.bottomLevel(i);
			System.out.print(tree.bottomNode.key + " ");
		}
		
		System.out.println("\n\nTREE 2 BOTTOM VIEW: ");
		for(int i = tree2.minWidth; i<= tree2.maxWidth; i++) {
			tree2.bottomLevel(i);
			System.out.print(tree2.bottomNode.key + " ");
		}
	}
}
