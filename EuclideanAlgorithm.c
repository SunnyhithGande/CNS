#include<stdio.h>

int euclidian(int a, int b)  // Moved above
{
	if(b == 0)
		return a;
	else
		return euclidian(b, a % b);
}

int main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	
	int ans = (a > b) ? euclidian(a, b) : euclidian(b, a);
	
	printf("GCD: %d\n", ans);
	return 0;
}
