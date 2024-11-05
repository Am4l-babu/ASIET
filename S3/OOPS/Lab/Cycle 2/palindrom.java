import java.util.*;
class palindrom
{
	public static void main(String args[])
	{
	
		Scanner s=new Scanner(System.in);
		String word,rev="";
		System.out.println("Enter the string: ");
		word=s.nextLine();
		int n=word.length();
		word=word.toLowerCase();
		for(int i=n-1;i>-1;i--)
		{
			rev=rev+word.charAt(i);
		}
		if(word.equals(rev))
			System.out.println("The Given string is Palindrome");
		else
			System.out.println("The Given string is not a palindrome");
		s.close();
	}
}
		
			
