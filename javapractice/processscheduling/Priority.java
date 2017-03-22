/* Sample program in Java demonstrating classes, interfaces, polymorphism, generics etc. */

package javapractice.processscheduling;

import java.lang.Comparable; // for the Comparable interface. Not necessary to import, imported by default in Java.
import java.util.Comparator; // for the Comparator interface.

/* PRIORITY CLASS */
public class Priority implements Comparable/*<T>*/
{
	private Integer avgTime;
	private Integer medianTime;
	
	public Priority(Integer avgTime, Integer medianTime)
	{
		this.avgTime = avgTime;
		this.medianTime = medianTime;
	}
	
	public Integer getAvgTime()
	{
		return avgTime;
	}

	public Integer getMedianTime()
	{
		return medianTime;
	}

	/* Implementing compareTo() method based on avgTime */
	@Override
	public int compareTo(Object o)
	{
		Priority p = (Priority) o;
		
		if(this.avgTime > p.avgTime) return 1;
		else if(this.avgTime < p.avgTime) return -1;
		else return 0;
	}
}

/* COMPARATORBYAVGTIME CLASS IMPLEMENTING COMPARATOR INTERFACE */
class ComparatorByAvgTime implements Comparator/*<T>*/
{
	@Override
	public int compare(Object o1, Object o2)
	{
		Priority p1 = (Priority) o1;
		Priority p2 = (Priority) o2;
		
		if(p1.getAvgTime() > p2.getAvgTime()) return 1;
		else if(p1.getAvgTime() < p2.getAvgTime()) return -1;
		else return 0;
	}
}

/* COMPARATORBYMEDIANTIME CLASS IMPLEMENTING COMPARATOR INTERFACE */
class ComparatorByMedianTime implements Comparator/*<T>*/
{
	@Override
	public int compare(Object o1, Object o2)
	{
		Priority p1 = (Priority) o1;
		Priority p2 = (Priority) o2;
		
		if(p1.getMedianTime() > p2.getMedianTime()) return 1;
		else if(p1.getMedianTime() < p2.getMedianTime()) return -1;
		else return 0;
	}
}