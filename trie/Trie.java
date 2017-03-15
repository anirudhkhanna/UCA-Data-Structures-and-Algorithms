package trie;

import java.util.LinkedList; // for generic queue implementation

public class Trie {
	
	public final int ALPHABET_SIZE = 26;
	TrieNode root;
	
	
	/* ****************** *
	 * CLASS FOR TRIENODE *
	 * ****************** */
	private class TrieNode {
		Integer     value = null; // indicates termination/completion of a key (word) with a not-null integer value
		TrieNode    children[] = new TrieNode[ALPHABET_SIZE]; // array of child node references of that node
	}
	
	
	/* ************************* *
	 * CONSTRUCTOR OF TRIE CLASS *
	 * ************************* */
	public Trie() {
		root = new TrieNode(); // root is not initially null in tries - it has an initialization. root's initial children[] will all be null.
	}
	
	
	/* ***************** *
	 * UTILITY FUNCTIONS *
	 * ***************** */
	
	/* INSERTION OF A KEY (WORD) AND VALUE */
	public void insert(String key, int value) {
		
		TrieNode p = root;
		
		for(int i = 0; i < key.length(); i++) {
			int index = key.charAt(i) - 'a'; // considering lowercase alphabets
			
			if(p.children[index] == null)
				p.children[index] = new TrieNode(); // create a node at that index if not already present
			
			p = p.children[index]; // move p further to its child at that index
		}
		
		p.value = value; // assign value at the end character
	}
	
	
	/* SEARCH A COMPLETE KEY (WORD) AND RETURN ITS VALUE */
	public Integer search(String key) {
		
		TrieNode p = root;
		
		for(int i = 0; i < key.length(); i++) {
			int index = key.charAt(i) - 'a';
			
			if(p.children[index] == null)
				return null; // not found
			
			p = p.children[index];
		}
		
		return p.value; // returns value at the last node of key, or null if given string was just a prefix and not a complete key
		
	/*	Or just this:
		TrieNode p = searchString(key);
		if(p == null) return null;
		else return p.value; // returns value at the last node of key, or null if given string was just a prefix and not a complete key
	*/
	}
	
	
	/* SEARCH A PREFIX AND RETURN TRUE OR FALSE BASED ON ITS PRESENCE */
	public boolean searchPrefix(String str) {
		return searchString(str) != null;
	}
	
	/* SEARCH A STRING/PREFIX FOR ITS PRESENCE AND RETURN ITS LAST NODE (OR NULL IF NOT FOUND) */
	private TrieNode searchString(String str) {
		
		TrieNode p = root;
		
		for(int i = 0; i < str.length(); i++) {
			int index = str.charAt(i) - 'a';
			
			if(p.children[index] == null)
				return null; // not found
			
			p = p.children[index];
		}
		
		return p;
	}
	
	
	/* SOFT DELETE A KEY (JUST REMOVE THE KEY'S VALUE AT THE END) */
	public void softDelete(String key) {
		softDelete(key, root, 0); // keyword, current node, current level
	}
	
	private void softDelete(String key, TrieNode n, int level) {
		// if current node is null
		if(n == null) return;
		
		// if end level node found
		if(level == key.length()) {
			n.value = null; // remove its value
			return;
		}
		
		// intermediate node found
		int index = key.charAt(level) - 'a';
		softDelete(key, n.children[index], level + 1); // call recursively for next level
	}
	
	
	/* HARD DELETE A KEY (REMOVE INDIVIDUAL NODES, STARTING FROM THE END, IF THEY DO NOT HAVE ANOTHER EXISTING CHILD) */
	public void hardDelete(String key) {
		hardDelete(key, root, 0); // keyword, current node, current level
	}
	
	private boolean hardDelete(String key, TrieNode n, int level) {
		// if current node is null
		if(n == null) return false;
		
		// if end level node found
		if(level == key.length()) {
			n.value = null; // remove its value
			return !hasChild(n); // return to the caller if it is delete-able (means if it has no further children)
		}
		
		// intermediate node found
		int index = key.charAt(level) - 'a';
		boolean canDel = hardDelete(key, n.children[index], level + 1); // check recursively if it's child is delete-able
		if(canDel == true) {
			n.children[index] = null; // remove its indexth child node if it is delete-able
			return !hasChild(n); // return canDel for itself (means if it has no further children)
		}
		
		return false;
	}
	
	private boolean hasChild(TrieNode n) {
		for(int i = 0; i < ALPHABET_SIZE; i++)
			if(n.children[i] != null)
				return true;
		
		return false;
	}
	
	
	/* DISPLAY ALL KEYS AND VALUES IN TRIE */
	public void displayAll() {
		String prefix = "";
		displayAll(root, prefix);
	}
	
	private void displayAll(TrieNode n, String prefix) {
		// show when a complete word is reached
		if(n.value != null)
			System.out.println(prefix + " (" + n.value + ")");
		
		for(int index = 0; index < ALPHABET_SIZE; index++) {
			if(n.children[index] != null) {
				char ch = (char)(index + 'a');
				
				prefix = prefix + ch; // add a character at the end
				displayAll(n.children[index], prefix); // call recursively
				if(prefix != null && prefix.length() != 0)
					prefix = prefix.substring(0, prefix.length() - 1); // remove a character from the end
			}
		}
	}
	
	
	/* ALL KEYS STARTING FROM GIVEN PREFIX (RETURN IN AN ARRAY OF STRINGS) */
	public String[] startingFrom(String str) {
		if(str == null) return null;
		
		String prefix = "";
		Queue<String> resQ = new Queue<String>();
		TrieNode n = searchString(str);
		startingFrom(n, prefix, resQ);
		
		String results[] = new String[resQ.size()];
		for(int i = 0; i < results.length; i++)
			results[i] = str + resQ.delete();
		
		return results;
	}
	
	private void startingFrom(TrieNode n, String prefix, Queue<String> resQ) {
		// add to results queue when a complete word is reached
		if(n.value != null)
			resQ.insert(prefix);
		
		for(int index = 0; index < ALPHABET_SIZE; index++) {
			if(n.children[index] != null) {
				char ch = (char)(index + 'a');
				
				prefix = prefix + ch; // add a character at the end
				startingFrom(n.children[index], prefix, resQ); // call recursively
				if(prefix != null && prefix.length() != 0)
					prefix = prefix.substring(0, prefix.length() - 1); // remove a character from the end
			}
		}
	}
	
} // Trie class closed


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