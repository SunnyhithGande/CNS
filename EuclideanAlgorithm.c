#include<stdio.h>
int main()
{
	int a,b;
	printf("Enter a number1--");
	scanf("%d",&a);
	printf("Enter a number2--");
	scanf("%d",&b);
	int c;
	if(a>b)
	{
		c=Euclidean(a,b);
	}
	else
	{
		c = Euclidean(b,a);
	}
	printf("GCD of %d and %d: %d\n",a,b,c);
}
int Euclidean(int a,int b)
{
	if(b==0)
	{
		return a;
	}
	else
	{
		Euclidean(b,a&b);
	}
}
