#include<stdio.h>
int main()
{
	int a,b;
	printf("Enter number-1: ");
	scanf("%d",&a);
	printf("Enter number-2: ");
	scanf("%d",&b);
	int c = Euclidean(a,b,0,1,0);
	printf("%d\n",c);
}
int Euclidean(int a,int b,int t1,int t2,int t){
	if(b==0){
		return t1;
	}
	else{
		int q = a/b;
		t1=t2;
		t2=t;
		int t=t1-(t2*q);
		Euclidean(b,a%b,t1,t2,t);
	}
}
