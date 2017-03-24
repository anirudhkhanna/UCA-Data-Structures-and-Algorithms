package javapractice;

import java.util.Iterator;
import java.util.Scanner;
import java.util.ArrayList;

// Book class
class Book {
	private int id;
	private String name, author;
	
	public Book() {
		this(0, "", ""); // Call to another constructor. Must be the very first statement.
	}
	
	public Book(int id, String name, String author) {
		this.id = id;
		this.name = name;
		this.author = author;
	}
	
	@Override
	public String toString() {
		String bookDetails = new String();
		bookDetails += "id = " + this.id;
		bookDetails += "\nname = " + this.name;
		bookDetails += "\nauthor = " + this.author;
		
		return bookDetails;
	}
}

// Books Catalogue class
public class BooksCatalogue {
	private ArrayList<Book> books;
	
	public BooksCatalogue() {
		books = new ArrayList<Book>();
	}
	
	public void addBook() {
		Scanner cin = new Scanner(System.in);
		
		System.out.println("Enter book id: ");
		int id = cin.nextInt();
		cin.nextLine();
		System.out.println("Enter book name: ");
		String name = cin.nextLine();
		System.out.println("Enter book author: ");
		String author = cin.nextLine();
		
		Book book = new Book(id, name, author);
		books.add(book);
	}
	
	@Override
	public String toString() {
		String catalogueDetails = new String();
		
		// Iterate the list of books.
		Iterator<Book> iter = books.iterator();
		while(iter.hasNext()) {
			Book book = iter.next();
			catalogueDetails += (book + "\n\n");
		}
		
		return catalogueDetails;
	}
	
	// Driver function for demo.
	public static void main(String[] args) {
		BooksCatalogue catalogue = new BooksCatalogue();
		
		System.out.println("Add new books: ");
		catalogue.addBook();
		catalogue.addBook();
		System.out.println("\nCatalogue: ");
		System.out.println(catalogue);
	}
}