import java.util.*;
class search{
	void search(int a[],int key,int len)
	{
		int left=0,right=len;
		boolean b=false;
		while(left<right)
		{
			int mid=left+(right-left)/2;
			if(a[mid]==key)
			{
				System.out.println("The elements is found at "+mid);
				b=true;
				break;
			}
			else if(a[mid]>key)
			{
				right=mid-1;
			}
			else
			{
				left=left+1;
			}
		}
			if(b==false)
			{
				System.out.println("The element is not found at the array");
			}
	}
}
class main{
	public static void main(String[] args)
	{
		Scanner s=new Scanner(System.in);
		search obj=new search();
		int arr[]=new int[100];
		System.out.println("Enter the length of the array");
		int len=s.nextInt();
		System.out.println("Enter a sorted array");
		for(int i=0;i<len;i++)
		{
			arr[i]=s.nextInt();
		}
		System.out.println("Enter the search key");
		int key=s.nextInt();
		obj.search(arr,key,len);
		System.out.println();
	}
}
		
			
