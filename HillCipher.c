#include<stdio.h>
#include<string.h>
int main() {
    unsigned int a[3][3] = { { 17, 17, 5 }, { 21,18,21 }, {2,2,19 } };
    unsigned int b[3][3] = { { 4, 9, 15 }, { 15, 17, 6 }, { 24, 0, 17 } };
    int i, j;
    unsigned int c[20], d[20];
    char msg[20];
    int determinant = 0, t = 0;
    
    printf("Enter plaintext to Encrypt: ");
    scanf("%s", msg);
    for (i = 0; i < 3; i++) 
	{
        c[i] = msg[i] - 65;
        printf("%d ", c[i]);
    }
    
    for (i = 0; i < 3; i++) 
	{
        t = 0;
        for (j = 0; j < 3; j++) 
		{
            t = t + (a[i][j] * c[j]);
        }
        d[i] = t % 26;
    }
    
    printf("\nEncrypted Cipher Text :");
    
    for (i = 0; i < 3; i++)
        printf(" %c", d[i] + 65);
    for (i = 0; i < 3; i++) 
	{
        t = 0;
        for (j = 0; j < 3; j++) 
		{
            t = t + (b[i][j] * d[j]);
        }
        c[i] = t % 26;
    }
    printf("\nDecrypted Cipher Text :");
    for (i = 0; i < 3; i++)
        printf(" %c", c[i] + 65);
    return 0;
}
