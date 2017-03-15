package bst;

import bst.BinarySearchTree;

public class BSTClient {

	public static void main(String... args) {
		
		BinarySearchTree tree = new BinarySearchTree();
		
		tree.insert(7);
		tree.insert(1);
		tree.insert(0);
		tree.insert(3);
		tree.insert(2);
		tree.insert(5);
		tree.insert(4);
		tree.insert(6);
		tree.insert(9);
		tree.insert(8);
		tree.insert(10);
		
		tree.inOrderTraverse();
		tree.preOrderTraverse();
		tree.postOrderTraverse();
		
		System.out.print("\nIsBST: "+tree.isBST());
		System.out.print("\nSize: "+tree.size());
		System.out.print("\nMin: "+tree.min()+", Max: "+tree.max()+"\n");
		
		tree.deleteMin();
		tree.deleteMax();
		
		System.out.print("\n(After delete-min and delete-max: )");
		tree.inOrderTraverse();
		System.out.print("\nMin: "+tree.min()+", Max: "+tree.max());
		System.out.print("\nSize: "+tree.size());
		
		tree.clear();
		
		/*
		 *  Building new tree, now with parent references:
		 */
		tree.insertWithParent(7);//                        7
		tree.insertWithParent(1);//                       /  \
		tree.insertWithParent(0);//                      /    \
		tree.insertWithParent(3);//                     1      9
		tree.insertWithParent(2);//                    / \    / \
		tree.insertWithParent(5);//                   0   3  8  10
		tree.insertWithParent(4);//                      / \
		tree.insertWithParent(6);//                     2   5
		tree.insertWithParent(9);//                        / \
		tree.insertWithParent(8);//                       4   6
		tree.insertWithParent(10);//
		
		System.out.println("\n\n(Now the tree is cleared and built again, now with parent references stored too: )");
		tree.inOrderTraverseWithParent();
		tree.inOrderTraverse();
		System.out.print("\n(LevelOrder: )");
		tree.levelOrderTraverse();
		System.out.print("\n(TopView: )");
		tree.topView();
		System.out.print("\n(PrintLeaves: )");
		tree.printLeaves();
		System.out.print("\n(PrintLeftBoundary: )");
		tree.printLeftBoundary();
		System.out.print("\n(PrintRightBoundary: )");
		tree.printRightBoundary();
		System.out.print("\n(PrintBoundary [Circumference]: )");
		tree.printBoundary();
		System.out.println();
		System.out.print("\nIsBST: "+tree.isBST());
		System.out.print("\nHeight: "+tree.height());
		System.out.print("\nParent(5): "+tree.parent(5)+", Parent(8): "+tree.parent(8)+", Parent(7): "+tree.parent(7));
		System.out.print("\n(Without using parent references: )");
		System.out.print("\nParent2(5): "+tree.parent2(5)+", Parent2(8): "+tree.parent2(8)+", Parent2(7): "+tree.parent2(7)+", Parent2(100): "+tree.parent2(100));
		System.out.print("\nSizeL(3): "+tree.sizeLeft(3)+", SizeL(8): "+tree.sizeLeft(8)+", SizeL(7): "+tree.sizeLeft(7)+", SizeL(100): "+tree.sizeLeft(100));
		System.out.print("\nSizeR(3): "+tree.sizeRight(3)+", SizeR(8): "+tree.sizeRight(8)+", SizeR(7): "+tree.sizeRight(7)+", SizeR(100): "+tree.sizeRight(100));
		System.out.print("\nDepth(7): "+tree.depth(7)+", Depth(1): "+tree.depth(1)+", Depth(8): "+tree.depth(8)+", Depth(4): "+tree.depth(4)+", Depth(100): "+tree.depth(100));
		System.out.print("\nKthSmallest(1): "+tree.kthSmallestElement(1)+", KthSmallest(2): "+tree.kthSmallestElement(2)+", KthSmallest(6): "+tree.kthSmallestElement(6)+", KthSmallest(8): "+tree.kthSmallestElement(8)+", KthSmallest(9): "+tree.kthSmallestElement(9)+", KthSmallest(100): "+tree.kthSmallestElement(100));
		System.out.print("\n(Kth smallest element with iteration: )");
		System.out.print("\nKthSmallest(1): "+tree.kthSmallestElementIterative(1)+", KthSmallest(2): "+tree.kthSmallestElementIterative(2)+", KthSmallest(6): "+tree.kthSmallestElementIterative(6)+", KthSmallest(8): "+tree.kthSmallestElementIterative(8)+", KthSmallest(9): "+tree.kthSmallestElementIterative(9)+", KthSmallest(100): "+tree.kthSmallestElementIterative(100));
		System.out.print("\nLCA(1, 9): "+tree.lowestCommonAncestor(1, 9)+", LCA(3, 6): "+tree.lowestCommonAncestor(3, 6)+", LCA(3, 8): "+tree.lowestCommonAncestor(3, 8)+", LCA(0, 1): "+tree.lowestCommonAncestor(0, 1)+", LCA(0, 6): "+tree.lowestCommonAncestor(0, 6)+", LCA(2, 4): "+tree.lowestCommonAncestor(2, 4)+", LCA(-2, -100): "+tree.lowestCommonAncestor(-2, -100)+", LCA(2, 100): "+tree.lowestCommonAncestor(2, 100));
		System.out.print("\nRank(0): "+tree.rank(0)+", Rank(1): "+tree.rank(1)+", Rank(2): "+tree.rank(2)+", Rank(3): "+tree.rank(3)+", Rank(4): "+tree.rank(4)+", Rank(5): "+tree.rank(5)+", Rank(6): "+tree.rank(6)+", Rank(7): "+tree.rank(7)+", Rank(8): "+tree.rank(8)+", Rank(9): "+tree.rank(9)+", Rank(10): "+tree.rank(10)+", Rank(100): "+tree.rank(100));
		System.out.print("\n(Without using parent references: )");
		System.out.print("\nRank(0): "+tree.rank2(0)+", Rank(1): "+tree.rank2(1)+", Rank(2): "+tree.rank2(2)+", Rank(3): "+tree.rank2(3)+", Rank(4): "+tree.rank2(4)+", Rank(5): "+tree.rank2(5)+", Rank(6): "+tree.rank2(6)+", Rank(7): "+tree.rank2(7)+", Rank(8): "+tree.rank2(8)+", Rank(9): "+tree.rank2(9)+", Rank(10): "+tree.rank2(10)+", Rank(100): "+tree.rank2(100));
		
//		tree.inOrderTraverse();
//		System.out.print("\nSizeL(3): "+tree.sizeLeft(3)+", SizeL(8): "+tree.sizeLeft(8)+", SizeL(7): "+tree.sizeLeft(7)+", SizeL(100): "+tree.sizeLeft(100));
//		System.out.print("\nSizeR(3): "+tree.sizeRight(3)+", SizeR(8): "+tree.sizeRight(8)+", SizeR(7): "+tree.sizeRight(7)+", SizeR(100): "+tree.sizeRight(100));
//		tree.delete(8);
//		System.out.print("\n~ Modified");
//		tree.inOrderTraverse();
//		System.out.print("\nSizeL(9): "+tree.sizeLeft(9)+", SizeL(8): "+tree.sizeLeft(8)+", SizeL(7): "+tree.sizeLeft(7)+", SizeL(100): "+tree.sizeLeft(100));
//		System.out.print("\nSizeR(3): "+tree.sizeRight(3)+", SizeR(8): "+tree.sizeRight(8)+", SizeR(7): "+tree.sizeRight(7)+", SizeR(100): "+tree.sizeRight(100));
	}
}