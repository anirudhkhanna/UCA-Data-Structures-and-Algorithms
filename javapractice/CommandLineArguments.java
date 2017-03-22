/* Command line arguments can pass additional information to a program at execution time via command line.
 * This can alter the program's behavior dynamically.
 * They are given just after the program's name on the command line interface of the operating system.
 * Note that unlike C, Java does not store the program file's name as a command line argument.
 */

package javapractice;

public class CommandLineArguments {

	public static void main(String[] args) {
		int sum = 0;
		if(args.length == 0) {
			System.out.println("No arguments provided.");
			return;
		}
		
		for(int i = 0; i < args.length; i++)
			sum += Integer.parseInt(args[i]);	// Convert the string args[i] to an integer
		
		System.out.println("Sum of provided numbers: " + sum);
	}
}

/* Run as:
 * 
 * java CommandLineArguments
 * No arguments provided.
 * 
 * java CommandLineArguments 15 3
 * Sum of provided numbers: 18
 * 
 * java CommandLineArguments "15" "3"
 * Sum of provided numbers: 18
 */
