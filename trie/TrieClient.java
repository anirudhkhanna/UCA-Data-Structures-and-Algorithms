package trie;

import trie.Trie;

public class TrieClient {
	
	public static void main(String args[]) {
		
		Trie trie = new Trie();
		
		trie.insert("anirudh", 75);
		trie.insert("aneesh", 71);
		trie.insert("akshay", 50);
		trie.insert("akshita", 59);
		trie.insert("aksh", 42);
		
		System.out.println("\nsearch(key)");
		System.out.println("-----------");
		System.out.println("anirudh: " + trie.search("anirudh"));
		System.out.println("aneesh: "  + trie.search("aneesh"));
		System.out.println("an: "      + trie.search("an"));
		System.out.println("xxxxxx: "  + trie.search("xxxxxx"));
		
		System.out.println("\nsearchPrefix(str)");
		System.out.println("-----------------");
		System.out.println("anirudh: " + trie.searchPrefix("anirudh"));
		System.out.println("aneesh: "  + trie.searchPrefix("aneesh"));
		System.out.println("an: "      + trie.searchPrefix("an"));
		System.out.println("xxxxxx: "  + trie.searchPrefix("xxxxxx"));
		
		System.out.println("\nsoftDelete(\"akshita\")");
		System.out.println("---------------------");
		trie.softDelete("akshita");
		System.out.println("search(akshita): " + trie.search("akshita") + ", searchPrefix(akshita): " + trie.searchPrefix("akshita") + " <-- Still shows as prefix, because it is not actually removed!");
		
		System.out.println("\nhardDelete(\"aneesh\")");
		System.out.println("--------------------");
		trie.hardDelete("aneesh");
		System.out.println("search(aneesh): " + trie.search("aneesh") + ", searchPrefix(aneesh): " + trie.searchPrefix("aneesh") + ", searchPrefix(ane): " + trie.searchPrefix("ane") + ", searchPrefix(an): " + trie.searchPrefix("an"));
		
		System.out.println("\ndisplayAll()");
		System.out.println("------------");
		trie.displayAll();
		
		System.out.println("\nstartingFrom(\"ak\")");
		System.out.println("------------------");
		String keys[] = trie.startingFrom("ak");
		if(keys != null)
			for(int i = 0; i < keys.length; i++)
				System.out.println(keys[i]);
	}
}
