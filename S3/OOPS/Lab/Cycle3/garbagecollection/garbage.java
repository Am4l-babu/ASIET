import java.util.*;
class test
{
	protected void finalize()
	{
		System.out.println("Object is garbage collected");
	}
	public static void main(String[] args)
	{
		Scanner s=new Scanner(System.in);
		test s1=new test();
		test s2=new test();
		s1=null;
		s2=null;
		s.close();
		System.gc();
	}
}
