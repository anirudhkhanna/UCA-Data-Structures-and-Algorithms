/* Sample implementation of integer wrapper to demonstrate equals(), Comparable, Comparator etc. */

package javapractice.integerimplementation.integerclient;

/* Even if integerclient is inside integerimplementation, it is considered as a separate package.
   There is no concept of sub-packages in Java, so pkg.proj and pkg.proj.test are completely separate packages!
*/

import javapractice.integerimplementation.Integer;
import javapractice.integerimplementation.IntegerComparator;

/* Integer client */
public class IntegerClient {

	public static void main(String[] args) {
		Integer i1 = new Integer(10);
		Integer i2 = new Integer(20);
		Integer i3 = new Integer(30);
		
		Integer i4 = new Integer(0);
		i4.setVal(i1.getVal() * i2.getVal());
		
		System.out.println("i1 = " + i1.getVal() + "\ni2 = " + i2.getVal() + "\ni3 = " + i3.getVal() + "\ni4 = " + i4.getVal() + "\n");
		
		System.out.println("i1.compareTo(i2): " + i1.compareTo(i2));
		IntegerComparator intCmp = new IntegerComparator();
		System.out.println("intCmp.compare(i3, i4): " + intCmp.compare(i3, i4));
	}
}
