package rbt;

import rbt.RedBlackTree;

public class RBTClient {
	public static void main(String... args) {
		
		RedBlackTree tree = new RedBlackTree();
		
		tree.insert(0);
		tree.insert(1);
		tree.insert(2);
		tree.insert(3);
		tree.insert(4);
		tree.insert(5);
		tree.insert(6);
		tree.insert(7);
		
		tree.inOrderTraverse();
		tree.preOrderTraverse();
		tree.postOrderTraverse();
		
		System.out.println();
		System.out.print("\nHeight: " + tree.height());
		System.out.print("\nSize: " + tree.size());
		System.out.print("\nMin: " + tree.min() + ", Max: " + tree.max());
		System.out.print("\nLevelOrder: ");
		tree.levelOrderTraverse();
	}
}
