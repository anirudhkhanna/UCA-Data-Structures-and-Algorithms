package javapractice;

class Dummy implements Runnable {

	String threadName;
	
	public Dummy(String name) {
		threadName = name;
	}
	
	/* Implement the inherited method run() from Runnable */
	public void run() {
		System.out.println("Running " + threadName);
		try {
			Thread.sleep(1000);
		} catch(InterruptedException e) {
			e.printStackTrace();
		}
		System.out.println("Finished " + threadName);
	}
}

public class ThreadExample {
	public static void main(String[] args) {
		Dummy dObj = new Dummy("Dummy Thread");
		
		Thread t = new Thread(dObj, "My DT");	// allocate a Thread object by passing a Runnable object and a thread name
		t.start();	// start() the Thread object, which basically calls its run() method after creating a new thread of execution

		Dummy d1 = new Dummy("Thread 1");
		Dummy d2 = new Dummy("Thread 2");
		Thread t1 = new Thread(d1, "My DT");
		Thread t2 = new Thread(d2, "My DT");
		
		t1.start();

		/* For t2 to start only after t1 */
		try{
			t1.join();	// join t1
		} catch(Exception e) {
			e.printStackTrace();
		}

		System.out.println("(Thread 1 must be finished by now.)");
		t2.start();
	}
}
