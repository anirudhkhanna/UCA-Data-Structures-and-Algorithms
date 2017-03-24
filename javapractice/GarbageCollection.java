package javapractice;

import java.util.Arrays;

class Sample {

	int s[];
	
	/* Parameterized constructor */
	Sample(int n) {
		s = new int[n];
	}
	
	/* Default constructor */
	Sample() {
		this(0); // This is OK.
	//	s = new int[0]; // Or this too.
	//	this(20); <-- Not OK. Calling another constructor of the class is fine. But this must be at the very first line only. Constructor call must be the first statement in a constructor.
	}
	
	/* Overriding the toString() method from Object class. Called for displaying an object. */
	@Override
	public String toString() {
		return Arrays.toString(s);
	}
	
	/* Overriding the finalize() method from Object class. Called by Garbage Collector before deallocating an object.
	 * Can be used for cleanup and releasing any external resources like files.
	 * But note that the finalize() method might end up never being called, as Garbage Collection is not instantaneous. For eg:
	 * The object is not garbage collected because it is still reachable.
	 * The object is not garbage collected because the GC doesn't run before your test finishes.
	 * The object is found by the GC and placed in the finalization queue, but it doesn't complete before your test finishes.
	 */
	@Override
	protected void finalize() throws Throwable {
	//	super.finalize();
		System.out.println("Cleaning up...");
		s = null;
	}
}

public class GarbageCollection {

	public static void main(String[] args) {
		Sample sample = new Sample();
		System.out.println("sample = " + sample);
		
		sample = null; // Unreferencing the object.
		System.out.println("sample = " + sample);
		
		System.out.println("Call System.gc()");
		System.gc(); // Explicitly reminding GC to deallocate any unreferenced objects.
	//	System.runFinalization(); // Run the finalization methods of any objects having pending finalizations.
	}
}