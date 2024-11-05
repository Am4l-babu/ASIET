#include<stdio.h>
void sort(int arr[],int n)
{
	int i,j,b,temp;
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
int main()
{
	int a[100],n,i;
	printf("Enter the number of elements in the array");
	scanf("%d",&n);
	printf("Enter the array");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a,n);
	printf("The sorted array is\n");
	for(i=0;i<n;i++)
	{
		if(i!=0)
			printf(",%d",a[i]);
		else
			printf("%d",a[i]);
	}
	printf("\n");
	return 0;
}
				

	
