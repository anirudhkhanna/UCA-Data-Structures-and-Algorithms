/* Sample implementation of integer wrapper to demonstrate equals(), Comparable, Comparator etc. */

package javapractice.integerimplementation;

import java.lang.Comparable; // Not mandatory, as java.lang package is imported by default

/* Integer class implementing Comparable */
public class Integer implements Comparable<Integer> {

	private int val;
	
	public Integer() {
		val = 0;
	}
	
	public Integer(int val) {
		this.val = val;
	}
	
	public int getVal() {
		return val;
	}
	
	public void setVal(int val) {
		this.val = val;
	}
	
	@Override
	public boolean equals(Object obj) {
	//	return super.equals(obj);
		if(obj instanceof Integer && ((Integer)obj).val == this.val)
			return true;
		else
			return false;
	}
	
	@Override
	public int compareTo(Integer obj) {
		if(this.val > obj.val)
			return 1;
		if(this.val < obj.val)
			return -1;
		return 0;
	}
}
