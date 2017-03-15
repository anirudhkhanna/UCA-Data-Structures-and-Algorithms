/* Sample program in Java demonstrating classes, interfaces, polymorphism, generics etc. */

package javapractice.processscheduling;

/* PROCESS CLASS */
public class Process
{
	private Integer pId;
	private String pName;
	
	public Process(Integer pId, String pName)
	{
		this.pId = pId;
		this.pName = pName;
	}
	
	public String getPName()
	{
		return pName;
	}

	public Integer getPId()
	{
		return pId;
	}
	
	public String toString()
	{
		return pName;
	}
};