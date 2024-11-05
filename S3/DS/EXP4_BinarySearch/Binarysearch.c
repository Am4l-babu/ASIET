#include<stdio.h>
void sort(int arr[],int n)
{
	int i,j,b=0,temp;
	for(i=0;i<n-1;i++)	
	{
		b=0;
		for(j=0;j<n-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
				b=1;
			}
		}
		
		if(b==0)
			break;
	}
}
void search(int arr[],int n,int s)
{
	int fe=0,le=n,me,b=0;
	while(fe<=le)
	{
		me=fe+(le-fe)/2;
		if(arr[me]==s)
		{
			printf("The element is found at %d",me);
			b=1;
			break;
		}
		else if(arr[me]>s)
			le=me-1;
		else 
			fe=me+1;		
	}
		if (b==0)
		{
			printf("The element is not found in the array");
		}
		
}
		
int main()
{
	int a[100],n,i,s;
	printf("Enter the number of elements in the array");
	scanf("%d",&n);
	printf("Enter the array");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("Enter the Search element");
	scanf("%d",&s);
	sort(a,n);
	search(a,n,s);
	printf("\n");
	return 0;
}
				

	
