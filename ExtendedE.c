#include <stdio.h>

int modInverse(int a, int b) {
    int t1 = 0, t2 = 1, t, q, r, origA = a;

    while (b != 0) {
        q = a / b;
        r = a % b;
        t = t1 - q * t2;
        t1 = t2;
        t2 = t;
        a = b;
        b = r;
    }

    if (a != 1) {
        printf("Inverse doesn't exist\n");
        return -1;
    }

    return (t1 < 0) ? t1 + origA : t1;
}

int main() {
    int a,b;
    scanf("%d %d",&a, &b);
    
    int inverse;
    if(a>b)
    {
    	inverse = modInverse(a, b);
	}
	else
	{
		inverse = modInverse(b,a);
	}

    if (inverse != -1)
        printf("Multiplicative Inverse of %d modulo %d is: %d\n", a,b, inverse);

    return 0;
}
