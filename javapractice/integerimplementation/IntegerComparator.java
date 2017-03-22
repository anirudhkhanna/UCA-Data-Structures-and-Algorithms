/* Sample implementation of integer wrapper to demonstrate equals(), Comparable, Comparator etc. */

package javapractice.integerimplementation;

import java.util.Comparator;

/* Separate IntegerComparator class implementing Comparator */
public class IntegerComparator implements Comparator<Integer> {

	@Override
	public int compare(Integer obj1, Integer obj2) {
		if(obj1.getVal() > obj2.getVal())
			return 1;
		if(obj1.getVal() < obj2.getVal())
			return -1;
		return 0;
	}
}