#include<stdio.h>

int power(int,int,int);
int q,alpha;

int main()
{
	scanf("%d %d", &q, &alpha);
	
	int xA,yA;
	int xB,yB;
	
	scanf("%d",&xA);//xA<q
	
	yA = power(alpha,xA,q);	
	
	scanf("%d",&xB);//xB<q
	yB = power(alpha,xB,q);
	
	int KA,KB;
	KA = power(yB,xA,q);
	KB = power(yA,xB,q);
	if(KA==KB)
	{
		printf("Successfull");
		printf("\nKA: %d\nKB: %d",KA,KB);
	}
}
int power(int alpha, int x, int mod)
{
	int res=1;
	alpha = alpha%mod;
	while(x>0)
	{
		if(x%2==1)
		{
			res = (res*alpha)%mod;
		}
		alpha = (alpha*alpha)%mod;
		x /= 2;
	}
	return res;
}