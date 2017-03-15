/* Given a large text file, find and display the word which occurs the maximum times and also its number of occurrences */

package bst;

import java.io.File;
import java.io.IOException;
import java.util.*;

public class BSTWordSearch {
	
	private class Node {
		String  key;		// key (string having a word)
		int     value;		// value of the key (no of occurrences)
		Node    left;		// left child node
		Node    right;		// right child node

		public Node(String key) {
			this.key = key;
			this.value++;
			this.left = this.right = null;
		}
	} // Node class closed

	private Node root = null;
	
	
	/* INSERTION */
	public void insert(String key) {
		root = insert(root, key);
	}
	private Node insert(Node n, String key) {
		if(n == null)	return new Node(key);

		if(key.equals(n.key))	n.value++; // duplicate found
		else if(key.compareTo(n.key) < 0)	n.left = insert(n.left, key);
		else	n.right = insert(n.right, key);

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
		System.out.print(n.key+" ("+n.value+")  ");
		inOrderTraverse(n.right);
	}
	
	/* MAX OCCURENCE (Key having the maximum value) */
	Node max = root;
	public void maxOccurence() {
		if(root == null) return;
		
		max = root;
		maxOccurence(root);
		printMaxOccurence(root);
	}
	private void maxOccurence(Node n) {
		if(n == null) return;

		maxOccurence(n.left);
		if(n.value > max.value)		max = n;
		maxOccurence(n.right);
	}
	private void printMaxOccurence(Node n) {
		if(n == null)
			return;

		printMaxOccurence(n.left);
		if(n.value == max.value)	System.out.println(n.key + " (" + n.value + ")");
		printMaxOccurence(n.right);
	}
	
	/* CLEAR THE TREE */
	public void clear() {
		root = null;
	}
	
	
	/* MAIN FUNCTION */
	public static void main(String[] args) {
		BSTWordSearch tree = new BSTWordSearch();
		
		System.out.println("Running...");
		try {
			File file = new File("bigTale.txt");
			Scanner cin = new Scanner(file);
			String str;
			while(cin.hasNext()) {
				str = cin.next();
				if(str.length() >= 10)
					tree.insert(str);
			}
		}
		catch (IOException e) {
			e.printStackTrace();
		}
		
	//	tree.inOrderTraverse();
		System.out.println("\nMAX OCCURRENCE: ");
		tree.maxOccurence();
	}
}
