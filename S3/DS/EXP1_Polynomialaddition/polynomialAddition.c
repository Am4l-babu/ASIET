#include<stdio.h>

struct poly
{
	int exp;
	int cof;
};	

int main()
{
	struct poly p1[100], p2[100], r[100];
	int a, b, i, j, k, frun = 0;
	
	printf("Enter the length of the first polynomial: ");
	scanf("%d", &a);
	
	printf("Enter the length of the second polynomial: ");
	scanf("%d", &b);
	
	printf("Enter the first polynomial:\n");
	for(i = 0; i < a; i++)
	{
		printf("Enter exponent for term %d: ", i + 1);
		scanf("%d", &p1[i].exp);
		printf("Enter coefficient for term %d: ", i + 1);
		scanf("%d", &p1[i].cof);
	}
	
	printf("Enter the second polynomial:\n");
	for(i = 0; i < b; i++)
	{
		printf("Enter exponent for term %d: ", i + 1);
		scanf("%d", &p2[i].exp);
		printf("Enter coefficient for term %d: ", i + 1);
		scanf("%d", &p2[i].cof);
	}
	
	i = 0; j = 0; k = 0;
	while (i < a && j < b)
	{
		if (p1[i].exp == p2[j].exp)
		{
			r[k].cof = p1[i].cof + p2[j].cof;
			r[k].exp = p1[i].exp;
			i++; j++;
		}
		else if (p1[i].exp > p2[j].exp)
		{
			r[k].cof = p1[i].cof;
			r[k].exp = p1[i].exp;
			i++;
		}
		else
		{
			r[k].cof = p2[j].cof;
			r[k].exp = p2[j].exp;
			j++;
		}
		k++;
	}

	while (i < a)
	{
		r[k].cof = p1[i].cof;
		r[k].exp = p1[i].exp;
		i++; k++;
	}

	while (j < b)
	{
		r[k].cof = p2[j].cof;
		r[k].exp = p2[j].exp;
		j++; k++;
	}
	
	printf("The resultant polynomial is: ");
	for(i = 0; i < k; i++)
	{
		if (r[i].cof < 0)
		{
			printf("-");
		}
		else if (i != 0)
		{
			printf("+");
		}
		printf("%dx^%d", r[i].cof, r[i].exp);
	}
	printf("\n");
	
	return 0;
}
